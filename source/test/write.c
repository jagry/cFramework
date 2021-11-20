#include <stdio.h>
#include "write.h"

static JVoid writeTestError( JPTest testIn , JPCTestResult resultIn ) ;

JVoid jagryWriteTestResult( JPTest testIn , JPCTestResult resultIn ) {
if( resultIn->methods ) writeTestError( testIn , resultIn ) ; else printf( writeSucces ) ;
}

JVoid writeAlreadyHasErrorTestResult( JPTest testIn , JPCVoid dataIn ) { printf( "already has error" ) ; }

JVoid writeEmptyTestResult( JPTest testIn , JPCVoid dataIn ) {}

JVoid writeInvalidStackTestResult( JPTest testIn , JPCVoid dataIn ) { printf( "invalid stack" ) ; }

JVoid writeNotEnoughMemoryTestResult( JPTest testIn , JPCVoid dataIn ) {
printf( "not enough memory(size(bytes): %i)" , ( ( JPCTestNotEnoudhMemoryData )dataIn )->size ) ;
}

JVoid writeNotInitializeDataTestResult( JPTest testIn , JPCVoid dataIn ) {
printf( "not initialize stack data(size(bytes): %i)" , testIn->internalSize ) ;
}

JVoid writeNotInitializeStackTestResult( JPTest testIn , JPCVoid dataIn ) { printf( "not initialize stack" ) ; }

JVoid writeStatusTestResult( JPTest testIn , JPCVoid dataIn ) {
printf( "method returned %i(%Xh)" , ( ( JPCTestStatusData )dataIn )->code , ( ( JPCTestStatusData )dataIn )->code ) ;
}

JVoid writeTestError( JPTest testIn , JPCTestResult resultIn ) {
printf( "error: " ) ;
resultIn->methods->write( testIn , resultIn->data ) ;
printf( jEndOfLine ) ;
while( testIn->stack )
	{
		JPTestStack stack = testIn->stack->next ;
		printf(
			"\t\t%s line %i in file %s\n" ,
			testIn->stack->method ,
			testIn->stack->position.line ,
			testIn->stack->position.file ) ;
		if( testIn->stack != &testIn->internalMainStack &&
				testIn->stack != &testIn->internalNewStack )
			free( testIn->stack ) ;
		testIn->stack = stack ;
	}
}

JVoid writeTestResult( JPTest testIn , JPCTestResult resultIn ) {
if( resultIn->methods )
	{
		writeTestError( testIn , resultIn ) ;
		if( resultIn->methods->free ) resultIn->methods->free( resultIn->data ) ;
	}
else
	printf( writeSucces ) ;
}