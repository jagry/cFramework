#include <jagry/buffer.i>
#include <stdio.h>

#define iteration( nameArg , stringArg , pointsArg ) { \
	.key = jStringBuffer( stringArg ) , \
	.name = nameArg , \
	.points = pointsArg , \
	.value = jStringBuffer( "@" stringArg "$" ) }

typedef JUnsignedInteger1 IterationPoints ;
typedef struct Iteration Iteration ;

typedef Iteration * PIteration ;

struct Iteration {
	JPCCharacter1 name ;
	JBuffer key ;
	JBuffer value ;
	IterationPoints points ; } ;