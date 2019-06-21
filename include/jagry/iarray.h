#ifndef JagryArrayInterfece
#define JagryArrayInterfece


#define jArraySuccessResult jSuccessResult
#define jNotEnoughtMemoryArrayErrorResult jNotEnoughtMemoryErrorResult

#define jAddArrayPointer( type ) JResult( *add )( type* , JPCBuffer ) ;
#define jEraseArrayPointer( type ) JResult( *erase )( type* , JBuffer , JPBuffer ) ;

#define jMapSupers JMap map ; jBaseSupers
#define jMapMethodsSupers JMapMethods map ; jBaseMethodsSupers

#define jMapSelf( add , erase ) \
	jAddMapPointer( add ) \
	jEraseMapPointer( erase )

#define jMapEach( acquire , dump , getInterface , release , add , erase ) \
	jBaseEach( acquire , dump , getInterface , release ) \
	jMapSelf( add , erase )

#define jMapAll( type ) jMapEach( type , type , type , type , type , type )

typedef union JMap JMap ;
typedef union JMapMethods JMapMethods ;

typedef union JMap *JIMap ;

#include "buffer.h"
#include "ibase.h"

/*typedef union jMap jMap ;
typedef union jMapMethods jMapMethods ;

union jMap {
	jMapMethods* methods ;
	jBase super ;
	struct { jBaseSupers } supers ;
} ;

union jMapMethods {
	struct {
		jMapAllMethods( jMap ) ;
	} ;
	struct { jBaseMethodsSupers } supers ;
	jBaseMethods super ;
} ;*/

jInterface( JMap , JBase , jBaseSupers , methods , jMapAll( JMap ) , JMapMethods , JBaseMethods , jBaseMethodsSupers )

#define jAcquireMap( argument ) jAcquireBase( argument )
#define jDumpMap( argument ) jDumpBase( argument )
#define jGetMapInterface( self , in , out ) jGetBaseInterface( self , in , out )
#define jReleaseMap( argument ) jReleaseBase( argument )

#define jAddMap( self , keyIn , valueIn , out ) ( self )->methods->add( ( self ) , ( keyIn ) , ( valueIn ) , ( out ) )
#define jEraseMap( self , in , out ) ( self )->methods->erase( ( self ) , ( in ) , ( out ) )

#endif