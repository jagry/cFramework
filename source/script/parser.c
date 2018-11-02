#include <stdio.h>
#include <stdlib.h>
#include "keyword.h"
#include "parser.h"

#include "blank.h"
#include "is.h"

static int ExecuteParser( const JParser* self , const char character , JParserStatus* status , JToken** token ) {
    return ( ( Parser* )self )->current->methods->execute( self , character , status , token ) ;
}

static int ExecuteStartParser( const Parser* parser , const char character , JParserStatus* status , JToken** token ) {
    printf( "ExecuteStartLocalParser\n" ) ;
    int result ;
    if( isBlank( character ) )
        {
            SkipBlankParser* sbp ;
            if( ( result = createBlankParser( parser , &sbp ) ) < 0 )
                return result ;
            *status = jRepeatParserStatus ;
            return 0 ;
        }
    return -1 ;
}

int jParser( JParser** out ) {
    static const JParserMethods methods = {
        .execute = ExecuteParser } ;
    static const JParserMethods startMethods = { .execute = 0 } ;
    static const StartParser start = { .methods = &startMethods } ;
    printf( "debug jParser: out before %p\n" , *out ) ;
    if( ( *out = malloc( sizeof( JParser ) ) ) == 0 )
        return -1 ;
    printf( "debug jParser: out after %p\n" , *out ) ;
    printf( "debug jParser: members before %p\n" , ( *out )->methods ) ;
    ( *out )->methods = &methods ;
    printf( "debug jParser: members after %p\n" , ( *out )->methods ) ;
    ( ( Parser* )*out )->current = ( Parser* )&start ;
    printf( "debug jParser: members after %p\n" , ( *out )->methods ) ;
    return 0 ;
}