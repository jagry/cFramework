#include <jagry/dynamic.i.h>
#include <jagry/implementation.h>

#define implementationMembers jImplementationMembers( PCMImplementation , _ ) JIMBase base ; JIBase owned1 ; JUnsignedInteger value ;
#define implementationMethods( acuireArg , otherArg ) \
	jBaseEachMethods( acuireArg , otherArg , otherArg ) JUnsignedInteger( *owner )( otherArg , JUnsignedInteger ) ;
#define ownedImplementationInterfaceIdentifier   ( ( JInterfaceIdentifier )1 )
#define ownerImplementationInterfaceIdentifier   ( ( JInterfaceIdentifier )2 )
#define missingImplementationInterfaceIdentifier ( ( JInterfaceIdentifier )3 )

//jDeclareStandardChildInterface( Implementation )
//jDefineStandardChildInterface( Implementation , implementationMethods( IImplementation , IImplementation ) , JIBase , JIBase )
//jDeclareStandardImplementation( Implementation )
//jDefineStandardImplementation( Implementation , implementationMembers , implementationMethods( JImplementation , Implementation ) , IImplementation )

typedef struct IMImplementation IMImplementation ; \
typedef IMImplementation const ICMImplementation ; \
typedef ICMImplementation * IPCMImplementation ; \
typedef IPCMImplementation const ICPCMImplementation ; \
typedef union IDImplementation IDImplementation ; \
typedef IDImplementation * IPDImplementation ; \
typedef union IImplementation IImplementation ; \
typedef IImplementation * PIImplementation ;

union IDImplementation { ICPCMImplementation m ; };
union IImplementation { JIBase b ; JIBase s ; IPDImplementation t ; } ;
struct IMImplementation { implementationMethods( IImplementation , IImplementation ) } ;

typedef struct MImplementation MImplementation ; \
typedef MImplementation const CMImplementation ; \
typedef CMImplementation * PCMImplementation ; \
typedef struct DImplementation DImplementation; \
typedef DImplementation * PDImplementation; \
typedef union Implementation Implementation ;
typedef Implementation * PImplementation ;

typedef PImplementation * PPImplementation ;

/* !!! Нужен define для определения методов JPCMDynamic
	что-то типа DynamicMethods( name , acuire , getInterface , release , type , member ) */
struct DImplementation { PCMImplementation m ; JIBase b ; /* JIBase owner ; */ JUnsignedInteger r ; JIBase owned ; JUnsignedInteger value ; } ;
union Implementation { PDImplementation d ; IImplementation i ; } ;
struct MImplementation { implementationMethods( JDynamic , Implementation ) } ;

typedef struct { DImplementation _ ; JIDBase i ; JIDBase d ; JIPCMBase m ; } * ImplementationBase ;

extern JICMBase baseImplementationMethods ;
extern CMImplementation ownedImplementationMethods , ownerImplementationMethods ;