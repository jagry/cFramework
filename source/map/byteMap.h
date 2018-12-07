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
	#define eraseByteMapReturn( point , value ) \
		{ \
			jagryDebugEraseByteMap.exit = point ; \
			result = value ; \
			break ; \
		}
	#define eraseByteMapPoint( member , action ) \
		{ \
			++jagryDebugEraseByteMap.member ; \
			action ; \
		}
	#define eraseByteMapEmpty        ( 1 << 0 ) /* Нет узлов, возвращаем "элемент не нейден" */
	#define eraseByteMapEndIn        ( 1 << 1 ) /* Входящий буфер короче буфера ноды, возвращаем "элемент не нейден" */
	#define eraseByteMapMissingChild ( 1 << 2 ) /* Отсутсвует необходимый дочерний узел, возвращаем "элемент не нейден" */
	#define eraseByteMapNotEqual     ( 1 << 3 ) /* Соответствующие байты аргумента и ноды различаются, возвращаем "элемент не нейден" */
	#define eraseByteMapNoValue      ( 1 << 4 ) /* Узел существует, но не имеет значения, возвращаем "элемент не нейден" */
	#define eraseByteMapAll ( eraseByteMapEmpty | eraseByteMapEndIn | eraseByteMapMissingChild | eraseByteMapNoValue )

	typedef struct JDebugEraseByteMap {
	JUnsignedInteger8 byte ;
	JUnsignedInteger8 node ;
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