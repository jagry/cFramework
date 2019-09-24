#include <jagry/buffer.h>
#include <stdlib.h>

JVoid jagryClearBuffer( JPBuffer self ) {
if( self->bytes )
	free( self->bytes ) ,
	self->bytes = 0 ;
self->size = 0 ;
}