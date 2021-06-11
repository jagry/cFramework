#include <stdio.h>
#include <stdlib.h>
#include "check.h"
#include "return.h"

typedef jGetSimpleArrayItemMethod( CheckNext , JISimpleArrayItem )
typedef JUnsignedInteger( *CheckOffset )(
	JUnsignedInteger , JUnsignedInteger ) ;
typedef jGetSimpleArrayStartItemMethod( CheckStart , JISimpleArray ) ;
typedef struct checkTestExtraItemFound CheckTestExtraItemFound ;
typedef struct checkTestInvalidSize CheckTestInvalidSize ;
typedef struct checkTestInvalidValue CheckTestInvalidValue ;
typedef struct checkTestMissingItem CheckTestMissingItem ;

struct checkTestExtraItemFound {
	JUnsignedInteger value ; } ;
struct checkTestInvalidSize {
	JUnsignedInteger have , need ; } ;
struct checkTestInvalidValue {
	JUnsignedIntegerPointer have , need ;
	JUnsignedInteger item ; } ;
struct checkTestMissingItem {
	JUnsignedInteger current , need ; } ;

typedef union {
	CheckTestExtraItemFound extraItemFound ;
	CheckTestInvalidSize invalidSize ;
	CheckTestInvalidValue invalidValue ;
	CheckTestMissingItem missingItem ;
	JTestStatusData status ; } CheckTest , *PCheckTest ;

static JTestResult check( JPTest , JISimpleArray , PCGauge ) ;
static JUnsignedInteger checkBackwardOffset(
	JUnsignedInteger , JUnsignedInteger ) ;
static JUnsignedInteger checkForwardOffset(
	JUnsignedInteger , JUnsignedInteger ) ;
static JISimpleArrayItem checkGetNext( JISimpleArrayItem ) ;
static JISimpleArrayItem checkGetPrevious( JISimpleArrayItem ) ;
static JTestResult checkIteration(
	JPTest , JISimpleArrayItem , CheckOffset , CheckNext , PCGauge ) ;
static JVoid writeCheckExtraItemFound( JPCTest , JPCVoid ) ;
static JVoid writeCheckInvalidSize( JPCTest , JPCVoid ) ;
static JVoid writeCheckInvalidValue( JPCTest , JPCVoid ) ;
static JVoid writeCheckMissingItem( JPCTest, JPCVoid ) ;

static JCTestMethods
	checkExtraItemFoundMethods = {
		.free = jNil ,
		.write = writeCheckExtraItemFound } ,
	checkInvalidSizeMethods = { .free = jNil , .write = writeCheckInvalidSize } ,
	checkInvalidValueMethods = {
		.free = jNil ,
		.write = writeCheckInvalidValue } ,
	checkMissingItemMethods = { .free = jNil , .write = writeCheckMissingItem } ;

JTestResult check( JPTest testIn , JISimpleArray listIn , PCGauge gaugeIn ) {
JPTestStack stack ;
{ // push test
	JTestResult result = jPushTest( testIn , sizeof( CheckTest ) , stack ) ;
	jReturnTestIfError( stack , result ) ;
}
{ // hit size
	JSize size = jGetSimpleArrayCount( listIn ) ;
	if( size != gaugeIn->size )
		{
			( ( PCheckTest )stack->data )->invalidSize.have = size ;
			( ( PCheckTest )stack->data )->invalidSize.need = gaugeIn->size ;
			jReturnTest(
				stack , jTestResult( stack->data , &checkInvalidSizeMethods ) ) ;
		}
}
{
	JISimpleArrayItem item = jGetSimpleArrayFirst( listIn ) ;
	JTestResult result = checkIteration(
		testIn , item , checkForwardOffset , checkGetNext , gaugeIn ) ;
	jReturnTestIfError( stack , result )
	item = jGetSimpleArrayLast( listIn ) ;
	result = checkIteration(
		testIn , item , checkBackwardOffset , checkGetPrevious , gaugeIn ) ;
	jReturnTestIfError( stack , result )
}
return jPopTest( testIn , stack ) ;
}

JUnsignedInteger checkBackwardOffset(
	JUnsignedInteger countIn , JUnsignedInteger offsetIn ) {
return countIn - offsetIn - 1 ;
}

JUnsignedInteger checkForwardOffset(
	JUnsignedInteger countIn , JUnsignedInteger offsetIn ) {
return offsetIn ;
}

JISimpleArrayItem checkGetNext( JISimpleArrayItem itemIn ) {
return jGetSimpleArrayItemNext( itemIn );
}

JISimpleArrayItem checkGetPrevious( JISimpleArrayItem itemIn ) {
return jGetSimpleArrayItemPrevious( itemIn );
}

JTestResult checkIteration(
	JPTest testIn ,
	JISimpleArrayItem itemIn ,
	//JPCCharacter1 directionIn ,
	CheckOffset offsetIn ,
	CheckNext nextIn ,
	//CheckStart startIn ,
	PCGauge gaugeIn ) {
JPTestStack stack ;
JTestResult result = jPushTest( testIn , sizeof( CheckTest ) , stack ) ;
jReturnTestIfError( stack , result ) ;
for( JSize itemCounter = 0 ; ; ++itemCounter )
	{
		JUnsignedIntegerPointer value ;
		if( itemCounter == gaugeIn->size )
			if( itemIn )
				{
					( ( PCheckTest )stack->data )->extraItemFound.value = itemCounter ;
					jReturnTest(
						stack ,
						jTestResult( stack->data , &checkExtraItemFoundMethods ) )
				}
			else break ;
		if( !itemIn )
			{
				( ( PCheckTest )stack->data )->missingItem.current = itemCounter ;
				( ( PCheckTest )stack->data )->missingItem.need = gaugeIn->size ;
				jReturnTest(
					stack , jTestResult( stack->data , &checkMissingItemMethods ) )
			}
		{ // get value
			JStatus status;
			status = jGetSimpleArrayItemValue( itemIn , &value ) ;
			jReturnTestStatusIfError( stack , CheckTest , status, status )
		}
		{ // check value
			JUnsignedInteger offset = offsetIn( gaugeIn->size , itemCounter ) ;
			if( value != gaugeIn->data[ offset ] )
				{
					( ( PCheckTest )stack->data )->invalidValue.have = value ;
					( ( PCheckTest )stack->data )->invalidValue.item = itemCounter ;
					( ( PCheckTest )stack->data )->invalidValue.need =
						gaugeIn->data[ offset ] ;
					jReturnTest(
						stack , jTestResult( stack->data , &checkInvalidValueMethods ) )
				}
		}
		itemIn = nextIn( itemIn ) ;
	}
return jPopTest( testIn , stack ) ;
}


JTestResult checkRange(
	JPTest testIn ,
	JISimpleArray listIn ,
	JSize countIn ,
	JSize startIn ,
	JSize stepIn ) {
PGauge gauge ; JPTestStack stack ; JStatus status ;
JTestResult result = jPushTest( testIn , sizeof( CheckTest ) , stack ) ;
jReturnTestIfError( stack , result ) ;
status = gaugeRange( countIn , startIn , stepIn , &gauge ) ;
jReturnTestStatusIfError( stack , CheckTest , status , status ) ;
result = check( testIn , listIn , gauge ) ;
jReturnTestIfError( stack , result )
return jPopTest( testIn , stack ) ;
}

JTestResult checkStatic(
	JPTest testIn ,
	JISimpleArray listIn ,
	JSize sizeIn ,
	JPUnsignedIntegerPointer guageIn ) {
PGauge gauge ; JPTestStack stack ; JStatus status ;
JTestResult result = jPushTest( testIn , sizeof( CheckTest ) , stack ) ;
jReturnTestIf( stack , jTestIsError( result ) , result ) ;
status = gaugeStatic( sizeIn , guageIn , &gauge ) ;
jReturnTestStatusIfError( stack , CheckTest , status , status ) ;
result = check( testIn , listIn , gauge ) ;
jReturnTestIfError( stack , result )
return jPopTest( testIn , stack ) ;
}

JVoid writeCheckExtraItemFound( JPCTest testIn , JPCTestResult resultIn ) {
printf( "extra element found" ) ;
}

JVoid writeCheckInvalidSize( JPCTest testIn , JPCVoid dataIn ) {
printf(
	"invalid size array. Have %d, need %d" ,
	( ( PCheckTest )dataIn )->invalidSize.have ,
	( ( PCheckTest )dataIn )->invalidSize.need ) ;
}

JVoid writeCheckInvalidValue( JPCTest testIn , JPCVoid dataIn ) {
printf(
	"invalid size value(item %i). Have %d, need %d" ,
	( ( PCheckTest )dataIn )->invalidValue.item ,
	( ( PCheckTest )dataIn )->invalidValue.have ,
	( ( PCheckTest )dataIn )->invalidValue.need ) ;
}

JVoid writeCheckMissingItem( JPCTest testIn , JPCVoid dataIn ) {
printf(
	"missing item with index %d, need %d" ,
	( ( PCheckTest )dataIn )->missingItem.current ,
	( ( PCheckTest )dataIn )->missingItem.need ) ;
}