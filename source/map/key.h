#define mapKeyMembers \
	jDynamicMembers( PCMMapKey ) \
	JUnsignedInteger size ;

jStdDeclareBaseImplementation( MapKey )
jStdDeclareChildImplementation( FixedMapKey )

#define JOMapKey PIMapKey

#include <jagry/map/key.h>

jStdDefineBaseImplementation( \
	MapKey , \
	jDynamicMembers( PCMMapKey ) , \
	JIMapKey , \
	jMapKeyEach( \
		JIDynamic , \
		IMapKey , \
		JIDynamic , \
		IMapKey , \
		IMapKey , \
		IMapKey , \
		IMapKey ) )
jStdDefineChildImplementation( \
	FixedMapKey , \
	jDynamicMembers( PCMFixedMapKey ) JUnsignedInteger size ; , \
	JIMapKey , \
	jMapKeyEach( \
		JIStatic , \
		IMapKey , \
		JIStatic , \
		IFixedMapKey , \
		IFixedMapKey , \
		IFixedMapKey , \
		IFixedMapKey ) , \
	DMapKey )
