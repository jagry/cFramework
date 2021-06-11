#define argument( argument ) \
	( JTestArgument ){ .deep = argument , .stack = testArg.stack }
#define clearCount 9

#include <jagry/test.h>
#include "check.h"
#include "return.h"

typedef union {
	JTestStatusData status ; } ClearTest ;

JStatus fill( JISimpleArray , JUnsignedIntegerPointer ) ;

JTestResult clear( JPTest testIn , JPISimpleArray arrayIn ) {
JPTestStack stack ; JStatus status ;
JTestResult result = jPushTest( testIn , sizeof( ClearTest ) , stack ) ;
jReturnTestIfError( stack , result )
status = fill( *arrayIn , clearCount ) ;
jReturnTestStatusIfError( stack , ClearTest , status , status )
result = checkRange( testIn , *arrayIn , clearCount , clearCount - 1 , -1 ) ;
jReturnTestIfError( stack , result )
jClearSimpleArray( *arrayIn ) ;
result = checkRange( testIn , *arrayIn , jZero , jZero , jZero ) ;
jReturnTestIfError( stack , result )
return jPopTest( testIn , stack ) ; ;
}