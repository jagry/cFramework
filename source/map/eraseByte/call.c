#include <jagry/lbase.h>
#include <jagry/lmap.h>
#include <stdio.h>
#include "@.h"

#include <byteMapNode.h>
#include "call.h"

#include <byteMap.h>

extern JUnsignedInteger1 mainDebug ;

static JResult call( callTest testIn , JPBuffer value) {
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
					mainDebug |= jagryDebugEraseByteMap.exit ;
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

JResult callNull( callTest testIn ) {
return call( testIn , 0 ) ;
}

JResult callValue( callTest testIn , JPCBuffer bufferIn ) {
JBuffer buffer = jBuffer( 0 , 0 ) ;
JResult result = call( testIn , &buffer ) ;
if( result == 0 )
	{
		// !!! Сравнить buffer and bufferIn
	}
jagryClearBuffer( &buffer ) ;
return result ;
}

//#include <jagry/lbase.h>
//#include <jagry/lmap.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "#.h"
//
//#include <byteMapNode.h>
//
//#include <byteMap.h>
//
//JResult emptyNull( JPCharacter1 items[] , JSignedInteger count, JPCBuffer key , JPBuffer value ) {
//JIMap map ;
//JResult result ;
//JBuffer key = jEmptyBuffer ;
//if( jResultIsError( result = jagryByteMap( &map ) ) )
//	{
//		printf( callReturnedError , "jagryByteMap", result , __FILE__ , __LINE__ ) ;
//		return -1 ;
//	}
//if( ( result = jEraseMap( map , key , 0 ) ) != jMapValueNotFoundErrorResult )
//	{
//		printf( eraseMapReturnedOther , __FILE__ , __LINE__ , result , jMapValueNotFoundErrorResult ) ;
//		jReleaseMap( map ) ;
//		return -1 ;
//	}
//jReleaseMap( map ) ;
//return 0 ;
//}