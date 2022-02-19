#define jReturnTest(_stack_,_result_) \
	{ \
		_Generic(_stack_, JPTestStack: _Generic(_result_, JTestResult: _stack_->position.line = __LINE__ ) ) ; \
		return _result_ ; \
	}
#define jReturnTestIf(_stack_,_condition_,_result_) \
	if( _condition_ ) \
		{ _Generic(_stack_, JPTestStack: _Generic(_condition_, JBoolean: _Generic(_result_, JTestResult: _stack_->position.line ) ) ) ; jReturnTest( _stack_ , _result_ ) }
#define jReturnTestIfError(_stack_,_result_) \
	{ \
		_Generic(_stack_, JPTestStack: _Generic(_result_, JTestResult: _stack_ ) ) ; \
		jReturnTestIf( _stack_ , jTestIsError( _result_ ) , _result_ ) \
	}
#define jReturnEmptyTest(_stack_) jReturnTest( _stack_ , jTestResult( jNil , jagryGetEmptyTestMethods() ) )
#define jReturnEmptyTestIf(_stack_,_condition_) if( _condition_ ) jReturnEmptyTest( _stack_ )

#define jReturnTextTest(_stack_,_type_,_member_,_text_) \
	{ \
		( ( _type_* )_stack_->data )->_member_.text = _text_ ; \
		jReturnTest( _stack_ , ( jTestResult( _stack_->data , jagryGetTextTestMethods() ) ) ) \
	}
#define jReturnTextTestIf(_stack_,_condition_,_type_,_member_,_text_) \
	if( _condition_ ) { \
		( ( _type_* )_stack_->data )->_member_.text = _text_ ; \
		jReturnTest( _stack_ , ( jTestResult( _stack_->data , jagryGetTextTestMethods() ) ) ) \
	}

#define jReturnTestIfInterfaceEquals(_stack_,_value1_,_value2_,_type_,_member_,_text_) \
	if( ( _value1_ ).this == ( _value2_ ).this ) \
		{ \
			( ( _type_* )( _stack_ )->data )->_member_.text = _text_ ; \
			( ( _type_* )( _stack_ )->data )->_member_.value = _value1_ ; \
			jReturnTest( _stack_ , jTestResult( ( _stack_ )->data , jagryGetInterfaceEqualsTestMethods() ) ) \
		}
#define jReturnTestIfPointerEquals(_stack_,_value1_,_value2_,_type_,_member_,_text_) \
	if( ( _value1_ ) == ( _value2_ ) ) \
		{ \
			( ( _type_* )( _stack_ )->data )->_member_.text = _text_ ; \
			( ( _type_* )( _stack_ )->data )->_member_.value = _value1_ ; \
			jReturnTest( _stack_ , jTestResult( ( _stack_ )->data , jagryGetPointerEqualsTestMethods() ) ) \
		}
#define jReturnTestIfInterfaceNotEquals(_stack_,_value1_,_value2_,_type_,_member_,_text_) \
	if( ( _value1_ ).this != ( _value2_ ).this ) \
		{ \
			( ( _type_* )( _stack_ )->data )->_member_.text = _text_ ; \
			( ( _type_* )( _stack_ )->data )->_member_.value1 = _value1_ ; \
			( ( _type_* )( _stack_ )->data )->_member_.value2 = _value2_ ; \
			jReturnTest( _stack_ , jTestResult( ( _stack_ )->data , jagryGetInterfaceNotEqualsTestMethods() ) ) \
		}
#define jReturnTestIfPointerNotEquals(_stack_,_value1_,_value2_,_type_,_member_,_text_) \
	if( ( _value1_ ) != ( _value2_ ) ) \
		{ \
			( ( _type_* )( _stack_ )->data )->_member_.text = _text_ ; \
			( ( _type_* )( _stack_ )->data )->_member_.value1 = _value1_ ; \
			( ( _type_* )( _stack_ )->data )->_member_.value2 = _value2_ ; \
			jReturnTest( _stack_ , jTestResult( ( _stack_ )->data , jagryGetPointerNotEqualsTestMethods() ) ) \
		}
#define jReturnTestNotEnoughMemory(_stack_,_type_,_member_,_size_) \
	do \
		{ \
			( ( _type_* )_stack_->data )->_member_.size = _size_ ; \
			jReturnTest( _stack_ , jTestResult( _stack_->data , jagryGetNotEnoughMemoryTestMethods() ) ) \
		} while( jFalse ) ;
// !!! Заменить аргументы с _{name}_ на {name}Arg
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

#define jReturnTestIfPointerEqual(_stack_,_value1_,_value2_,_type_,_member_,_name_) \
	( \
		jReturnTestIf( _stack_ , _value1_ == _value2_ , memberArg , statusArg ) \
	)

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
#define jPopTest(_self_,_stack_) _Generic( _self_ , JPTest : _Generic( _stack_ , JPTestStack : jagryPopTest( _self_ , _stack_ ) ) )
#define jPushTest(_self_,_size_,_stack_) \
	_Generic(_self_, JPTest: _Generic(_size_, JSize: _Generic(_stack_, JPTestStack : jagryPushTest( _self_ , _size_ , __FILE__ , __LINE__ , __FUNCTION__ , &_stack_ ) ) ) )
#define jPushTestLoop( _in_ , _iteration_ , _out_ ) jagryPushTestLoop( _in_ , _iteration_ , __FILE__ , __LINE__ , __FUNCTION__ , &_out_ ) ;

#define jTestItemFull( bodyArg , initializeArg , finalifeArg , nameArg ) \
	{ .body = bodyArg , .finalize = finalifeArg , .initialize = initializeArg , .name = #bodyArg }
#define jTestItemShort( bodyArg , initializeArg , finalizeArg ) jTestItemFull( bodyArg , initializeArg , finalizeArg , #bodyArg )
#define jTestIsError( argument ) ( ( JBoolean )( argument ).methods )
#define jTestIsNotError( argument ) ( ( JBoolean )!( argument ).methods )

#define jTestResult( dataArg , methodsArg ) ( JTestResult ){ .data = dataArg , .methods = methodsArg }
#define jEmptyErrorTestResult() jTestResult( jNil , jagryGetEmptyTestMethods() )
#define jSuccesTestResult jTestResult( jNil , jNil )

#include <jagry/base.i.h>

typedef struct jTest JTest ;
typedef struct jNotEnoughMemoryTestData JNotEnoughMemoryTestData ;
typedef struct jInterfaceEqualsTestData JInterfaceEqualsTestData ;
typedef struct jPointerEqualsTestData JPointerEqualsTestData ;
typedef struct jInterfaceNotEqualsTestData JInterfaceNotEqualsTestData ;
typedef struct jPointerNotEqualsTestData JPointerNotEqualsTestData ;
typedef struct jStatusTestData JStatusTestData ;
typedef struct jTextTestData JTextTestData ;
typedef struct jTestItem JTestItem ;
typedef struct jTestIteration JTestIteration ;
typedef struct jTestMethods JTestMethods ;
typedef struct jTestPosition JTestPosition ;
typedef struct jTestResult JTestResult ;
// !!! typedef struct jTestLoopData JTestLoopData ;
typedef struct jTestStack JTestStack ;

typedef JTest const JCTest ;
typedef JTest * JPTest ;
typedef JNotEnoughMemoryTestData const JCNotEnoughMemoryTestData ;
typedef JInterfaceEqualsTestData const JCInterfaceEqualsTestData ;
typedef JPointerEqualsTestData const JCPointerEqualsTestData ;
typedef JInterfaceNotEqualsTestData const JCInterfaceNotEqualsTestData ;
typedef JPointerNotEqualsTestData const JCPointerNotEqualsTestData ;
typedef JStatusTestData const JCStatusTestData ;
typedef JTestItem const JCTestItem ;
typedef JTestIteration * JPTestIteration ;
typedef JTestMethods const JCTestMethods ;
typedef JTestPosition * JPTestPosition ;
typedef JTestResult const JCTestResult ;
typedef JTestStack * JPTestStack ;

typedef JCTest * JPCTest ;
typedef JCStatusTestData * JPCStatusTestData ;
typedef JCNotEnoughMemoryTestData * JPCNotEnoughMemoryTestData ;
typedef JCInterfaceEqualsTestData * JPCInterfaceEqualsTestData ;
typedef JCPointerEqualsTestData * JPCPointerEqualsTestData ;
typedef JCInterfaceNotEqualsTestData * JPCInterfaceNotEqualsTestData ;
typedef JCPointerNotEqualsTestData * JPCPointerNotEqualsTestData ;
typedef JCTestItem * JPCTestItem ;
typedef JCTestMethods * JPCTestMethods ;
typedef JCTestResult * JPCTestResult ;
typedef JPTestStack * JPPTestStack ;

typedef JVoid( *JTestFreeMethod )( JPCVoid ) ;
typedef JVoid( *JTestWriteMethod )( JPTest , JPCVoid ) ;

struct jTextTestData { JPCharacter1 text ; } ;
struct jNotEnoughMemoryTestData { JUnsignedInteger size ; } ;
struct jInterfaceEqualsTestData { JCPCCharacter1 text ; JPVoid value ; } ;
struct jPointerEqualsTestData { JCPCCharacter1 text ; JPVoid value ; } ;
struct jInterfaceNotEqualsTestData { JPCCharacter1 text ; JIBase value1 , value2 ; } ;
struct jPointerNotEqualsTestData { JPCCharacter1 text ; JPCVoid value1 , value2 ; } ;
struct jStatusTestData { JStatus code ; } ;
struct jTestItem {
	JTestResult( *body )( JPTest , JPVoid ) ;
	JVoid( *finalize )( JPTest , JPVoid ) ;
	JTestResult( *initialize )( JPTest , JPPVoid ) ;
	JCPCCharacter1 name ; } ;
struct jTestMethods { JTestFreeMethod free ; JTestWriteMethod write ; } ;
struct jTestPosition { JPCCharacter1 file ; JUnsignedInteger line ; } ;
struct jTestResult { JPCVoid data ; JPCTestMethods methods ; } ;
struct jTestStack { JPVoid data ; JPTestIteration first , last ; JPCCharacter1 method ; JPTestStack next ; JTestPosition position ; } ;

struct jTestIteration {
	JCounter counter ;
	JPTestIteration next , previous ;
	JTestPosition position ; } ;

// !!! struct jTestInterfaceData { JPVoid value1 , value2 ; JCPCCharacter1 name ; } ; 
// !!! struct jTestLoopData { JCounter loop ; } ;

struct jTest { JPTestStack stack ; union { JSize internalSize ; JPTestStack internalStack; } ; JTestStack internalMainStack, internalNewStack; };

//JVoid jagryFreeTest( JPCVoid ) ;
jTestMethod( JPCTestMethods )jagryGetEmptyTestMethods( JVoid ) ;
jTestMethod( JPCTestMethods )jagryGetInterfaceEqualsTestMethods( JVoid ) ;
jTestMethod( JPCTestMethods )jagryGetPointerEqualsTestMethods( JVoid ) ;
jTestMethod( JPCTestMethods )jagryGetInterfaceNotEqualsTestMethods( JVoid ) ;
jTestMethod( JPCTestMethods )jagryGetPointerNotEqualsTestMethods( JVoid ) ;
jTestMethod( JPCTestMethods )jagryGetNotEnoughMemoryTestMethods( JVoid ) ;
jTestMethod( JPCTestMethods )jagryGetStatusTestMethods( JVoid ) ;
jTestMethod( JPCTestMethods )jagryGetTextTestMethods( JVoid ) ;
jTestMethod( JTestResult )jagryPopTest( JPTest , JPTestStack ) ;
jTestMethod( JTestResult )jagryPushTest( JPTest , JSize , JPCCharacter1 , JUnsignedInteger , JPCCharacter1 , JPPTestStack ) ;
jTestMethod( JTestResult )jagryPushTestLoop( JPTest , JCCounter , JPCCharacter1 , JUnsignedInteger , JPCCharacter1 , JPPTestStack ) ;
jTestMethod( JBoolean )jagryRunTest( JPCTestItem , JSize ) ;