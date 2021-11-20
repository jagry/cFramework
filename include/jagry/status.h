#ifndef JagryStatus
#define JagryStatus

#define jNotEnoughtMemoryErrorStatus ( ( JStatus )-1 )
#define jSuccessStatus ( ( JStatus )0 )
#define jPointerIsNilWarningStatus ( ( JStatus )1 )
#define jErrorLastStatus jNotEnoughtMemoryErrorStatus
#define jWarningLastStatus jPointerIsNilWarningStatus

#define jStatusIsError( argument ) ( ( argument ) < 0 )
#define jStatusIsNotError( argument ) ( ( argument ) >= 0 )

#define jStatusDecSpecifier jSignedIntegerDecSpecifier
#define jStatusHexSpecifier jSignedIntegerHexSpecifier

#define jReturnIfStatusIsError( variable , condition ) if( jStatusIsError( variable = ( condition ) ) ) return variable ;
#define jReturnIfNotAllocated( variable , type ) if( !( variable = malloc( sizeof( type ) ) ) ) return jNotEnoughtMemoryErrorStatus ;
#define jReturnIfVariableIsNotError( variable , condition ) if( jStatusIsError( variable = ( condition ) ) ) return variable ;

#include "../jagry.h"

typedef JSignedInteger JStatus ;

#endif