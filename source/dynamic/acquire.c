#define jDynamicMethod jExport

#include "g.h"
#include "w.h"

#include <jagry/dynamic.i.h>

#include <jagry/dynamic/acquire>

JCounter jagryAcquireDynamicBase( JIDynamic self ) {
return jAtomicIncrement( self._->references ) ;
}

JCounter jagryAcquireDynamic( JIDynamic self ) {
return self._->owner ?
	jAcquireBase( self._->owner ) :
	jAtomicIncrement( self._->references ) ;
}