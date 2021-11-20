#ifndef JagryArrayInterfece
#define JagryArrayInterfece

// array interface
#define jSelfArrayMethods( clearArg , getCountArg , getFirstArg , getItemArg , getLastArg , itemArg ) \
	JVoid( *clear )( clearArg ) ; \
	JUnsignedInteger( *getCount )( getCountArg ) ; \
	itemArg( *getFirst )( getFirstArg ) ; \
	itemArg( *getItem )( getItemArg , JUnsignedInteger ) ; \
	itemArg( *getLast )( getLastArg ) ;
#define jEachArrayMethods( acquireArg , getInterfaceArg , releaseArg , clearArg , getCountArg , getFirstArg , getItemArg , getLastArg , itemArg ) \
	jBaseEachMethods( acquireArg , getInterfaceArg , releaseArg ) \
	jSelfArrayMethods( clearArg , getCountArg , getFirstArg , getItemArg , getLastArg , itemArg )
#define jAllArrayMethods( selfArg , itemArg ) \
	jEachArrayMethods( selfArg , selfArg , selfArg , selfArg , selfArg , selfArg , selfArg , selfArg , itemArg )

// arrayItem interface
#define jSelfArrayItemMethods( freeArg , getNextArg , getPreviousArg , getValueArg ) \
	JVoid( *free )( freeArg ) ; \
	getNextArg( *getNext )( getNextArg ) ; \
	getPreviousArg( *getPrevious )( getPreviousArg ) ; \
	getValueArg( *getValue )( getValueArg ) ;
#define jEachArrayItemMethods( freeArg  , getNextArg , getPreviousArg , getValueArg ) \
	jSelfArrayItemMethods( freeArg , getNextArg , getPreviousArg , getValueArg )
#define jAllArrayItemMethods( arg ) jEachArrayItemMethods( arg , arg , arg , arg )

// simpleArray interface
#define jSelfSimpleArrayMethods( insertArg , popBackwardArg , popForwardArg , pushBackwardArg , pushForwardArg , itemArg ) \
	JStatus( *insert )( insertArg  , JPVoid , itemArg ) ; \
	JStatus( *popBackward )( popBackwardArg , itemArg ) ; \
	JStatus( *popForward )( popForwardArg , itemArg ) ; \
	JStatus( *pushBackward )( pushBackwardArg , JPVoid , itemArg ) ; \
	JStatus( *pushForward )( pushForwardArg , JPVoid , itemArg ) ;
#define jEachSimpleArrayMethods( \
		acquireArg  , \
		getInterfaceArg  , \
		releaseArg , \
		clearArg , \
		getCountArg , \
		getFirstArg , \
		getItemArg , \
		getLastArg , \
		insertArg , \
		popBackwardArg , \
		popForwardArg , \
		pushBackwardArg , \
		pushForwardArg , \
		itemArg ) \
	jEachArrayMethods( acquireArg , getInterfaceArg , releaseArg , clearArg , getCountArg , getFirstArg , getItemArg , getLastArg , itemArg ) \
	jSelfSimpleArrayMethods( insertArg , popBackwardArg , popForwardArg , pushBackwardArg , pushForwardArg , itemArg )
#define jAllSimpleArrayMethods( selfArg , itemArg ) \
	jEachSimpleArrayMethods( \
		selfArg , \
		selfArg , \
		selfArg , \
		selfArg , \
		selfArg , \
		selfArg , \
		selfArg , \
		selfArg , \
		selfArg , \
		selfArg , \
		selfArg , \
		selfArg , \
		selfArg , \
		itemArg )

// simpleArrayItem interface
#define jSelfSimpleArrayItemMethods( addAfterArg , addBeforeArg , setValueArg ) \
	JStatus( *addAfter )( addAfterArg ) ; JStatus( *addBefore )( addBeforeArg ) ; JStatus( *setValue )( setValueArg ) ;
#define jEachSimpleArrayItemMethods( freeArg , getNextArg , getPreviousArg , getValueArg , addAfterArg , addBeforeArg , setValueArg ) \
	jEachArrayItemMethods( freeArg , getNextArg , getPreviousArg , getValueArg ) \
	jSelfSimpleArrayItemMethods( addAfterArg , addBeforeArg , setValueArg )
#define jAllSimpleArrayItemMethods( arg ) \
	jEachSimpleArrayItemMethods( arg , arg , arg , arg , arg , arg , arg )

// inherit methods: array , base
#define jAcquireArray( self ) jAcquireBase( ( self ).super )
#define jGetArrayInterface( self , in , out ) jGetBaseInterface( ( self ).super , in , out )
#define jReleaseArray( self ) jReleaseBase( ( self ).super )

// inherit methods: simpleArray , array
#define jClearSimpleArray( self ) jClearArray( self )
#define jEraseSimpleArrayItem( self , in ) jEraseArrayItem( self , in )
#define jGetSimpleArrayCount( self ) jGetArrayCount( self )
#define jGetSimpleArrayFirst( self ) jGetArrayFirst( self )
#define jGetSimpleArrayItem( self , in , out ) jGetArrayItem( self , in , out )
#define jGetSimpleArrayLast( self ) jGetArrayLast( self )
#define jGetSimpleValue( self , in , out ) jGetValue( self , in , out )

// inherit methods: simpleArray , base
#define jAcquireSimpleArray( self ) jAcquireArray( self )
#define jGetSimpleArrayInterface( self , in , out ) jGetArrayInterface( self , in , out )
#define jReleaseSimpleArray( self ) jReleaseArray( self )

// inherit methods: simpleArrayItem, arrayItem
#define jFreeSimpleArrayItem( self ) jFreeArrayItem( self )
#define jGetSimpleArrayItemNext( self ) jGetArrayItemNext( self )
#define jGetSimpleArrayItemPrevious( self ) jGetArrayItemPrevious( self )
#define jGetSimpleArrayItemValue( self , out ) jGetArrayItemValue( self , out )

// self methods: array
#define jClearArray( self ) ( ( *( self )._ )->clear( self ) )
#define jEraseArrayItem( self , in ) ( ( *( self )._ )->eraseItem( self , in ) )
#define jGetArrayCount( self ) ( ( *( self )._ )->getCount( self ) )
#define jGetArrayFirst( self ) ( ( *( self )._ )->getFirst( self ) )
#define jGetArrayItem( self , in , out ) ( ( *( self )._ )->getItem( self , in , out ) )
#define jGetArrayLast( self ) ( ( *( self )._ )->getLast( self ) )
#define jGetValue( self , in , out ) ( ( *( self )._ )->getValue( self , in , out ) )

// self methods: arrayItem
#define jFreeArrayItem( self ) ( ( *( ( self )._ ) )->free( self ) )
#define jGetArrayItemNext( self ) ( ( *( ( self )._ ) )->getNext( self ) )
#define jGetArrayItemPrevious( self ) ( ( *( ( self )._ ) )->getPrevious( self ) )
#define jGetArrayItemValue( self , out ) ( ( *( ( self )._ ) )->getValue( self , out ) )

// self methods: simpleArray
#define jInsertSimpleArrayItem( self , indexIn , valueIn , out ) ( ( *( self )._ )->insertItem( self , indexIn , valueIn , out ) )
#define jPopSimpleArrayBackward( self , in , out ) ( ( *( self )._ )->popBackwardItem( self , in , out ) )
#define jPopSimpleArrayForward( self , in , out ) ( ( *( self )._ )->popForwardItem( self , in , out ) )
#define jPushSimpleArrayBackward( self , in , out ) ( ( *( self )._ )->pushBackward( self , in , out ) )
#define jPushSimpleArrayForward( self , in , out ) ( ( *( self )._ )->pushForward( self , in , out ) )
//#define jSetSimpleArrayItemValue( self , in ) ( ( *( self )._ )->setValue( self , in ) )

// self methods: simpleArrayItem
#define jAddSimpleArrayItemAfter( self , out ) ( ( *( self ) )->addAfter( self ) )
#define jAddSimpleArrayItemBefore( self , out ) ( ( *( self ) )->addBefore( self ) )
#define jSetSimpleArrayItemValue( self , in ) ( ( *( self ) )->getValue( self , in ) )

// nil
#define jIArrayNil ( ( JIArray ){ ._ = jNil } )
#define jIArrayItemNil ( ( JIArrayItem )jNil )
#define jISimpleArrayNil ( ( JISimpleArray ){ ._ = jNil } )
#define jISimpleArrayItemIsNil( arg ) ( ( arg )._ == jNil )
#define jISimpleArrayItemIsNotNil( arg ) ( ( arg ) != jNil )

// status inherit
#define jSuccessArrayStatus jSuccessBaseStatus
#define jNoInterfaceArrayErrorStatus jNoInterfaceErrorBaseStatus
#define jNotEnoughtMemoryErrorArrayStatus jNotEnoughtMemoryErrorBaseStatus

// status self
#define jOffsetOutRangeErrorArrayResult ( -20 )

#include "base.i.h"

jDeclarePrefixStandardBaseInterface( J , ArrayItem )
jDeclarePrefixStandardChildInterface( J , Array )
jDeclarePrefixStandardChildInterface( J , SimpleArray )
jDeclarePrefixStandardChildInterface( J , SimpleArrayItem )

struct JMArrayItem { jAllArrayItemMethods( JIArrayItem ) } ;
jDefinePrefixStandardBaseInterface( J , ArrayItem , jAllArrayItemMethods( JIArrayItem ) )
jDefinePrefixStandardChildInterface( J , Array , jAllArrayMethods( JIArray , JIArrayItem ) , JIBase , JIBase )
jDefinePrefixStandardChildInterface( J , SimpleArray , jAllSimpleArrayMethods( JISimpleArray , JISimpleArrayItem ) , JIBase , JIArray )
jDefinePrefixStandardChildInterface( J , SimpleArrayItem , jAllSimpleArrayItemMethods( JISimpleArrayItem ) , JIArrayItem , JIArrayItem )

#endif