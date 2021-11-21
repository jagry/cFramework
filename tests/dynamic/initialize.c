#include "implementation.h"
#include <jagry\test.h>
#include <memory.h>

JTestResult create( JPTest , PImplementation ) ;
JTestResult createBase( JPTest , JIBase , PImplementation ) ;

JTestResult initialize( JPTest in , PPImplementation out ) {
typedef union { JTestNotEnoudhMemoryData _ ; } Stack ;
Implementation implementation ; JPTestStack stack ;
JTestResult result = jPushTest( in , sizeof( Stack ) , stack ) ;
jReturnTestIfError( stack , result )
// !!! JUnsignedInteger debug = sizeof( *out ) ;
// debug = sizeof( *out ) << 1 ;
// debug = sizeof( *( *out )->d ) ;
if( !( *out = malloc( sizeof( *out ) << 1 ) ) ) jReturnTestNotEnoughMemory( stack , Stack , _ , sizeof( *out ) << 1 )
result = create( in , &( *out )[ 0 ] ) ;
if( jTestIsNotError( result ) )
	{
		result = createBase( in , ( *out )[ 0 ].i.b , &implementation ) ;
		if( jTestIsNotError( result ) ) return ( *out )[ 0 ].d->owned = ( ( *out )[ 1 ] = implementation ).i.b , jPopTest( in , stack ) ;
		jReleaseBase( ( *out )[ 0 ].i.b ) ;
	}
free( *out ) ;
jReturnTest( stack , result )
}