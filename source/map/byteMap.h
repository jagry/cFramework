#ifdef DEBUG
	#define byteMapReturn( point , value , variable ) \
		{ \
			variable.exit = point ; \
			return value ; \
		}
	#define byteMapPoint( member , action ) \
		{ \
			++jagryDebugEraseByteMap.member ; \
			action ; \
		}
	#define eraseByteMapReturn( point , value ) byteMapReturn( point , value , jagryDebugEraseByteMap )
	#define eraseByteMapPoint( member , action ) \
		{ \
			++jagryDebugEraseByteMap.member ; \
			action ; \
		}
	#define eraseByteMapPointReturnEmpty   ( 1 << 0 ) /* Нет узлов, возвращаем "элемент не нейден" */
	#define eraseByteMapPointReturnEndIn   ( 1 << 1 ) /* Входящий буфер короче буфера ноды, возвращаем "элемент не нейден" */
	#define eraseByteMapPointReturnNoValue ( 1 << 2 ) /* Узел существует, но не имеет значения, возвращаем "элемент не нейден" */
	#define eraseByteMapAllPoint ( \
		eraseByteMapPointByte | \
		eraseByteMapPointNode | \
		eraseByteMapPointReturnEmpty | \
		eraseByteMapPointReturnEndIn | \
		eraseByteMapPointReturnNoValue )

	typedef struct JDebugEraseByteMap {
	JUnsignedInteger1 byte ;
	JUnsignedInteger1 node ;
	JUnsignedInteger1 exit ;
	} JDebugEraseByteMap ;

	extern JDebugEraseByteMap jagryDebugEraseByteMap ;
#else
	#define eraseByteMapReturn( bit , value ) \
		{ \
			return value ; \
		}
	#define eraseByteMapBreak( bit , value ) \
		{ \
			break ; \
		}

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
