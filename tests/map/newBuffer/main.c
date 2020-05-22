#include <jagry/map.l>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "iteration.h"
#include "../message.h"

JResult addTest( void ) ;
JResult newTest( void ) ;
JResult putTest( void ) ;
JResult setTest( void ) ;

#define mainIteration( nameArg , stringArg , pointsArg ) { \
	.key = jStringBuffer( stringArg ) , \
	.name = nameArg , \
	.points = pointsArg , \
	.value = jStringBuffer( "@" stringArg "$" ) }

typedef struct MainIteration MainIteration ;

struct MainIteration {
	JResult( *method )( void ) ;
	JPCCharacter1 name ; } ;

JResult main() {
MainIteration iterations[] = {
	{ .method = addTest , .name = "addBufferMapItem" } /*,
	{ .method = newTest , .name = "newBufferMapItem" } ,
	{ .method = putTest , .name = "putBufferMapItem" } ,
	{ .method = setTest , .name = "setBufferMapItem" } */ } ;
for(
		JUnsignedInteger1 counter = 0 ;
		counter < sizeof( iterations ) / sizeof( MainIteration ) ;
		++counter )
	{
		printf( "Test '%s'\n" , iterations[ counter ].name ) ;
		iterations[ counter ].method( ) ;
	}
return 0 ;
}