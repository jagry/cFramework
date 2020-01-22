#define identifierTokenType 0
#define keywordTokenType 1

#define variableKeywordToken 0

#define defineTokenImplementation( name , members ) \
	struct D##name { PCM##name methods ; JByte type ; members ; } ; \
	union I##name { IBaseToken base ; PD##name data ; } ; \
	struct M##name \
	{ \
		JResult( *execute )( IBaseToken ) ; \
		JVoid( *free )( I##name ) ; \
	} ;

//jStdDeclareImplementation( BaseToken )
//jStdDeclareImplementation( IdentifierToken )
//jStdDeclareImplementation( KeywordToken )

typedef struct BaseToken BaseToken ;
typedef struct IdentifierToken IdentifierToken ;
typedef struct KeywordToken KeywordToken ;

typedef union UToken UToken ;

typedef UToken * PUToken ;

typedef JVoid( *FreeToken )( PUToken ) ;

struct BaseToken { JByte type ; } ;
struct IdentifierToken { JByte type ; JBuffer name ; } ;
struct KeywordToken { JByte type ; JByte identifier ; } ;

union UToken {
	BaseToken base ;
	IdentifierToken identifier ;
	KeywordToken keyword ; } ;
	
jInternal( JVoid )freeToken( PUToken ) ;