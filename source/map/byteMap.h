typedef struct ByteMap ByteMap ;
typedef struct ByteMapMethods ByteMapMethods ;

typedef ByteMap * PByteMap ;

struct ByteMapMethods { jMapAll( ByteMap ) ; } ;

struct ByteMap {
//JMap* interface ;
//struct
//	{
		jMinimalMembers( ByteMapMethods , methods )
		ByteMapNode* node ;
		JUnsignedInteger count ;
//	} ;
} ;
