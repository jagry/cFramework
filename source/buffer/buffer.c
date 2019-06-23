#include <jagry/buffer.h>
#include <stdlib.h>
#include <string.h>

JResult jagryAddBufferCharacter( JPBuffer self , JByte byte ) {
JSize size = self->size + 1 ;
JByte* bytes = realloc( self->bytes , size ) ;
if( bytes == 0 ) return jNotEnoughtMemoryErrorResult ;
bytes[ self->size ] = byte ;
self->bytes = bytes ;
self->size = size ;
return jSuccessResult ;
}

JVoid jagryClearBuffer( JPBuffer self ) {
if( self->bytes )
	free( self->bytes ) ,
	self->bytes = 0 ;
self->size = 0 ;
}

JResult jagryConcateBuffer( JCPCBuffer in1 , JCPCBuffer in2 , JPBuffer out ) {
JBuffer local ;
jagryClearBuffer( out ) ;
if( ( local.bytes = malloc( local.size = in1->size + in2->size ) ) == 0 )
	return jNotEnoughtMemoryErrorResult ;
*out = local ;
memcpy( local.bytes , in1->bytes , in1->size ) ;
memcpy( local.bytes + in1->size , in2->bytes , in2->size ) ;
return jSuccessResult ;
}

JResult jagryCreatePBuffer( JPCBuffer in , JPPBuffer out ) {
if( in ) return jagryCreateBuffer( in->bytes , in->size , out ) ;
*out = 0 ;
return jPointerIsNilWarningResult ;
}

JResult jagryCreateBuffer( JPCByte bytesIn , JSize sizeIn , JPPBuffer out ) {
JResult result ;
if( ( *out = malloc( sizeof( JBuffer ) ) ) == 0 )
	return jNotEnoughtMemoryErrorResult ;
if( jResultIsError( result = jagryInitializeBuffer( *out , bytesIn , sizeIn ) ) )
	free( *out ) ;
return result ;
}

JVoid jagryFreeBuffer( JPBuffer self ) {
if( self->bytes )
	free( self->bytes ) ;
free( self ) ;
}

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