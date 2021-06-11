#include "check.h"

JStatus fill( JISimpleArray instanceIn , JUnsignedIntegerPointer countIn ) {
JStatus status ;
for( JUnsignedIntegerPointer counter = jZero ; countIn > counter ; ++counter )
	if( jStatusIsError( status =
			jPushSimpleArrayForward( instanceIn , ( JPVoid )counter , jNil ) ) )
		return status ;
return jSuccessStatus ;
}