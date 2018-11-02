#include <stdlib.h>
#include <string.h>
#include <jagry/buffer.h>

JResult jagryAddBufferCharacter( JPBuffer self , JByte byte ) {
JSize size = self->size + 1 ;
JByte* bytes = realloc( self->bytes , size ) ;
if( bytes == 0 ) return jNotEnoughtMemoryErrorResult ;
bytes[ self->size ] = byte ;
self->bytes = bytes ;
self->size = size ;
return jSuccesResult ;
}

JVoid jagryClearBuffer( JPBuffer self ) {
if( self->bytes )
	free( self->bytes ) ,
	self->bytes = 0 ;
self->size = 0 ;
}

JResult jagryCreatePBuffer( JPCBuffer in , JPPBuffer out ) {
if( in ) return jagryCreateBuffer( in->bytes , in->size , out ) ;
*out = 0 ;
return jPointerIsNilWarningResult ;
}

JResult jagryCreateBuffer( JPCByte bytesIn , JSize sizeIn , JPPBuffer out ) {
JResult result ;
if( ( *out = malloc( sizeof( JBuffer ) ) ) == 0 ) return jNotEnoughtMemoryErrorResult ;
if( jResultIsError( result = jagryInitializeBuffer( *out , bytesIn , sizeIn ) ) ) free( *out ) ;
return result ;
}

//void jagryDumpBuffer( JIDump dump , JCPCBuffer self ) {
/*jagryDumpString1( dump , "buffer{ size = " ) ;
jagryDumpDecimalSignedInteger( dump , self->size ) ;
jagryDumpString1( dump , " , value = " ) ;
jagryDumpByteArray( dump , self->bytes , self->size ) ;
jagryDumpString1( dump , " }" ) ;*/
//}

JVoid jagryFreeBuffer( JPBuffer self ) {
if( self->bytes )
	free( self->bytes ) ;
free( self ) ;
}

	JResult jagryInitializeBuffer( JPBuffer self , JCPCVoid bytes , JSize size ) {
if( size == 0 )
	{
		self->bytes = 0 ;
		self->size = 0 ;
		return jSuccesResult ;
	}
if( ( self->bytes = malloc( size ) ) == 0 )
	return jNotEnoughtMemoryErrorResult ;
memcpy( self->bytes , bytes , self->size = size ) ;
return jSuccesResult ;

}

JResult jagrySetBuffer( JPBuffer self , JPVoid bytes , JSize size ) {
JPByte local ;
if( size )
	{
		if( ( local = malloc( size ) ) == 0 ) return jNotEnoughtMemoryErrorResult ;
		memcpy( local , bytes , size ) ;
	}
else
	local = 0 ;
if( self->bytes )
	free( self->bytes ) ;
self->bytes = local ;
self->size = size ;
return jSuccesResult ;
}