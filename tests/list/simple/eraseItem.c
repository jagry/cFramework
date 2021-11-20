#define eraseItemCount 7
#define eraseItemIteration( count , gauge ) \
	{ count , ( ( JUnsignedIntegerPointer[] ){ gauge } ) }

#include "check.h"
#include "return.h"
#include <jagry/test.h>
#include <stdio.h>

typedef struct {
	JTestResult sub ;
	JPCCharacter1 method ;
	JCounter counter ; } EraseItemIteration , *PEraseItemIteration ;

typedef union {
	EraseItemIteration iteration ;
	JTestStatusData status ; } EraseItemTest , *PEraseItemTest ;

JStatus fill( JISimpleArray , JUnsignedIntegerPointer ) ;

static JVoid freeEraseItem( JPCVoid ) ;
static JVoid writeEraseItem( JPTest , JPCVoid ) ;

JCTestMethods eraseItemMethods = {
	.free = freeEraseItem ,
	.write = writeEraseItem } ;

JTestResult eraseItem( JPTest testIn , JPISimpleArray arrayIn ) {
typedef struct {
	JCOffset offset ;
	JPUnsignedIntegerPointer gauge ; } Iteration ;
JPTestStack stack ;
{ // !!!
	JTestResult result = jPushTest( testIn , sizeof( EraseItemTest ), stack ) ;
	jReturnTestIfError( stack , result ) ;
}
{ // !!!
	JStatus status = fill( *arrayIn , eraseItemCount ) ;
	jReturnTestStatusIfError( stack , EraseItemTest , status , status )
}
{ // !!!
	Iteration iterations[ ] = {
		{ 2 , ( ( JUnsignedIntegerPointer[] ){ 6 , 5 , 3 , 2 , 1 , 0 } ) } ,
		{ 1 , ( ( JUnsignedIntegerPointer[] ){ 6 , 3 , 2 , 1 , 0 } ) } ,
		{ 0 , ( ( JUnsignedIntegerPointer[] ){ 3 , 2 , 1 , 0 } ) } ,
		{ -3 , ( ( JUnsignedIntegerPointer[] ){ 3 , 1 , 0 } ) } ,
		{ -2 , ( ( JUnsignedIntegerPointer[] ){ 3 , 0 } ) } ,
		{ -1 , ( ( JUnsignedIntegerPointer[] ){ 3 } ) } } ;
	JTestResult result = checkRange( testIn , *arrayIn , eraseItemCount , eraseItemCount - 1 , -1 ) ;
	jReturnTestIfError( stack , result )
	for( JOffset counter = 0 ; counter < ( sizeof( iterations ) / sizeof( *iterations ) ) ; ++counter )
		{
			jEraseSimpleArrayItem( *arrayIn , iterations[ counter ].offset ) ;
			result = checkStatic( testIn , *arrayIn , eraseItemCount - counter - 1 , iterations[ counter ].gauge ) ;
			if( jTestIsError( result ) )
				{
					( ( PEraseItemTest )stack->data )->iteration.counter = counter ;
					( ( PEraseItemTest )stack->data )->iteration.method = __FUNCTION__ ;
					( ( PEraseItemTest )stack->data )->iteration.sub = result ;
					jReturnTest( stack , jTestResult( stack->data , &eraseItemMethods ) ) ;
				}
		}
}
return jPopTest( testIn , stack ) ;
}

JVoid freeEraseItem( JPCVoid in ) {
/*PEraseItemIteration iteration = &((PEraseItemTest)in)->iteration;
if( ( ( ( PEraseItemTest )in )->iteration ).sub.methods->free )
	( ( ( PEraseItemTest )in )->iteration ).sub.methods->free(
		( ( ( PEraseItemTest )in )->iteration ).sub.data )
if( ( ( ( PEraseItemTest )in )->iteration ).sub.data )*/
}

JVoid writeEraseItem( JPTest testIn , JPCVoid dataIn ) {
PEraseItemIteration iteration = &( ( PEraseItemTest )dataIn )->iteration ;
printf( "%s iteration %i: " , iteration->method , iteration->counter ) ;
iteration->sub.methods->write( testIn , iteration->sub.data ) ;
}