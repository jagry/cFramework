#include "byteMap.d.h"

typedef struct ByteMap ByteMap ;
typedef struct ByteMapMethods ByteMapMethods ;

typedef ByteMap * PByteMap ;

struct ByteMapMethods { jAllMap( ByteMap ) ; } ;

struct ByteMap {
//JMap* interface ;
//struct
//	{
		jMinimalMembers( ByteMapMethods , methods )
		ByteMapNode* node ;
		JUnsignedInteger count ;
//	} ;
} ;