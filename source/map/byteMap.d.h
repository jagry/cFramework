#ifdef DEBUG
	#define eraseByteMapIncrement( memberArg , actionArg ) \
		{ \
			++jagryDebugEraseByteMap.memberArg ; \
			actionArg ; \
		}
	#define eraseByteMapPoint( arg ) jagryDebugEraseByteMap.point |= arg
	#define eraseByteMapReturn( pointArg , valueArg ) return jagryDebugEraseByteMap.point |= pointArg , valueArg ;

	#define eraseByteMapEmptyPoint        ( 1 << 0 ) /* Нет узлов, возвращаем "элемент не нейден" */
	#define eraseByteMapEndInPoint        ( 1 << 1 ) /* Входящий буфер короче буфера ноды, возвращаем "элемент не нейден" */
	#define eraseByteMapLastNodePoint     ( 1 << 2 ) /* Узел существует и является единственным в словаре */
	#define eraseByteMapMissingChildPoint ( 1 << 3 ) /* Отсутсвует необходимый дочерний узел, возвращаем "элемент не нейден" */
	#define eraseByteMapNotEqualPoint     ( 1 << 4 ) /* Соответствующие байты аргумента и ноды различаются, возвращаем "элемент не нейден" */
	#define eraseByteMapNoValuePoint      ( 1 << 5 ) /* Узел существует, но не имеет значения, возвращаем "элемент не нейден" */
	#define eraseByteMapPointMask ( eraseByteMapEmpty | eraseByteMapEndIn | eraseByteMapLastNodePoint | eraseByteMapMissingChild | eraseByteMapNotEqual | \
		eraseByteMapNoValue )

	typedef struct DebugEraseByteMap {
	JUnsignedInteger1 point ;
	JUnsignedInteger1 byte ;
	JUnsignedInteger1 node ;
	} DebugEraseByteMap ;

	extern DebugEraseByteMap jagryDebugEraseByteMap ;
#else
	#define eraseByteMapIncrement( memberArg , actionArg ) actionArg ;
	#define eraseByteMapPoint( arg )
	#define eraseByteMapReturn( pointArg , valueArg ) return valueArg ;
#endif