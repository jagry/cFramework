#define jMapMethod jExport

#include <stdlib.h>
#include <jagry/buffer.i.h>
#include <jagry/map.i.h>
#include <jagry/super.h>
#include "node.h"

#include "key.h"

#include "@.h"

#include "item.h"

static JResult modifyMap( PIMap , JPVoid , JCPCVoid , JCPCVoid , JPIMapItem ) ;

static CMMap mapMethods = {
	/* map */ .addItem = addMapItem } ;

JResult jagryMap( JCIMapKey in , JOMap out ) {
if( !( *out = malloc( sizeof( IMap ) ) ) ) \
	return jNotEnoughtMemoryErrorResult ;
jInitializeSuper( *out , mapMethods , jNull , 1 )
( *out )->data = ( MapData ){ .count = jNull , .node = jNull } ;
( *out )->key = in ;
jAcquireMapKey( in ) ;
return jSuccessResult ;
}

JResult jagryMapBase(
	JIBase baseIn , JCIMapKey managerIn , JPIBase out ) {
/* !!! Не реализовано же
if( !( *out = malloc( sizeof( IBufferMap ) ) ) )
	return jNotEnoughtMemoryErrorResult ;
jInitializeSuper( *out , data , bufferMap , baseIn.data , 1 )
( *out )->count = jNull ;
( *out )->node.base = jNull ;
return jSuccessResult ; */
}