#include <jagry/lbase.h>
#include <jagry/lmap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <byteMapNode.h>

#include <byteMap.h>

#include "eraseByteMap.h"

JResult noValueNull() {
JIMap map ;
JResult result ;
JBuffer key = jEmptyBuffer ;
printf( "test '" stringify( eraseByteMapReturnEmpty ) "' without return value: " ) ;
if( jResultIsError( result = jagryByteMap( &map ) ) )
	{
		printf( factoryReturnedError , "jagryByteMap", result , __FILE__ , __LINE__ ) ;
		return -1 ;
	}
if( ( result = jEraseMap( map , key , 0 ) ) != jMapValueNotFoundErrorResult )
	{
		printf( eraseMapReturnedOther , result , jMapValueNotFoundErrorResult , __FILE__ , __LINE__ ) ;
		return -1 ;
	}
if( jagryDebugEraseByteMap != eraseByteMapReturnEmpty )
	{
		printf( debugMustBe , jagryDebugEraseByteMap , eraseByteMapReturnEmpty , __FILE__ , __LINE__ ) ;
		return -1 ;
	}
printf( "done" jNewLine ) ;
return jSuccesResult ;
}

JResult noValueValue() {
JIMap map ;
JResult result ;
JBuffer
	key = jEmptyBuffer ,
	value = jEmptyBuffer ;
printf( "test '" stringify( eraseByteMapPointEmpty ) "' with return value: " ) ;
if( jResultIsError( result = jagryByteMap( &map ) ) )
	{
		printf(factoryReturnedError , "jagryByteMap" , result , __FILE__ , __LINE__ ) ;
		return -1 ;
	}
if( ( result = jEraseMap( map , jEmptyBuffer , &value ) ) != jMapValueNotFoundErrorResult )
	{
		printf( eraseMapReturnedOther , result , jMapValueNotFoundErrorResult , __FILE__ , __LINE__ ) ;
		return -1 ;
	}
if( value.bytes != 0 || value.size != 0 )
	{
		printf(
			"value has changed to { bytes = " jPointerSpecifier ", size = " jSignedIntegerSpecifier "}" jNewLine "\t" jStringSpecifier ":" jSignedIntegerSpecifier jNewLine ,
			value.bytes ,
			value.size ,
			__FILE__ ,
			__LINE__ ) ;
		return -1 ;
	}
if( jagryDebugEraseByteMap != eraseByteMapReturnEmpty )
	{
		printf( debugMustBe , jagryDebugEraseByteMap , eraseByteMapReturnEmpty , __FILE__ , __LINE__ ) ;
		return -1 ;
	}
printf( "done" jNewLine ) ;
return jSuccesResult ;
}