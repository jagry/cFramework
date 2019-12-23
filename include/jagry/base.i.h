#ifndef JagryBaseInterface
#define JagryBaseInterface

#define jDeclareInterface( interface , interfaceP , methods , methodsC , methodsPC , methodsCPC , data , dataC , dataP , dataPC ) \
	typedef union interface interface ; \
	typedef interface * interfaceP ; \
	typedef struct methods methods ; \
	typedef methods const methodsC ; \
	typedef methodsC * methodsPC ; \
	typedef methodsPC const methodsCPC ; \
	typedef struct data data ; \
	typedef data * dataP ; \
	typedef data const dataC ; \
	typedef dataC * dataPC ;

#define jPrefixStdDeclareInterface( prefix , name ) jDeclareInterface( prefix##I##name , prefix##PI##name , prefix##M##name , \
	prefix##CM##name , prefix##PCM##name , prefix##CPCM##name , prefix##D##name , prefix##CD##name , prefix##PD##name , prefix##PCD##name )

#define jStdDeclareInterface( name ) jPrefixStdDeclareInterface( , name )

#define jDefineInterface( data , dataType , dataName , methods , methodsStructure , \
		interface , interfaceBaseType , interfaceBaseName , interfaceDataType , \
		interfaceDataName , interfaceSuperType , interfaceSuperName ) \
	struct data { dataType dataName ; } ; \
	struct methods { methodsStructure } ; \
	union interface \
		{ \
			interfaceBaseType interfaceBaseName ; \
			interfaceDataType interfaceDataName ; \
			interfaceSuperType interfaceSuperName ; \
		} ;

#define jPrefixStdDefineInterface( prefix , type , structure , superType ) jDefineInterface( prefix##D##type , prefix##CPCM##type , \
	methods , prefix##M##type , structure , prefix##I##type , JIBase , base , prefix##PCD##type , data , superType , super ) 

#define jStdDefineInterface( type , structure , superType ) jPrefixStdDefineInterface( , type , structure , superType )

/*#define jInterface( type , superType , supersUnion , member , methods , methodsType , methodsSuperType , methodsSupersUnion ) \
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
	} ;*/

#define jDeclareImplementation( interface , interfaceP , methods , methodsC , methodsPC , methodsCPC , data , dataP ) \
	typedef union interface interface ; \
	typedef interface * interfaceP ; \
	typedef struct methods methods ; \
	typedef methods const methodsC ; \
	typedef methodsC * methodsPC ; \
	typedef methodsPC const methodsCPC ; \
	typedef struct data data ; \
	typedef data * dataP ;

#define jPrefixStdDeclareImplementation( prefix , name ) jDeclareImplementation( prefix##I##name , prefix##PI##name , prefix##M##name , \
	prefix##CM##name , prefix##PCM##name , prefix##CPCM##name , prefix##D##name , prefix##PD##name )

#define jStdDeclareImplementation( name ) jPrefixStdDeclareImplementation( , name )

#define jAcquireBasePointer( type ) JCounter( *acquire )( type ) ;
#define jGetBaseInterfacePointer( type ) JResult( *getInterface )( type ) ;
#define jReleaseBasePointer( type ) JCounter( *release )( type ) ;

#define jAcquireBase( argument ) ( argument.data->methods->acquire( argument ) )
#define jGetBaseInterface( self , identifier , out ) ( self.data->methods->getInterface( self , identifier , out ) )
#define jReleaseBase( argument ) ( argument.data->methods->release( argument ) )

#define jBaseSupers JBase base ;
#define jBaseMethodsSupers JBaseMethods base ;

#define jBaseSelf( acquire , getInterface , release ) \
	jAcquireBasePointer( acquire ) \
	jGetBaseInterfacePointer( getInterface ) \
	jReleaseBasePointer( release )
#define jBaseEach( acquire , getInterface , release ) jBaseSelf( acquire , getInterface , release )
#define jBaseAll( type ) jBaseEach( type , type , type )

jPrefixStdDeclareInterface( J , Base )

#include "result.h"

struct JDBase { JCPCMBase methods ; } ;
struct JMBase { jBaseAll( JIBase ) } ;
union JIBase { JPCDBase data ; } ;

//#define jNullInterface

#endif