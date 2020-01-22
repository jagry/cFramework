#ifndef JagryMapInterfece
#define JagryMapInterfece

// define all
#define jAllMap( type ) jEachMap( type , type , type , type , \
	type , type , type , type , type , type , type , type , type )
#define jAllMapItem( type ) jEachMapItem( type , \
	type , type , type , type , type , type , type )

// define each
#define jEachMap( acquire , getInterface , release , \
		addItem , clear , eraseItem , getFirstItem , \
		getLastItem , getItem , getItemValue , newItem , putItem , setItem ) \
	jBaseEach( acquire , getInterface , release ) \
	jSelfMap( addItem , clear , eraseItem , getFirstItem , \
		getLastItem , getItem , getItemValue , newItem , putItem , setItem )
#define jEachMapItem( free , freeNext , freePrevious , \
		getKey , getNext , getPrevious , getValue , setValue ) \
	jSelfMapItem( free , freeNext , freePrevious , \
		getKey , getNext , getPrevious , getValue , setValue )

// define object map inherit methods
#define jAcquireMap( self ) jAcquireBase( ( self ).super )
#define jGetMapInterface( self , in , out ) \
	jGetBaseInterface( ( self ).super , in , out )
#define jReleaseMap( self ) jReleaseBase( ( self ).super )

// define object map self method
#define jAddMapItem( self , keyIn , valueIn , out ) \
	( ( self ).data->methods->addItem( self , keyIn , valueIn , out ) )
#define jClearMap( self ) ( ( self ).data->methods->clear( self ) )
#define jEraseMapItem( self , in ) \
	( ( self ).data->methods->eraseItem( self , in ) )
#define jGetFirstMapItem( self , out ) \
	( ( self ).data->methods->getFirstItem( self , out ) )
#define jGetLastMapItem( self , out ) \
	( ( self ).data->methods->getLastItem( self , out ) )
#define jGetMapItem( self , in , out ) \
	( ( self ).data->methods->getItem( self , in , out ) )
#define jGetMapValue( self , in , out ) \
	( ( self ).data->methods->getValue( self , in , out ) )
#define jNewMapItem( self , keyIn , valueIn , out ) \
	( ( self ).data->methods->newItem( self , keyIn , valueIn , out ) )
#define jPutMapItem( self , keyIn , valueIn , out ) \
	( ( self ).data->methods->putItem( self , keyIn , valueIn , out ) )
#define jSetMapItem( self , keyIn , valueIn , out ) \
	( ( self ).data->methods->setItem( self , keyIn , valueIn , out ) )

// define object map pointers
#define jAddMapItemDeclare( type ) \
	JResult( *addItem )( type , JCPCBuffer , JCPCBuffer , JPIMapItem ) ;
#define jClearMapDeclare( type ) JResult( *clear )( type ) ;
#define jEraseMapItemDeclare( type ) JResult( *eraseItem )( type , JBuffer ) ;
#define jGetFirstMapItemDeclare( type ) \
	JResult( *getFirstItem )( type , JPIMapItem ) ;
#define jGetLastMapItemDeclare( type ) \
	JResult( *getLastItem )( type , JPIMapItem ) ;
#define jGetMapItemDeclare( type ) \
	JResult( *getItem )( type , JCBuffer , JPIMapItem ) ;
#define jGetMapValueDeclare( type ) \
	JResult( *getValue )( type , JCBuffer , JPBuffer ) ;
#define jNewMapItemDeclare( type ) \
	JResult( *newItem )( type , JCPCBuffer , JCPCBuffer , JPIMapItem ) ;
#define jPutMapItemDeclare( type ) \
	JResult( *putItem )( type , JCPCBuffer , JCPCBuffer , JPIMapItem ) ;
#define jSetMapItemDeclare( type ) \
	JResult( *setItem )( type , JCPCBuffer , JCPCBuffer , JPIMapItem ) ;

// define object mapItem methods
#define jDeleteMapItem( self ) ( ( self )->methods->free( self ) )
#define jDeleteMapItemAndNext( self , out ) \
	( ( self )->methods->freeAndNext( self , out ) )
#define jDeleteMapItemAndPrevious( self , out ) \
	( ( self )->methods->freeAndPrevious( self , out ) )
#define jGetMapItemNext( self , out ) \
	( ( self )->methods->getNext( self , out ) )
#define jGetMapItemPrevious( self , out ) \
	( ( self )->methods->getPrevious( self , out ) )

// define object mapItem pointers
#define jFreeMapItemDeclare( type ) JResult( *free )( type ) ;
#define jFreeMapItemNextDeclare( type ) \
	JResult( *freeNext )( type , JPIMapItem ) ;
#define jFreeMapItemPreviousDeclare( type ) \
	JResult( *freePrevious )( type* , JPIMapItem ) ;
#define jGetMapItemKeyDeclare( type ) JResult( *getKey )( type , JPIMapItem ) ;
#define jGetMapItemNextDeclare( type ) \
	JResult( *getNext )( type , JPIMapItem ) ;
#define jGetMapItemPreviousDeclare( type ) \
	JResult( *getPprevious )( type , JPIMapItem ) ;
#define jGetMapItemValueDeclare( type ) \
	JResult( *getValue )( type , JPBuffer ) ;
#define jSetMapItemValueDeclare( type ) \
	JResult( *setValue )( type , JCPCBuffer ) ;

// define self
#define jSelfMap( addItem , clear , eraseItem , getFirstItem , \
		getLastItem , getItem , getItemValue , newItem , putItem , setItem ) \
	jAddMapItemDeclare( addItem ) \
	jClearMapDeclare( clear ) \
	jEraseMapItemDeclare( eraseItem ) \
	jGetFirstMapItemDeclare( getFirstItem ) \
	jGetLastMapItemDeclare( getLastItem ) \
	jGetMapItemDeclare( getItem ) \
	jGetMapValueDeclare( getItemValue ) \
	jNewMapItemDeclare( newItem ) \
	jPutMapItemDeclare( putItem ) \
	jSetMapItemDeclare( setItem )
#define jSelfMapItem( free , freeNext , freePrevious , \
		getKey , getNext , getPrevious , getValue , setValue ) \
	jFreeMapItemDeclare( free ) \
	jFreeMapItemNextDeclare( freeNext ) \
	jFreeMapItemPreviousDeclare( freePrevious ) \
	jGetMapItemKeyDeclare( getKey ) \
	jGetMapItemNextDeclare( getNext ) \
	jGetMapItemPreviousDeclare( getPrevious ) \
	jGetMapItemValueDeclare( getValue ) \
	jSetMapItemValueDeclare( setValue )

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

#include "base.i.h"
#include "buffer.h"
		
jPrefixType( J , DMapItem , struct JDMapItem ) ;
jPrefixType( J , IMapItem , struct JIMapItem ) ;
jPrefixType( J , MMapItem , struct JMMapItem ) ;

jPrefixStdDeclareInterface( J , Map )
jPrefixStdDefineInterface( J , Map , jAllMap( JIMap ) , JIBase )

struct JDMapItem { JCPCMMapItem methods ; }	;
struct JIMapItem { JPDMapItem data ; } ;
struct JMMapItem { jAllMapItem( JIMapItem ) } ;

#define jIMapNil ( JIMap ){ .data = 0 }
#define jIMapItemNil ( JIMapItem ){ .data = 0 }

#endif