#include "buffer.h"
#include "keyword.h"
#include "parser.h"

#define MAX_KEYWORD_SIZE 3
#define MIN_KEYWORD_SIZE 3

struct dd {
    Keyword identifier ;
    char* name ;
} ;

static struct dd keywords[ 1 ] = {
    { .identifier = INT_KEYWORD , .name = "int" } } ;

int getIdentifier( Parser* parser , JInputStream* stream , JBuffer* out ) ;

int getKeyword( Parser* parser , JInputStream* stream , Keyword* out ) {
    /*JBuffer buffer ;
    int result = readCharacter( parser , stream ) ;
    if( result < 0 )
        return result ;
    if( ( result = initBuffer( &buffer , &parser->character , 1 ) ) < 0 )
        return result ;
    if( ( result = getIdentifier( parser , stream , &buffer ) ) <  0 )
        return result ;
    for( int counter = 0 ; ( sizeof( keywords ) / sizeof( keywords ) ) > counter ; ++counter )
        if( strlen( keywords[ counter ].name ) == buffer.size && memcpy( buffer.pointer , keywords[ counter ].name , buffer.size ) )
            {
                *out = keywords[ counter ].identifier ;
                return 0 ;
            }*/
    return 0 ;
}