#ifdef WIN32

#ifndef SINGLETHREAD
	#define jAtomicDecrement( argument ) ( --argument )
	#define jAtomicIncrement( argument ) ( ++argument )
#else
	#include <windows.h>

	#define jAtomicDecrement( argument ) InterlockedDecrement( &argument )
	#define jAtomicIncrement( argument ) InterlockedIncrement( &argument )
#endif

#endif