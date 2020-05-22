#define jBufferMethod jExport

#include <jagry/buffer.i>
#include <jagry/result.h>
#include <stdlib.h>

#include <jagry/buffer/create>
#include <jagry/buffer/initialize>

JResult jagryCreatePBuffer( JCPCBuffer in , JPPBuffer out ) {
return in ?
	jagryCreateBuffer( in->bytes , in->size , out ) :
	( *out = 0 , jPointerIsNilWarningResult ) ;
}

JResult jagryCreateBuffer( JPCByte bytesIn , JSize sizeIn , JPPBuffer out ) {
JResult result ;
if( !( *out = malloc( sizeof( JBuffer ) ) ) )
	return jNotEnoughtMemoryErrorResult ;
result = jagryInitializeBuffer( *out , bytesIn , sizeIn ) ;
if( jResultIsError( result ) )
	free( *out ) ;
return result ;
}