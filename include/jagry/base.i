#ifndef JagryBaseInterface
#define JagryBaseInterface

#define jDeclareBaseImplementation( \
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

#define jDeclareChildImplementation( \
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
	typedef union data data ; \
	typedef data * dataP ;

#define jDeclareInterface( \
		interface , \
		interfaceC , \
		interfaceP , \
		methods , \
		methodsC , \
		methodsPC , \
		methodsCPC ) \
	typedef union interface interface ; \
	typedef union interface interfaceC ; \
	typedef interface * interfaceP ; \
	typedef struct methods methods ; \
	typedef methods const methodsC ; \
	typedef methodsC * methodsPC ; \
	typedef methodsPC const methodsCPC ;

#define jDeclarePrefixStandardInterface( prefix , name ) \
	jDeclareInterface( \
		prefix##I##name , \
		prefix##CI##name , \
		prefix##PI##name , \
		prefix##M##name , \
		prefix##CM##name , \
		prefix##PCM##name , \
		prefix##CPCM##name )

#define jDeclareStandardInterface( name ) \
	jDeclareInterface( \
		I##name , \
		CI##name , \
		PI##name , \
		M##name , \
		CM##name , \
		PCM##name , \
		CPCM##name )

// --------------------------

#define jPrefixStdDeclareBaseImplementation( prefix , name ) \
	jDeclareBaseImplementation( \
		prefix##I##name , \
		prefix##PI##name , \
		prefix##M##name , \
		prefix##CM##name , \
		prefix##PCM##name , \
		prefix##CPCM##name , \
		prefix##D##name , \
		prefix##PD##name )

#define jPrefixStdDeclareChildImplementation( prefix , name ) \
	jDeclareChildImplementation( \
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

#define jStdDeclareBaseImplementation( name ) \
	jDeclareBaseImplementation( \
		I##name , \
		PI##name , \
		M##name , \
		CM##name , \
		PCM##name , \
		CPCM##name , \
		D##name , \
		PD##name )

#define jStdDeclareChildImplementation( name ) \
	jDeclareChildImplementation( \
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
		struct { methodsStructure } * * methodsName ; \
		baseType baseName ; \
		superType superName ; } ; \
	union nameC { \
		struct { methodsStructure } * * methodsName ; \
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

#define jDefineBaseImplementation( \
		type , \
		name , \
		interfaceType , \
		interfaceName , \
		dataName , \
		dataPointer , \
		dataStructure , \
		methodsName , \
		methodsStructure ) \
	struct dataName { dataStructure } ; \
	struct methodsName { methodsStructure } ; \
	union type { dataPointer name ; interfaceType interfaceName ; } ;

#define jPrefixStdDefineBaseImplementation( \
		prefix , \
		type , \
		dataStructure , \
		interfaceType , \
		methodsType , \
		methodsStructure ) \
	jDefineBaseImplementation( \
		prefix##I##type , \
		_ , \
		interfaceType , \
		interface , \
		prefix##D##type , \
		prefix##PD##type , \
		dataStructure , \
		methodsType , \
		methodsStructure )

#define jStdDefineBaseImplementation( \
		type , dataStructure , interfaceType , methodsStructure ) \
	jDefineBaseImplementation( \
		I##type , \
		_ , \
		interfaceType , \
		interface , \
		D##type , \
		PD##type , \
		dataStructure , \
		M##type , \
		methodsStructure )

#define jDefineChildImplementation( \
		type , \
		name , \
		methodsType , \
		methodsStructure , \
		interfaceType , \
		interfaceName , \
		dataType , \
		dataPointer , \
		dataStructure , \
		dataName , \
		baseType , \
		baseName ) \
	union type { dataPointer name ; interfaceType interfaceName ; } ; \
	union dataType { \
		baseType baseName ; \
		struct { dataStructure } dataName ; } ; \
	struct methodsType { methodsStructure } ;

#define jPrefixStdDefineChildImplementation( \
		prefix , \
		type , \
		methodsType , \
		methodsStructure , \
		interfaceType , \
		selfStructure , \
		baseType ) \
	jDefineChildImplementation( \
		prefix##I##type , \
		_ , \
		prefix##D##type , \
		prefix##PD##type , \
		methodsType , \
		methodsStructure \
		interfaceType , \
		interface , \
		selfStructure , \
		_ , \
		baseType , \
		base )

#define jStdDefineChildImplementation( \
		type , selfStructure , interfaceType , methodsStructure , baseType ) \
	jDefineChildImplementation( \
		I##type , \
		_ , \
		M##type , \
		methodsStructure , \
		interfaceType , \
		interface , \
		D##type , \
		PD##type , \
		selfStructure , \
		_ , \
		baseType , \
		base )

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