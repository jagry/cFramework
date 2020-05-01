#ifndef JagryResult
#define JagryResult

#define jSuccessResult 0
#define jNotEnoughtMemoryErrorResult ( -1 )
#define jPointerIsNilWarningResult 1

#define jResultIsError( argument ) ( ( argument ) < 0 )
#define jResultIsNotError( argument ) ( ( argument ) >= 0 )

#define jReturnIfResultIsError( variable , condition ) \
	if( jResultIsError( variable = ( condition ) ) ) return variable ;
#define jReturnIfVariableIsNotError( variable , condition ) \
	if( jResultIsError( variable = ( condition ) ) ) return variable ;

#define jResultSpecifier jSignedIntegerSpecifier

#include "../jagry.h"

typedef int JResult ;

#endif