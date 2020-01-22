#define baseStateParserMembers IBaseStateParser previous ;
#define characterStateParserMembers \
	baseStateParserMembers JCharacter1 character ;
#define textStateParserMembers baseStateParserMembers JBuffer buffer ;

#define jExecuteParser( self , in , out ) \
	( self.data->methods->execute( self , in , &out ) )
#define jFreeParser( self ) ( self.data->methods->free( self ) )
//#define jExecuteStateParser( self , parser , out ) \
//	( self.data->methods->execute( parser , out ) )

#define defineImplementation( name , members ) \
	struct D##name { PCM##name methods ; members } ; \
	struct M##name { \
		JResult( *execute )( IParser , JCharacter1 , PFactory ) ; \
		JVoid( *free )( I##name ) ; } ; \
	union I##name { IBaseStateParser base ; PD##name data ; } ;

jStdDeclareImplementation( Parser )
//jStdDeclareImplementation( BaseStateParser )
//jStdDeclareImplementation( CharacterStateParser )
//jStdDeclareImplementation( StartStateParser )
//jStdDeclareImplementation( TextStateParser )

/*union IBaseStateParser { PDBaseStateParser data ; } ;
struct DBaseStateParser {
	PCMBaseStateParser methods ;
	baseStateParserMembers } ;
struct MBaseStateParser {
	JResult( *execute )( IParser , JCharacter1 , PFactory ) ;
	JVoid( *free )( IBaseStateParser ) ; } ;

defineImplementation( CharacterStateParser , characterStateParserMembers )
defineImplementation( StartStateParser , baseStateParserMembers )
defineImplementation( TextStateParser , textStateParserMembers )*/

/*typedef union UStateParser UStateParser ; 

union UStateParser {
	IBaseStateParser base ;
	ICharacterStateParser character ;
	IStartStateParser start ;
	ITextStateParser text ; } ; */

struct DParser {
	PCMParser methods ;
	JBuffer buffer ;
	JIMap map ; } ;
union IParser { PDParser data ; } ;
struct MParser {
	JResult( *execute )( IParser , JCharacter1 , PFactory ) ;
	JVoid( *free )( IParser ) ; } ;

JResult parser(
	JIMap ,
	//JIReader ,
	PIParser ) ;