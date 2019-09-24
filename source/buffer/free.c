#include <jagry/buffer.h>
#include <stdlib.h>

JVoid jagryFreeBuffer( JPBuffer self ) {
if( self->bytes )
	free( self->bytes ) ;
free( self ) ;
}