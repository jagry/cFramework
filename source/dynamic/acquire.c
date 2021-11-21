#define jDynamicMethod jExport

#include "g.h"
#include "w.h"

#include <jagry/dynamic.i.h>

#include <jagry/dynamic/acquire>

JCounter jagryAcquireDynamic( JDynamic self ) { return /* self.d->b.t ? jAcquireBase(self.d->b) :*/ jAtomicIncrement( self.d->r ) ; }

JCounter jagryAcquireDynamicBase( JDynamic self ) { return self.d->b.t ? jAcquireBase( self.d->b ) : jAtomicIncrement( self.d->r ) ; }