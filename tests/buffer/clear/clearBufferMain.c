#include <jagry/buffer.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#define mainSpace "   "
#define mainText1 "test1"
#define mainText2 "test2"

#define checkInvalidBufferSize "clearBuffer - error: invalid buffer size(" jSizeSpecifier "). Must be " jSizeSpecifier "." jNewLine
#define checkBufferPointerIsNil "clearBuffer - error: buffer pointer must not be 0." jNewLine
#define checkInvalidBufferPointerByte "clearBuffer - error: invalid buffer pointer byte(index " jCounterSpecifier " have value " jByteSpecifier "). Must be " jByteSpecifier "." jNewLine

JVoid drawBuffer( JBuffer buffer , JCounter level ) ;

JResult checkBuffer( JBuffer buffer , JPVoid bytes , JSize size ) {
if( buffer.size != size )
	{
		printf( checkInvalidBufferSize , buffer.size , size ) ;
		return -1 ;
	}
if( size )
	{
		if( !buffer.bytes )
			{
				printf( checkBufferPointerIsNil ) ;
				return -2 ;
			}
		for( JCounter counter = 0 ; counter < size ; ++counter )
			if( ( ( JPByte )buffer.bytes )[ counter ] != ( ( JPByte )bytes )[ counter ] )
				{
					printf( checkInvalidBufferPointerByte , counter , ( ( JPByte )buffer.bytes )[ counter ] , ( ( JPByte )bytes )[ counter ] ) ;
					return -3 ;
				}
	}
else
	if( buffer.bytes )
		{
			printf( "clearBuffer - error: buffer pointer must be 0." jNewLine ) ;
			return -4 ;
		}
return 0 ;
}

/*JVoid checkBufferString( JBuffer buffer , JPCharacter1 text ) {
checkBuffer( buffer , text , strlen( text ) ) ;
}*/

JResult main( ) {
printf( "clearBuffer: start" jNewLine ) ;
JBuffer buffer ;
JResult result ;
JSize size = strlen( mainText1 ) ;
jagryInitializeBuffer( &buffer , mainText1 , size ) ;
if( ( result = checkBuffer( buffer , mainText1 , size ) ) < 0 )
	return result - 10 ;
printf( "clearBuffer: step 0" jNewLine ) ;
jagrySetBuffer( &buffer , mainText2 , size = strlen( mainText2 ) ) ;
if( ( result = checkBuffer( buffer , mainText2 , size ) ) < 0 )
	return result - 20 ;
printf( "clearBuffer: step 1" jNewLine ) ;
jagryClearBuffer( &buffer ) ;
if( ( result = checkBuffer( buffer , 0 , 0 ) ) < 0 )
	return result - 30 ;
printf( "clearBuffer - ok" jNewLine ) ;
return 0 ;
}