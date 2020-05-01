#define currentTokenStatus 0
#define endTokenStatus     1
#define readTokenStatus    2

#define endTokenType        0
#define identifierTokenType 1
#define keywordTokenType    2
#define operatorTokenType   3
#define variableTokenType   4

#define beginKeywordToken    0
#define endKeywordToken      1
#define variableKeywordToken 2

#define commaOperatorToken 0

#define escapeLineEndToken 0
#define lineEndToken       1
#define streamEndToken     2

#define undefineEndLine 0
#define warningEndLine  1
#define appleEndLine    2
#define linuxEndLine    3
#define windowsEndLine  4

#define defineTokenImplementation( name , members ) \
	struct D##name { PCM##name methods ; JByte type ; members ; } ; \
	union I##name { IBaseToken base ; PD##name data ; } ; \
	struct M##name { \
		JResult( *execute )( IBaseToken ) ; \
		JVoid( *free )( I##name ) ; } ;

#include <jagry/map.i.h>
#include <jagry/reader.i.h>

//#include "builder.h"

typedef struct BaseToken BaseToken ;
typedef struct IdentifierToken IdentifierToken ;
typedef struct NameToken NameToken ;
typedef struct TokenData TokenData ;

typedef TokenData * PTokenData ;
typedef union UToken UToken ;

typedef UToken * PUToken ;

struct BaseToken { JByte type ; } ;
struct NameToken { JByte type ; JBuffer value ; } ;
struct IdentifierToken { JByte type ; JByte value ; } ;

union UToken {
	BaseToken base ;
	IdentifierToken identifier ;
	NameToken name ; } ;
struct TokenData {
	JIBufferMap map ;
	JIReader reader ;
	UToken token ;
	JCharacter1 character ;
	JByte endLine ;
	JByte status ; } ;

jInternal( JVoid )freeToken( PUToken ) ;
jInternal( JResult )getToken( PTokenData ) ;
//jInternal( JResult )handleToken( PUBuilder , PUToken ) ;