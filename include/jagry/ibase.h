#ifndef JagryBaseInterface
#define JagryBaseInterface

#define jInterface( type , superType , supersUnion , member , methods , methodsType , methodsSuperType , methodsSupersUnion ) \
	union methodsType { \
		struct { methods } ; \
		struct { methodsSupersUnion } supers ; \
		methodsSuperType super ; \
	} ; \
	\
	union type { \
		union methodsType* member ; \
		superType super ; \
		struct { supersUnion } supers ; \
	} ;

#define jAqcuireBasePointer( type ) JCounter( *aqcuire )( type* ) ;
#define jDumpBasePointer( type ) void( *dump )( type* ) ;
#define jGetBaseInterfacePointer( type ) JResult( *getInterface )( type* ) ;
#define jReleaseBasePointer( type ) JCounter( *release )( type* ) ;

#define jBaseSupers JBase base ;
#define jBaseMethodsSupers JBaseMethods base ;

#define jBaseEach( aqcuire , dump , getInterface , release ) \
	jAqcuireBasePointer( aqcuire ) \
	jDumpBasePointer( dump ) \
	jGetBaseInterfacePointer( getInterface ) \
	jReleaseBasePointer( release )
#define jBaseAll( type ) jBaseEach( type , type , type , type )

typedef struct JBase JBase ;
typedef struct JBaseMethods JBaseMethods ;

#include "result.h"

struct JBase { JBaseMethods* methods ; } ;
struct JBaseMethods { jBaseAll( JBase ) } ;

#define jAqcuireBase( argument ) ( ( argument )->methods->aqcuire( argument ) )
#define jDumpBase( argument ) ( ( argument )->methods->dump( argument ) )
#define jGetBaseInterface( self , identifier , out ) ( ( self )->methods->getInterface( self , identifier , out ) )
#define jReleaseBase( argument ) ( ( argument )->methods->release( argument ) )

#endif