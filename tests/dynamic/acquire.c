#include "implementation.h"
#include <jagry/dynamic.l.h>
#include <jagry/test.h>

JTestResult acquire( JPTest testIn , Implementation argumentIn ) {
JPTestStack stack ;
JTestResult result = jPushTest( testIn , jZero, stack ) ;
jReturnTestIfError( stack , result )
/* !!! JCMDynamic methods = {jagryAcquireDynamic , jNil , jNil};
JDynamic dynamic = { .d = &( JDDynamic ){ .b = jNil , .m = &methods , .r = 1 } } ;
jReturnEmptyTestIf(stack, dynamic.d == jNil)
jReturnEmptyTestIf( stack , dynamic.d->b.t != jNil )
jReturnEmptyTestIf( stack , dynamic.d->m != &methods )
jReturnEmptyTestIf( stack , dynamic.d->r != 1 )
jReturnEmptyTestIf( stack , dynamic.d != dynamic.i.t )
jAcquireBase( dynamic.i ) ; jReturnEmptyTestIf( stack , dynamic.d->r != 2 )
jAcquireBase( dynamic.i ) ; jReturnEmptyTestIf( stack , dynamic.d->r != 3 )
jAcquireBase( dynamic.i ) ; jReturnEmptyTestIf( stack , dynamic.d->r != 4 ) */
return jPopTest( testIn , stack ) ;
}

JTestResult acquireBase( JPTest testIn , JPVoid argumentIn ) {
JPTestStack stack ;
JTestResult result = jPushTest( testIn , jZero, stack ) ;
jReturnTestIfError( stack , result )
/* !!! JCMDynamic methods = {jagryAcquireDynamicBase , jNil , jNil};
JDynamic dynamic = { .d = &( JDDynamic ){ .b = jNil , .m = &methods , .r = 1 } } ;
jReturnEmptyTestIf( stack , dynamic.d == jNil )
jReturnEmptyTestIf( stack , dynamic.i.t == jNil )
jReturnEmptyTestIf( stack , dynamic.d->m == jNil  )
jReturnEmptyTestIf( stack , dynamic.d->b.t != jNil )
jReturnEmptyTestIf( stack , dynamic.d->r != 1 )
jAcquireBase( dynamic.i ) ; jReturnEmptyTestIf( stack , dynamic.d->r != 2 )
jAcquireBase( dynamic.i ) ; jReturnEmptyTestIf( stack , dynamic.d->r != 3 )
jAcquireBase( dynamic.i ) ; jReturnEmptyTestIf( stack , dynamic.d->r != 4 ) */
return jPopTest( testIn , stack ) ;
}