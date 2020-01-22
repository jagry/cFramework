#define builderDefineImplementation( name , members ) \
	union I##name { IBaseBuilder base ; PD##name data ; } ; \
	struct D##name { PCM##name methods ; members } ; \
	struct M##name { \
		JResult( *execute )( IBaseBuilder ) ; \
		JVoid( *free )( IBaseBuilder ) ; \
		JResult( *pop )( PI##name , UToken ) ; \
		JResult( *push )( PI##name , PUToken ) ; } ;

#define baseBuilderMembers IBaseBuilder owner ;
#define unitBuilderMembers baseBuilderMembers
#define variableBuilderMembers baseBuilderMembers

jStdDeclareImplementation( BaseBuilder )
jStdDeclareImplementation( UnitBuilder )
jStdDeclareImplementation( VariableBuilder )
jStdDeclareImplementation( VariableItemBuilder )
	
struct DBuilder {
	PCMBaseBuilder methods ; } ;
	
union IBaseBuilder {
	PCMBaseBuilder * methods ; } ;

struct MBaseBuilder {
	JResult( *execute )( IBaseBuilder ) ;
	JVoid( *free )( IBaseBuilder ) ;
	JResult( *pop )( IBaseBuilder , UToken ) ;
	JResult( *push )( IBaseBuilder , UToken ) ; } ;
	
builderDefineImplementation( UnitBuilder , baseBuilderMembers )
builderDefineImplementation( VariableBuilder , variableBuilderMembers )
builderDefineImplementation( VariableItemBuilder , baseBuilderMembers )

typedef union UBuilder UBuilder ;

union UBuilder {
	IBaseBuilder base ;
	IUnitBuilder unit ;
	IVariableBuilder variable ;
	IVariableItemBuilder variableItem ; } ;
	
extern DUnitBuilder dUnitBuilder ;