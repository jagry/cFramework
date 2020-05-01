#define mapKeyMembers \
	jSuperMembers( PCMMapKey , _ ) \
	JUnsignedInteger size ;

jStdDeclareImplementation( MapKey )
jStdDeclareImplementation( IntegerMapKey )

static JResult getMapKeyInterface( IMapKey , JUnsignedInteger , JPIBase ) ;

#define JOMapKey PIMapKey

#include <jagry/map/key.h>

jStdDefineImplementation( \
	MapKey , \
	mapKeyMembers , \
	JIMapKey , \
	jMapKeyEach( JISuper , IMapKey , JISuper , IMapKey ) )
jStdDefineImplementation( \
	IntegerMapKey , \
	mapKeyMembers , \
	JIMapKey , \
	jMapKeyEach(
		JISuper , IMapKey , JISuper , IIntegerMapKey ) )