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
//#include <jagry/buffer.h>
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

static JPCharacter1 noValueRootNodeItemsB[] = { "001" , "002" } ;

static JUnsignedInteger1 debug = 0 ;
static const test tests[] = {
	initializeTest( eraseByteMapPointReturnEmpty , 0 , 0 , "empty node" , ( JAPCharacter1 ){} , jEmptyBuffer , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapPointReturnNoValue , 0 , 0 , "no value root node(no byte)" , ( ( JAPCharacter1 ){ "011" , "100" } ) , jStringBuffer( "" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapPointReturnNoValue , 2 , 0 , "no value root node(has byte)" , noValueRootNodeItemsB , jStringBuffer( "00" ) , jMapValueNotFoundErrorResult ) ,
	initializeTest( eraseByteMapPointReturnNoValue , 0 , 0 , "no value sub node(no byte)" , noValueRootNodeItemsB , jStringBuffer( "011" ) , jMapValueNotFoundErrorResult ) /*,
	initializeTest( eraseByteMapPointReturnNoValue , 0 , 0 , noValueNull ) ,
	initializeTest( eraseByteMapPointReturnNoValue , 0 , 0 , noValueValue ) ,
	initializeTest( eraseByteMapPointReturnNoValue , 2 , 1 , noValueBNull ) ,
	initializeTest( eraseByteMapPointReturnNoValue , 2 , 1 , noValueBValue ) ,
	initializeTest( eraseByteMapPointReturnNoValue , 0 , 0 , noValueBNNull ) ,
	initializeTest( eraseByteMapPointReturnNoValue , 0 , 0 , noValueBNValue ) ,
	initializeTest( eraseByteMapPointReturnNoValue , 0 , 0 , noValueNNull ) ,
	initializeTest( eraseByteMapPointReturnNoValue , 0 , 0 , noValueNValue ) ,
	initializeTest( eraseByteMapPointReturnNoValue , 0 , 0 , noValueNBNull ) ,
	initializeTest( eraseByteMapPointReturnNoValue , 0 , 0 , noValueNBValue )*/ } ;



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