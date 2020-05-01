#define jBufferMethod jExport

#include <jagry/buffer.i.h>
#include <jagry/result.h>
#include <stdlib.h>

#include <jagry/buffer/create.h>
#include <jagry/buffer/initialize.h>

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