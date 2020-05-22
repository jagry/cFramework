#define jDynamicMethod jExport

#include <jagry/dynamic.i>

#include <jagry/dynamic/acquire>

JCounter jagryAcquireDynamicBase( JIDynamic self ) {
return ++self._->references ;
}

JCounter jagryAcquireDynamic( JIDynamic self ) {
return self._->owner ? jAcquireBase( self._->owner ) : ++self._->references ;
}