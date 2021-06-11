#include "stack.h"

#define returnStatus( argument ) \
	jTestReturnStatus( self , argument )
#define returnStatusIf( condition , result ) \
	jTestReturnStatusIf( condition , stack , testArg , result )
#define returnTestResult( argument ) \
	jTestReturn( stack , testArg , argument )
#define returnTestResultIf( condition , result ) \
	jTestReturnIf( condition , stack , testArg , result )