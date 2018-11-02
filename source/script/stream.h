//#ifndef JAGRY_STREAM
//#define JAGRY_STREAM

#define jReadStream( self , buffer , size ) ( ( self )->methods->read( ( self ) , ( buffer ) , &( size ) ) )

typedef struct jIInputStream jIInputStream ;
typedef struct jMInputStream jMInputStream ;

struct jIInputStream {
    jMInputStream* methods ;
} ;

struct jMInputStream {
    int( *close )( jIInputStream* ) ;
    int( *read )( jIInputStream* , char* , int ) ;
    int( *release )( jIInputStream* ) ;
} ;

int jBufferInputStream( const char* , const int , jIInputStream** ) ;

//#endif // JAGRY_STREAM