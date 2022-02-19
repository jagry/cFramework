#include "implementation.h"
#include <jagry\test.h>
#include <stdlib.h>

JTestResult createSelf( JPTest , PUImplementation ) ;
JTestResult createBase( JPTest , JIBase , PCSMImplementation , JIPCMBase , JPIBase , PUImplementation ) ;

JTestResult initialize( JPTest in , PPUImplementation out ) {
typedef union { JNotEnoughMemoryTestData _ ; } Stack ;
JPTestStack stack ;
JTestResult result = jPushTest( in , sizeof( Stack ) , stack ) ;
jReturnTestIfError( stack , result )
if( !( *out = malloc( sizeof( **out ) * 3 ) ) ) jReturnTestNotEnoughMemory( stack , Stack , _ , sizeof( **out ) * 3 )
result = createSelf( in , &( *out )[ 0 ] ) ;
if( jTestIsNotError( result ) )
	{
		result = createBase( in , ( *out )[ 0 ].base , &middleImplementationMethods , &middleImplementationBaseMethods , &( *out )[ 0 ].this->owned , &( *out )[ 1 ] ) ;
		if( jTestIsNotError( result ) ) {
			result = createBase( in , ( *out )[ 1 ].base , &lastImplementationMethods , &lastImplementationBaseMethods , &( *out )[ 1 ].this->owned , &( *out )[ 2 ] ) ;
			if( jTestIsNotError( result ) ) return jPopTest( in , stack ) ;
			jReleaseBase( ( *out )[ 1 ].base ) ;
		}
		// !!! вызвать метод реализации, а не jReleaseBase( ( JIBase ){ .t = &( *out )[ 0 ]->b ) ; } ;
	}
free( *out ) ;
jReturnTest( stack , result )
}