#ifndef JagryDynamicInterface
#define JagryDynamicInterface

#define jInitializeDynamic( self , methodsArg , ownerArg , referencesArg ) \
	{ \
		( self )->_ = &methodsArg ; \
		( self )->owner = ownerArg ; \
		( self )->references = referencesArg ; \
	}

#define jDynamicMembers( type ) \
	type _ ; \
	JIBase owner ; \
	atomic_int references ;

typedef struct JDDynamic JDDynamic ;
typedef struct JMDynamic JMDynamic ;
typedef union JIDynamic JIDynamic ;

typedef JMDynamic const JCMDynamic ;
typedef JDDynamic * JPDDynamic ;

typedef JCMDynamic * JPCMDynamic ;

#include <stdatomic.h>
#include "base.i"

struct JDDynamic { jDynamicMembers( JPCMDynamic ) } ;
struct JMDynamic { jBaseAll( JIDynamic ) } ;
union JIDynamic { JPDDynamic _ ; JIBase interface ; } ;

#endif