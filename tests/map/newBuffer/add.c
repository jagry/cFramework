#define indent "   "

#include <jagry/map.l.h>

#include <buffer.d.h>

#include "iteration.h"

void showResult( JResult in ) ;

JResult addTest( JVoid ) {
JIMap map ;
JIMapKey key ;
Iteration iterations[] = {
	iteration( "First node" , "0" , newBufferMapFirstNode ) } ;
JResult result = jagryGetMapKey( 0 , &key ) ;
if( jResultIsError( result ) )
	return result ;
if( jResultIsError( result = jagryMap( key , &map ) ) )
	return result ;
for(
		JUnsignedInteger1 counter = 0 ;
		counter < sizeof( iterations ) / sizeof( Iteration ) ;
		++counter )
	{
		PIteration iteration = iterations + counter ;
		printf(
			indent "Test '%s': key %s - " , iteration->name , iteration->key.bytes ) ;
		result = jAddMapItem( map , &iteration->key , &iteration->value , 0 ) ;
		showResult( result ) ;
	}
return jSuccessResult ;
}