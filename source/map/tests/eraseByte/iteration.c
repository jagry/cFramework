#define _POSIX_C_SOURCE 199309L

#include <jagry/lbase.h>
#include <jagry/lmap.h>
#include <stdio.h>
#include <time.h>
#include "message.h"
#include "time.h"

#include <byteMapNode.h>
#include "iteration.h"

#include <byteMap.d.h>

extern JUnsignedInteger1 mainDebug ;

JResult iteration( IterationDescription testIn , JPBuffer value , PCallback callbackIn , JResult resultIn ) {
struct timespec time ;
JIMap map ;
JResult result ;
jagryDebugEraseByteMap = ( DebugEraseByteMap ){ .byte = 0 , .point = 0 , .node = 0 } ;
clock_gettime( CLOCK_REALTIME , &time ) ;
if( jResultIsError( result = jagryByteMap( &map ) ) )
	return printf( callReturnedErrorMessage , "jagryByteMap", result , __FILE__ , __LINE__ ) , result ;
for( JSignedInteger counter = 0 ; counter < testIn.itemCount ; ++counter )
	if( ( result = jAddMap( map , jStringBuffer( testIn.items[ counter ] ) , jStringBuffer( testIn.items[ counter ] ) , 0 ) ) != jMapSuccessResult )
		return printf( callReturnedErrorMessage , "jAddMap" , result , __FILE__ , __LINE__ ) , result ;
result = jEraseMap( map , testIn.key , value ) ;
jReleaseMap( map ) ;
if( result != resultIn )
	return printf( eraseMapReturnedOtherMessage , __FILE__ , __LINE__ , result , resultIn ) , -1 ;
if( jagryDebugEraseByteMap.point != testIn.point )
	return printf( returnPointMustBeMessage , __FILE__ , __LINE__ , jagryDebugEraseByteMap.point , testIn.point ) , -1 ;
if( jagryDebugEraseByteMap.byte != testIn.byte )
	return printf( pointValueMustBeMessage , __FILE__ , __LINE__ , "byte" , jagryDebugEraseByteMap.byte , testIn.byte ) , -1 ;
if( jagryDebugEraseByteMap.node != testIn.node )
	return printf( pointValueMustBeMessage , __FILE__ , __LINE__ , "node" , jagryDebugEraseByteMap.node , testIn.node ) , -1 ;
time = GetDuration( &time ) ;
printf( "%li.%09li" jNewLine , time.tv_sec , time.tv_nsec ) ;
return 0 ;
}