#include "implementation.h"
#include <jagry/test.h>
#include <stdlib.h>

typedef union { JNotEnoughMemoryTestData _ ; } CreateStack ;

static JTestResult create( JPTest testIn , PUImplementation out ) {
JPTestStack stack ;
JTestResult result = jPushTest( testIn , sizeof( CreateStack ) , stack ) ;
jReturnTestIfError( stack , result )
if( !( out->this = malloc( sizeof( *out->this ) ) ) ) jReturnTestNotEnoughMemory( stack , CreateStack , _ , sizeof( *out->this ) )
out->this->references = 1 ;
out->this->owned.this = jNil ;
out->this->value = jZero ;
return jPopTest( testIn , stack ) ;
}

JTestResult createBase( JPTest testIn , JIBase baseIn , PCSMImplementation methodsIn, JIPCMBase selfMethodsIn, JPUBase baseOut , PUImplementation implementationOut ) {
JPTestStack stack ;
JTestResult result = jPushTest( testIn , sizeof( CreateStack ) , stack ) ;
jReturnTestIfError( stack , result )
result = create( testIn , implementationOut ) ;
jReturnTestIfError( stack , result )
implementationOut->this->methods = methodsIn ;
implementationOut->this->owner = baseIn ;
implementationOut->this->self.methods = selfMethodsIn ;
*baseOut = ( JUBase ){ .this = &implementationOut->this->self } ;
return jPopTest( testIn , stack ) ;
}

JTestResult createSelf( JPTest in , PUImplementation out ) {
JPTestStack stack ;
JTestResult result = jPushTest( in , sizeof( CreateStack ) , stack ) ;
jReturnTestIfError( stack , result )
result = create( in , out ) ;
jReturnTestIfError( stack , result )
out->this->methods = &firstImplementationMethods ;
out->this->owner.this = jNil ;
out->this->self.methods = &firstImplementationBaseMethods ;
return jPopTest( in , stack ) ;
}