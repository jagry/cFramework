#ifndef JagryTest
#define JagryTest

#include <stdlib.h>

#define jReturnTest( _stack_ , _result_ ) \
	return _stack_->position.line = __LINE__ , _result_ ;
#define jReturnTestIf( _stack_ , _condition_ , _result_ ) \
	if( _condition_ ) jReturnTest( _stack_ , _result_ )
#define jReturnTestIfError( _stack_ , _result_ ) \
	jReturnTestIf( _stack_ , jTestIsError( _result_ ) , _result_ )
#define jReturnTestNotEnoughMemory( _stack_ , _type_ , _member_ , _size_ ) \
	do \
		{ \
			( ( _type_* )_stack_->data )->_member_.size = _size_ ; \
			jReturnTest( \
				_stack_ , \
				jTestResult( _stack_->data , jagryGetNotEnoughMemoryTestMethods() ) ) \
		} while( jFalse ) ;
#define jReturnTestNotEnoughMemoryIf( \
		_stack_ , _condition_ , _type_ , _member_ , _size_ ) \
	if( _condition_ ) \
		jReturnTestNotEnoughMemory( _stack_ , _type_ , _member_ , _size_ )
#define jReturnTestNotEnoughMemoryIfNil( \
		_stack_ , _pointer_ , _type_ , _member_ , _size_ ) \
	jReturnTestNotEnoughMemoryIf( \
		_stack_ , !( _pointer_ ) , _type_ , _member_ , _size_ )
#define jReturnTestStatus( stack , type , member , status ) \
	do \
		{ \
			( ( type* )stack->data )->member.code = status ; \
			jReturnTest( \
				stack , \
				jTestResult( stack->data , jagryGetStatusErrorTestMethods() ) ) \
		} while( jFalse ) ;
#define jReturnTestStatusIf( stack , condition , type , member , status ) \
	if( condition ) jReturnTestStatus( stack , type , member , status )
#define jReturnTestStatusIfError( stack , type , member , status ) \
	jReturnTestStatusIf( \
		stack , jStatusIsError( status ) , type , member , status )

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
#define jPopTest( testArg , stackArg ) \
	 jagryPopTest( testIn , stack )
#define jPushTest( self , size , stack ) \
	jagryPushTest( self , size , __FILE__ , __LINE__ , __FUNCTION__ , &stack )

#define jTestIsError( argument ) ( argument ).methods
#define jTestIsNotError( argument ) !( argument ).methods

#define jTestResult( dataArg , methodsArg ) \
	( JTestResult ){ .data = dataArg , .methods = methodsArg }
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
//typedef JPTestPosition * JPPTestPosition ;

typedef JVoid( *JTestFreeMethod )( JPCVoid ) ;
typedef JVoid( *JTestWriteMethod )( JPTest , JPCVoid ) ;

struct jTestItem {
	JTestResult( *body )( JPTest , JPVoid ) ;
	JVoid( *finalize )( JPTest , JPVoid ) ;
	JTestResult( *initialize )( JPTest , JPPVoid ) ;
	JCPCCharacter1 name ; } ;
//struct jTestLocal { JPTest owner ; JPTestPosition position ; } ;
struct jTestMethods { JTestFreeMethod free ; JTestWriteMethod write ; } ;
struct jTestPosition { JPCCharacter1 file ; JUnsignedInteger line ; } ;
struct jTestResult {
	JPCVoid data ;
	//JUnsignedInteger deep ;
	JPCTestMethods methods ; } ;
struct jTestStack {
	JPVoid data ; JPCCharacter1 method ; JPTestStack next ; JTestPosition position ; } ;

struct jTestNotEnoudhMemoryData {
	JUnsignedInteger size ; } ;
struct jTestStatusData {
	JStatus code ; } ;

struct jTest {
	JPTestStack stack ;
	//JPVoid data ;
	//`JSize size ;
	union { JSize internalSize ; JPTestStack internalStack ; } ;
	JTestStack internalMainStack , internalNewStack ; } ;

JVoid jagryFreeTest( JPCVoid ) ;
JPCTestMethods jagryGetNotEnoughMemoryTestMethods( JVoid ) ;
JPCTestMethods jagryGetStatusErrorTestMethods( JVoid ) ;
JTestResult jagryPopTest( JPTest , JPTestStack ) ;
JTestResult jagryPushTest(
	JPTest ,
	JSize ,
	JPCCharacter1 ,
	JUnsignedInteger ,
	JPCCharacter1 ,
	JPPTestStack ) ;
JBoolean jagryRunTest( JPCTestItem , JSize ) ;

#endif