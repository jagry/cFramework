#define writeSuccess "success\n"

#include "../../detail/test.h"

jHidden( JVoid )writeAlreadyHasErrorTestResult( JPTest , JPCVoid ) ;
jHidden( JVoid )writeEmptyTestResult( JPTest , JPCVoid ) ;
jHidden( JVoid )writeInterfaceEqualsTestResult( JPTest , JPCVoid );
jHidden( JVoid )writePointerEqualsTestResult( JPTest , JPCVoid );
jHidden( JVoid )writeInterfaceNotEqualsTestResult( JPTest , JPCVoid ) ;
jHidden( JVoid )writePointerNotEqualsTestResult( JPTest , JPCVoid ) ;
jHidden( JVoid )writeInvalidStackTestResult( JPTest , JPCVoid ) ;
jHidden( JVoid )writeNotEnoughMemoryTestResult( JPTest , JPCVoid ) ;
jHidden( JVoid )writeNotInitializeDataTestResult( JPTest , JPCVoid ) ;
jHidden( JVoid )writeNotInitializeStackTestResult( JPTest , JPCVoid ) ;
jHidden( JVoid )writeStatusTestResult( JPTest , JPCVoid ) ;
jHidden( JVoid )writeTextTestResult( JPTest , JPCVoid ) ;
jHidden( JVoid )writeTestResult( JPTest , JPCTestResult ) ;