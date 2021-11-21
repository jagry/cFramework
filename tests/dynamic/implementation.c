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

static JUnsignedInteger acquireOwnerImplementationBase( JIBase self ) {
Implementation impl ;
JPByte debug0 = ( JPByte )( &( ( PDImplementation )( jNil ) )->b ) ;
JPByte debug1 = ( JPByte )( self.t ) ;
JPByte debug2 = debug1 - debug0 ;
JPByte debug3 = ( JPByte )( &( ( PDImplementation )( jNil ) )->b ) ;

impl.d = ( PDImplementation )( ( JPByte )( self.t ) - ( JPByte )( &( ( PDImplementation )( jNil ) )->b ) ) ;
return ++impl.d->r ;
}

static JStatus getOwnerImplementationInterface( Implementation self , JInterfaceIdentifier in , JPIBase out ) {
// !!!: определиться с вариантом реализации
JPByte debug4 = ( JPByte )self.d->b.t - ( JPByte )self.d ;
if( in == jBaseInterfaceIdentifier || in == ownerImplementationInterfaceIdentifier )
	/* !!! */ return *out = self.i.b , jAcquireBase( self.i ) , jSuccessBaseStatus ;
else
	// /* !!! */ return self.d->b.t ? jGetBaseInterface( ( self.d->owned ) , in , *out ) : jNoInterfaceErrorBaseStatus ;
	/* !!! */ return jGetBaseInterface( ( self.d->owned ) , in , *out ) ;
//return jNotImplementErrorBaseStatus ;
//return in == jBaseInterfaceIdentifier || in == ownerImplementationInterfaceIdentifier ?
//	( *out = self.i.b , jAcquireBase( *out ) , jSuccessBaseStatus ) :
//	self.d->owned.t ? jGetBaseInterface( ( self.d->owned ) , in , *out ) : jNoInterfaceErrorBaseStatus ;
}

static JStatus getOwnedImplementationInterface( Implementation self , JInterfaceIdentifier in , JPIBase out ) {
if( in == jBaseInterfaceIdentifier || in == ownedImplementationInterfaceIdentifier )
	/* !!! */ return *out = self.i.b , jAcquireBase( self.i ) , jSuccessBaseStatus ;
else
	/* !!! */ return jNoInterfaceErrorBaseStatus ;
}

/* !!! JCMDynamic dynamicImplementationMethods = {
	.acquire = jagryAcquireDynamicBase ,
	.getInterface = getOwnedImplementationBaseInterface ,
	.release = jNil } ;
JICMBase 
	baseImplementationMethods = { .acquire = acquireOwnerImplementationBase , .getInterface = getOwnedImplementationBaseInterface , .release = jNil } ; */
CMImplementation
	ownedImplementationMethods = { .acquire = jagryAcquireDynamicBase , .getInterface = getOwnedImplementationInterface , .release = jNil } ,
	ownerImplementationMethods = { .acquire = jagryAcquireDynamic , .getInterface = getOwnerImplementationInterface , .release = jNil } ;