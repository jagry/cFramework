// #ifndef JAGRY_BLANK
// #define JAGRY_BLANK

typedef struct SkipBlankParser SkipBlankParser ;

struct SkipBlankParser {
    JParserMethods methods ;
    JParser* stack ;
} ;

int createBlankParser( const Parser* , SkipBlankParser** ) ;

// #endif // JAGRY_BLANK

