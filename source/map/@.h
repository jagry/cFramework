#define JOMap PPIMap

#include <jagry/dynamic.l>

typedef struct MMap const CMMap ;
typedef struct IMap IMap ;
typedef struct IMapItem * PIMapItem ;

typedef CMMap * PCMMap ;
typedef IMap * PIMap ;

typedef PIMap * PPIMap ;

struct IMap {
	jDynamicMembers( PCMMap )
	JCIMapKey key ;
	JMapData data ; } ;
struct MMap { jMapAll( PIMap ) } ;