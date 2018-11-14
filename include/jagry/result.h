#ifndef JagryResult
#define JagryResult

#define jSuccesResult 0
#define jNotEnoughtMemoryErrorResult ( -1 )
#define jPointerIsNilWarningResult 1

#define jResultIsError( argument ) ( ( argument ) < 0 )
#define jResultIsNotError( argument ) ( ( argument ) >= 0 )
#define jResultSpecifier jSignedIntegerSpecifier

#include "../jagry.h"

typedef int JResult ;

#endif