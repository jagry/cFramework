#include <jagry/map.i.h>
//#include <jagry/reader.i.h>
#include <stdlib.h>
#include "token.h"

//#include "builder.h"

#include "factory.h"

/* !!! */ #include <stdio.h>

typedef union KeywordFactoryBuffer KeywordFactoryBuffer ;

union KeywordFactoryBuffer {
	JBuffer buffer ;
	PKeywordFactory factory ; } ;
	
static JResult standartKeywordFactory( JByte in , PUToken out ) ;

JResult debugTestKeywordFactory( JPBuffer in , PUToken out ) {
return jSuccessResult ;
}

JResult declareVariableKeywordFactory( JPBuffer in , PUToken out ) {
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
return standartKeywordFactory( variableKeywordToken , out ) ;
}

JResult identifierFactory( JIMap mapIn , \
	JPBuffer bufferIn , PUToken out ) {
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
out->identifier.type = keywordTokenType ;
out->identifier.name = *bufferIn ;
*bufferIn = jEmptyBuffer ;
return jSuccessResult ;
}

JResult keywordFactory( JIMap mapIn , \
	JPBuffer bufferIn , PUToken out ) {
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
KeywordFactoryBuffer buffer = { .buffer = jEmptyBuffer } ;
JResult result = jGetMapValue( mapIn , *bufferIn , &buffer.buffer ) ;
if( jResultIsError( result ) )
	return result ;
result = ( *buffer.factory )( bufferIn , out ) ;
jagryClearBuffer( &buffer.buffer ) ;
return result ;
}

JResult standartKeywordFactory( JByte in , PUToken out ) {
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
out->keyword.type = keywordTokenType ;
out->keyword.identifier = in ;
return jSuccessResult ;
}