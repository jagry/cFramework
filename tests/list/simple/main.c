#include "error.h"
#include <jagry/list.l.h>
#include "stack.h"
#include <stdio.h>

JTestResult clear( JPTest , JPVoid ) ;
JTestResult eraseItem( JPTest , JISimpleArray ) ;
JTestResult push( JPTest , JISimpleArray ) ;

static JVoid finalize( JPTest testIn , JPVoid argument ) {
jReleaseArray( *( JPISimpleArray )argument ) ;
free( argument ) ;
}

static JTestResult initialize( JPTest testIn , JPPVoid argument ) {
typedef union { JTestNotEnoudhMemoryData _ ; } Test ;
JPTestStack stack ;
JTestResult result = jPushTest( testIn , sizeof( Test ) , stack ) ;
jReturnTestIfError( stack , result )
*argument = malloc( sizeof( JISimpleArray ) ) ;
jReturnTestNotEnoughMemoryIfNil(
	stack , *argument , Test , _ , sizeof( Test ) )
JStatus status = jagrySimpleList( jagryListPointerManager() , ( JPISimpleArray )*argument ) ;
return jPopTest( testIn , stack ) ;
}

#define item( bodyArg , finalifeArg , initializeArg , nameArg ) \
	{ \
		.body = bodyArg , \
		.finalize = finalifeArg , \
		.initialize = initializeArg , \
		.name = nameArg }

JUnsignedInteger main( JVoid ) {
JTestItem items[] = {
	item( clear , finalize , initialize , "clear" ) ,
	item( eraseItem , finalize , initialize , "eraseItem" ) } ;
return jagryRunTest( items , sizeof( items ) / sizeof( *items ) ) ? -2 : 0 ;
}