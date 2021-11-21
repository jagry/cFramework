#include "implementation.h"
#include <jagry/test.h>

typedef union { JTestNotEnoudhMemoryData _ ; } CreateStack ;

JTestResult create( JPTest in , PImplementation out ) {
JPTestStack stack ;
JTestResult result = jPushTest( in , sizeof( CreateStack ) , stack ) ;
jReturnTestIfError( stack , result )
if( !( out->d = malloc( sizeof( *out->d ) ) ) ) jReturnTestNotEnoughMemory( stack , CreateStack , _ , sizeof( *out->d ) )
out->d->b.t = jNil ; // !!! &( *out )->m ;
out->d->m = &ownerImplementationMethods ;
out->d->owned.t = jNil ;
out->d->r = 1 ;
out->d->value = jZero ;
// !!! ( *out )->m = &baseImplementationMethods ;
return jPopTest( in , stack ) ;
}

JTestResult createBase( JPTest testIn , JIBase baseIn , JPIBase out ) {
ImplementationBase ib ; JPTestStack stack ;
JTestResult result = jPushTest( testIn , sizeof( CreateStack ) , stack ) ;
jReturnTestIfError( stack , result )
if( !( ib = malloc( sizeof( *ib ) ) ) ) jReturnTestNotEnoughMemory( stack , CreateStack , _ , sizeof( *ib ) )
ib->_.b = baseIn ;
ib->_.m = &ownedImplementationMethods ;
ib->_.owned.t = jNil ;
ib->_.r = 1 ;
ib->_.value = jZero ;
ib->m = &baseImplementationMethods ;
ib->d = ( JIDBase ){ .m = &ib->m } ;
out->t = &ib->d ;
return jPopTest( testIn , stack ) ;
}