#include <jagry/dynamic.l.h>
#include <jagry/test.h>

JTestResult acquire( JPTest , JPVoid ) ;
JTestResult acquireBase( JPTest , JPVoid ) ;
JTestResult initialize( JPTest , JPPVoid ) ;
JTestResult interface( JPTest , JPVoid ) ;

#define intGen(_x_) _Generic( ( _x_ ).data, JPCVoid : ( _x_ ).data = jNil )
#define realGen(_x_) _Generic(_x_, double : _x_ = 0.5 , float : _x_ = ( float )0.2 )
#define base(_x_) _Generic( _x_ , JIBase : jAcquireBase( g ) )

JUnsignedInteger main( JVoid ) {
//	JIBase g ;
//g.this = jNil ;
//int a ; double b ; float c ; long long d ;
//char c ;
//base( g ) ;
//realGen( b ) ;
//realGen( c ) ;
JTestItem items[] = {
	//jTestItemShort( acquire , initialize , jNil ) ,
	//jTestItemShort( acquireBase , initialize , jNil ) ,
	jTestItemShort( interface , initialize , jNil ) } ;
// !!! Заменить sizeof( items ) / sizeof( *items ) на define
return jagryRunTest( items , sizeof( items ) / sizeof( *items ) ) ? -1 : 0 ;
}