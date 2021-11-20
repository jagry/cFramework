#if __linux__

#define jAtomicDecrement( argument ) --argument
#define jAtomicIncrement( argument ) ++argument

#endif
