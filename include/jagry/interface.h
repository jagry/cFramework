#ifndef JagryInterface
#define JagryInterface

#define jDeclareBaseInterface( \
		name , \
		nameC , \
		nameP , \
		methods , \
		methodsC , \
		methodsPC , \
		methodsCPC ) \
	typedef struct methods methods ; \
	typedef methods const methodsC ; \
	typedef methodsC * methodsPC ; \
	typedef methodsPC const methodsCPC ; \
	typedef methodsCPC * name ; \
	typedef name * nameP ;

#define jDeclareStandardBaseInterface( name ) \
	jDeclareBaseInterface( \
		I##name , \
		CI##name , \
		PI##name , \
		M##name , \
		CM##name , \
		PCM##name , \
		CPCM##name )

#define jDeclarePrefixStandardBaseInterface( prefix , name ) \
	jDeclareBaseInterface( \
		prefix##I##name , \
		prefix##CI##name , \
		prefix##PI##name , \
		prefix##M##name , \
		prefix##CM##name , \
		prefix##PCM##name , \
		prefix##CPCM##name )

#define jDefineBaseInterface( name , nameC , methods ) \
	struct { methods } * * name ; \
	struct { methods } * * nameC ;

#define jDefineStandardInterface( type , structure ) \
	jDefineBaseInterface( I##type , CI##type , structure )

#define jDefinePrefixStandardBaseInterface( prefix , type , structure ) \
	jDefineBaseInterface( prefix##I##type , prefix##CI##type , structure )

#define jDeclareChildInterface( \
		name , \
		nameC , \
		nameP , \
		methods , \
		methodsC , \
		methodsPC , \
		methodsCPC ) \
	typedef union name name ; \
	typedef union name nameC ; \
	typedef name * nameP ; \
	typedef struct methods methods ; \
	typedef methods const methodsC ; \
	typedef methodsC * methodsPC ; \
	typedef methodsPC const methodsCPC ;

#define jDeclareStandardChildInterface( name ) \
	jDeclareChildInterface( \
		I##name , \
		CI##name , \
		PI##name , \
		M##name , \
		CM##name , \
		PCM##name , \
		CPCM##name )

#define jDeclarePrefixStandardChildInterface( prefix , name ) \
	jDeclareChildInterface( \
		prefix##I##name , \
		prefix##CI##name , \
		prefix##PI##name , \
		prefix##M##name , \
		prefix##CM##name , \
		prefix##PCM##name , \
		prefix##CPCM##name )

#define jDefineChildInterface( \
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

#define jDefinePrefixStandardChildInterface( \
		prefix , type , structure , superType ) \
	jDefineChildInterface( \
		prefix##I##type , \
		prefix##CI##type , \
		structure , \
		_ , \
		JIBase , \
		base , \
		superType , \
		super )

#define jDefineStandardChildInterface( type , structure , superType ) \
	jDefineChildInterface( \
		I##type , \
		CI##type , \
		structure , \
		_ , \
		JIBase , \
		base , \
		superType , \
		super )

#include "../jagry.h"

typedef JUnsignedInteger8 JInterfaceIdentifier ;

#define JBaseInterfaceIdentifier        ( ( JInterfaceIdentifier )0 )
#define JArrayInterfaceIdentifier       ( ( JInterfaceIdentifier )1 )
#define JSimpleArrayInterfaceIdentifier ( ( JInterfaceIdentifier )2 )
#define JSortArrayInterfaceIdentifier   ( ( JInterfaceIdentifier )3 )
#define JListInterfaceIdentifier        ( ( JInterfaceIdentifier )4 )
#define JSimpleListInterfaceIdentifier  ( ( JInterfaceIdentifier )5 )
#define JSortListInterfaceIdentifier    ( ( JInterfaceIdentifier )6 )

#endif