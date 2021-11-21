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
#define jAcquireBase( self ) ( ( self ).t->m->acquire( self ) )
#define jGetBaseInterface( self , identifier , out ) ( ( self ).t->m->getInterface( self , identifier , &out ) )
#define jReleaseBase( self ) ( ( self ).t->m->release( self ) )

#define jSuccessBaseStatus jSuccessStatus
#define jNotEnoughtMemoryErrorBaseStatus jNotEnoughtMemoryErrorStatus

#define jBaseErrorLastStatus jNotImplementErrorBaseStatus
#define jBaseWarningLastStatus jWarningLastStatus

#define jNoInterfaceErrorBaseStatus  ( ( JStatus )( jErrorLastStatus - 1 ) )
#define jNotImplementErrorBaseStatus ( ( JStatus )( jErrorLastStatus - 2 ) )

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

union JIDBase { JICPCMBase m ; } ;
union JIBase { JIPDBase t ; } ;
struct JIMBase { jBaseAllMethods( JIBase ) } ;


#endif