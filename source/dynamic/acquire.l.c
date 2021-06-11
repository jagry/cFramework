#ifdef __linux__

#define jDynamicMethod jExport

#ifdef _WIN32
	#include <windows.h>
#endif

#include <jagry/dynamic.i>

#include <jagry/dynamic/acquire>

JCounter jagryAcquireDynamicBase( JIDynamic self ) {
jLinux( return ++self._->references ) ;
jWindows( return ++self._->references ) ;
}

JCounter jagryAcquireDynamic( JIDynamic self ) {
return self._->owner ? jAcquireBase( self._->owner ) : ++self._->references ;
}

#endif