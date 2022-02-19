#ifndef JagryBaseInterface
#define JagryBaseInterface

// base interface
#define jBaseSelfMethods( acquireArg , getInterfaceArg , releaseArg ) \
	JCounter( *acquire )( acquireArg ) ; \
	JStatus( *getInterface )( getInterfaceArg , JInterfaceIdentifier , JPIBase ) ; \
	JCounter( *release )( releaseArg ) ;
#define jBaseEachMethods( acquireArg , getInterfaceArg , releaseArg ) jBaseSelfMethods( acquireArg , getInterfaceArg , releaseArg )
#define jBaseAllMethods( typeArg ) jBaseEachMethods( typeArg , typeArg , typeArg )

// base self methods
#define jAcquireBase( self ) _Generic( self , JIBase : ( ( self ).this->methods->acquire( self ) ) )
#define jGetBaseInterface( self , in , out ) \
	_Generic( self , JIBase :  _Generic( in , JInterfaceIdentifier : _Generic( out , JIBase : ( ( self ).this->methods->getInterface( self , in , &out ) ) ) ) )
#define jReleaseBase( self ) _Generic( self , JIBase : ( ( self ).this->methods->release( self ) ) )

#define jSuccessBaseStatus jSuccessStatus
#define jNotEnoughtMemoryErrorBaseStatus jNotEnoughtMemoryErrorStatus

#define jBaseErrorLastStatus jNotImplementErrorBaseStatus
#define jBaseWarningLastStatus jWarningLastStatus

#define jNoInterfaceErrorBaseStatus  ( ( JStatus )( jErrorLastStatus - 1 ) )
#define jNotImplementErrorBaseStatus ( ( JStatus )( jErrorLastStatus - 2 ) )

#define jBaseNil ( ( JIBase ){ .this = jNil } )

#include "interface.h"
#include "status.h"

//jPrefixStandardBaseInterface( J , Base , jBaseAllMethods( JIBase ) )
typedef struct JIMBase JIMBase ; \
typedef JIMBase const JICMBase ; \
typedef JICMBase * JIPCMBase ; \
typedef JIPCMBase const JICPCMBase ; \
typedef union JIDBase JIDBase ; \
typedef JIDBase * JIPDBase ; \
typedef union JIBase JIBase ; \
typedef JIBase * JPIBase ;

union JIDBase { JICPCMBase methods ; } ;
union JIBase { JIPDBase this ; } ;
struct JIMBase { jBaseAllMethods( JIBase ) } ;


#endif