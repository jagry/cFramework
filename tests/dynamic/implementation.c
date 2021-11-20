#include "implementation.h"
#include <jagry/dynamic.l.h>
#include <jagry/test.h>

typedef union { JTestNotEnoudhMemoryData _ ; } ImplementationStack ;

#define jGetImplementationOwner( _self_ , _type_ , _member_ ) \
	( _type_ )( ( JPByte )( _self_ ) - ( JPByte )( &( ( ( _type_ )* )( jNil ) )->_member_ ) )

static JStatus getOwnedImplementationBaseInterface( JIBase self , JInterfaceIdentifier in , JPIBase out ) {
Implementation impl ;
impl.d = ( PDImplementation )( ( JPByte )( self.t ) - ( JPByte )( &( ( PDImplementation )( jNil ) )->b ) ) ;
/* !!! */ return jNoInterfaceErrorBaseStatus ;
//return in == jBaseInterfaceIdentifier ?
//	( *out = self.i.b , jAcquireBase( *out ) , jSuccessBaseStatus ) :
//	in == ownerImplementationInterfaceIdentifier ? ( *out = self.i.b , jAcquireBase( *out ) , jSuccessBaseStatus ) : jNoInterfaceErrorBaseStatus ;
}

static JStatus getOwnerImplementationInterface( Implementation self , JInterfaceIdentifier in , JPIBase out ) {
// !!!: определиться с вариантом реализации
if( in == jBaseInterfaceIdentifier || in == ownerImplementationInterfaceIdentifier )
	/* !!! */ return *out = self.i.b , jAcquireBase( self.d->b ) , jSuccessBaseStatus ;
else
	/* !!! */ return self.d->b.t ? jGetBaseInterface( ( self.d->owned ) , in , *out ) : jNoInterfaceErrorBaseStatus ;
//return jNotImplementErrorBaseStatus ;
//return in == jBaseInterfaceIdentifier || in == ownerImplementationInterfaceIdentifier ?
//	( *out = self.i.b , jAcquireBase( *out ) , jSuccessBaseStatus ) :
//	self.d->owned.t ? jGetBaseInterface( ( self.d->owned ) , in , *out ) : jNoInterfaceErrorBaseStatus ;
}

static JStatus getOwnedImplementationInterface( Implementation self , JInterfaceIdentifier in , JPIBase out ) {
/* !!! */ return jNotImplementErrorBaseStatus ;
//return self.d->b.t ? jGetBaseInterface( ( self.d->owner ) , in , *out ) : getOwnedImplementationBaseInterface ( self , in , out) ;
}

JCMDynamic dynamicImplementationMethods = {
	.acquire = jagryAcquireDynamicBase ,
	.getInterface = getOwnedImplementationBaseInterface ,
	.release = jNil } ;
JICMBase 
	baseImplementationMethods = { .acquire = jagryAcquireDynamicBase , .getInterface = getOwnedImplementationBaseInterface , .release = jNil } ;
CMImplementation
	ownedImplementationMethods = { .acquire = jagryAcquireDynamic , .getInterface = getOwnedImplementationInterface , .release = jNil } ,
	ownerImplementationMethods = { .acquire = jagryAcquireDynamic , .getInterface = getOwnerImplementationInterface , .release = jNil } ;