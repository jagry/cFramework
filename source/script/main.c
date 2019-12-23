#include <jagry/map.l.h>
#include <jagry/base.i.h>
#include <jagry/buffer.h>
#include <stdio.h>
#include <string.h>
#include "result.h"
#include "token.h"

#include "parser.h"

int main(int argc, char** argv) {
IParser consoleParser ;
IBaseToken token ;
JIReader reader ;
JResult result ;
char* text = " $var b = 0" ;
JDMap map ;
printf( "DEBUG %s(%i) %x\n" , __PRETTY_FUNCTION__ , __LINE__ , unexpectedCharacterParserErrorResult ) ;
if( jResultIsError( result = jagryBufferInstanceReader( &( JBuffer ){ .bytes = text , .size = 10 } , &reader ) ) )
	return -1 ;
if( jResultIsNotError( result = jagryInitializeByteMap( &map ) ) )
	
result = parser( reader , &consoleParser ) ;
jReleaseReader( reader ) ;
if( jResultIsNotError( result ) )
	// for( ; ; )
		{
			if( jResultIsError( result = jExecuteParser( consoleParser , token ) ) )
				if( result != jEndReaderErrorResult )
					return jFreeParser( consoleParser ) , -2 ;
		}
jFreeParser( consoleParser ) ;
return 0 ;
}