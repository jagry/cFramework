#define jMapMethod jExport

#include <stdlib.h>
#include <jagry/buffer.i>
#include <jagry/dynamic.l>
#include <jagry/map.i>
#include <jagry/static.l>

#include <jagry/map/node>

#include <jagry/map/data.h>

#include "key.h"

#include "@.h"

#include "item.h"

static JResult addMapItem( PIMap , JCPCVoid , JCPCVoid , JPIMapItem ) ;

static CMMap map = {
	/* map */ .addItem = addMapItem } ;

JResult addMapItem( \
	PIMap self , JCPCVoid keyIn , JCPCVoid valueIn , JPIMapItem out ) {
return ( *self->key._ )->add( \
	self->key , &self->data , keyIn , valueIn , out) ;
}

JResult jagryMap( JCIMapKey in , JOMap out ) {
if( !( *out = malloc( sizeof( IMap ) ) ) ) \
	return jNotEnoughtMemoryErrorResult ;
jInitializeDynamic( *out , map , jNull , 1 )
( *out )->data = ( JMapData ){ .count = jNull , .node = jNull } ;
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