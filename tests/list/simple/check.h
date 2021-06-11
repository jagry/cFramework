#include <jagry/array.i.h>
#include <jagry/test.h>
#include "gauge.h"

#define errorStatus ( jErrorStatusMask | 0x10000000 )
#define successStatus jSuccessStatus

JTestResult checkRange(
	JPTest ,
	JISimpleArray ,
	JUnsignedInteger ,
	JUnsignedInteger ,
	JUnsignedInteger ) ;
JTestResult checkStatic(
	JPTest , JISimpleArray , JSize , JPUnsignedIntegerPointer ) ;