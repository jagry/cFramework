#ifndef jagryBuffer
#define jagryBuffer

#define jEmptyBuffer( ) jBuffer( 0 , 0 )
#define jBuffer( bytesIn , sizeIn ) { .bytes = bytesIn , .size = sizeIn }

typedef struct JBuffer JBuffer ;

typedef JBuffer const JCBuffer ;
typedef JBuffer * JPBuffer ;

typedef JCBuffer * JPCBuffer ;
typedef JPBuffer * JPPBuffer ;


#include "result.h"

struct JBuffer {
JPVoid bytes ;
JSize size ;
} ;

#include "idump.h"

JResult jagryAddBufferByte( JPBuffer , JByte ) ;
JVoid jagryClearBuffer( JPBuffer ) ;
JResult jagryCreatePBuffer( JPCBuffer , JPPBuffer ) ;
JResult jagryCreateBuffer( JPCByte , JSize , JPPBuffer ) ;
//void jagryDumpBuffer( JIDump , JCPCBuffer ) ;
void jagryFreeBuffer( JPBuffer ) ;
JResult jagryInitializeBuffer( JPBuffer , JCPCVoid , JSize ) ;
JResult jagrySetBuffer( JPBuffer , JPVoid , JSize ) ;

#endif