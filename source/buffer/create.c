#include <jagry/buffer.h>
#include <stdlib.h>

JResult jagryCreatePBuffer( JPCBuffer in , JPPBuffer out ) {
if( in ) return jagryCreateBuffer( in->bytes , in->size , out ) ;
*out = 0 ;
return jPointerIsNilWarningResult ;
}

JResult jagryCreateBuffer( JPCByte bytesIn , JSize sizeIn , JPPBuffer out ) {
JResult result ;
if( ( *out = malloc( sizeof( JBuffer ) ) ) == 0 )
	return jNotEnoughtMemoryErrorResult ;
if( jResultIsError( result = jagryInitializeBuffer( *out , bytesIn , sizeIn ) ) )
	free( *out ) ;
return result ;
}