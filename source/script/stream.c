#include <memory.h>
#include <string.h>
#include "stream.h"

typedef struct BufferInputStream {
    jMInputStream methods ;
    char* buffer ;
    int offset , size ;
} BufferInputStream ;

static int BufferInputStreamRead( jIInputStream* self , char* buffer , int* size ) {
    int available = ( ( BufferInputStream* )self )->size - ( ( BufferInputStream* )self )->offset ;
    if( !available )
        return - 1 ;
    if( available < size )
        *size = available ;
    memcpy( buffer , ( ( BufferInputStream* )self )->buffer + ( ( BufferInputStream* )self )->offset , *size ) ;
    return 0 ;
}

static int BufferInputStreamRelease( jIInputStream* self ) {
    free( self ) ;
    return 0 ;
}

int jBufferInputStream( const char* buffer , const int size , jIInputStream** out ) {
    static const jMInputStream methods = {
        .close = 0 ,
        .read = BufferInputStreamRead ,
        .release = BufferInputStreamRead } ;
    if( *out = malloc( sizeof( jIInputStream ) ) )
        return -1 ;
    ( *out )->methods = &methods ;
    ( ( BufferInputStream* )*out )->buffer = buffer ;
    ( ( BufferInputStream* )*out )->offset = 0 ;
    ( ( BufferInputStream* )*out )->size = size ;
    return 0 ;
}