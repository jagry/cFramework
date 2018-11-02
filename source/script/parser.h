//#ifndef JAGRY_PARSER
//#define JAGRY_PARSER

#define jExecuteParser( self , stream , status , token ) ( ( self )->methods->execute( ( self ) , ( stream ) , &( status ) , &( token ) ) )

#include "stream.h"
#include "token.h"

typedef struct JParser JParser ;
typedef struct JParserMethods JParserMethods ;
typedef enum JParserStatus JParserStatus ;

struct JParser {
    const JParserMethods* methods ;
} ;

struct JParserMethods {
    int( *execute )( const JParser* , const jIInputStream* , JParserStatus* , JToken** ) ;
} ;

enum JParserStatus {
    jNextParserStatus ,
    jRepeatParserStatus ,
    jTokenParserStatus ,
    jTopParserStatus } ;

int jParser( JParser** ) ;

//

typedef struct LocalParser LocalParser ;
typedef struct Parser Parser ;
typedef struct StartParser StartParser ;

struct LocalParser {
    JParserMethods* methods ;
    Parser* stack ;
} ;

/*struct LocalParserMethods {
    int( *execute )( const Parser* , const char , JParserStatus* , JToken** ) ;
} ;*/

struct Parser {
    JParserMethods* methods ;
    Parser* current ;
} ;

struct StartParser {
    const JParserMethods* methods ;
} ;

//#endif