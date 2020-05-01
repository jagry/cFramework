#ifndef JagryBufferInterface
#define JagryBufferInterface

#define jEmptyBuffer jBuffer( 0 , 0 )
#define jBuffer( bytesIn , sizeIn ) ( ( JBuffer ){ .bytes = bytesIn , .size = sizeIn } )
#define jStringBuffer( in ) ( ( JCBuffer ){ .bytes = in , .size = strlen( in ) } )
#define jMethodBuffer( in ) ( ( JCBuffer ){ .bytes = ( JPByte )&in , .size = sizeof( &in ) } )

// !!! #include <string.h>
#include "../jagry.h"

jPrefixType( J , Buffer , struct JBuffer )

struct JBuffer {
	JPByte bytes ;
	JSize size ; } ;

#endif
