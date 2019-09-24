//#ifndef JAGRY_STREAM
//#define JAGRY_STREAM

#include <jagry/buffer.h>

#include "buffer.h"

#define jReadStream( self , buffer , size ) ( ( self )->methods->read( ( self ) , ( buffer ) , &( size ) ) )

typedef struct JInputStream JInputStream ;
typedef struct JInputStreamMethods JInputStreamMethods ;
typedef struct JStreamStatus JStreamStatus ;
typedef struct JStreamStatusMethods JStreamStatusMethods ;

typedef JInputStream * JIInputStream ;
typedef JInputStreamMethods * JPInputStreamMethods ;
typedef JStreamStatus * JIStreamStatus ;
typedef JStreamStatusMethods * JPStreamStatusMethods ;

typedef const JPInputStreamMethods JCPInputStreamMethods ;

typedef JPInputStreamMethods * JPPInputStreamMethods ;

struct JInputStream {
    JCPInputStreamMethods methods ;
} ;

struct JInputStreamMethods {
	int( *close )( JIInputStream ) ;
	int( *read )( JIInputStream , char* , int* ) ;
	int( *release )( JIInputStream ) ;
} ;

int jagryBufferInputStream( const JBuffer const* , JInputStream** ) ;

//#endif // JAGRY_STREAM