#ifndef JagryImplementation
#define JagryImplementation

#define jDeclareImplementation( interfaceArg , interfacePArg , methodsArg , methodsCArg , methodsPCArg , methodsCPCArg , dataArg , dataPArg ) \
	typedef union interfaceArg interfaceArg ; \
	typedef interfaceArg * interfacePArg ; \
	typedef struct methodsArg methodsArg ; \
	typedef methodsArg const methodsCArg ; \
	typedef methodsCArg * methodsPCArg ; \
	typedef methodsPCArg const methodsCPCArg ; \
	typedef struct dataArg dataArg ; \
	typedef dataArg * dataPArg ;

#define jDeclarePrefixStandardImplementation( prefixArg , nameArg ) \
	jDeclareImplementation( \
		prefixArg##nameArg , \
		prefixArg##P##nameArg , \
		prefixArg##M##nameArg , \
		prefixArg##CM##nameArg , \
		prefixArg##PCM##nameArg , \
		prefixArg##CPCM##nameArg , \
		prefixArg##D##nameArg , \
		prefixArg##PD##nameArg )

#define jDeclareStandardImplementation( nameArg ) \
	jDeclareImplementation( nameArg , P##nameArg , M##nameArg , CM##nameArg , PCM##nameArg , CPCM##nameArg , D##nameArg , PD##nameArg )

#define jDefineImplementation( \
		typeArg , \
		dataNameArg , \
		dataTypeArg , \
		dataTypePArg , \
		dataStructureArg , \
		methodsTypeArg , \
		methodsStructureArg , \
		interfaceNameArg , \
		interfaceTypeArg ) \
	union typeArg { dataTypePArg dataNameArg ; interfaceTypeArg interfaceNameArg ; } ; \
	struct dataTypeArg { dataStructureArg } ; \
	struct methodsTypeArg { methodsStructureArg } ;

#define jDefinePrefixStandardImplementation( prefixArg , nameArg , dataArg , methodsArg , interfaceArg ) \
	jDefineImplementation( \
		prefixArg##nameArg , _ , prefixArg##D##nameArg , prefixArg##PD##nameArg , dataArg , prefixArg##M##nameArg , methodsArg , i , interfaceArg )

#define jDefineStandardImplementation( nameArg , dataArg , methodsArg , interfaceArg ) \
	jDefineImplementation( nameArg , _ , D##nameArg , PD##nameArg , dataArg , M##nameArg , methodsArg , i , interfaceArg )

#endif