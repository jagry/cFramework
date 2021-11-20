#include <jagry/list.l.h>
#include <jagry/test.h>

typedef union {
	JTestStatusData status ; } PushTest;

JTestResult push(JPTest testIn, JPISimpleArray arrayIn) {
JPTestStack stack ; JStatus status ;
JTestResult result = jPushTest( testIn , sizeof( PushTest ) , stack ) ;
jReturnTestIfError(stack, result)
return jPopTest(testIn, stack); ;
}