#define jBufferMethod jExport

#include <jagry/buffer.i>
#include <stdlib.h>

#include <jagry/buffer/clear>

JVoid jagryClearBuffer( JPBuffer self ) {
if( self->bytes )
	free( self->bytes ) ,
	self->bytes = 0 ;
self->size = 0 ;
}