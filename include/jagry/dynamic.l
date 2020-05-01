#ifndef JagrySuper
#define JagrySuper

#define jInitializeSuper( self , methodsArg , ownerArg , referencesArg ) \
	{ \
		( self )->_ = &methodsArg ; \
		( self )->owner = ownerArg ; \
		( self )->references = referencesArg ; \
	}

#define jSuperMembers( type , name ) \
	type _ ; \
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

struct JMSuper { jBaseAll( JISuper ) } ;
union JISuper {
	struct { jSuperMembers( JPCMSuper , _ ) } * _ ;
	JIBase interface ; } ;

JCounter jagryAcquireSuper( JISuper ) ;
JCounter jagryReleaseSuper( JISuper ) ;

#endif