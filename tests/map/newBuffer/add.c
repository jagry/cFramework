#define indent "   "

#include <jagry/map.l>

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
		JUnsignedInteger1 counter0 = 0 ;
		counter0 < sizeof( iterations ) / sizeof( Iteration ) ;
		++counter0 )
	{
		PIteration iteration = iterations + counter0 ;
		printf(
			indent "Test '%s': key %s\n" , iteration->name , iteration->key.bytes ) ;
		result = jAddMapItem( map , &iteration->key , &iteration->value , 0 ) ;
		if( jResultIsError( result ) )
			return result ;
		for( JUnsignedInteger1 counter1 = 0 ; counter0 >= counter1 ; ++counter1 )
			{
				JIMapItem item ;
				iteration = iterations + counter1 ;
				printf( indent indent "Get %s - " , iteration->key.bytes ) ;
				result = jGetMapItem( map , &iteration->key , item ) ;
				showResult( result ) ;
			}
	}
return jSuccessResult ;
}