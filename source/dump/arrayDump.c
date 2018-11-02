#include <jagry/ldump.h>
#include <memory.h>
#include <unistd.h>

JBuffer gSpace = { .bytes = ( JByte[ ] ){ ' ' } , .size = 1 } ;

JSize calculateLength( JBuffer buffer ) {
JSize result = 0 ;
for( ; buffer.size ; ++buffer.bytes , ++result , --buffer.size )
	if( *buffer.bytes == '/' )
		++buffer.bytes , --buffer.size ;
return result ;
}

static JBoolean flushArrayDump( JPDump self ) {
for( JCounter counter = 0 ; counter < ( ( JPMainDump )self )->buffer.size ; ++counter )
	if( ( ( JPMainDump )self )->buffer.bytes[ counter ] == ':' )
		{
			if( ( ( JPMainDump )self )->mode == jIndentDumpMode )
				for( JCounter blankCounter = ( ( JPMainDump )self )->level ; blankCounter ; --blankCounter )
					write( ( ( JPMainDump )self )->stream , ( ( JPMainDump )self )->indent.bytes , ( ( JPMainDump )self )->indent.size ) ;
			write( ( ( JPMainDump )self )->stream , ( ( JPMainDump )self )->buffer.bytes , counter + 1 ) ;
			write( ( ( JPMainDump )self )->stream , ( JByte[ ] ){ '\r' , '\n' } , 2 ) ;
			memcpy( ( ( JPMainDump )self )->buffer.bytes , &( ( JPMainDump )self )->buffer.bytes[ counter + 1 ] , ( ( JPMainDump )self )->buffer.size - counter - 1 ) ;
			( ( JPMainDump )self )->buffer.size -= counter  + 1 ;
			( ( JPMainDump )self )->offset -= counter + 1 ;
			++( ( JPMainDump )self )->level ;
			return jTrue ; 
		}
return jFalse ;
}

static void flushArrayDumpAll( JPDump self ) {
if( ( ( JPMainDump )self )->mode == jIndentDumpMode )
	for( JCounter counter = ( ( JPMainDump )self )->level ; counter ; --counter )
		write( ( ( JPMainDump )self )->stream , ( ( JPMainDump )self )->indent.bytes , ( ( JPMainDump )self )->indent.size ) ;
write( ( ( JPMainDump )self )->stream , ( ( JPMainDump )self )->buffer.bytes , ( ( JPMainDump )self )->buffer.size ) ;
( ( JPMainDump )self )->mode = jTransitDumpMode ;
}

static JSize getArrayDumpSize( JPCDump self ) {
return 0 ;
}

static void writeArrayDump( JPDump self , JPCByte bytesIn , JSize sizeIn ) {
start : if( ( ( JPMainDump )self )->mode == jTransitDumpMode )
	write( ( ( JPMainDump )self )->stream , bytesIn , sizeIn ) ;
else
	{
		while( sizeIn )
			{
				while( ( ( JPMainDump )self )->buffer.size >= ( ( JPMainDump )self )->size )
					if( flushArrayDump( self ) == jFalse )
						{
							flushArrayDumpAll( self ) ;
							goto start ;
						}
				( ( JPMainDump ) self )->buffer.bytes[ ( ( JPMainDump ) self )->buffer.size ] = *bytesIn ;
				++( ( JPMainDump ) self )->offset ;
				++( ( JPMainDump ) self )->buffer.size ;
				++bytesIn , --sizeIn ;
			}
	}
}

JDumpMethods staticMainMethods = {
	.flush = flushMainDump ,
	.flushAll = flushMainDumpAll ,
	.getSize = getMainDumpSize ,
	.write = writeMainDump } ;

void jagryInitializeArrayDump( JPArrayDump self , JPDump afterColon , JPCBuffer beforeColon ) {
self->mode = jIndentDumpMode ;
self->afterColon = afterColon ? *afterColon : gSpace ;
self->beforeColon = beforeColon ? *beforeColon : gSpace ;
}