#include <jagry/test.h>
#include <stdio.h>
#include <stdlib.h>

JVoid jagryOutTest(
	JPTest testIn ,
	JPCTestResult resultIn ,
	JPCCharacter1 fileIn ,
	JUnsignedInteger lineIn ) {
printf( "error: " ) ;
resultIn->methods->write( testIn , resultIn->data ) ;
printf( jEndOfLine ) ;
//if( resultIn->methods->free ) resultIn->methods->free( testIn->data ) ;
while( testIn->stack )
	{
		JPTestStack stack = testIn->stack->next ;
		printf(
			"\t\t%s line %i in file %s\n" ,
			testIn->stack-> method ,
			testIn->stack->position.line ,
			testIn->stack->position.file ) ;
		if( testIn->stack != &testIn->internalMainStack &&
				testIn->stack != &testIn->internalNewStack )
			free( testIn->stack ) ;
		testIn->stack = stack ;
	}
}

JVoid simpleError( JPVoid in ) {
printf( "" ) ;
}

JVoid statusError( JPVoid in ) {
printf( "" ) ;
}