#include <memory.h>
#include <stdlib.h>
#include <string.h>
#include "stream.h"

typedef struct BufferInputStream
{
	JCPInputStreamMethods methods ;
	JPBuffer buffer ;
	int offset , size ;
} BufferInputStream ;

typedef BufferInputStream * IBufferInputStream ;

typedef IBufferInputStream * PIBufferInputStream ;

static int BufferInputStreamRead( JIInputStream self , char* buffer , int* size ) {
int available = ( ( BufferInputStream* )self )->size - ( ( BufferInputStream* )self )->offset ;
if( !available )
		return - 1 ;
if( available < *size )
		*size = available ;
memcpy( buffer , ( ( BufferInputStream* )self )->buffer + ( ( BufferInputStream* )self )->offset , *size ) ;
return 0 ;
}

static int BufferInputStreamRelease( JIInputStream self ) {
    //free( self ) ;
    return 0 ;
}

int jagryBufferInputStream( const JBuffer * in , PIBufferInputStream out ) {
    static JInputStreamMethods methods = {
        .close = 0 ,
        .read = BufferInputStreamRead ,
        .release = BufferInputStreamRelease } ;
    if( *out = malloc( sizeof( BufferInputStream ) ) )
        return -1 ;
		*out = &( BufferInputStream ){ .methods = &methods } ;
   /*( *out )->methods = &methods ;
    ( ( BufferInputStream* )*out )->buffer = buffer ;
    ( ( BufferInputStream* )*out )->offset = 0 ;
    ( ( BufferInputStream* )*out )->size = size ;*/
    return 0 ;
}