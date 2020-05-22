#define jBufferMethod jExport

#include <jagry/buffer.i>
#include <stdlib.h>

#include <jagry/buffer/free>

JVoid jagryFreeBuffer( JPBuffer self ) {
if( self->bytes )
	free( self->bytes ) ;
free( self ) ;
}