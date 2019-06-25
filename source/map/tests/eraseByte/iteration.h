// 0 define
#define initializeIterationDescription( pointArg , byteArg , nodeArg , textArg , itemsArg , keyArg ) { \
	.byte = byteArg , \
	.itemCount = sizeof( itemsArg ) / sizeof( *itemsArg ) , \
	.items = itemsArg , \
	.key = keyArg , \
	.node = nodeArg , \
	.point = pointArg , \
	.text = textArg }

// 0 typedef
typedef struct IterationDescription {
JPCCharacter1 text ;
JPPCharacter1 items ;
JSize itemCount ;
JBuffer key ;
JUnsignedInteger2 point ;
JUnsignedInteger1 byte ;
JUnsignedInteger1 node ;
} IterationDescription ;

// 1
#include "callback.h"

// 2
JResult iteration(
	IterationDescription testIn ,
	JPBuffer value ,
	PCallback callbackIn ,
	JResult resultIn ) ;