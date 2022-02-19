#define jDynamicMethod jStaticExport

#include "g.h"
#include "w.h"

#include <jagry/dynamic.i.h>
#include <stdlib.h>

#include <jagry/dynamic/release>

jDynamicMethod( JCounter )jagryReleaseDynamic( JDynamic self ) {
return jReleaseBase( self.this->owner ) ;
}

jDynamicMethod( JCounter )jagryReleaseDynamicBase( JDynamic self ) {
JCounter result = jAtomicDecrement( self.this->references ) ;
if( !result ) free( self.this ) ;
return result ;
}