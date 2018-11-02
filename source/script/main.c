#include <stdio.h>
#include <string.h>
#include "parser.h"

int main(int argc, char** argv) {
    JParser* parser ;
    JParserStatus parserStatus ;
    JToken* token ;
    const char* text = "#int a = 0" ;
    jParser( &parser ) ;
    for( int counter = 0 ; counter < strlen( text ) ; ++counter )
        jExecuteParser( parser , text[ counter ] , parserStatus , token ) ;
    return 0 ;
}

