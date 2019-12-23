#include "byteMap.d.h"

jStdDeclareImplementation( ByteMap )

union IByteMap {
	PDByteMap data ; } ;
		
struct DByteMap {
	jSuperMembers( PCMByteMap , methods )
	IByteMapNode node ;
	JUnsignedInteger count ; } ;
	
struct MByteMap { jAllMap( IByteMap ) } ;