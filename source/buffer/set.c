#include <jagry/buffer.h>
#include <stdlib.h>

/* !!! */#include <stdio.h>

JResult jagrySetBuffer( JPBuffer self , JPVoid bytes , JSize size ) {
JPByte local ;
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
if( size )
	{
		if( ( local = malloc( size ) ) == 0 )
			return jNotEnoughtMemoryErrorResult ;
		memcpy( local , bytes , size ) ;
	}
else
	local = 0 ;
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
if( self->bytes )
	printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ,
	free( self->bytes ) ,
	printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
self->bytes = local ;
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
self->size = size ;
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
return jSuccessResult ;
}