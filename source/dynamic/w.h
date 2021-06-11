#ifdef WIN32

#include <windows.h>

#ifdef SINGLETHREAD
	#define jAtomicDecrement( argument ) ( --argument )
	#define jAtomicIncrement( argument ) ( ++argument )
#else
	#define jAtomicDecrement( argument ) InterlockedDecrement( &argument )
	#define jAtomicIncrement( argument ) InterlockedIncrement( &argument )
#endif

#endif