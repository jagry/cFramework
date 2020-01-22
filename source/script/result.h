#define errorResult ( ( jMinSignedInteger >> 1 ) | jMinSignedInteger )
#define warningResult ( jMinSignedInteger >> 1 )

#define currentCharacterParserResult 0
#define nextCharacterParserResult 1

#define emptyInputErrorResult          ( errorResult | 1 )
#define unexpectedCharacterErrorResult ( errorResult | 2 )
#define unexpectedEndErrorResult       ( errorResult | 3 )
#define unexpectedKeywordErrorResult   ( errorResult | 4 )
#define unknownKeywordErrorResult      ( errorResult | 5 )

#define notReadyWarningBuilderResult ( warningResult | 1 )
