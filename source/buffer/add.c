#include <jagry/buffer.h>
#include <stdlib.h>

JResult jagryAddBufferCharacter( JPBuffer self , JByte byte ) {
JSize size = self->size + 1 ;
JByte* bytes = realloc( self->bytes , size ) ;
if( bytes == 0 ) return jNotEnoughtMemoryErrorResult ;
bytes[ self->size ] = byte ;
self->bytes = bytes ;
self->size = size ;
return jSuccessResult ;
}