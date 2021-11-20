#ifndef JagryInterface
#define JagryInterface

// TODO: Нужен ли const interface?
#define jDeclareBaseInterface( nameArg , nameCArg , namePArg , methodsArg , methodsCArg , methodsPCArg , methodsCPCArg ) \
	typedef struct methodsArg methodsArg ; \
	typedef methodsArg const methodsCArg ; \
	typedef methodsCArg * methodsPCArg ; \
	typedef methodsPCArg const methodsCPCArg ; \
	typedef methodsCPCArg * nameArg ; \
	typedef nameArg * namePArg ;

// TODO: Нужен ли const interface?
#define jDeclarePrefixStandardBaseInterface( prefixArg , nameArg ) jDeclareBaseInterface( \
	prefixArg##I##nameArg , \
	prefixArg##CI##nameArg , \
	prefixArg##PI##nameArg , \
	prefixArg##IM##nameArg , \
	prefixArg##CIM##nameArg , \
	prefixArg##PCIM##nameArg , \
	prefixArg##CPCIM##nameArg )

// TODO: Нужен ли const interface?
#define jDeclareStandardBaseInterface( nameArg ) \
	jDeclareBaseInterface( I##nameArg , CI##nameArg , PI##nameArg , IM##nameArg , CIM##nameArg , PCIM##nameArg , CPCIM##nameArg )

// TODO: Нужен ли const interface?
#define jDefineBaseInterface( nameArg , nameCArg , methodsStructureArg , methodsNameArg ) \
	union nameArg { struct { methodsStructureArg } * methodsNameArg ; } ; \
	union nameCArg { struct { methodsStructureArg } * methodsNameArg ; } ;

// TODO: Нужен ли const interface?
#define jDefineStandardBaseInterface( nameArg , structureArg ) jDefineBaseInterface( I##nameArg , CI##nameArg , structureArg , _ )

// TODO: Нужен ли const interface?
#define jDefinePrefixStandardBaseInterface( prefixArg , nameArg , structureArg ) \
	jDefineBaseInterface( prefixArg##I##nameArg , prefixArg##CI##nameArg , structureArg , _ )

// TODO: Нужен ли const interface?
#define jDeclareChildInterface( nameArg , nameCArg , namePArg , methodsArg , methodsCArg , methodsPCArg , methodsCPCArg ) \
	typedef struct methodsArg methodsArg ; \
	typedef union nameArg * nameArg ; \
	typedef methodsArg const methodsCArg ; \
	typedef nameArg * namePArg ; \
	typedef methodsCArg * methodsPCArg ; \
	typedef methodsPCArg const methodsCPCArg ;

// TODO: Нужен ли const interface?
#define jDeclareStandardChildInterface( nameArg ) \
	jDeclareChildInterface( I##nameArg , CI##nameArg , PI##nameArg , IM##nameArg , CIM##nameArg , PCIM##nameArg , CPCIM##nameArg )

// TODO: Нужен ли const interface?
#define jDeclarePrefixStandardChildInterface( prefixArg , nameArg ) \
	jDeclareChildInterface( \
		prefixArg##I##nameArg , \
		prefixArg##CI##nameArg , \
		prefixArg##PI##nameArg , \
		prefixArg##IM##nameArg , \
		prefixArg##CIM##nameArg , \
		prefixArg##PCIM##nameArg , \
		prefixArg##CPCIM##nameArg )

// TODO: Нужен ли const interface?
#define jDefineChildInterface( nameArg , nameCArg , methodsStructureArg , methodsNameArg , baseTypeArg , baseNameArg , superTypeArg , superNameArg ) \
	union nameArg { struct { methodsStructureArg } * methodsNameArg ; baseTypeArg baseNameArg ; superTypeArg superNameArg ; } ; \
	union nameCArg { struct { methodsStructureArg } * methodsNameArg ; baseTypeArg baseNameArg ; superTypeArg superNameArg ; } ;

// TODO: Нужен ли const interface?
#define jDefinePrefixStandardChildInterface( prefixArg , nameArg , structureArg , baseArg , superArg ) \
	jDefineChildInterface( prefixArg##I##nameArg , prefixArg##CI##nameArg , structureArg , _ , baseArg , base , superArg , super )

// TODO: Нужен ли const interface?
#define jDefineStandardChildInterface( nameArg , structureArg , superArg , baseArg ) \
	jDefineChildInterface( I##nameArg , CI##nameArg , structureArg , _ , baseArg , base , superArg , super )

#define jBaseInterface( nameArg , nameCArg , namePArg , methodsArg , methodsCArg , methodsPCArg , methodsCPCArg , structureArg ) \
	jDeclareBaseInterface( nameArg , nameCArg , namePArg , methodsArg , methodsCArg , methodsPCArg , methodsCPCArg ) \
	jDefineBaseInterface( nameArg , nameCArg , structureArg )

#define jStandardBaseInterface( nameArg , structureArg ) \
	jDeclareStandardBaseInterface( nameArg ) \
	jDefineStandardBaseInterface( nameArg , structureArg )

#define jPrefixStandardBaseInterface( prefixArg , nameArg , structureArg ) \
	jDeclarePrefixStandardBaseInterface( prefixArg , nameArg ) \
	jDefinePrefixStandardBaseInterface( prefixArg , nameArg , structureArg )

#include "../jagry.h"

typedef JUnsignedInteger8 JInterfaceIdentifier ;

#define jBaseInterfaceIdentifier        ( ( JInterfaceIdentifier )0 )
#define jArrayInterfaceIdentifier       ( ( JInterfaceIdentifier )1 )
#define jSimpleArrayInterfaceIdentifier ( ( JInterfaceIdentifier )2 )
#define jSortArrayInterfaceIdentifier   ( ( JInterfaceIdentifier )3 )
#define jListInterfaceIdentifier        ( ( JInterfaceIdentifier )4 )
#define jSimpleListInterfaceIdentifier  ( ( JInterfaceIdentifier )5 )
#define jSortListInterfaceIdentifier    ( ( JInterfaceIdentifier )6 )
#define jSliceInterfaceIdentifier       ( ( JInterfaceIdentifier )7 )
#define jSimpleSliceInterfaceIdentifier ( ( JInterfaceIdentifier )8 )
#define jSortSliceInterfaceIdentifier   ( ( JInterfaceIdentifier )9 )

#endif