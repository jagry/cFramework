#include <jagry/super.h>
#include <stdlib.h>

JCounter jagryReleaseSuperBase( JISuper self ) {
JCounter result = --self._->references ;
if( !result )
	free( self._ ) ;
return result ;
}

JCounter jagryReleaseSuper( JISuper self ) {
return self._->owner ?
	jReleaseBase( self._->owner ) :
	jagryReleaseSuperBase( self ) ;
}