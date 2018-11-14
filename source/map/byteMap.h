#ifdef DEBUG
	#define eraseByteMapReturn( bit , value ) \
		{ \
			jagryDebugEraseByteMap |= bit ; \
			return value ; \
		}
	#define eraseByteMapPointMapEmpty ( 1 << 0 )
	#define eraseByteMapPointOther ( 1 << 1 )
	#define eraseByteMapAllPoint ( \
		eraseByteMapPointMapEmpty | \
		eraseByteMapPointOther )

	extern JUnsignedInteger8 jagryDebugEraseByteMap ;
#endif

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
