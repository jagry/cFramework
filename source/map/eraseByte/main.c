#define initializeTest( exitArg , byteArg , nodeArg , textArg , itemsArg , keyArg , resultArg ) { \
	.byte = byteArg , \
	.exit = exitArg , \
	.itemCount = sizeof( itemsArg ) / sizeof( *itemsArg ) , \
	.items = itemsArg , \
	.key = keyArg , \
	.node = nodeArg , \
	.result = resultArg , \
	.text = textArg }

#include <jagry/lbase.h>
#include <jagry/lmap.h>
#include <stdio.h>
#include <stdio.h>
#include "@.h"

#include <byteMapNode.h>
#include "call.h"

#include <byteMap.h>

JUnsignedInteger1 mainDebug = 0 ;
static JPCharacter1
	endInItems[] = { "00" } ,
	endInItemsB[] = { "00" } ,
	endInItemsBN[] = { "00122" , "003" } ,
	endInItemsN[] = { "011" , "2" } ,
	endInItemsNB[] = { "011" , "2" } ,
	missingChildItems[] = { "0" , "1" } ,
	missingChildItemsB[] = { "001" , "002" } ,
	missingChildItemsBN[] = { "0012" , "0013" , "004"} ,
	missingChildItemsN[] = { "01" , "02" , "3"} ,
	missingChildItemsNB[] = { "0112" , "0113" , "4" } ,
	noValueItemsB[] = { "001" , "002" } ,
	noValueItemsBN[] = { "0012" , "0013" , "004" } ,
	noValueItemsN[] = { "01" , "02" , "3" } ,
	noValueItemsNB[] = { "0112" , "0113" , "4" } ;

static const callTest tests[] = {
	initializeTest( eraseByteMapEmpty , 0 , 0 , "empty node" , ( JAPCharacter1 ){} , jEmptyBuffer , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapEndIn , 0 , 0 , "end argument buffer root node(no byte)" , endInItems , jStringBuffer( "" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapEndIn , 1 , 0 , "end argument buffer root node(byte)" , endInItemsB , jStringBuffer( "0" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapEndIn , 0 , 1 , "end argument buffer sub node(no byte)" , endInItemsN , jStringBuffer( "0" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapEndIn , 2 , 1 , "end argument buffer sub node(root byte)" , endInItemsBN , jStringBuffer( "001" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapEndIn , 1 , 1 , "end argument buffer sub node(sub byte)" , endInItemsNB , jStringBuffer( "01" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapMissingChild , 0 , 0 , "missing child root(no byte)" , missingChildItems , jStringBuffer( "2" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapMissingChild , 2 , 0 , "missing child root(byte)" , missingChildItemsB , jStringBuffer( "003" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapMissingChild , 0 , 1 , "missing child sub(no byte)" , missingChildItemsN , jStringBuffer( "03" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapMissingChild , 2 , 1 , "missing child sub(root byte)" , missingChildItemsBN , jStringBuffer( "0014" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapMissingChild , 2 , 1 , "missing child sub(sub byte)" , missingChildItemsNB , jStringBuffer( "0114" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapNotEqual , 0 , 0 , "not equal root node(no byte)" , ( ( JAPCharacter1 ){ "00" } ) , jStringBuffer( "1" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapNotEqual , 1 , 0 , "not equal root node(no byte)" , ( ( JAPCharacter1 ){ "00" } ) , jStringBuffer( "01" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapNotEqual , 0 , 1 , "not equal sub node(no byte)" , ( ( JAPCharacter1 ){ "011" , "2"} ) , jStringBuffer( "02" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapNotEqual , 2 , 1 , "not equal sub node(root byte)" , ( ( JAPCharacter1 ){ "00122" , "002"} ) , jStringBuffer( "0013" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapNotEqual , 1 , 1 , "not equal sub node(sub byte)" , ( ( JAPCharacter1 ){ "011" , "2"} ) , jStringBuffer( "012" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapNoValue , 0 , 0 , "no value root node(no byte)" , ( ( JAPCharacter1 ){ "011" , "233" } ) , jStringBuffer( "" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapNoValue , 2 , 0 , "no value root node(byte)" , noValueItemsB , jStringBuffer( "00" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapNoValue , 0 , 1 , "no value sub node(no byte)" , noValueItemsN , jStringBuffer( "0" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapNoValue , 2 , 1 , "no value sub node(root byte)" , noValueItemsBN , jStringBuffer( "001" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapNoValue , 2 , 1 , "no value sub node(sub byte)" , noValueItemsNB , jStringBuffer( "011" ) , jMapValueNotFoundErrorResult ) } ;

JResult callNull( callTest ) ;
JResult callValue( callTest , JPCBuffer ) ;

JResult main() {
JResult result ;
JCounter errors = 0 ;
printf( "> start test 'eraseByteMap'" jNewLine ) ;
for( JSignedInteger1 counter = 0 ; ( sizeof( tests ) / sizeof( *tests ) ) > counter ; ++counter )
	{
		JBuffer value = jBuffer( 0 , 0 ) ;
		printf( space "call " jStringSpecifier " with value: " , tests[ counter ].text ) ;
		if( ( result = callNull( tests[ counter ] ) ) )
			++errors ;
		else
			printf( "done" jNewLine ) ;
		printf( space "call " jStringSpecifier " without value: " , tests[ counter ].text ) ;
		if( ( result = callValue( tests[ counter ] , 0 ) ) )
			++errors ;
		else
			printf( "done" jNewLine ) ;
	}
printf( "< finish test 'eraseByteMap' " ) ;
if( errors == 0 )
	{
		printf( "succesfully" jNewLine ) ;
		return 0 ;
	}
if( errors == 1 )
	printf( "with error" jNewLine ) ;
else
	printf( "with errors(" jCounterSpecifier ")" jNewLine , errors ) ;
return -1 ;
}