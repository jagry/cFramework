#define jListMethod jExport

#include <jagry/array.i.h>
#include <jagry/dynamic.l.h>
#include <stdlib.h>

#include <jagry/list/manager.h>

#include "simple.h"

static JStatus clearSimpleList( USimpleList ) ;
//static JStatus eraseSimpleListItem( USimpleList , JOffset ) ;
static JSize getSimpleListCount( USimpleList ) ;
static JStatus getSimpleListInterface(
	USimpleList , JInterfaceIdentifier , JPIBase ) ;
static JISimpleArrayItem getSimpleListFirst( USimpleList ) ;
static JStatus getSimpleListItem( USimpleList , JOffset , JPISimpleArrayItem ) ;
static JISimpleArrayItem getSimpleListLast( USimpleList ) ;
static JStatus pushSimpleListBackward(
	USimpleList , JCPCVoid , JPISimpleArrayItem ) ;
static JStatus pushSimpleListForward(
	USimpleList , JCPCVoid , JPISimpleArrayItem ) ;
static JUnsignedInteger releaseSimpleList( USimpleList ) ;

static JStatus addSimpleListItemAfter(
	USimpleListItem , JPVoid , JPISimpleArrayItem ) ;
static JStatus addSimpleListItemBefore(
	USimpleListItem , JPVoid , JPISimpleArrayItem ) ;
static JVoid freeSimpleListItem( USimpleListItem ) ;
static JISimpleArrayItem getSimpleListItemNext( USimpleListItem ) ;
static JISimpleArrayItem getSimpleListItemPrevious( USimpleListItem ) ;
static JStatus getSimpleListItemValue( USimpleListItem , JPVoid ) ;

static CMSimpleList simpleList = {
	/* base */
		.acquire = jNil , // jagryAcquireDynamic ,
		.getInterface = jNil , // getSimpleListInterface ,
		.release = jNil , // releaseSimpleList ,
	/* simpleList */
		.clear = jNil , // clearSimpleList ,
		.getCount = jNil , // getSimpleListCount ,
		.getFirst = jNil , // getSimpleListFirst ,
		.getItem = jNil , // getSimpleListItem ,
		.getLast = jNil , // getSimpleListLast ,
		.pushBackward = jNil , // pushSimpleListBackward ,
		.pushForward = jNil } ; // pushSimpleListForward } ;
static CMSimpleListItem simpleListItem = {
	.addAfter = jNil , // addSimpleListItemAfter ,
	.addBefore = jNil , // addSimpleListItemBefore ,
	.free = jNil , // freeSimpleListItem ,
	.getNext = jNil , // getSimpleListItemNext ,
	.getPrevious = jNil , // getSimpleListItemPrevious ,
	.getValue = jNil } ; // getSimpleListItemValue } ;

static JUnsignedInteger simpleListChunk = 1 ;

JStatus clearSimpleList( USimpleList self ) {
JISimpleArrayItem nextItem ,
	item = self._->first.i ;
while( jISimpleArrayItemIsNotNil( item ) )
	nextItem = jGetSimpleArrayItemNext( item ) ,
	jFreeSimpleArrayItem( item ) ,
	item = nextItem ;
return jSuccessArrayStatus ;
}

/*JStatus eraseSimpleListItem(USimpleList self, JOffset in) {
JISimpleArrayItem item ;
JStatus status = getSimpleListItem( self , in , &item ) ;
if( jStatusIsNotError( status ) ) jFreeSimpleArrayItem( item ) ;
return status ;
}*/

JSize getSimpleListCount( USimpleList self ) {
return self._->count ;
}

JISimpleArrayItem getSimpleListFirst( USimpleList self ) {
return self._->first.i ;
}

JStatus getSimpleListItem(
	USimpleList self , JOffset in , JPISimpleArrayItem out ) {
if( in < 0 )
	{
		if( self._->count < ( JSize )-in )
			return jOffsetOutRangeErrorArrayResult ;
		*out = self._->last.i ;
		for( JSignedInteger counter = in ; ++counter ; )
			*out = jGetSimpleArrayItemPrevious( *out ) ;
	}
else
	{
		if( self._->count <= ( JSize )in )
			return jOffsetOutRangeErrorArrayResult ;
		*out = self._->first.i ;
		for( JSignedInteger counter = in ; counter ; --counter )
			*out = jGetSimpleArrayItemNext( *out ) ;
	}
return jSuccessArrayStatus ;
}

JISimpleArrayItem getSimpleListLast( USimpleList self ) {
return self._->last.i ;
}

JStatus getSimpleListInterface(
	USimpleList self , JInterfaceIdentifier in , JPIBase out ) {
switch( in ) {
case JArrayInterfaceIdentifier :
case JBaseInterfaceIdentifier :
case JSimpleArrayInterfaceIdentifier :
	( *( *out = self.i.base ) )->acquire( self.i.base ) ;
	return jSuccessArrayStatus ;
}
return jNoInterfaceArrayErrorStatus ;
}

JStatus jagrySimpleList( JCPCListManager in , JPISimpleList out ) {
jReturnIfNotAllocated( out->_ , SSimpleList )
jInitializeDynamic( out->_ , simpleList , 0 , 1 )
out->_->first = out->_->last = jUListArrayItemNil ;
out->_->manager = in ;
out->_->count = 0 ;
return jSuccessArrayStatus ;
}

JStatus pushSimpleListBackward(
	USimpleList self , JCPCVoid in , JPISimpleArrayItem out ) {
USimpleListItem item ; JStatus status ;
jReturnIfNotAllocated( item._ , SSimpleList )
status = self._->manager->set( self._->manager , item._ , in ) ;
if( jStatusIsError( status ) )
	return free( item._ ) , status ;
if( self._->count )
	( self._->first._->previous = item )._->next = self._->first ;
else
	( self._->last = item )._->next = jUListArrayItemNil ;
if( out )
	*out = item.i ;
++self._->count ;
item._->_ = &simpleListItem;
item._->previous = jUListArrayItemNil ;
self._->first = item ;
return jSuccessArrayStatus ;
}

JStatus pushSimpleListForward(
	USimpleList self , JCPCVoid in , JPISimpleArrayItem out ) {
USimpleListItem item ; JStatus status ;
jReturnIfNotAllocated( item._ , SSimpleListItem )
status = self._->manager->set( self._->manager, &item._->data, in) ;
if( jStatusIsError( status ) )
	return free( item._ ), status ;
if( self._->count )
	( self._->first._->previous = item )._->next = self._->first ;
else
	( self._->last = item )._->next = jUListArrayItemNil ;
if( out )
	*out = item.i ;
++self._->count ;
item._->_ = &simpleListItem ;
item._->owner = self._ ;
item._->previous = jUListArrayItemNil ;
self._->first = item ;
return jSuccessArrayStatus ;
}

JUnsignedInteger releaseSimpleList( USimpleList self ) {
USimpleListItem item ;
JUnsignedInteger references = --self._->references ;
if( !references )
	while( self._->last._ )
		item = self._->last , self._->last = item._->previous ,
		self._->manager->free( self._->manager , item._->data ) , free( item._ ) ;
return references ;
}

JStatus addSimpleListItemAfter(
	USimpleListItem self , JPVoid in , JPISimpleArrayItem out ) {
USimpleListItem item ;
jReturnIfNotAllocated( item._ , SSimpleListItem )
if( item._->next._ = self._->next._ ) item._->next._->previous = item ;
if( out ) *out = item.i ;
item._->owner = self._->owner ;
item._->previous = self ;
self._->next = item ;
return jSuccessArrayStatus ;
}

JStatus addSimpleListItemBefore(
	USimpleListItem self , JPVoid in , JPISimpleArrayItem out ) {
USimpleListItem item ;
jReturnIfNotAllocated( item._ , SSimpleListItem )
if( item._->previous._ = self._->previous._ ) item._->previous._->next = item ;
if( out ) *out = item.i ;
item._->owner = self._->owner ;
item._->next = self ;
self._->previous = item ;
return jSuccessArrayStatus ;
}

JVoid freeSimpleListItem( USimpleListItem self ) {
if( self._->next._ ) self._->next._->previous = self._->previous ;
else self._->owner->last = self._->previous ;
if( self._->previous._ ) self._->previous._->next = self._->next ;
else self._->owner->first = self._->next ;
self._->owner->manager->free( self._->owner->manager , self._->data ) ;
--self._->owner->count ;
free( self._ ) ;
}

JISimpleArrayItem getSimpleListItemNext( USimpleListItem self ) { return self._->next.i ; }

JISimpleArrayItem getSimpleListItemPrevious( USimpleListItem self ) { return self._->previous.i ; }

JStatus getSimpleListItemValue(USimpleListItem self, JPVoid out) {
return self._->owner->manager->get( self._->owner->manager , out , self._->data ) ;
}