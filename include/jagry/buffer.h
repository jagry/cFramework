#ifndef jagryBuffer
#define jagryBuffer

#define jEmptyBuffer jBuffer( 0 , 0 )
#define jBuffer( bytesIn , sizeIn ) ( ( JBuffer ){ .bytes = bytesIn , .size = sizeIn } )
#define jStringBuffer( in ) ( ( JBuffer ){ .bytes = in , .size = strlen( in ) } )

typedef struct JBuffer JBuffer ;

typedef JBuffer const JCBuffer ;
typedef JBuffer * JPBuffer ;

//typedef JPBuffer const JCPBuffer ;
typedef JCBuffer * JPCBuffer ;
typedef JPBuffer * JPPBuffer ;

typedef JPCBuffer const JCPCBuffer ;

#include "result.h"

struct JBuffer {
JPVoid bytes ;
JSize size ;
} ;

//#include "idump.h"

JResult jagryAddBufferByte( JPBuffer , JByte ) ;
JVoid jagryClearBuffer( JPBuffer ) ;
JResult jagryConcateBuffer( JCPCBuffer , JCPCBuffer , JPBuffer ) ;
JResult jagryCreatePBuffer( JPCBuffer , JPPBuffer ) ;
JResult jagryCreateBuffer( JPCByte , JSize , JPPBuffer ) ;
//void jagryDumpBuffer( JIDump , JCPCBuffer ) ;
void jagryFreeBuffer( JPBuffer ) ;
JResult jagryInitializeBuffer( JPBuffer , JCPCVoid , JSize ) ;
JResult jagrySetBuffer( JPBuffer , JPVoid , JSize ) ;

#endif