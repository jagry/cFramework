#define JOMap PPIMap

#include <jagry/super.h>

typedef struct MapData MapData ;
typedef struct MMap const CMMap ;
typedef struct IMap IMap ;
typedef struct IMapItem * PIMapItem ;

typedef CMMap * PCMMap ;
typedef IMap * PIMap ;

typedef PIMap * PPIMap ;

struct MapData {
	JUnsignedInteger count ;
	UMapNode node ; } ;
struct IMap {
	jSuperMembers( PCMMap , _ )
	JIMapKey key ;
	MapData data ; } ;
struct MMap { jMapAll( PIMap ) } ;