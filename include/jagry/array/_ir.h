#ifdef _RELEASE

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
#define jClearSimpleArray( self ) jClearArray( ( self ).super )
#define jEraseSimpleArrayItem( self , in ) jEraseArrayItem( ( self ).super , in )
#define jGetSimpleArrayCount( self ) jGetArrayCount( ( self ).super )
#define jGetSimpleArrayFirst( self ) jGetArrayFirst( ( self ).super )
#define jGetSimpleArrayItem( self , in , out ) jGetArrayItem( ( self ).super , in , out )
#define jGetSimpleArrayLast( self ) jGetArrayLast( ( self ).super )
#define jGetSimpleValue( self , in , out ) jGetValue( ( self ).super , in , out )

// inherit methods: simpleArray , base
#define jAcquireSimpleArray( self ) jAcquireArray( ( self ).super )
#define jGetSimpleArrayInterface( self , in , out ) jGetArrayInterface( ( self ).super , in , out )
#define jReleaseSimpleArray( self ) jReleaseArray( ( self ).super )

// inherit methods: simpleArrayItem, arrayItem
#define jFreeSimpleArrayItem( self ) jFreeArrayItem( ( self ).super )
#define jGetSimpleArrayItemNext( self ) jGetArrayItemNext( ( self ).super )
#define jGetSimpleArrayItemPrevious( self ) jGetArrayItemPrevious( ( self ).super )
#define jGetSimpleArrayItemValue( self , out ) jGetArrayItemValue( ( self ).super , out )

// self methods: array
#define jClearArray( self ) ( ( *( self )._ )->clear( self ) )
#define jEraseArrayItem( self , in ) ( ( *( self )._ )->eraseItem( self , in ) )
#define jGetArrayCount( self ) ( ( *( self )._ )->getCount( self ) )
#define jGetArrayFirst( self ) ( ( *( self )._ )->getFirst( self ) )
#define jGetArrayItem( self , in , out ) ( ( *( self )._ )->getItem( self , in , out ) )
#define jGetArrayLast( self ) ( ( *( self )._ )->getLast( self ) )
#define jGetValue( self , in , out ) ( ( *( self )._ )->getValue( self , in , out ) )

// self methods: arrayItem
#define jFreeArrayItem( self ) ( ( *( self ) )->free( self ) )
#define jGetArrayItemNext( self ) ( ( *( self ) )->getNext( self ) )
#define jGetArrayItemPrevious( self ) ( ( *( self ) )->getPrevious( self ) )
#define jGetArrayItemValue( self , out ) ( ( *( self ) )->getValue( self , out ) )

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
#define jISimpleArrayItemIsNotNil( arg ) ( ( arg )._ != jNil )

// status inherit
#define jSuccessArrayStatus jSuccessBaseStatus
#define jNoInterfaceArrayErrorStatus jNoInterfaceErrorBaseStatus
#define jNotEnoughtMemoryErrorArrayStatus jNotEnoughtMemoryErrorBaseStatus

// status self
#define jOffsetOutRangeErrorArrayResult ( -20 )

#include "base.i.h"

jDeclarePrefixStandardChildInterface( J , Array )
jDeclarePrefixStandardBaseInterface( J , ArrayItem )
jDeclarePrefixStandardChildInterface( J , SimpleArray )
jDeclarePrefixStandardChildInterface( J , SimpleArrayItem )

jDefinePrefixStandardChildInterface( J , SimpleArrayItem , jAllSimpleArrayItemMethods( JISimpleArrayItem ) , JIArrayItem , JIArrayItem )
jDefinePrefixStandardBaseInterface( J , ArrayItem , jAllArrayItemMethods( JIArrayItem ) )
jDefinePrefixStandardChildInterface( J , Array , jAllArrayMethods( JIArray , JIArrayItem ) , JIBase , JIBase )
jDefinePrefixStandardChildInterface( J , SimpleArray , jAllSimpleArrayMethods( JISimpleArray , JIArrayItem ) , JIBase , JIArray )

#endif