#define jDynamicMethod jExport

#include <jagry/dynamic.i>
#include <stdlib.h>

#include <jagry/dynamic/release>

JCounter jagryReleaseDynamicBase( JIDynamic self ) {
JCounter result = --self._->references ;
if( !result )
	free( self._ ) ;
return result ;
}

JCounter jagryReleaseDynamic( JIDynamic self ) {
return self._->owner ?
	jReleaseBase( self._->owner ) :
	jagryReleaseDynamicBase( self ) ;
}