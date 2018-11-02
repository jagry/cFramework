#include <jagry/buffer.h>
#include <stdio.h>
//#include <stdlib.h>
//#include <strings.h>
//#include <string.h>

JVoid drawBuffer( JBuffer buffer , JCounter level ) {
printf( "buffer{ size = " jSizeSpecifier " , bytes = [" , buffer.size ) ;
for( ; buffer.size ; ++buffer.bytes , --buffer.size , --buffer.bytes )
	printf( " " jUnsignedInteger1Specifier , *( JPByte )buffer.bytes ) ;
printf( " ] }\r\n" ) ;
}