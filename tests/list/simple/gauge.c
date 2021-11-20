#include <stdlib.h>
#include "gauge.h"

static JVoid gaugeFree( PGauge ) ;

JVoid gaugeFree( PGauge in ) {

}

JStatus gaugeRange(
	JUnsignedIntegerPointer countIn ,
	JUnsignedIntegerPointer startIn ,
	JUnsignedIntegerPointer stepIn ,
	PPGauge out ) {
if( !( *out = malloc( sizeof( Gauge ) ) ) )
	return jNotEnoughtMemoryErrorStatus ;
if( !( ( *out )->data = malloc( sizeof( GaugeItem ) * countIn ) ) )
	return free( *out ) , jNotEnoughtMemoryErrorStatus ;
for( JUnsignedInteger counter = 0 ; counter < countIn ; ++counter )
	( *out )->data[ counter ] = counter * stepIn + startIn ;
( *out )->free = gaugeFree ;
( *out )->size = countIn ;
return jSuccessStatus ;
}

JStatus gaugeStatic(
	JSize sizeIn , JPUnsignedIntegerPointer dataIn , PPGauge out ) {
if( !( *out = malloc( sizeof( Gauge ) ) ) )
	return jNotEnoughtMemoryErrorStatus ;
( *out )->data = dataIn ;
( *out )->size = sizeIn ;
return jSuccessStatus ;
}