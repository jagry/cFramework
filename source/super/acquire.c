#include <jagry/super.h>

JCounter jagryAcquireSuperBase( JISuper self ) {
return ++self.data->references ;
}

JCounter jagryAcquireSuper( JISuper self ) {
if( self.data->owner.data )
	return jAcquireBase( self.data->owner ) ;
return ++self.data->references ;
}