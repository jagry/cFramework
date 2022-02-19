#define jTestMethod jStaticExport

#define writeSuccess ( "success" jEndOfLine )

#include "../../detail/test.h"
#include <stdio.h>
#include <stdlib.h>

typedef JTextTestData const JCTextTestData;
typedef JCTextTestData * JPCTextTestData ;

static JVoid writeTestError( JPTest testIn , JPCTestResult resultIn ) ;

JVoid jagryWriteTestResult( JPTest testIn , JPCTestResult resultIn ) { if( resultIn->methods ) writeTestError( testIn , resultIn ) ; else printf( writeSuccess ) ; }

// !!! Расставить квалификаторы jHidden
JVoid writeAlreadyHasErrorTestResult( JPTest testIn , JPCVoid dataIn ) { printf( "already has error" ) ; }

JVoid writeEmptyTestResult( JPTest testIn , JPCVoid dataIn ) {}

JVoid writeInterfaceEqualsTestResult( JPTest testIn , JPCPointerEqualsTestData dataIn ) {
printf( "interface equals(%p)" , dataIn->value ) ; if( dataIn->text ) printf( ". % s" , dataIn->text ) ;
}

JVoid writePointerEqualsTestResult( JPTest testIn , JPCPointerEqualsTestData dataIn ) {
printf( "pointers equals(%p)" , dataIn->value ) ; if( dataIn->text ) printf( ". % s" , dataIn->text ) ;
}

JVoid writeInterfaceNotEqualsTestResult( JPTest testIn , JPCPointerNotEqualsTestData dataIn ) {
printf( "interface not equals(%p and %p)" , dataIn->value1 , dataIn->value2 ) ; if( dataIn->text ) printf( ". % s" , dataIn->text ) ;
}

JVoid writePointerNotEqualsTestResult( JPTest testIn , JPCPointerNotEqualsTestData dataIn ) {
printf( "pointers not equals(%p and %p)" , dataIn->value1 , dataIn->value2 ) ; if( dataIn->text ) printf( ". % s" , dataIn->text ) ;
}

JVoid writeInvalidStackTestResult( JPTest testIn , JPCVoid dataIn ) { printf( "invalid stack" ) ; }

JVoid writeNotEnoughMemoryTestResult( JPTest testIn , JPCNotEnoughMemoryTestData dataIn ) {
printf( "not enough memory(size(bytes): %i)" , dataIn->size ) ;
}

JVoid writeNotInitializeDataTestResult( JPTest testIn , JPCVoid dataIn ) {
printf( "not initialize stack data(size(bytes): %i)" , testIn->internalSize ) ;
}

JVoid writeNotInitializeStackTestResult( JPTest testIn , JPCVoid dataIn ) { printf( "not initialize stack" ) ; }

JVoid writeStatusTestResult( JPTest testIn , JPCStatusTestData dataIn ) {
printf( "method returned %i(%Xh)" , dataIn->code , dataIn->code ) ;
}

jHidden( JVoid )writeTextTestResult( JPTest testIn , JPCTextTestData dataIn ) {
printf( "%s" , dataIn->text ) ;

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

JVoid writeTestResult(JPTest testIn, JPCTestResult resultIn) {
if( resultIn->methods )
	{
		writeTestError( testIn , resultIn ) ;
		if( resultIn->methods->free ) resultIn->methods->free( resultIn->data ) ;
	}
else
	printf( writeSuccess ) ;
}