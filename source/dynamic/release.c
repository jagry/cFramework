#define jDynamicMethod jExport

#include "g.h"
#include "w.h"

#include <jagry/dynamic.i.h>
#include <stdlib.h>

#include <jagry/dynamic/release>

JCounter jagryReleaseDynamic( JDynamic self ) { return self.d->b.t ? jReleaseBase( self.d->b ) : jAtomicDecrement( self.d->r ) ; }

JCounter jagryReleaseDynamicBase( JDynamic self ) {
JCounter result = jAtomicDecrement( self.d->r ) ;
if( !result ) free( self.d ) ;
return result ;
}