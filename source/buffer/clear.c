#define jBufferMethod jExport

#include <jagry/buffer.i.h>
#include <stdlib.h>

#include <jagry/buffer/clear.h>

JVoid jagryClearBuffer( JPBuffer self ) {
if( self->bytes )
	free( self->bytes ) ,
	self->bytes = 0 ;
self->size = 0 ;
}