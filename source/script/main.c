#include <jagry/buffer.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"

int main(int argc, char** argv) {
	JParser* parser ;
	JParserStatus parserStatus ;
	JToken* token ;
	char* text = "$int a = 0" ;
	jParser( &parser ) ;
	JInputStream * stream ;
	jagryBufferInputStream( &( JBuffer ){ .bytes = text , .size = 10 } , &stream  ) ;
	for( ; ; )
		{
			jExecuteParser( parser , token ) ;
		}
	return 0 ;
}

