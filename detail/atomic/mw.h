#ifdef _WIN32
#ifndef SINGLETHREAD

#include <windows.h>

#define jDecrementAtomic(_) InterlockedDecrement( &_ )
#define jIncrementAtomic(_) InterlockedIncrement( &_ )

#endif
#endif