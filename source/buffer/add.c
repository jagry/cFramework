#define jBufferMethod jExport

#include <jagry/buffer.i>
#include <jagry/result.h>
#include <stdlib.h>

#include "jagry/buffer/add"

JResult jagryAddBufferByte( JPBuffer self , JByte in ) {
JSize size = self->size + 1 ;
JByte* bytes = realloc( self->bytes , size ) ;
return bytes ?
	( bytes[ self->size ] = in , self->bytes = bytes ,
		self->size = size , jSuccessResult ) :
	jNotEnoughtMemoryErrorResult ;
}