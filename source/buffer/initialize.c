#define jBufferMethod jExport

#include <jagry/buffer.i.h>
#include <jagry/result.h>
#include <memory.h>
#include <stdlib.h>

#include <jagry/buffer/initialize.h>

JResult jagryInitializeBuffer( JPBuffer self , JCPCVoid bytes , JSize size ) {
if( size == 0 )
	{
		self->bytes = 0 ;
		self->size = 0 ;
		return jSuccessResult ;
	}
if( ( self->bytes = malloc( size ) ) == 0 )
	return jNotEnoughtMemoryErrorResult ;
memcpy( self->bytes , bytes , self->size = size ) ;
return jSuccessResult ;
}