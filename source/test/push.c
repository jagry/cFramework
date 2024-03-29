#include "methods.h"
#include <stdlib.h>

JTestResult jagryPushTest( JPTest self , JSize sizeIn , JPCCharacter1 fileIn , JUnsignedInteger lineIn , JPCCharacter1 methodIn , JPPTestStack out ) {
if( self->stack == &self->internalNewStack ) return *out = self->stack , jTestResult( jNil , &alreadyHasErrorTestMethods ) ;
self->internalNewStack.first = self->internalNewStack.last = jNil ;
self->internalNewStack.method = methodIn ;
self->internalNewStack.position.file = fileIn ;
self->internalNewStack.position.line = lineIn ;
self->internalNewStack.next = self->stack ;
self->stack = &self->internalNewStack ;
if( !sizeIn ) self->internalNewStack.data = jNil ;
else
	if( !( self->internalNewStack.data = malloc( sizeIn ) ) )
		return *out = self->stack , self->internalSize = sizeof( sizeIn ) , jTestResult( jNil , &notInitializeDataTestMethods ) ;
if( !( *out = malloc( sizeof( **out ) ) ) )
	return
		free( self->internalNewStack.data ) ,
		self->internalNewStack.data = jNil ,
		self->internalSize = sizeof( **out ) ,
		jTestResult( &self->internalSize , &notInitializeStackTestMethods ) ;
**out = self->internalNewStack ;
self->stack = *out ;
self->internalNewStack.data = jNil ;
return jTestResult( jNil , jNil ) ;
}

JTestResult jagryPushTestLoop( JPTest self , JCounter counterIn , JPCCharacter1 fileIn , JUnsignedInteger lineIn , JPCCharacter1 methodIn , JPPTestStack out ) {

//self->stack->iteration
//return jTestResult( jNil , jNil ) ;
}