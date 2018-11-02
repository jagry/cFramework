//#ifndef JAGRY_IS
//#define JAGRY_IS

#include "character.h"

#define isBlank( character ) ( character == CARRIAGE_RETURN_CHARACTER || character == LINE_FEED_CHARACLER || character == SPACE_CHARACTER || character == TAB_CHARACTER )
#define isCapital( character ) ( character >= CAPITAL_A_CHARACTER && character <= CAPITAL_Z_CHARACTER )
#define isDigit( character ) ( character >= ZERO_DIGIT_CHARACTER && character <= NINE_DIGIT_CHARACTER )
#define isLetter( character ) ( isCapital( character ) || isSmall( character ) )
#define isSmall( character ) ( character >= SMALL_A_CHARACTER && character <= SMALL_Z_CHARACTER )

//#endif // JAGRY_IS