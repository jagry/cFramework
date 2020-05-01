#define jMapMethod jExport

#include <stdlib.h>
#include <jagry/map.i.h>
#include <jagry/super.h>
#include "node.h"

#include "key.h"

#include "@.h"

#include "item.h"

static JPCMapKeyMethods addFixedMapKey( JVoid ) ;
static JResult createMapKeyFirst( IMapKey , JCPCVoid , JCPCVoid , JPIMapItem ) ;
static JResult getMapKeyInterface( IMapKey , JUnsignedInteger , JPIBase ) ;

static CMMapKey
	fixedMapKey = {
		/* base */
			.acquire = jagryAcquireSuper ,
			.getInterface = getMapKeyInterface ,
			.release = jagryReleaseSuper ,
		/* mapKey */
			.add = addFixedMapKey } ,
	signedIntegerMapKey = {
		/* base */
			.acquire = jagryAcquireSuper ,
			.getInterface = getMapKeyInterface ,
			.release = jagryReleaseSuper ,
		/* mapKey */
			.add = 0 } ,
	unsignedIntegerMapKey = {
		/* base */
			.acquire = jagryAcquireSuper ,
			.getInterface = getMapKeyInterface ,
			.release = jagryReleaseSuper ,
		/* mapKey */
			.add = 0 } ;
static DMapKey dSignedIntegerMapKey = {
	/* base */ ._ = &signedIntegerMapKey , .owner = jNull , .references = 1 ,
	/* mapKey */ .size = 8 } ;
static IMapKey iMapKeys[] = { { ._ = &dSignedIntegerMapKey } } ;

JPCMapKeyMethods addFixedMapKey( JVoid ) {

}

JResult createMapKeyFirst( \
	IMapKey self , JCPCVoid keyIn , JCPCVoid valueIn , JPIMapItem out ) {

}

JResult getMapKeyInterface( IMapKey self , JUnsignedInteger in , JPIBase out ) {
return -1 ;
}

JResult jagryMapKey( JUnsignedInteger in , JOMapKey out ) {
}

JResult jagryGetMapKey( JUnsignedInteger in , JOMapKey out ) {
*out = iMapKeys[ in ] ;
return jSuccessMapResult ;
}

//JResult jagryMapManagerCopy( \
//	JIFixedMapManager self , JPVoid destinationIn , JCPCVoid sourceIn ) {
//memcpy( destinationIn , sourceIn , self._->size ) ;
//return jSuccessMapResult ;
//}
//
//JVoid jagryMapManagerFree( JCPCIMapManager self , JPVoid objectIn ) { }
//
//JResult jagryMapManagerPointer( \
//	JCPCIMapManager self , JPVoid destinationIn, JCPCVoid sourceIn ) {
//memcpy( destinationIn , &sourceIn , sizeof( JPVoid ) ) ;
//return jSuccessMapResult ;
//}