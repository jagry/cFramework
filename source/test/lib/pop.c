#include "methods.h"

JTestResult jagryPopTest( JPTest self , JPTestStack stackIn ) {
if( self->stack != stackIn )
	return
		self->internalStack = self->stack ,
		self->stack = stackIn ,
		jTestResult( jNil , &invalidStackTestMethods ) ;
self->internalStack = self->stack->next ;
if( self->stack->data ) free( self->stack ->data ) ;
if( self->stack != &self->internalMainStack &&
		self->stack != &self->internalNewStack )
	free( self->stack ) ;
self->stack = self->internalStack ;
return jTestResult( jNil , jNil ) ;
}