// define
#define initializeIterationDescription( pointsArg , byteArg , nodeArg , textArg , itemsArg , keyArg ) { \
	.byte = byteArg , \
	.itemCount = sizeof( itemsArg ) / sizeof( *itemsArg ) , \
	.items = itemsArg , \
	.key = keyArg , \
	.node = nodeArg , \
	.points = pointsArg , \
	.text = textArg }

// 0 struct
typedef struct IterationDescription {
	JPCCharacter1 text ;
	JPPCharacter1 items ;
	JSize itemCount ;
	JBuffer key ;
	JUnsignedInteger2 points ;
	JUnsignedInteger1 byte ;
	JUnsignedInteger1 node ; } ;

// 0 typedef
typedef struct IterationDescription IterationDescription ;

// 1
#include "callback.h"

// 2
JResult iteration(
	IterationDescription testIn ,
	JPBuffer value ,
	PCallback callbackIn ,
	JResult resultIn ) ;