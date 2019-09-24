#include <jagry/buffer.h>
#include <stdlib.h>

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