#define baseStateParserMembers IBaseStateParser previous ;
//#define dollarStateParserMembers baseStateParserMembers JBuffer buffer ;
//#define keywordStateParserMembers dollarStateParserMembers
//#define numberStateParserMembers dollarStateParserMembers
#define startStateParserMembers baseStateParserMembers
#define textStateParserMembers baseStateParserMembers JBuffer buffer ;

#define jExecuteParser( self , out ) ( self.data->methods->execute( self , &out ) )
#define jFreeParser( self ) ( self.data->methods->free( self ) )
#define jExecuteStateParser( self , parser , out ) ( self.data->methods->execute( parser , out ) )

#define continueResult 1

#define defineImplementation( name , members ) \
	struct D##name { PCMBaseStateParser methods ; members } ; \
	union I##name { IBaseStateParser base ; PD##name data ; } ;

jStdDeclareImplementation( Parser )
jStdDeclareImplementation( BaseStateParser )
jStdDeclareImplementation( TextStateParser ) // Последовательность после символf "$", переключается на Heximal или Keyword
//jStdDeclareInterface( JDollarStateParser ) // Последовательность после символf "$", переключается на Heximal или Keyword
//jStdDeclareInterface( JNumberStateParser ) // Число с указанием системы счисления
//jStdDeclareInterface( JKeywordStateParser )
jStdDeclareImplementation( StartStateParser )

union IBaseStateParser { PDBaseStateParser data ; } ;
struct DBaseStateParser { PCMBaseStateParser methods ; IBaseStateParser previous ; } ;
struct MBaseStateParser { JResult( *execute )( IParser , PIBaseToken ) ; JVoid( *free )( IParser ) ; JResult( *token )( IParser , IBaseToken ) ; } ;

struct DParser { PCMParser methods ; IBaseStateParser current ; JIReader reader ; } ;
union IParser { PDParser data ; } ;
struct MParser { JResult( *execute )( IParser , PIBaseToken ) ; JVoid( *free )( IParser ) ; } ;

//defineImplementation( JDollarStateParser , dollarStateParserMembers )
//defineImplementation( JNumberStateParser , numberStateParserMembers )
//defineImplementation( JKeywordStateParser , keywordStateParserMembers )
defineImplementation( StartStateParser , startStateParserMembers )
defineImplementation( TextStateParser , textStateParserMembers )

int parser( JIReader , PIParser ) ;