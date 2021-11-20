//#include <stdio.h>
//#include "test.h"
//
//static JVoid writeTestAlreadyHasError( JPTest , JPCVoid ) ;
//static JVoid writeTestInvalidStack( JPTest , JPCVoid ) ;
//static JVoid writeTestNotInitalizeAllocate( JPTest , JPCVoid ) ;
//static JVoid writeTestNotAllocate( JPTest , JPCVoid ) ;
//static JVoid writeTestNotInitalizeStack( JPTest , JPCVoid ) ;
//
//static JCTestMethods
//	testAlreadyHasError = {
//		.free = jNil ,
//		.write = writeTestAlreadyHasError } ,
//	testDataStatus = {
//		.free = jNil ,
//		.write = jNil } ,
//	testInvalidStack = {
//		.free = jNil ,
//		.write = writeTestInvalidStack } ,
//	testNotAllocate = {
//		.free = jNil ,
//		.write = writeTestNotAllocate } ,
//	testNotInitalizeAllocate = {
//		.free = jNil ,
//		.write = writeTestNotInitalizeAllocate } ,
//	testNotInitalizeStack = {
//		.free = jNil ,
//		.write = writeTestNotInitalizeStack } ;
//
//JVoid jagryFreeTest( JPVoid in ) {
//free( in ) ;
//}
//
//JPCTestMethods jagryGetTestDataAllocate( JVoid ) {
//return &testNotInitalizeAllocate ;
//}
//
//JTestResult jagryPopTest(
//	JPTest self ,
//	JPTestStack stackIn ,
//	JPCCharacter1 fileIn ,
//	JUnsignedInteger lineIn ) {
//// Did ned __FILE__ and __LINE__
//if( self->stack != stackIn )
//	return
//		self->internalStack = self->stack ,
//		self->stack = stackIn ,
//		jTestResult( jNil , &testInvalidStack ) ;
//self->internalStack = self->stack->next ;
//if( self->stack->data ) free( self->stack ->data ) ;
//if( self->stack != &self->internalMainStack &&
//		self->stack != &self->internalNewStack )
//	free( self->stack ) ;
//self->stack = self->internalStack ;
//return jTestResult( jNil , jNil ) ;
//}
//
//JTestResult jagryPushTest(
//	JPTest self ,
//	JSize sizeIn ,
//	JPCCharacter1 fileIn ,
//	JUnsignedInteger lineIn ,
//	JPCCharacter1 methodIn ,
//	JPPTestStack out ) {
//if( self->stack == &self->internalNewStack )
//	return jTestResult( jNil , &testAlreadyHasError ) ;
//self->internalNewStack.data = jNil ;
//self->internalNewStack.method = methodIn ;
//self->internalNewStack.next = self->stack ;
//self->internalNewStack.position.file = fileIn ;
//self->internalNewStack.position.line = lineIn ;
//self->stack = &self->internalNewStack ;
//if( !sizeIn )
//	self->internalNewStack.data = jNil ;
//else
//	if( !( self->internalNewStack.data = malloc( sizeIn ) ) )
//		return
//			self->internalSize = sizeof( sizeIn ) ,
//			jTestResult( jNil , &testNotInitalizeAllocate ) ;
//if( *out = malloc( sizeof( **out ) ) )
//	**out = self->internalNewStack , self->stack = *out ;
//else
//	return
//		free( self->internalNewStack.data ) ,
//		self->internalNewStack.data = jNil ,
//		self->internalSize = sizeof( **out ) ,
//		jTestResult( &self->internalSize , &testNotInitalizeStack ) ;
////out->owner = self , out->position = &self->stack->position ;
//return jTestResult( jNil , jNil ) ;
//}
//
//
//
//JVoid writeTestAlreadyHasError( JPTest testIn , JPVoid resultIn ) {
//printf( "push: already has error" ) ;
//}
//
//JVoid jagryWriteTestDataNotEnoughMemory( JPTest testIn , JPCVoid dataIn ) {
//printf(
//	"method returned %i(%Xh)" ,
//	( ( JPCTestDataStatusError )dataIn )->code ,
//	( ( JPCTestDataStatusError )dataIn )->code ) ;
//}
//
//JVoid jagryWriteTestDataStatus( JPTest testIn , JPCVoid dataIn ) {
//printf(
//	"method returned %i(%Xh)" ,
//	( ( JPCTestDataStatusError )dataIn )->code ,
//	( ( JPCTestDataStatusError )dataIn )->code ) ;
//}
//
//JVoid writeTestInvalidStack( JPTest testIn , JPCVoid dataIn ) {
//printf( "pop: invalid stack" ) ;
//while( testIn->internalStack && testIn->internalStack != testIn->stack )
//	{
//		JPTestStack stack = testIn->internalStack->next ;
//		printf(
//			"\n\t\t\t( file %s, line %i)" ,
//			testIn->internalStack->position.file ,
//			testIn->internalStack->position.line ) ;
//		if( testIn->internalStack != &testIn->internalMainStack &&
//				testIn->internalStack != &testIn->internalNewStack )
//			{
//				if( testIn->internalStack->data )
//					free( testIn->internalStack->data ) ;
//				free( testIn->internalStack ) ;
//			}
//		testIn->internalStack = stack ;
//	}
//}
//
//JVoid writeTestNotInitalizeAllocate( JPTest testIn , JPVoid dataIn ) {
//printf(
//	"push: cann't allocate memory for data(size in bytes: %i)" ,
//	testIn->internalSize ) ;
//}
//
//JVoid writeTestNotAllocate( JPTest testIn , JPVoid dataIn ) {
//printf(
//	"push: cann't allocate memory for data(size in bytes: %i)" ,
//	testIn->internalSize ) ;
//}
//
//JVoid writeTestNotInitalizeStack( JPTest testIn , JPVoid dataIn ) {
//printf(
//	"push: cann't allocate memory for stack(size in bytes: %i)" ,
//	testIn->internalSize ) ;
//}