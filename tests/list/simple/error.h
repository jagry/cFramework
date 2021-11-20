#define showError( test , method ) \
	( test )->internalMainStack.position.line = __LINE__ , \
	jagryOutTest( test , method , __FILE__ , __LINE__ )

#include <jagry/test.h>
#include "stack.h"

JVoid statusError( JPVoid ) ;

void jagryOutTest(
	JPTest , JPCTestResult , JPCCharacter1 , JUnsignedInteger ) ;