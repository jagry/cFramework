#include "data.h"
#include "implementation.h"
#include <jagry/test.h>

JTestResult check( JPTest testIn , Implementation implementationIn , Data dataIn ) {
JPTestStack stack ;
JTestResult result = jPushTest( testIn , jZero , stack ) ;
jReturnTestIfError( stack , result )
// !!! jReturnEmptyTestIf( stack , implementationIn.d->owned.t != dataIn.owned.t )
// !!! jReturnEmptyTestIf( stack , implementationIn.d->owner.t != dataIn.owner.t )
jReturnEmptyTestIf( stack , implementationIn.d->r != dataIn.references )
jReturnEmptyTestIf( stack , implementationIn.d->value != dataIn.value )
return jPopTest( testIn , stack ) ;
}