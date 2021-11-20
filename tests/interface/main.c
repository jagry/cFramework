#include <jagry/base.i.h>
#include <jagry/test.h>

JTestResult clear( JPTest testIn , JPVoid argumentIn ) {
typedef union { JTestNotEnoudhMemoryData _ ; } Test ;
JPTestStack stack ;
JTestResult result = jPushTest( testIn , sizeof( Test ) , stack ) ;
jReturnTestIfError( stack , result )
return jPopTest( testIn , stack ) ;
}

static JVoid mainFinalize( JPTest testIn , JPVoid argument ) {
}

static JTestResult mainInitialize( JPTest testIn , JPPVoid argument ) {
typedef union { JTestNotEnoudhMemoryData _ ; } Test ;
JPTestStack stack ;
JTestResult result = jPushTest( testIn , sizeof( Test ) , stack ) ;
jReturnTestIfError( stack , result )
return jPopTest( testIn , stack ) ;
}

JUnsignedInteger main(JVoid) {
JTestItem items[] = {
	jTestItemShort( clear , mainFinalize , mainInitialize ) } ;
return jagryRunTest( items , sizeof( items ) / sizeof( *items ) ) ? -1 : 0 ;
}