#include <jagry/base.i.h>

#define jMiddleSelfMethods( arg ) JVoid( *middle )( arg ) ;
#define jMiddleEachMethods( acquireArg , getInterfaceArg , releaseArg , middleArg ) \
	jBaseEachMethods( acquireArg , getInterfaceArg , releaseArg ) jMiddleSelfMethods( middleArg ) ;
#define jMiddleAllMethods( arg ) jMiddleEachMethods( arg ) ;

#define jMiddle( arg ) ( ( arg )->_->middle( arg ) )

jDeclarePrefixStandardChildInterface( J , Middle )
jDefinePrefixStandardChildInterface( J , Middle , jMiddleAllMethods( JIMiddle ) , JIBase , JIBase )