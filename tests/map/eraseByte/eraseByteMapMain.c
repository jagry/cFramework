#include <jagry/lbase.h>
#include <jagry/lmap.h>
#include <jagry/buffer.h>

#include <byteMapNode.h>

#include <byteMap.h>

#include "eraseByteMap.h"

typedef  JResult sss() ;

JResult emptyNull() ;
JResult emptyValue() ;

JResult main() {
JResult error ;
JResult result = 0 ;
const struct {
	JResult( *function )() ;
	JUnsignedInteger8 debug ;
} tests = {
	{ .function = emptyNull , .debug = eraseByteMapReturnEmpty } ,
	{ .function = emptyValue , .debug = eraseByteMapReturnEmpty } ,
	{ .function = noValueNull , .debug = eraseByteMapReturnNoValue } } ;
for( JSignedInteger1 counter = 0 ; ( sizeof( tests ) / sizeof( *tests ) ) > counter ; ++counter )
	{
		error = tests[ counter ].function() ;
		if( jagryDebugEraseByteMap != tests[ counter ].debug )
			printf( debugMustBe , jagryDebugEraseByteMap , eraseByteMapReturnEmpty , __FILE__ , __LINE__ ) ,
			result = -1 ;
		else
			printf( "done" jNewLine ) ;
	}
return result ;
}