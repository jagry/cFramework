#include <jagry/dynamic.l.h>
#include <jagry/test.h>

JTestResult acquire( JPTest , JPVoid ) ;
JTestResult acquireBase( JPTest , JPVoid ) ;
JTestResult initialize( JPTest , JPPVoid ) ;
JTestResult owner( JPTest , JPVoid ) ;

JUnsignedInteger main( JVoid ) {
JTestItem items[] = {
	jTestItemShort( acquire , initialize , jNil ) ,
	jTestItemShort( acquireBase , initialize , jNil ) ,
	jTestItemShort( owner , initialize , jNil ) } ;
return jagryRunTest( items , sizeof( items ) / sizeof( *items ) ) ? -1 : 0 ;
}