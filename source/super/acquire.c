#include <jagry/super.h>

JCounter jagryAcquireSuperBase( JISuper self ) {
return ++self._->references ;
}

JCounter jagryAcquireSuper( JISuper self ) {
return self._->owner ? jAcquireBase( self._->owner ) : ++self._->references ;
}