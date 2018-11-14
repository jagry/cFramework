#include <jagry/lbase.h>
#include <jagry/lmap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <byteMapNode.h>

#include <byteMap.h>

#define indent "   "

#define jStringify( argument ) #argument

JPCharacter1 addItems[] = { "AbbbCdddEfff" , "AbbbGhhh" , "AbbbCddd" } ;
JPCharacter1 eraseItems[] = { "AbbbGhhh" , "AbbbCddd" , "AbbbCdddEfff" } ;

extern JUnsignedInteger8 jagryDebugEraseByteMap ;

JResult main() {
JIMap map ;
JResult result ;
{ // eraseByteMapPointMapEmpty with return value
	JBuffer
		key = jEmptyBuffer ,
		value = jEmptyBuffer ;
	printf( "test '" jStringify( eraseByteMapPointMapEmpty ) "' with return value: " ) ;
	if( jResultIsError( result = jagryByteMap( &map ) ) )
		{
			printf( "jagryByteMap returned error " jResultSpecifier jNewLine "\terror: %s:" jSignedIntegerSpecifier jNewLine , result , __FILE__ , __LINE__ ) ;
			return -1 ;
		}
	if( ( result = jEraseMap( map , key , 0 ) ) != jMapValueNotFoundErrorResult )
		{
			printf( "jEraseMap returned " jResultSpecifier ", must be " jResultSpecifier jNewLine "\terror: %s:" jSignedIntegerSpecifier jNewLine ,
				result , jMapValueNotFoundErrorResult , __FILE__ , __LINE__ ) ;
			return -1 ;
		}
	if( jagryDebugEraseByteMap != eraseByteMapPointMapEmpty )
		{
			printf( "jagryDebugEraseByteMap = " jUnsignedInteger8Specifier ", must be " jResultSpecifier jNewLine "\terror: %s:" jSignedIntegerSpecifier jNewLine ,
				jagryDebugEraseByteMap , eraseByteMapPointMapEmpty , __FILE__ , __LINE__ ) ;
			return -1 ;
		}
	printf( "done" jNewLine ) ;
}
{ // eraseByteMapPointMapEmpty without return value
	JBuffer key = jEmptyBuffer ;
	printf( "test '" jStringify( eraseByteMapPointMapEmpty ) "' with return value: " ) ;
	if( jResultIsError( result = jagryByteMap( &map ) ) )
		{
			printf( "jagryByteMap returned error " jResultSpecifier jNewLine "\terror: %s:" jSignedIntegerSpecifier jNewLine , result , __FILE__ , __LINE__ ) ;
			return -1 ;
		}
	if( ( result = jEraseMap( map , key , 0 ) ) != jMapValueNotFoundErrorResult )
		{
			printf( "jEraseMap returned " jResultSpecifier ", must be " jResultSpecifier jNewLine "\terror: %s:" jSignedIntegerSpecifier jNewLine ,
				result , jMapValueNotFoundErrorResult , __FILE__ , __LINE__ ) ;
			return -1 ;
		}
	if( jagryDebugEraseByteMap != eraseByteMapPointMapEmpty )
		{
			printf( "jagryDebugEraseByteMap = " jUnsignedInteger8Specifier ", must be " jResultSpecifier jNewLine "\terror: %s:" jSignedIntegerSpecifier jNewLine ,
				jagryDebugEraseByteMap , eraseByteMapPointMapEmpty , __FILE__ , __LINE__ ) ;
			return -1 ;
		}
	printf( "done" jNewLine ) ;
}
return 0 ;
}