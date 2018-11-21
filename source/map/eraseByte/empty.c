#include <jagry/lbase.h>
#include <jagry/lmap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "!define.h"

#include <byteMapNode.h>

#include <byteMap.h>

JResult emptyNull() {
JIMap map ;
JResult result ;
JBuffer key = jEmptyBuffer ;
if( jResultIsError( result = jagryByteMap( &map ) ) )
	{
		printf( callReturnedError , "jagryByteMap", result , __FILE__ , __LINE__ ) ;
		return -1 ;
	}
if( ( result = jEraseMap( map , key , 0 ) ) != jMapValueNotFoundErrorResult )
	{
		printf( eraseMapReturnedOther , result , jMapValueNotFoundErrorResult , __FILE__ , __LINE__ ) ;
		jReleaseMap( map ) ;
		return -1 ;
	}
jReleaseMap( map ) ;
return 0 ;
}

JResult emptyValue() {
JIMap map ;
JResult result ;
JBuffer
	key = jEmptyBuffer ,
	value = jEmptyBuffer ;
if( jResultIsError( result = jagryByteMap( &map ) ) )
	{
		printf( callReturnedError , "jagryByteMap" , result , __FILE__ , __LINE__ ) ;
		return -1 ;
	}
if( ( result = jEraseMap( map , jEmptyBuffer , &value ) ) != jMapValueNotFoundErrorResult )
	{
		printf( eraseMapReturnedOther , result , jMapValueNotFoundErrorResult , __FILE__ , __LINE__ ) ;
		jReleaseMap( map ) ;
		return -1 ;
	}
jReleaseMap( map ) ;
if( value.bytes != 0 || value.size != 0 )
	{
		printf( valueHasChanged , value.bytes , value.size , __FILE__ , __LINE__ ) ;
		return -1 ;
	}
return 0 ;
}