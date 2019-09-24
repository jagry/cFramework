#ifndef JagryMinimal
#define JagryMinimal

#define jInitializeMinimal( self , methodsArg , ownerArg , referencesArg ) \
	{ \
		( self )->methods = &methodsArg ; \
		( self )->owner = ownerArg ; \
		( self )->references = referencesArg ; \
	}

#define jMinimalMembers( type , name ) \
	type* name ; \
	JBase* owner ; \
	JCounter references ;

typedef struct JMinimal JMinimal ;

#include "base.i.h"

//typedef struct jsmMinimal jsmMinimal ;

struct JMinimal { jMinimalMembers( JBaseMethods , methods ) } ;

#endif