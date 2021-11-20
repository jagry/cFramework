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

#include "base.i.h"
#include "dynamic/_l"
#include "dynamic/_w"
#include "implementation.h"

//jDeclarePrefixStandardImplementation( J , Dynamic )
//jDefinePrefixStandardImplementation( J , Dynamic , jDynamicMembers( JPCMDynamic , _ ) , jBaseAllMethods( JDynamic ) , JIBase )

typedef struct JMDynamic JMDynamic ; \
typedef JMDynamic const JCMDynamic ; \
typedef JCMDynamic * JPCMDynamic ; \
typedef struct JDDynamic JDDynamic; \
typedef JDDynamic * JPDDynamic; \
typedef union JDynamic JDynamic ;
typedef JDynamic * JPDynamic ;

struct JDDynamic { JPCMDynamic m ; JIBase b ; JUnsignedInteger r ; } ;
union JDynamic { JPDDynamic d ; JIBase i ; } ;
struct JMDynamic { jBaseAllMethods( JDynamic ) } ;

#endif