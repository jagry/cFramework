//#ifndef JAGRY_PARSER
//#define JAGRY_PARSER

#define jExecuteParser( self , out ) ( ( self )->methods->execute( ( self ) , &( out ) ) )

#include "stream.h"
#include "token.h"

typedef struct JParser JParser ;
typedef struct JParserMethods JParserMethods ;
typedef struct JParserStatus JParserStatus ;
typedef struct JParserStatusMethods JParserStatusMethods ;

typedef JParser * JIParser ;
typedef JParserStatus * JIParserStatus ;
typedef JParserMethods * JPParserMethods ;
typedef JParserStatusMethods * JPParserStatusMethods ;

typedef JPParserMethods * JCPParserMethods ;

struct JParser {
	const JParserMethods * methods ;
	JInputStream * stream ;
} ;

struct JParserMethods {
	JIParserStatus( *execute )( const JParser* , JToken** ) ;
} ;

struct JParserStatus {
} ;

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
	const JParserMethods *methods ;
	JInputStream *stream ;
	LocalParser *current ;
} ;

struct StartParser {
	const JParserMethods* methods ;
} ;

//#endif