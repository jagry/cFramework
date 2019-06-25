#ifndef JagryMapInterfece
#define JagryMapInterfece


#define jSuccessMapResult jSuccessResult
#define jNotEnoughtMemoryErrorMapResult jNotEnoughtMemoryErrorResult

#define jEmptyErrorMapResult -20
#define jValueNotFoundErrorMapResult -21
#define jEmptyWarningMapResult 20
#define jValueAlreadyExistsWarningMapResult 21

#define jAddMapItemPointer( type ) JResult( *addItem )( type* , JBuffer , JBuffer , JPBuffer ) ;
#define jClearMapPointer( type ) JResult( *clear )( type* ) ;
#define jEraseMapItemPointer( type ) JResult( *eraseItem )( type* , JBuffer , JPBuffer ) ;
#define jGetLastMapItemPointer( type ) JResult( *getLastItem )( type* , JMapItem** ) ;
#define jGetMapItemPointer( type ) JResult( *getLastItem )( type* , JCBuffer , JMapItem** ) ;

#define jGetMapItemNextPointer( type ) JResult( *eraseItem )( type* , JBuffer , JPBuffer ) ;
#define jGetMapItemPreviousPointer( type ) JResult( *getLastItem )( type* , JMapItem** ) ;

#define jMapSupers JMap map ; jBaseSupers
#define jMapMethodsSupers JMapMethods map ; jBaseMethodsSupers

#define jMapSelf( addItem , clear , eraseItem , getLastItem , getItem ) \
	jAddMapItemPointer( addItem ) \
	jClearMapPointer( clear ) \
	jEraseMapItemPointer( eraseItem ) \
	jGetLastMapItemPointer( getLastItem )
	jGetMapItemPointer( getItem )

#define jMapEach( acquire , getInterface , release , addItem , clear , eraseItem , getLastItem , getItem) \
	jBaseEach( acquire , getInterface , release ) \
	jMapSelf( addItem , clear , eraseItem , getLastItem , getItem )

#define jMapAll( type ) jMapEach( type , type , type , type , type , type , type )

#define jMapItemSelf( getNext , getPrevious ) \
	jGetMapItemNextPointer( getNext ) \
	jGetMapItemPreviousPointer( getPrevious )

#define jMapItemEach( acquire , getInterface , release , getNext , getPrevious ) \
	jBaseEach( acquire , getInterface , release ) \
	jMapItemSelf( getNext , getPrevious )

#define jMapItemAll( type ) jMapItemEach( type , type , type , type , type )

typedef union JMap *JIMap ;
typedef union JMapItem *JIMapItem ;
typedef union JMap JMap ;
typedef union JMapItem JMapItem ;
typedef union JMapMethods JMapMethods ;
typedef union JMapItemMethods JMapItemMethods ;


#include "buffer.h"
#include "ibase.h"

jInterface( JMap , JBase , jBaseSupers , methods , jMapAll( JMap ) , JMapMethods , JBaseMethods , jBaseMethodsSupers )
jInterface( JMapIten , JBase , jBaseSupers , methods , jMapItemAll( JMapItem ) , JMapItemMethods , JBaseMethods , jBaseMethodsSupers )

#define jAcquireMap( argument ) jAcquireBase( argument )
#define jGetMapInterface( self , in , out ) jGetBaseInterface( self , in , out )
#define jReleaseMap( argument ) jReleaseBase( argument )

#define jAddMapItem( self , key , value , out ) ( self )->methods->addItem( self , key , value , out )
#define jClearMap( self ) ( self )->methods->clear( self )
#define jEraseMapItem( self , in , out ) ( self )->methods->eraseItem( self , in , out )
#define jGetLastMapItem( self , out ) ( self )->methods->getLastItem( self , out )
#define jGetMapItem( self , in , out ) ( self )->methods->getItem( self , in , out )

#endif