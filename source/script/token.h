#define keywordTokenType 0

#define defineTokenImplementation( name , members ) \
	struct D##name { PCM##name methods ; JByte type ; members } ; \
	union I##name { IBaseToken base ; PD##name data ; } ; \
	struct M##name \
	{ \
		JResult( *execute )( IBaseToken ) ; \
		JVoid( *free )( I##name ) ; \
	} ;

jStdDeclareImplementation( BaseToken )
jStdDeclareImplementation( KeywordToken )

struct DBaseToken { PCMBaseToken methods ; JByte type ; } ;
union IBaseToken { PDBaseToken data ; } ;
struct MBaseToken
{
	JResult( *execute )( ) ;
	JVoid( *free )( ) ;
} ;

defineTokenImplementation( KeywordToken , JBuffer buffer ; )