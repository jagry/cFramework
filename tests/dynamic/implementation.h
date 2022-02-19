#include <jagry/dynamic.i.h>
#include <jagry/implementation.h>

#define jGetOwner(_type_,_self_,_member_) ( ( _type_ )( ( JPByte )( ( _self_ ).this ) - ( JPByte )( &( ( PSDImplementation )jNil )->_member_ ) ) )
//#define getImplementationOwner(_self_) ( ( UImplementation ){ .this = jGetOwner( PSDImplementation  , _self_ , self ) } )
#define getImplementationOwner(_self_) jGetOwner( PSDImplementation  , _self_ , self )

#define implementationMembers jImplementationMembers( PCMImplementation , _ ) JIMBase base ; JIBase owned1 ; JUnsignedInteger value ;
#define implementationMethods( acuireArg , otherArg ) \
	jBaseEachMethods( acuireArg , otherArg , otherArg ) JUnsignedInteger( *owner )( otherArg , JUnsignedInteger ) ;
#define firstImplementationInterfaceIdentifier   ( ( JInterfaceIdentifier )1 )
#define middleImplementationInterfaceIdentifier  ( ( JInterfaceIdentifier )2 )
#define missingImplementationInterfaceIdentifier ( ( JInterfaceIdentifier )3 )
#define lastImplementationInterfaceIdentifier    ( ( JInterfaceIdentifier )4 )

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

union IDImplementation { ICPCMImplementation methods ; };
union IImplementation { JIBase base ; JIBase super ; IPDImplementation this ; } ;
struct IMImplementation { implementationMethods( IImplementation , IImplementation ) } ;

typedef union jUBase JUBase ;
typedef union jUDBase JUDBase ;
typedef JUBase * JPUBase ;
typedef JUDBase * JPUDBase ;
union jUBase { JIBase interface ; JPUDBase this ; JIPCMBase this1 ; } ;
union jUDBase { JIPCMBase methods ; };

typedef union uImplementation UImplementation ;
typedef struct sDImplementation SDImplementation ;
typedef struct sMImplementation SMImplementation ;

typedef UImplementation * PUImplementation ;
typedef SDImplementation * PSDImplementation ;
typedef SMImplementation const CSMImplementation ;

typedef PUImplementation * PPUImplementation ;
typedef CSMImplementation* PCSMImplementation;

struct sDImplementation {
	PCSMImplementation methods ; JIBase owner ; JUDBase self ; JUnsignedInteger references ; JIBase owned ; JUnsignedInteger value ; } ;

/* !!! Нужен define для определения методов JPCMDynamic
	что-то типа DynamicMethods( name , acuire , getInterface , release , type , member ) */
union uImplementation {
	JIBase base ;
	IImplementation iface ;
	JIBase super ;
	PSDImplementation this ; } ;
// !!! union ImplementationBase { PDImplementationBase d ; IImplementation i ; } ;
// !!! struct DImplementation { PCMImplementation m ; JIBase b ; JDBase d ; JUnsignedInteger r ; JIBase owned ; JUnsignedInteger value ; } ;
// !!! нужно сделать define для объявления *Base
struct sMImplementation { implementationMethods( JDynamic , UImplementation ) } ;

//typedef struct { Implementation _ ; ImplementationBase b ; } TestImplementation ;
//typedef TestImplementation * PTestImplementation ;
//typedef PTestImplementation * PPTestImplementation ;

extern JICMBase firstImplementationBaseMethods , lastImplementationBaseMethods , middleImplementationBaseMethods ;
extern CSMImplementation firstImplementationMethods , lastImplementationMethods , middleImplementationMethods ;