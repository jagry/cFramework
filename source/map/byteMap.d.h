#ifdef DEBUG
	#define eraseByteMapIncrement( memberArg , actionArg ) \
		{ \
			++jagryDebugEraseByteMap.memberArg ; \
			actionArg ; \
		}
	#define eraseByteMapPoint( arg ) jagryDebugEraseByteMap.point |= arg
	#define eraseByteMapReturn( pointArg , valueArg ) \
		return jagryDebugEraseByteMap.point |= pointArg , valueArg ;

	#define eraseByteMapConcateParentPoint  ( 1 << 0 ) // Заполнение результатов
	#define eraseByteMapEmptyPoint          ( 1 << 1 ) // Нет узлов, возвращаем "элемент не нейден"
	#define eraseByteMapEndInPoint          ( 1 << 2 )
		// Входящий буфер короче буфера ноды, возвращаем "элемент не нейден"
	#define eraseByteMapLastNodePoint       ( 1 << 3 ) // Узел существует и является единственным в словаре
	#define eraseByteMapMissingChildPoint   ( 1 << 4 )
		// Отсутсвует необходимый дочерний узел, возвращаем "элемент не нейден"
	#define eraseByteMapNotEqualPoint       ( 1 << 5 )
		// Соответствующие байты аргумента и ноды различаются, возвращаем "элемент не нейден"
	#define eraseByteMapNotModifyOwnerPoint ( 1 << 6 )
		// Узел существует, на родительском узле есть значение или другие дочерние узлы(больше одного)
	#define eraseByteMapNoValuePoint        ( 1 << 7 )
		// Узел существует, но не имеет значения, возвращаем "элемент не нейден"
	#define eraseByteMapSetValuePoint       ( 1 << 8 ) // Заполнение результатов
	#define eraseByteMapPointMask ( eraseByteMapConcateParentPoint | eraseByteMapEmpty | eraseByteMapEndIn | \
		eraseByteMapLastNodePoint | eraseByteMapMissingChild | eraseByteMapNotModifyOwnerPoint | \
		eraseByteMapNotEqual | eraseByteMapNoValue | eraseByteMapSetValuePoint )

	typedef struct DebugEraseByteMap {
	JUnsignedInteger2 point ;
	JUnsignedInteger1 byte ;
	JUnsignedInteger1 node ;
	} DebugEraseByteMap ;

	extern DebugEraseByteMap jagryDebugEraseByteMap ;
#else
	#define eraseByteMapIncrement( memberArg , actionArg ) actionArg ;
	#define eraseByteMapPoint( arg )
	#define eraseByteMapReturn( pointArg , valueArg ) return valueArg ;
#endif