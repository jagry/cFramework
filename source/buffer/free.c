#define jBufferMethod jExport

#include <jagry/buffer.i.h>
#include <stdlib.h>

#include <jagry/buffer/free.h>

JVoid jagryFreeBuffer( JPBuffer self ) {
if( self->bytes )
	free( self->bytes ) ;
free( self ) ;
}