#include "buffer.h"
#include "parser.h"

#include "is.h"

int getIdentifier( Parser const* parser , const char character , JBufferS* out ) {
    /*for( ; ; ) {
        int result = readCharacter( parser , stream ) ;
        if( result < 0 )
            return result ;
        if( !isDigit( parser->character ) && !isLetter( parser->character ) && parser->character != LOW_LINE_CHARACTER )
            return 0 ;
        if( ( result = AddBufferCharacter( out , parser->character ) ) < 0 )
            return result ;
    }*/
    return 0 ;
}
