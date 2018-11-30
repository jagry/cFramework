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
#include "eraseByteMap.h"

#include <byteMapNode.h>

#include <byteMap.h>

typedef struct test {
JPCCharacter1 text ;
JPPCharacter1 items ;
JSize itemCount ;
JBuffer key ;
JResult result ;
JUnsignedInteger8 byte ;
JUnsignedInteger8 node ;
JUnsignedInteger1 exit ;
} test ;

static JPCharacter1 noValueItemsB[] = { "001" , "002" } ;
static JPCharacter1 noValueItemsBN[] = { "0012" , "0013" , "004" } ;
static JPCharacter1 noValueItemsN[] = { "01" , "02" , "3" } ;
static JPCharacter1 noValueItemsNB[] = { "0112" , "0113" , "4" } ;
static JPCharacter1 endInItems[] = { "00" } ;
static JPCharacter1 endInItemsB[] = { "00" } ;
static JPCharacter1 endInItemsBN[] = { "00122" , "003" } ;
static JPCharacter1 endInItemsN[] = { "011" , "2" } ;
static JPCharacter1 endInItemsNB[] = { "011" , "2" } ;
static JPCharacter1 missingChildItems[] = { "0" , "1" } ;

static JUnsignedInteger1 debug = 0 ;
static const test tests[] = {
	initializeTest( eraseByteMapEmpty , 0 , 0 , "empty node" , ( JAPCharacter1 ){} , jEmptyBuffer , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapMissingChild , 0 , 0 , "missing child root(no byte)" , missingChildItems , jStringBuffer( "2" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapEndIn , 0 , 0 , "end argument buffer root node(no byte)" , endInItems , jStringBuffer( "" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapEndIn , 1 , 0 , "end argument buffer root node(byte)" , endInItemsB , jStringBuffer( "0" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapEndIn , 0 , 1 , "end argument buffer sub node(no byte)" , endInItemsN , jStringBuffer( "0" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapEndIn , 2 , 1 , "end argument buffer sub node(root byte)" , endInItemsBN , jStringBuffer( "001" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapEndIn , 1 , 1 , "end argument buffer sub node(sub byte)" , endInItemsNB , jStringBuffer( "01" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapNoValue , 0 , 0 , "no value root node(no byte)" , ( ( JAPCharacter1 ){ "011" , "233" } ) , jStringBuffer( "" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapNoValue , 2 , 0 , "no value root node(byte)" , noValueItemsB , jStringBuffer( "00" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapNoValue , 0 , 1 , "no value sub node(no byte)" , noValueItemsN , jStringBuffer( "0" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapNoValue , 2 , 1 , "no value sub node(root byte)" , noValueItemsBN , jStringBuffer( "001" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapNoValue , 2 , 1 , "no value sub node(sub byte)" , noValueItemsNB , jStringBuffer( "011" ) , jMapValueNotFoundErrorResult ) } ;



static JResult call( test testIn , JPBuffer value) {
JIMap map ;
JResult result ;
// start debug
JPCharacter1 inChar = testIn.key.bytes ;
// finish debug
jagryDebugEraseByteMap = ( JDebugEraseByteMap ){ .byte = 0 , .node =0 , .exit = 0 } ;
if( jResultIsError( result = jagryByteMap( &map ) ) )
	{
		printf( callReturnedError , "jagryByteMap", result , __FILE__ , __LINE__ ) ;
		return result ;
	}
for( JSignedInteger counter = 0 ; counter < testIn.itemCount ; ++counter )
	if( ( result = jAddMap( map , jStringBuffer( testIn.items[ counter ] ) , jStringBuffer( testIn.items[ counter ] ) , 0 ) ) != jSuccesResult )
		{
			printf( callReturnedError , "jAddMap" , result , __FILE__ , __LINE__ ) ;
			return result ;
		}
result = jEraseMap( map , testIn.key , value ) ;
jReleaseMap( map ) ;
if( ( result ) == testIn.result )
	if( jagryDebugEraseByteMap.exit == testIn.exit )
		if( jagryDebugEraseByteMap.byte == testIn.byte )
			if( jagryDebugEraseByteMap.node == testIn.node )
				{
					debug |= jagryDebugEraseByteMap.exit ;
					return 0 ;
				}
			else
				printf( pointValueMustBe , __FILE__ , __LINE__ , "node" , jagryDebugEraseByteMap.node , testIn.node ) ;
		else
			printf( pointValueMustBe , __FILE__ , __LINE__ , "byte" , jagryDebugEraseByteMap.byte , testIn.byte ) ;
	else
		printf( returnPointMustBe , __FILE__ , __LINE__ , jagryDebugEraseByteMap.exit , testIn.exit ) ;
else
	printf( eraseMapReturnedOther , __FILE__ , __LINE__ , result , testIn.result ) ;
return -1 ;
}

static JResult callNull( test testIn ) {
return call( testIn , 0 ) ;
}

static JResult callValue( test testIn , JPCBuffer bufferIn ) {
JBuffer buffer = jBuffer( 0 , 0 ) ;
JResult result = call( testIn , &buffer ) ;
if( result == 0 )
	{
		// !!! Сравнить buffer and bufferIn
	}
jagryClearBuffer( &buffer ) ;
return result ;
}

JResult main() {
JResult result ;
JCounter errors = 0 ;
printf( "start test 'eraseByteMap'" jNewLine ) ;
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
printf( "finish test 'eraseByteMap' " ) ;
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