//#define indent "   "
//
//#include <jagry/map.l.h>
//
//#include <buffer.d.h>
//
//#include "iteration.h"
//
//void showResult( JResult in ) ;
//
//JResult newTest( void ) {
//JIBufferMap map ;
//Iteration iterations[] = {
//	iteration( "First node" , "0" , newBufferMapFirstNode ) } ;
//JMapManager  manager = {
//	.free = jagryMapManagerFree ,
//	.get = jagryMapManagerCopy ,
//	.set = jagryMapManagerCopy ,
//	.size = sizeof( JBuffer ) } ;
//JResult result = jagryBufferMap( &manager , &map ) ;
//for(
//		JUnsignedInteger1 counter = 0 ;
//		counter < sizeof( iterations ) / sizeof( Iteration ) ;
//		++counter )
//	{
//		PIteration iteration = iterations + counter ;
//		printf(
//			indent "Test '%s': key %s - " , iteration->name , iteration->key.bytes ) ;
//		result = jNewMapItem( map , &iteration->key , &iteration->value , 0 ) ;
//		showResult( result ) ;
//	}
//return jSuccessResult ;
//}