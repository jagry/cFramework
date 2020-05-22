#ifndef JagryStaticInterface
#define JagryStaticInterface

#define jInitializeStatic( self , methodsArg , ownerArg , referencesArg ) \
	{ \
		( self )->_ = &methodsArg ; \
		( self )->owner = ownerArg ; \
	}

#define jStaticMembers( type ) \
	type _ ; \
	JIBase owner ;

typedef struct JDStatic JDStatic ;
typedef struct JMStatic JMStatic ;
typedef union JIStatic JIStatic ;

typedef JMStatic const JCMStatic ;
typedef JDStatic * JPDStatic ;

typedef JCMStatic * JPCMStatic ;

#include "base.i"

struct JDStatic { jStaticMembers( JPCMStatic ) } ;
struct JMStatic { jBaseAll( JIStatic ) } ;
union JIStatic { JPDStatic * _ ; JIBase interface ; } ;

#endif