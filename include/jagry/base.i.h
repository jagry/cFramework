#ifndef JagryBaseInterface
#define JagryBaseInterface

#define jAcquireBasePointer( type ) JCounter( *acquire )( type ) ;
#define jGetBaseInterfacePointer( type ) JStatus( *getInterface )( type , JInterfaceIdentifier , JPIBase ) ;
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

#define jNoInterfaceBaseErrorStatus ( jErrorStatusMask | ~( ( JInterfaceIdentifier )1 ) )


//jPrefixStdDeclareInterface( J , Base )

//typedef struct JMBase JMBase ;
//typedef JMBase const JCMBase ;
//typedef JCMBase * JPCMBase ;
//typedef JPCMBase const JCPCMBase ;
//typedef JCPCMBase * JIBase ;
//typedef JIBase * JPIBase ;

#include "interface.h"
#include "status.h"

jDeclarePrefixStandardBaseInterface( J , Base )
struct JMBase { jBaseAll( JIBase ) } ;
//struct JMBase { jBaseAll( JIBase ) } ;

//#define jNullInterface

#endif
