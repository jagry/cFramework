#ifndef JagryArrayInterfece
#define JagryArrayInterfece

// declare self methods
#define jClearSimpleArray( self ) ( ( *( self )._ )->clear( self ) )
#define jEraseSimpleArrayItem( self , in ) \
	( ( *( self )._ )->eraseItem( self , in ) )
#define jGetSimpleArrayCount( self ) ( ( *( self )._ )->getCount( self ) )
#define jGetSimpleArrayFirst( self ) ( ( *( self )._ )->getFirst( self ) )
#define jGetSimpleArrayLast( self ) ( ( *( self )._ )->getLast( self ) )
#define jEraseSimpleArrayItem( self , in ) \
	( ( *( self )._ )->eraseItem( self , in ) )
#define jGetSimpleArrayValue( self , in , out ) \
	( ( *( self )._ )->getValue( self , in , out ) )
#define jInsertSimpleArrayItem( self , indexIn , valueIn , out ) \
	( ( *( self )._ )->insertItem( self , indexIn , valueIn , out ) )
#define jPopSimpleArrayBackwardValue( self , in , out ) \
	( ( *( self )._ )->popBackwardItem( self , in , out ) )
#define jPopSimpleArrayForwardValue( self , in , out ) \
	( ( *( self )._ )->popForwardItem( self , in , out ) )
#define jPushSimpleArrayBackward( self , in , out ) \
	( ( *( self )._ )->pushBackward( self , in , out ) )
#define jPushSimpleArrayForward( self , in , out ) \
	( ( *( self )._ )->pushForward( self , in , out ) )
#define jSetSimpleArrayItem( self , indexIn , valueIn , out ) \
	( ( *( self )._ )->setItem( self , indexIn , valueIn , out ) )

// declare self methods(item)
#define jAddSimpleArrayItemAfter( self , out ) \
	( ( *( self ) )->addAfter( self ) )
#define jAddSimpleArrayItemBefore( self , out ) \
	( ( *( self ) )->addBefore( self ) )
#define jFreeSimpleArrayItem( self ) ( ( *( self ) )->free( self ) )
#define jGetSimpleArrayItemNext( self ) \
	( ( *( self ) )->getNext( self ) )
#define jGetSimpleArrayItemNextFree( self ) \
	( ( *self )->getNextFree( self ) )
#define jGetSimpleArrayItemPrevious( self ) \
	( ( *( self ) )->getPrevious( self ) )
#define jgetSimpleArrayItemPreviousFree( self ) \
	( ( *( self ) )->methods->getPreviousFree( self ) )
#define jGetSimpleArrayItemValue( self , out ) \
	( ( *( self ) )->getValue( self , out ) )

// define methods
#define jClearSimpleArrayMethod( name , type ) JStatus( *name )( type )
#define jEraseSimpleArrayItemMethod( name , type ) JStatus( *name )( type , JOffset )
#define jGetSimpleArrayCountMethod( name , type ) JCounter( *name )( type )
#define jGetSimpleArrayStartItemMethod( name , type ) \
	JISimpleArrayItem( *name )( type )
#define jGetSimpleArrayItemByIndexMethod( name , type ) \
	JStatus( *name )( type , JUnsignedInteger , JPISimpleArrayItem )
#define jGetSimpleArrayValueMethod( name , type ) \
	JStatus( *name )( type , JUnsignedInteger , JPBuffer )
#define jInsertSimpleArrayItemMethod( name , type ) \
	JStatus( *name )( type , JUnsignedInteger , JPBuffer , JPISimpleArrayItem )
#define jPopSimpleArrayMethod( name , type ) \
	JStatus( *name )( type , JPBuffer )
#define jPushSimpleArrayMethod( name , type ) \
	JStatus( *name )( type , JCPCVoid , JPISimpleArrayItem )
#define jSetSimpleArrayItemMethod( name , type ) \
	JStatus( *setItem )( \
		type , JUnsignedInteger , JPBuffer , JPISimpleArrayItem )

// define methods(item)
#define jAddSimpleArrayItemMethod( name , type ) \
	JStatus( *name )( type , JPVoid , JPISimpleArrayItem ) ;
#define jFreeSimpleArrayItemMethod( name , type ) JVoid( *name )( type ) ;
#define jGetSimpleArrayItemMethod( name , type ) \
	JISimpleArrayItem( *name )( type ) ;
#define jGetSimpleArrayItemValueMethod( name , type ) \
	JStatus( *name )( type , JPVoid ) ;
#define jSetSimpleArrayItemValueMethod( name , type ) \
	JStatus( *name )( type , JCPCBuffer ) ;

// define method list(item)
#define jSelfSimpleArrayItemMethods( \
		addAfterArg , \
		addBeforeArg , \
		freeArg , \
		getNextArg , \
		getNextFreeArg , \
		getPreviousArg , \
		getPreviousFreeArg , \
		getValueArg , \
		setValueArg ) \
	jAddSimpleArrayItemMethod( addAfter , addAfterArg ) \
	jAddSimpleArrayItemMethod( addBefore , addBeforeArg ) \
	jFreeSimpleArrayItemMethod( free , freeArg ) \
	jGetSimpleArrayItemMethod( getNext , getNextArg ) \
	jGetSimpleArrayItemMethod( getNextFree , getNextFreeArg ) \
	jGetSimpleArrayItemMethod( getPrevious , getPreviousArg ) \
	jGetSimpleArrayItemMethod( getPreviousFree , getPreviousFreeArg ) \
	jGetSimpleArrayItemValueMethod( getValue , getValueArg ) \
	jSetSimpleArrayItemValueMethod( setValue , setValueArg )
#define jEachSimpleArrayItemMethods( \
		addAfterArg , \
		addBeforeArg , \
		freeArg , \
		getNextArg , \
		getNextFreeArg , \
		getPreviousArg , \
		getPreviousFreeArg , \
		getValueArg , \
		setValueArg ) \
	jSelfSimpleArrayItemMethods( \
		addAfterArg , \
		addBeforeArg , \
		freeArg , \
		getNextArg , \
		getNextFreeArg , \
		getPreviousArg , \
		getPreviousFreeArg , \
		getValueArg , \
		setValueArg )
#define jAllSimpleArrayItemMethods( argument ) \
	jEachSimpleArrayItemMethods( \
		argument , \
		argument , \
		argument , \
		argument , \
		argument , \
		argument , \
		argument , \
		argument , \
		argument )

// define nils
#define jISimpleArrayNil ( ( JISimpleArray ){ ._ = 0 } )
#define jISimpleArrayItemNil ( ( JISimpleArrayItem )0 )

// define status inherit
// !!! Надо наследоваться от base
#define jSuccessArrayStatus jSuccessStatus
#define jNoInterfaceArrayErrorStatus jNoInterfaceBaseErrorStatus
#define jNotEnoughtMemoryErrorArrayStatus jNotEnoughtMemoryErrorStatus

// define status self
#define jOffsetOutRangeErrorArrayResult ( -20 )

#include "base.i.h"
#include "buffer.i.h"

// declare inherit methods
#define jAcquireArray( self ) jAcquireBase( ( self ).super )
#define jGetArrayInterface( self , in , out ) \
	jGetBaseInterface( ( self ).super , in , out )
#define jReleaseArray( self ) jReleaseBase( ( self ).super )

// define method list
#define jSelfSimpleArrayMethods( \
		clearArg , \
		eraseItemArg , \
		getCountArg , \
		getFirstArg , \
		getItemArg , \
		getLastArg , \
		getValueArg , \
		insertItemArg , \
		popBackwardArg , \
		popForwardArg , \
		pushBackwardArg , \
		pushForwardArg , \
		setItemArg ) \
	jClearSimpleArrayMethod( clear , clearArg ) ; \
	jEraseSimpleArrayItemMethod( eraseItem , eraseItemArg ) ; \
	jGetSimpleArrayCountMethod( getCount , getCountArg ) ; \
	jGetSimpleArrayStartItemMethod( getFirst , getFirstArg ) ; \
	jGetSimpleArrayItemByIndexMethod( getItem , getItemArg ) ; \
	jGetSimpleArrayStartItemMethod( getLast , getLastArg ) ; \
	jGetSimpleArrayValueMethod( getValue , getValueArg ) ; \
	jInsertSimpleArrayItemMethod( insertItem , insertItemArg ) ; \
	jPopSimpleArrayMethod( popBackward , popBackwardArg ) ; \
	jPopSimpleArrayMethod( popForward , popForwardArg ) ; \
	jPushSimpleArrayMethod( pushBackward , pushBackwardArg ) ; \
	jPushSimpleArrayMethod( pushForward , pushForwardArg ) ; \
	jSetSimpleArrayItemMethod( setItem , setItemArg ) ;
#define jEachSimpleArrayMethods( \
		acquireArg , \
		getInterfaceArg , \
		releaseArg , \
		clearArg , \
		eraseItemArg , \
		getCountArg , \
		getFirstArg , \
		getItemArg , \
		getLastArg , \
		getValueArg , \
		insertItemArg , \
		popBackwardArg , \
		popForwardArg , \
		pushBackwardArg , \
		pushForwardArg , \
		setItemArg ) \
	jBaseEach( acquireArg , getInterfaceArg , releaseArg ) \
	jSelfSimpleArrayMethods( \
		clearArg , \
		eraseItemArg , \
		getCountArg , \
		getFirstArg , \
		getItemArg , \
		getLastArg , \
		getValueArg , \
		insertItemArg , \
		popBackwardArg , \
		popForwardArg , \
		pushBackwardArg , \
		pushForwardArg , \
		setItemArg )
#define jAllSimpleArrayMethods( argument ) \
	jEachSimpleArrayMethods( \
		argument , \
		argument , \
		argument , \
		argument , \
		argument , \
		argument , \
		argument , \
		argument , \
		argument , \
		argument , \
		argument , \
		argument , \
		argument , \
		argument , \
		argument , \
		argument )

jDeclarePrefixStandardBaseInterface( J , SimpleArrayItem )
jDeclarePrefixStandardChildInterface( J , SimpleArray )
jDefinePrefixStandardChildInterface(
	J ,
	SimpleArray ,
	jAllSimpleArrayMethods( JISimpleArray ) ,
	JIBase )
struct JMSimpleArrayItem { jAllSimpleArrayItemMethods( JISimpleArrayItem ) } ;

#endif