#ifndef JagryDynamicInterface
#define JagryDynamicInterface

#define jInitializeDynamic( self , methodsArg , ownerArg , referencesArg ) \
	{ \
		( self )->_ = &methodsArg ; \
		( self )->owner = ownerArg ; \
		( self )->references = referencesArg ; \
	}

#define jDynamicMembers( type , members ) \
	type members ; \
	JIBase owner ; \
	JAtomic references ;

typedef struct JDDynamic JDDynamic ;
typedef struct JMDynamic JMDynamic ;
typedef union JIDynamic JIDynamic ;

typedef JMDynamic const JCMDynamic ;
typedef JDDynamic * JPDDynamic ;

typedef JCMDynamic * JPCMDynamic ;

#include "base.i.h"
#include "dynamic/_l"
#include "dynamic/_w"

struct JDDynamic { jDynamicMembers( JPCMDynamic , _ ) } ;
struct JMDynamic { jBaseAll( JIDynamic ) } ;
union JIDynamic { JPDDynamic _ ; JIBase i ; } ;

#endif