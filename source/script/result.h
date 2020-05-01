#define errorResult ( ( jMinSignedInteger >> 1 ) | jMinSignedInteger )
#define warningResult ( ( JUnsignedInteger )jMinSignedInteger >> 1 )

//#define buildParserResult   3
//#define currentParserResult 1
//#define nextParserResult    2

#define successResult jSuccessResult

//#define nextCharacterParserResult 1
//#define tokenEndParserResult      2

#define emptyInputErrorResult           ( errorResult | 1 )
#define missingKeywordErrorResult       ( errorResult | 2 )
#define unexpectedCharacterErrorResult  ( errorResult | 3 )
#define unexpectedEndErrorResult        ( errorResult | 4 )
#define unexpectedIdentifierErrorResult ( errorResult | 5 )
#define unexpectedKeywordErrorResult    ( errorResult | 6 )
#define unexpectedOperatorErrorResult   ( errorResult | 7 )
#define unknownKeywordErrorResult       ( errorResult | 8 )

#define notReadyAnalyzerWarningResult ( warningResult | 1 )
