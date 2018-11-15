#include <jagry/lbase.h>
#include <jagry/lmap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <byteMapNode.h>

#include <byteMap.h>

#define indent "   "

#define jStringify( argument ) #argument

extern JUnsignedInteger8 jagryDebugEraseByteMap ;

JResult emptyNull() {
JIMap map ;
JResult result ;
JBuffer key = jEmptyBuffer ;
printf( "test '" jStringify( eraseByteMapPointMapEmpty ) "' without return value: " ) ;
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
return jSuccesResult ;
}

JResult emptyValue() {
JIMap map ;
JResult result ;
JBuffer
	key = jEmptyBuffer ,
	value = jEmptyBuffer ;
printf( "test '" jStringify( eraseByteMapPointMapEmpty ) "' with return value: " ) ;
if( jResultIsError( result = jagryByteMap( &map ) ) )
	{
		printf( "jagryByteMap returned error " jResultSpecifier jNewLine "\t%s:" jSignedIntegerSpecifier jNewLine , result , __FILE__ , __LINE__ ) ;
		return -1 ;
	}
if( ( result = jEraseMap( map , key , &value ) ) != jMapValueNotFoundErrorResult )
	{
		printf( "jEraseMap returned " jResultSpecifier ", must be " jResultSpecifier jNewLine "\t%s:" jSignedIntegerSpecifier jNewLine ,
			result , jMapValueNotFoundErrorResult , __FILE__ , __LINE__ ) ;
		return -1 ;
	}
if( value.bytes != 0 || value.size != 0 )
	{
		printf(
			"value has changed to { bytes = " jPointerSpecifier ", size = " jSignedIntegerSpecifier "}" jNewLine "\t%s:" jSignedIntegerSpecifier jNewLine ,
			jagryDebugEraseByteMap ,
			eraseByteMapPointMapEmpty ,
			__FILE__ ,
			__LINE__ ) ;
		return -1 ;
	}
if( jagryDebugEraseByteMap != eraseByteMapPointMapEmpty )
	{
		printf(
			"jagryDebugEraseByteMap = " jUnsignedInteger8Specifier ", must be " jResultSpecifier jNewLine "\t%s:" jSignedIntegerSpecifier jNewLine ,
			jagryDebugEraseByteMap ,
			eraseByteMapPointMapEmpty ,
			__FILE__ ,
			__LINE__ ) ;
		return -1 ;
	}
printf( "done" jNewLine ) ;
return jSuccesResult ;
}