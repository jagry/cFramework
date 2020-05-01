#ifndef JagryBaseInterface
#define JagryBaseInterface

#define jDeclareInterface( \
		interface , \
		interfaceC , \
		interfaceP , \
		methods , \
		methodsC , \
		methodsPC , \
		methodsCPC ) \
	typedef union interface interface ; \
	typedef union interface const interfaceC ; \
	typedef interface * interfaceP ; \
	typedef struct methods methods ; \
	typedef methods const methodsC ; \
	typedef methodsC * methodsPC ; \
	typedef methodsPC const methodsCPC ;

#define jPrefixStdDeclareInterface( prefix , name ) \
	jDeclareInterface( \
		prefix##I##name , \
		prefix##CI##name , \
		prefix##PI##name , \
		prefix##M##name , \
		prefix##CM##name , \
		prefix##PCM##name , \
		prefix##CPCM##name )

#define jStdDeclareInterface( name ) \
	jPrefixStdDeclareInterface( \
		I##name , \
		CI##name , \
		PI##name , \
		M##name , \
		CM##name , \
		PCM##name , \
		CPCM##name )

#define jDeclareImplementation( \
		interface , \
		interfaceP , \
		methods , \
		methodsC , \
		methodsPC , \
		methodsCPC , \
		data , \
		dataP ) \
	typedef union interface interface ; \
	typedef interface * interfaceP ; \
	typedef struct methods methods ; \
	typedef methods const methodsC ; \
	typedef methodsC * methodsPC ; \
	typedef methodsPC const methodsCPC ; \
	typedef struct data data ; \
	typedef data * dataP ;

#define jPrefixStdDeclareImplementation( prefix , name ) \
	jDeclareImplementation( \
		prefix##I##name , \
		prefix##PI##name , \
		prefix##M##name , \
		prefix##CM##name , \
		prefix##PCM##name , \
		prefix##CPCM##name , \
		prefix##D##name , \
		prefix##PD##name )

#define jStdDeclareImplementation( name ) \
	jDeclareImplementation( \
		I##name , \
		PI##name , \
		M##name , \
		CM##name , \
		PCM##name , \
		CPCM##name , \
		D##name , \
		PD##name )

#define jDefineInterface( \
		name , \
		nameC , \
		methodsStructure , \
		methodsName , \
		baseType , \
		baseName , \
		superType , \
		superName ) \
	union name { \
		struct { methodsStructure } ** methodsName ; \
		baseType baseName ; \
		superType superName ; } ; \
	union nameC { \
		struct { methodsStructure } ** methodsName ; \
		baseType baseName ; \
		superType superName ; } ;

#define jPrefixStdDefineInterface( prefix , type , structure , superType ) \
	jDefineInterface( \
		prefix##I##type , \
		prefix##CI##type , \
		structure , \
		_ , \
		JIBase , \
		base , \
		superType , \
		super )

#define jStdDefineInterface( type , structure , superType ) \
	jPrefixStdDefineInterface( , type , structure , superType )

#define jDefineImplementation( \
		name , \
		interfaceType , \
		interfaceName , \
		dataName , \
		dataPointer , \
		dataStructure , \
		methodsName , \
		methodsStructure ) \
	struct dataName { dataStructure } ; \
	union name { dataPointer _ ; interfaceType interfaceName ; } ; \
	struct methodsName { methodsStructure } ;

#define jPrefixStdDefineImplementation( \
		prefix , \
		name , \
		dataStructure , \
		interfaceType , \
		methodsType , \
		methodsStructure ) \
	jDefineImplementation( \
		prefix##I##name , \
		interfaceType , \
		interface , \
		prefix##D##name , \
		prefix##PD##name , \
		dataStructure , \
		methodsType , \
		methodsStructure ) \

#define jStdDefineImplementation( \
		name , dataStructure , interfaceType , methodsStructure ) \
	jDefineImplementation( \
		I##name , \
		interfaceType , \
		interface1 , \
		D##name , \
		PD##name , \
		dataStructure , \
		M##name , \
		methodsStructure ) \

#define jAcquireBasePointer( type ) JCounter( *acquire )( type ) ;
#define jGetBaseInterfacePointer( type ) JResult( *getInterface )( type , JUnsignedInteger , JPIBase ) ;
#define jReleaseBasePointer( type ) JCounter( *release )( type ) ;

#define jAcquireBase( self ) ( ( *self )->acquire( self ) )
#define jGetBaseInterface( self , identifier , out ) ( ( *self )->getInterface( self , identifier , out ) )
#define jReleaseBase( self ) ( ( *self )->release( self ) )

#define jBaseSupers JBase base ;
#define jBaseMethodsSupers JBaseMethods base ;

#define jBaseSelf( acquire , getInterface , release ) \
	jAcquireBasePointer( acquire ) \
	jGetBaseInterfacePointer( getInterface ) \
	jReleaseBasePointer( release )
#define jBaseEach( acquire , getInterface , release ) jBaseSelf( acquire , getInterface , release )
#define jBaseAll( type ) jBaseEach( type , type , type )

#define jBaseAll( type ) jBaseEach( type , type , type )

//jPrefixStdDeclareInterface( J , Base )

typedef struct JMBase JMBase ; \
typedef JMBase const JCMBase ; \
typedef JCMBase * JPCMBase ; \
typedef JPCMBase const JCPCMBase ; \
typedef JCPCMBase * JIBase ; \
typedef JIBase * JPIBase ; \

#include "result.h"

struct JMBase { jBaseAll( JIBase ) } ;

//#define jNullInterface

#endif