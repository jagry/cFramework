#ifndef JagryArrayInterfece
#define JagryArrayInterfece

// define all
#define jAllArray( self , item ) jEachArray( self , \
	self , self , self , self , self , self , self , self , \
	self , self , self , self , self , self , self , item )
#define jAllArrayItem( type ) jEachArrayItem( type , \
	type , type , type , type , type , type , type )

// define each
#define jEachArray( acquire , getInterface , release , clear , eraseItem , \
		getCount , getFirst , getLast , getItem , getValue , insertItem , \
		popBackward , popForward , pushBackward , pushForward , setItem , item ) \
	jBaseEach( acquire , getInterface , release ) \
	jSelfArray( clear , eraseItem , getCount , getFirst , getLast , \
		getItem , getValue , insertItem , popBackward , \
		popForward , pushBackward , pushForward , setItem , item )
#define jEachArrayItem( free , freeNext , freePrevious , \
		getKey , getNext , getPrevious , getValue , setValue ) \
	jSelfArrayItem( free , freeNext , freePrevious , \
		getKey , getNext , getPrevious , getValue , setValue )

// define object map inherit methods
#define jAcquireArray( self ) jAcquireBase( ( self ).super )
#define jGetArrayInterface( self , in , out ) \
	jGetBaseInterface( ( self ).super , in , out )
#define jReleaseArray( self ) jReleaseBase( ( self ).super )

// define object map self method
#define jClearArray( self ) ( ( self ).data->methods->clear( self ) )
#define jEraseArrayItem( self , in ) \
	( ( self ).data->methods->eraseItem( self , in ) )
#define jGetArrayCount( self ) \
	( ( self ).data->methods->getCount( self ) )
#define jGetFirstArrayItem( self , out ) \
	( ( self ).data->methods->getFirstItem( self , out ) )
#define jGetLastArrayItem( self , out ) \
	( ( self ).data->methods->getLastItem( self , out ) )
#define jGetArrayItem( self , in , out ) \
	( ( self ).data->methods->getItem( self , in , out ) )
#define jGetArrayValue( self , in , out ) \
	( ( self ).data->methods->getValue( self , in , out ) )
#define jInsertArrayItem( self , indexIn , valueIn , out ) \
	( ( self ).data->methods->insertItem( self , indexIn , valueIn , out ) )
#define jPopArrayBackwardValue( self , in , out ) \
	( ( self ).data->methods->popBackwardItem( self , in , out ) )
#define jPopArrayForwardValue( self , in , out ) \
	( ( self ).data->methods->popForwardItem( self , in , out ) )
#define jPushArrayBackwardItem( self , indexIn , valueIn , out ) \
	( ( self ).data->methods->pushBackwardItem( self , indexIn , valueIn , out ) )
#define jPushArrayForwardItem( self , indexIn , valueIn , out ) \
	( ( self ).data->methods->pushForwardItem( self , indexIn , valueIn , out ) )
#define jSetArrayItem( self , indexIn , valueIn , out ) \
	( ( self ).data->methods->setItem( self , indexIn , valueIn , out ) )

// define object map pointers
#define jAddArrayItemDeclare( type ) \
	JResult( *addItem )( type , JCPCBuffer , JCPCBuffer , JPIMapItem ) ;
#define jClearArrayDeclare( type ) JResult( *clear )( type ) ;
#define jEraseArrayItemDeclare( type ) JResult( *eraseItem )( type , JBuffer ) ;
#define jGetArrayCountDeclare( type ) JCounter( *getCount )( type ) ;
#define jGetArrayFirstDeclare( type , item ) \
	JResult( *getFirst )( type , item ) ;
#define jGetArrayLastDeclare( type , item ) \
	JResult( *getLast )( type , item ) ;
#define jGetArrayItemDeclare( type , item ) \
	JResult( *getItem )( type , JUnsignedInteger , item ) ;
#define jGetArrayValueDeclare( type ) \
	JResult( *getValue )( type , JUnsignedInteger , JPBuffer ) ;
#define jInsertArrayItemDeclare( type , item ) \
	JResult( *insertItem )( type , JUnsignedInteger , JPBuffer , item ) ;
#define jPopArrayBackwardDeclare( type ) \
	JResult( *popBackward )( type , JPBuffer ) ;
#define jPopArrayForwardDeclare( type ) \
	JResult( *popForward )( type , JPBuffer ) ;
#define jPushArrayBackwardDeclare( type , item ) \
	JResult( *pushBackward )( type , JCPCVoid , item ) ;
#define jPushArrayForwardDeclare( type , item ) \
	JResult( *pushForward )( type , JCPCVoid , item ) ;
#define jSetArrayItemDeclare( type , item ) \
	JResult( *setItem )( type , JUnsignedInteger , JPBuffer , item ) ;

// define object mapItem methods
#define jDeleteArrayItem( self ) ( ( self )->methods->free( self ) )
#define jDeleteArrayItemAndNext( self , out ) \
	( ( self )->methods->freeAndNext( self , out ) )
#define jDeleteArrayItemAndPrevious( self , out ) \
	( ( self )->methods->freeAndPrevious( self , out ) )
#define jGetNextArrayItem( self , out ) \
	( ( self )->methods->getNext( self , out ) )
#define jGetPreviousArrayItem( self , out ) \
	( ( self )->methods->getPrevious( self , out ) )

// define object mapItem pointers
#define jFreeMapItemDeclare( type ) JResult( *free )( type ) ;
#define jFreeMapItemNextDeclare( type ) \
	JResult( *freeNext )( type , JPIArrayItem ) ;
#define jFreeMapItemPreviousDeclare( type ) \
	JResult( *freePrevious )( type* , JPIArrayItem ) ;
#define jGetMapItemKeyDeclare( type ) \
	JResult( *getKey )( type , JPIArrayItem ) ;
#define jGetMapItemNextDeclare( type ) \
	JResult( *getNext )( type , JPIArrayItem ) ;
#define jGetMapItemPreviousDeclare( type ) \
	JResult( *getPprevious )( type , JPIArrayItem ) ;
#define jGetMapItemValueDeclare( type ) \
	JResult( *getValue )( type , JPBuffer ) ;
#define jSetMapItemValueDeclare( type ) \
	JResult( *setValue )( type , JCPCBuffer ) ;

// define self
#define jSelfArray( clear , eraseItem , getCount , getFirst , \
		getLast , getItem , getValue , insertItem , popBackward , \
		popForward , pushBackward , pushForward , setItem , item ) \
	jClearArrayDeclare( clear ) \
	jEraseArrayItemDeclare( eraseItem ) \
	jGetArrayCountDeclare( getCount ) \
	jGetArrayFirstDeclare( getFirst , item ) \
	jGetArrayLastDeclare( getLast , item ) \
	jGetArrayItemDeclare( getItem , item ) \
	jGetArrayValueDeclare( getValue ) \
	jInsertArrayItemDeclare( insertItem , item ) \
	jPopArrayBackwardDeclare( popBackward ) \
	jPopArrayForwardDeclare( popForward ) \
	jPushArrayBackwardDeclare( pushBackward , item ) \
	jPushArrayForwardDeclare( pushForward , item ) \
	jSetArrayItemDeclare( setItem , item )
#define jSelfArrayItem( free , freeNext , freePrevious , \
		getKey , getNext , getPrevious , getValue , setValue ) \
	jFreeMapItemDeclare( free ) \
	jFreeMapItemNextDeclare( freeNext ) \
	jFreeMapItemPreviousDeclare( freePrevious ) \
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
#define jSuccessArrayResult jSuccessResult
#define jNotEnoughtMemoryErrorArrayResult jNotEnoughtMemoryErrorResult

// define supers
#define jSupersMap JMap map ; jBaseSupers
#define jSupersMapMethods JMapMethods map ; jBaseMethodsSupers

#include "base.i.h"
#include "buffer.h"
		
jPrefixType( J , DArrayItem , struct JDArrayItem ) ;
jPrefixType( J , IArrayItem , struct JIArrayItem ) ;
jPrefixType( J , MArrayItem , struct JMArrayItem ) ;

jPrefixStdDeclareInterface( J , Array )

typedef struct JArrayManager JArrayManager ;

typedef JArrayManager const JCArrayManager ;

typedef JCArrayManager * JPCArrayManager ;

typedef JPCArrayManager const JCPCArrayManager ;

typedef JResult JArrayManagerFree( JCPCArrayManager , JPVoid ) ; 
typedef JResult JArrayManagerGet( JCPCArrayManager , JPVoid , JPVoid ) ; 
typedef JResult JArrayManagerSet( JCPCArrayManager , JPVoid , JPVoid ) ; 

typedef JArrayManagerFree * JPArrayManagerFree ; 
typedef JArrayManagerGet * JPArrayManagerGet ; 
typedef JArrayManagerSet * JPArrayManagerSet ; 

jPrefixStdDefineInterface( J , Array , jAllArray( JIArray , JPIArrayItem ) , JIBase )

struct JDArrayItem { JCPCMArrayItem methods ; }	;
struct JIArrayItem { JPDArrayItem data ; } ;
struct JMArrayItem { jAllArrayItem( JIArrayItem ) } ;

struct JArrayManager {
	JPArrayManagerFree free ;
	JPArrayManagerGet get ;
	JPArrayManagerSet set ;
	int size ; } ;

#define jIArrayNil ( ( JIArray ){ .data = 0 } )
#define jIArrayItemNil ( ( JIArrayItem ){ .data = 0 } )

#endif