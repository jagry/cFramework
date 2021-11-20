#include "implementation.h"
#include <jagry/test.h>

typedef struct { DImplementation d ; JIBase b ; JIPCMBase m ; } /* CreateImplementation, */ * PCreateOut ;
typedef union { JTestNotEnoudhMemoryData _ ; } CreateStack ;

JTestResult create( JPTest in , PCreateOut out ) {
JPTestStack stack ;
JTestResult result = jPushTest( in , sizeof( CreateStack ) , stack ) ;
jReturnTestIfError( stack , result )
JUnsignedInteger debug = sizeof( *out ) ;
JIDBase b = { .m = &baseImplementationMethods } ;
if( !( out = malloc( sizeof( *out ) ) ) ) jReturnTestNotEnoughMemory( stack , CreateStack , _ , sizeof( *out ) )
out->m = &baseImplementationMethods ;
//out->b.d->m = &out->m ;
out->d.b.t = &b ;
out->d.m = &ownerImplementationMethods ;
out->d.owned.t = jNil ;
out->d.r = 1 ;
out->d.value = jZero ;
return jPopTest( in , stack ) ;
}

JTestResult createBase( JPTest testIn , JIBase baseIn , PImplementation out ) {
// !!! Рефакторить
PDImplementation data ; Implementation implementation ; JPTestStack stack ;
JTestResult result = jPushTest( testIn , sizeof( CreateStack ) , stack ) ;
jReturnTestIfError( stack , result )
if( !( data = implementation.d = malloc( sizeof( *data ) ) ) ) jReturnTestNotEnoughMemory( stack , CreateStack , _ , sizeof( *data ) )
data->b = baseIn , data->m = &ownerImplementationMethods , data->owned.t = jNil , data->r = 1 , data->value = jZero ;
*out = implementation ;
return jPopTest( testIn , stack ) ;
}