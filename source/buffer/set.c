#define jBufferMethod jExport

#include <jagry/buffer.i.h>
#include <jagry/result.h>
#include <memory.h>
#include <stdlib.h>

#include <jagry/buffer/set.h>

JResult jagrySetBuffer( JPBuffer self , JPVoid bytes , JSize size ) {
JPByte local ;
if( size )
	{
		if( ( local = malloc( size ) ) == 0 )
			return jNotEnoughtMemoryErrorResult ;
		memcpy( local , bytes , size ) ;
	}
else
	local = 0 ;
if( self->bytes )
	free( self->bytes ) ;
self->bytes = local ;
self->size = size ;
return jSuccessResult ;
}