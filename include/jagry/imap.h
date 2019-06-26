#ifndef JagryMapInterfece
#define JagryMapInterfece

// define all
#define jAllMap( type ) jEachMap( type , type , type , type , type , type , type , type , type , type , type )
#define jAllMapItem( type ) jEachMapItem( type , type , type , type , type )

// define each
#define jEachMap( acquire , getInterface , release , addItem , clear , eraseItem , eraseItemNext , \
		eraseItemPrevious , getFirstItem , getItem , getLastItem ) \
	jBaseEach( acquire , getInterface , release ) \
	jSelfMap( addItem , clear , eraseItem , eraseItemNext , eraseItemPrevious , getFirstItem , getItem , \
		getLastItem )
#define jEachMapItem( acquire , getInterface , release , getNext , getPrevious ) \
	jBaseEach( acquire , getInterface , release ) \
	jSelfMapItem( getNext , getPrevious )

// define object map inherit methods
#define jMapAcquire( argument ) jAcquireBase( argument )
#define jMapGetInterface( self , in , out ) jGetBaseInterface( self , in , out )
#define jMapRelease( argument ) jReleaseBase( argument )

// define object map pointers
#define jPMapAddItem( type ) JResult( *addItem )( type* , JBuffer , JBuffer , JPBuffer ) ;
#define jPMapClear( type ) JResult( *clear )( type* ) ;
#define jPMapEraseItem( type ) JResult( *eraseItem )( type* , JBuffer ) ;
#define jPMapEraseItemNext( type ) JResult( *eraseItemNext )( type* , JBuffer , JMapItem** ) ;
#define jPMapEraseItemPrevious( type ) JResult( *eraseItemPrevious )( type* , JBuffer , JMapItem** ) ;
#define jPMapGetFirstItem( type ) JResult( *getFirstItem )( type* , JMapItem** ) ;
#define jPMapGetLastItem( type ) JResult( *getLastItem )( type* , JMapItem** ) ;
#define jPMapGetItem( type ) JResult( *getItem )( type* , JCBuffer , JMapItem** ) ;

// define object map self method
#define jMapAddItem( self , keyIn , valueIn , out ) ( self )->methods->addItem( self , keyIn , valueIn , out )
#define jMapClear( self ) ( self )->methods->clear( self )
#define jMapEraseItem( self , in ) ( self )->methods->eraseItem( self , in )
#define jMapEraseItemNext( self , in , out ) ( self )->methods->eraseItem( self , in , out )
#define jMapEraseItemPrevious( self , in , out ) ( self )->methods->eraseItem( self , in , out )
#define jMapGetFirstItem( self , out ) ( self )->methods->getFirstItem( self , out )
#define jMapGetItem( self , in , out ) ( self )->methods->getItem( self , in , out )
#define jMapGetLastItem( self , out ) ( self )->methods->getLastItem( self , out )

// define object mapItem methods
#define jMapItemErase( self ) ( self )->methods->addItem( self )
#define jMapItemEraseNext( self , out ) ( self )->methods->addItem( self , out )
#define jMapItemErasePrevious( self , out ) ( self )->methods->addItem( self , out )
#define jMapItemGetNext( self , out ) ( self )->methods->addItem( self , out )
#define jMapItemGetParent( self , out ) ( self )->methods->addItem( self , out )
#define jMapItemGetPrevious( self , out ) ( self )->methods->addItem( self , out )

// define object mapItem pointers
#define jPMapItemErase( type ) JResult( *erase )( type* ) ;
#define jPMapItemEraseNext( type ) JResult( *eraseNext )( type* , JMapItem** ) ;
#define jPMapItemErasePrevious( type ) JResult( *erasePrevious )( type* , JMapItem** ) ;
#define jPMapItemGetNext( type ) JResult( *next )( type* , JMapItem** ) ;
#define jPMapItemGetParent( type ) JResult( *parent )( type* , JMapItem** ) ;
#define jPMapItemGetPrevious( type ) JResult( *previous )( type* , JMapItem** ) ;

// define self
#define jSelfMap( addItem , clear , eraseItem , eraseItemNext , eraseItemPrevious , getFirstItem , getItem , getLastItem ) \
	jPMapAddItem( addItem ) \
	jPMapClear( clear ) \
	jPMapEraseItem( eraseItem ) \
	jPMapEraseItemNext( eraseItemNext ) \
	jPMapEraseItemPrevious( eraseItemPrevious ) \
	jPMapGetFirstItem( getFirstItem ) \
	jPMapGetItem( getItem ) \
	jPMapGetLastItem( getLastItem )
#define jSelfMapItem( getNext , getPrevious ) \
	jPMapItemGetNext( getNext ) \
	jPMapItemGetPrevious( getPrevious )

// define status
#define jEmptyErrorMapResult -20
#define jValueNotFoundErrorMapResult -21
#define jEmptyWarningMapResult 20
#define jValueAlreadyExistsWarningMapResult 21

// define status base
#define jSuccessMapResult jSuccessResult
#define jNotEnoughtMemoryErrorMapResult jNotEnoughtMemoryErrorResult

// define supers
#define jSupersMap JMap map ; jBaseSupers
#define jSupersMapMethods JMapMethods map ; jBaseMethodsSupers

// 0 include
#include "buffer.h"
#include "ibase.h"

// 0 typedef
typedef union JMap JMap ;
typedef union JMapItem JMapItem ;
typedef union JMapMethods JMapMethods ;
typedef union JMapItemMethods JMapItemMethods ;

// 1 interfce
jInterface( JMap , JBase , jBaseSupers , methods , jAllMap( JMap ) , JMapMethods , JBaseMethods , jBaseMethodsSupers )
jInterface( JMapIten , JBase , jBaseSupers , methods , jAllMapItem( JMapItem ) , JMapItemMethods , JBaseMethods , jBaseMethodsSupers )

// 2 typedef
typedef JMap * JIMap ;
typedef JMapItem * JPMapItem ;

// 3 typedef
typedef JIMap * JPIMap ;
typedef JPMapItem * JPPMapItem ;

#endif