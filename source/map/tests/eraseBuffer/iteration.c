// 0 define
#define _POSIX_C_SOURCE 199309L

// 0 include
#include <jagry/lbase.h>
#include <jagry/lmap.h>
#include <stdio.h>
#include "time.h"
#include "../message.h"

// 1
#include <time.h>
#include "../../byteMapNode.h"

// 2
#include "../../byteMap.h"

// 3
#include "iteration.h"

// 4
JResult iteration( IterationDescription testIn , JPBuffer value , PCallback callbackIn , JResult resultIn ) {
struct timespec time ;
JIMap map ;
JResult result ;
jagryDebugEraseByteMap = ( DebugEraseByteMap ){ .byte = 0 , .points = 0 , .node = 0 } ;
clock_gettime( CLOCK_REALTIME , &time ) ;
if( jResultIsError( result = jagryCreateByteMap( &map ) ) )
	return printf( callReturnedErrorMessage , "jagryCreateByteMap", result , __FILE__ , __LINE__ ) , result ;
for( JSignedInteger counter = 0 ; counter < testIn.itemCount ; ++counter )
	{
		JBuffer buffer = jStringBuffer( testIn.items[ counter ] ) ;
		result = jMapAddItem( map , buffer , buffer , 0 ) ;
		if( result != jSuccessMapResult )
			return printf( callReturnedErrorMessage , "jAddMap" , result , __FILE__ , __LINE__ ) , result ;
	}
result = jMapEraseItem( map , testIn.key ) ;
jMapRelease( map ) ;
if( result != resultIn )
	return printf( eraseMapReturnedOtherMessage , __FILE__ , __LINE__ , result , resultIn ) , -1 ;
if( jagryDebugEraseByteMap.points != testIn.points )
	return
		printf( returnPointMustBeMessage , __FILE__ , __LINE__ , jagryDebugEraseByteMap.points , testIn.points ) ,
		-1 ;
if( jagryDebugEraseByteMap.byte != testIn.byte )
	return
		printf(
			pointValueMustBeMessage ,
			__FILE__ ,
			__LINE__ ,
			"byte" ,
			jagryDebugEraseByteMap.byte ,
			testIn.byte ) ,
		-1 ;
if( jagryDebugEraseByteMap.node != testIn.node )
	return
		printf(
			pointValueMustBeMessage ,
			__FILE__ ,
			__LINE__ ,
			"node" ,
			jagryDebugEraseByteMap.node ,
			testIn.node ) ,
		-1 ;
time = GetDuration( &time ) ;
printf( "%li.%09li" jNewLine , time.tv_sec , time.tv_nsec ) ;
return 0 ;
}