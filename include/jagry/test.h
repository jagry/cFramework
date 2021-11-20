#ifndef JagryTest
#define JagryTest

#include <stdlib.h>

#define jReturnTest( stackArg , resultArg ) return stackArg->position.line = __LINE__ , resultArg ;
#define jReturnTestIf( stackArg , conditionArg , resultArg ) if( conditionArg ) jReturnTest( stackArg , resultArg )
#define jReturnEmptyTestIf( stackArg , conditionArg ) jReturnTestIf( stackArg , conditionArg , jTestResult( jNil , jagryGetEmptyTestMethods() ) )

// TODO: Заменить аргументы с _{name}_ на {name}Arg
#define jReturnTestIfError( stackArg , resultArg ) jReturnTestIf( stackArg , jTestIsError( resultArg ) , resultArg )
#define jReturnTestNotEnoughMemory( stackArg , typeArg , memberArg , sizeArg ) \
	do \
		{ \
			( ( typeArg* )stackArg->data )->memberArg.size = sizeArg ; \
			jReturnTest( stackArg , jTestResult( stackArg->data , jagryGetNotEnoughMemoryTestMethods() ) ) \
		} while( jFalse ) ;
#define jReturnTestStatus( stackArg , typeArg , memberArg , statusArg ) \
	do \
		{ \
			( ( typeArg* )stackArg->data )->memberArg.code = statusArg ; \
			jReturnTest( \
				stackArg , \
				jTestResult( stackArg->data , jagryGetStatusTestMethods() ) ) \
		} while( jFalse ) ;
#define jReturnTestStatusIf( stackArg , conditionArg , typeArg , memberArg , statusArg ) \
	if( conditionArg ) jReturnTestStatus( stackArg , typeArg , memberArg , statusArg )
#define jReturnTestStatusIfError( stackArg , typeArg , memberArg , statusArg ) \
	jReturnTestStatusIf( stackArg , jStatusIsError( statusArg ) , typeArg , memberArg , statusArg )

#define jInitializeTest( test , needSize , stack ) \
	( \
		( \
				test.internalMainStack.method = __FUNCTION__ , \
				test.internalMainStack.next = jNil , \
				test.internalMainStack.position.file = __FILE__ , \
				test.internalMainStack.position.line = __LINE__ , \
				stack = test.stack = &test.internalMainStack , \
				needSize ) ? \
			( \
				( test.internalMainStack.data = malloc( needSize ) ) ? \
					( JTestResult ){ .data = jNil , .methods = jNil } : \
					( \
						test.internalSize = needSize , \
						( JTestResult ){ \
							.data = jNil , \
							.methods = jagryGetTestDataAllocate( ) } ) ) : \
			( \
				test.internalMainStack.data = jZero , \
				( JTestResult ){ .data = jNil , .methods = jNil } ) )
#define jPopTest( _self_ , _stack_ ) jagryPopTest( _self_ , _stack_ )
#define jPushTest( _self_ , _size_ , _stack_ ) jagryPushTest( _self_ , _size_ , __FILE__ , __LINE__ , __FUNCTION__ , &_stack_ )
#define jPushTestLoop( _self_ , _iteration_ , _stack_ ) jagryPushTestLoop( _self_ , _iteration_ , __FILE__ , __LINE__ , __FUNCTION__ , &_stack_ ) ;

#define jTestItemFull( bodyArg , initializeArg , finalifeArg , nameArg ) \
	{ .body = bodyArg , .finalize = finalifeArg , .initialize = initializeArg , .name = #bodyArg }
#define jTestItemShort( bodyArg , initializeArg , finalizeArg ) jTestItemFull( bodyArg , initializeArg , finalizeArg , #bodyArg )
#define jTestIsError( argument ) ( argument ).methods
#define jTestIsNotError( argument ) !( argument ).methods

#define jTestResult( dataArg , methodsArg ) \
	( JTestResult ){ .data = dataArg , .methods = methodsArg }
#define jEmptyErrorTestResult() jTestResult( jNil , jagryGetEmptyTestMethods() )
#define jSuccesTestResult jTestResult( jNil , jNil )

#include <jagry/status.h>

typedef struct jTest JTest ;
typedef struct jTestItem JTestItem ;
typedef struct jTestMethods JTestMethods ;
typedef struct jTestNotEnoudhMemoryData JTestNotEnoudhMemoryData ;
typedef struct jTestPosition JTestPosition ;
typedef struct jTestResult JTestResult;
typedef struct jTestStack JTestStack ;
typedef struct jTestStatusData JTestStatusData ;

typedef JTest const JCTest ;
typedef JTest * JPTest ;
typedef JTestStatusData const JCTestStatusData ;
typedef JTestNotEnoudhMemoryData const JCTestNotEnoudhMemoryData ;
typedef JTestItem const JCTestItem ;
typedef JTestMethods const JCTestMethods ;
typedef JTestPosition * JPTestPosition ;
typedef JTestResult const JCTestResult ;
typedef JTestStack * JPTestStack ;

typedef JCTest * JPCTest ;
typedef JCTestStatusData * JPCTestStatusData ;
typedef JCTestNotEnoudhMemoryData * JPCTestNotEnoudhMemoryData ;
typedef JCTestItem * JPCTestItem ;
typedef JCTestMethods * JPCTestMethods ;
typedef JCTestResult * JPCTestResult ;
typedef JPTestStack * JPPTestStack ;

typedef JVoid( *JTestFreeMethod )( JPCVoid ) ;
typedef JVoid( *JTestWriteMethod )( JPTest , JPCVoid ) ;

struct jTestItem {
	JTestResult( *body )( JPTest , JPVoid ) ;
	JVoid( *finalize )( JPTest , JPVoid ) ;
	JTestResult( *initialize )( JPTest , JPPVoid ) ;
	JCPCCharacter1 name ; } ;
struct jTestMethods { JTestFreeMethod free ; JTestWriteMethod write ; } ;
struct jTestPosition { JPCCharacter1 file ; JUnsignedInteger line ; } ;
struct jTestResult { JPCVoid data ; JPCTestMethods methods ; } ;
struct jTestStack { JPVoid data ; JPCCharacter1 method ; JPTestStack next ; JTestPosition position ; } ;

struct jTestNotEnoudhMemoryData { JUnsignedInteger size ; } ;
struct jTestStatusData { JStatus code ; } ;

struct jTest { JPTestStack stack ; union { JSize internalSize ; JPTestStack internalStack ; } ; JTestStack internalMainStack , internalNewStack ; } ;

JVoid jagryFreeTest( JPCVoid ) ;
JPCTestMethods jagryGetEmptyTestMethods( JVoid ) ;
JPCTestMethods jagryGetNotEnoughMemoryTestMethods( JVoid ) ;
JPCTestMethods jagryGetStatusTestMethods( JVoid ) ;
JTestResult jagryPopTest( JPTest , JPTestStack ) ;
JTestResult jagryPushTest( JPTest , JSize , JPCCharacter1 , JUnsignedInteger , JPCCharacter1 , JPPTestStack ) ;
JTestResult jagryPushTestLoop( JPTest , JCounter , JPCCharacter1 , JUnsignedInteger , JPCCharacter1 , JPPTestStack ) ;
JBoolean jagryRunTest( JPCTestItem , JSize ) ;

#endif