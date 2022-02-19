#define jDynamicMethod jStaticExport

#include "g.h"
#include "w.h"

#include <jagry/dynamic.i.h>

#include <jagry/dynamic/acquire>

jDynamicMethod( JCounter )jagryAcquireDynamic( JDynamic self ) { return /* !!! self.d->b.t ? jAcquireBase(self.d->b) :*/ jAtomicIncrement( self.this->references ) ; }

jDynamicMethod( JCounter )jagryAcquireDynamicBase( JDynamic self ) {
JIBase owner = self.this->owner ;
return /* !!! self.this->b.t ? jAcquireBase(self.d->b) : */ jAcquireBase( owner ) ;
}