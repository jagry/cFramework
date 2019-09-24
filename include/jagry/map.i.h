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
#define jEachMapItem( erase , eraseNext , erasePrevious , getNext , getPrevious ) \
	jSelfMapItem( erase , eraseNext , erasePrevious , getNext , getPrevious )

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
#define jMapItemErase( self ) ( self )->methods->erase( self )
#define jMapItemEraseNext( self , out ) ( self )->methods->eraseNext( self , out )
#define jMapItemErasePrevious( self , out ) ( self )->methods->erasePrevious( self , out )
#define jMapItemGetNext( self , out ) ( self )->methods->getNext( self , out )
#define jMapItemGetPrevious( self , out ) ( self )->methods->getPrevious( self , out )

// define object mapItem pointers
#define jPMapItemErase( type ) JResult( *erase )( type* ) ;
#define jPMapItemEraseNext( type ) JResult( *eraseNext )( type* , JMapItem** ) ;
#define jPMapItemErasePrevious( type ) JResult( *erasePrevious )( type* , JMapItem** ) ;
#define jPMapItemGetNext( type ) JResult( *next )( type* , JMapItem** ) ;
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
#define jSelfMapItem( erase , eraseNext , erasePrevious , getNext , getPrevious ) \
	jPMapItemErase( getNext ) \
	jPMapItemEraseNext( getNext ) \
	jPMapItemErasePrevious( getPrevious ) \
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
#include "base.i.h"
#include "buffer.h"

// 0 typedef
typedef union JMap JMap ;
typedef struct JMapItem JMapItem ;
typedef union JMapMethods JMapMethods ;
typedef struct JMapItemMethods JMapItemMethods ;

// 1 interfce
jInterface( JMap , JBase , jBaseSupers , methods , jAllMap( JMap ) , JMapMethods , JBaseMethods , jBaseMethodsSupers )
//jInterface( JMapItem , JBase , jBaseSupers , methods , jAllMapItem( JMapItem ) , JMapItemMethods , JBaseMethods , jBaseMethodsSupers )

// 1 struct
struct JMapItemMethods {
	jAllMapItem( JMapItem ) } ;

// 1 typedef
typedef JMap * JIMap ;
typedef JMapItem * JPMapItem ;
typedef JMapItemMethods * JPMapItemMethods ;

// 2 struct
struct JMapItem {
	JPMapItemMethods methods ; } ;

// 2 typedef
typedef JIMap * JPIMap ;
typedef JPMapItem * JPPMapItem ;

#endif