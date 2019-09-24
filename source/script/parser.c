#include <stdio.h>
#include <stdlib.h>
#include "keyword.h"
#include "parser.h"

#include "blank.h"
#include "is.h"

static JIParserStatus ExecuteParser( const JParser* self , JToken** token ) {
return ( ( Parser* )self )->current->methods->execute( self , token ) ;
}

static JIParserStatus ExecuteStartParser( const JParser* parser , JToken** token ) {
return 0 ;
}

static const JParserMethods methods = {
	.execute = ExecuteParser } ;
static const JParserMethods startMethods = { .execute = ExecuteStartParser } ;
static const StartParser start = { .methods = &startMethods } ;

int jParser( JParser** out ) {
printf( "debug jParser: out before %p\n" , *out ) ;
if( ( *out = malloc( sizeof( JParser ) ) ) == 0 )
		return -1 ;
printf( "debug jParser: out after %p\n" , *out ) ;
printf( "debug jParser: members before %p\n" , ( *out )->methods ) ;
( *out )->methods = &methods ;
printf( "debug jParser: members after %p\n" , ( *out )->methods ) ;
( ( Parser* )*out )->current = ( LocalParser* )&start ;
printf( "debug jParser: members after %p\n" , ( *out )->methods ) ;
return 0 ;
}