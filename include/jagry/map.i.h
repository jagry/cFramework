#ifndef JagryMapInterfece
#define JagryMapInterfece

// define all
#define jMapAll( self ) jMapEach( self , self , self , self , \
	self , self , self , self , self , self , self , self , self )
#define jAllMapItem( arg ) \
	jEachMapItem( arg , arg , arg , arg , arg , arg , arg , arg )

// define each
#define jMapEach( acquire , getInterface , release , \
		addItem , clear , eraseItem , getFirst , getLast , \
		getItem , getItemValue , newItem , putItem , setItem ) \
	jBaseEach( acquire , getInterface , release ) \
	jMapSelf( addItem , clear , eraseItem , getFirst , getLast , \
		getItem , getItemValue , newItem , putItem , setItem )
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
	( ( *( self )._ )->addItem( self , keyIn , valueIn , out ) )
#define jClearMap( self ) ( ( self ).data->methods->clear( self ) )
#define jEraseMapItem( self , in ) ( ( *( self )._ )->eraseItem( self , in ) )
#define jGetFirstMapItem( self , out ) \
	( ( *( self )._ )->getFirstItem( self , out ) )
#define jGetLastMapItem( self , out ) \
	( ( *( self )._ )->getLastItem( self , out ) )
#define jGetMapItem( self , in , out ) \
	( ( *( self )._ )->getItem( self , in , out ) )
#define jGetMapValue( self , in , out ) \
	( ( *( self )._ )->getValue( self , in , out ) )
#define jNewMapItem( self , keyIn , valueIn , out ) \
	( ( *( self )._ )->newItem( self , keyIn , valueIn , out ) )
#define jPutMapItem( self , keyIn , valueIn , out ) \
	( ( *( self )._ )->putItem( self , keyIn , valueIn , out ) )
#define jSetMapItem( self , keyIn , valueIn , out ) \
	( ( *( self )._ )->setItem( self , keyIn , valueIn , out ) )

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
	JResult( *freeNext )( type , JPIBufferMapItem ) ;
#define jFreeMapItemPreviousDeclare( type ) \
	JResult( *freePrevious )( type* , JPIBufferMapItem ) ;
#define jGetMapItemKeyDeclare( type ) JResult( *getKey )( type , JPBuffer ) ;
#define jGetMapItemNextDeclare( type ) \
	JResult( *getNext )( type , JPIBufferMapItem ) ;
#define jGetMapItemPreviousDeclare( type ) \
	JResult( *getPprevious )( type , JPIBufferMapItem ) ;
#define jGetMapItemValueDeclare( type ) \
	JResult( *getValue )( type , JPVoid ) ;
#define jSetMapItemValueDeclare( type ) \
	JResult( *setValue )( type , JCPCBuffer ) ;

// define self
#define jMapSelf( addItemArg , clearArg , eraseItemArg , \
		getFirstArg , getLastArg , getItemArg , \
		getValueArg , newItemArg , putItemArg , setItemArg ) \
	JResult( *addItem )( addItemArg , JCPCVoid , JCPCVoid , JPIMapItem ) ; \
	JResult( *clear )( clearArg ) ; \
	JResult( *eraseItem )( eraseItemArg , JCPCVoid ) ; \
	JResult( *getFirst )( getFirstArg , JPIMapItem ) ; \
	JResult( *getLast )( getLastArg , JPIMapItem ) ; \
	JResult( *getItem )( getItemArg , JCPCVoid , JPIMapItem ) ; \
	JResult( *getValue )( getValueArg , JCPCVoid , JPVoid ) ; \
	JResult( *newItem )( newItemArg , JCPCVoid , JCPCVoid , JPIMapItem ) ; \
	JResult( *putItem )( putItemArg , JCPCVoid , JCPCVoid , JPIMapItem ) ; \
	JResult( *setItem )( setItemArg , JCPCVoid , JCPCVoid , JPIMapItem ) ;
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

// define self status
#define jEmptyErrorMapResult -20
#define jItemAlreadyExistsErrorMapResult -21
#define jValueNotFoundErrorMapResult -22
#define jEmptyWarningMapResult 20
#define jValueAlreadyExistsWarningMapResult 21

// define super status
#define jSuccessMapResult jSuccessResult
#define jNotEnoughtMemoryErrorMapResult jNotEnoughtMemoryErrorResult

#include "base.i.h"

typedef union JIMapItem * JIMapItem ;

typedef JIMapItem * JPIMapItem ;

jPrefixStdDeclareInterface( J , Map )
jPrefixStdDefineInterface( J , Map , jMapAll( JIMap ) , JIBase )

#endif