#ifdef _WIN32
#ifdef SINGLETHREAD

#define jDecrementAtomic(_) ( --( _ ) )
#define jIncrementAtomic(_) ( ++( _ ) )

#endif
#endif