#ifndef JagrySuper
#define JagrySuper

#define jInitializeSuper( self , methodsArg , ownerArg , referencesArg ) \
	{ \
		( self ).data->methods = &methodsArg ; \
		( self ).data->owner.data = ownerArg ; \
		( self ).data->references = referencesArg ; \
	}

#define jSuperMembers( type , name ) \
	type name ; \
	JIBase owner ; \
	atomic_int references ;

typedef struct JDSuper JDSuper ;
typedef struct JMSuper JMSuper ;
typedef union JISuper JISuper ;

typedef JMSuper const JCMSuper ;
typedef JDSuper * JPDSuper ;

typedef JCMSuper * JPCMSuper ;

#include <stdatomic.h>
#include "base.i.h"

struct JDSuper { jSuperMembers( JPCMSuper , methods ) } ;
struct JMSuper { jBaseAll( JISuper ) } ;
union JISuper { JPDSuper data ; JIBase interface ; } ;

JCounter jagryAcquireSuper( JISuper ) ;

#endif