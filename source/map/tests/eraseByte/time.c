#include <time.h>
#include "time.h"

struct timespec GetDuration( struct timespec *argument ) {
struct timespec now ;
clock_gettime( CLOCK_REALTIME , &now ) ;
now.tv_sec -= argument->tv_sec ;
now.tv_nsec -= argument->tv_nsec ;
if( now.tv_nsec < 0 )
	now.tv_nsec += 1000000000 , --now.tv_sec ;
return now ;
}