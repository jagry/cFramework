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