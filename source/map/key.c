//#define jMapMethod jExport
//
//#include <jagry/buffer.l>
//#include <jagry/dynamic.l>
//#include <jagry/map.i>
//#include <jagry/static.l>
//#include <stdlib.h>
//
//#include <jagry/map/node>
//
//#include <jagry/map/data.h>
//#include "node.h"
//
//#include "key.h"
//
//#include "@.h"
//
//#include "item.h"
//
//typedef struct FixedMapKeyUpdater const CFixedMapKeyUpdater ;
//typedef JResult( *CreateFixedMapKeyUpdaterFirst )( \
//	IFixedMapKey , JPMapData , JCPCVoid , JCPCVoid , JPIMapItem ) ;
//
//typedef CFixedMapKeyUpdater * const PCFixedMapKeyUpdater ;
//
//struct FixedMapKeyUpdater {
//	CreateFixedMapKeyUpdaterFirst createFirst ; } ;
//
//// Добавить пункт для словаря с ключом фиксированого размера
//static JResult addFixedMapKeyItem( \
//	IFixedMapKey , JPMapData , JCPCVoid , JCPCVoid , JPIMapItem ) ;
//// Создать первый узел словаря с ключом
//// фиксированого размера операций Add, New и Set
//static JResult createFixedMapKeyUpdaterFirst ( \
//	IFixedMapKey , JPMapData , JCPCVoid , JCPCVoid , JPIMapItem ) ;
//// Создать первый узел словаря с ключом
//// фиксированого размера операции Put
//static JResult createPutFixedMapKeyUpdaterFirst ( \
//	IFixedMapKey , JPMapData , JCPCVoid , JCPCVoid , JPIMapItem ) ;
//// Создать узел словаря с ключом фиксированого
//// размера содержащим только значение
//JResult createValueFixedMapKeyNode( \
//	IFixedMapKey , JCPCVoid , JSize , JCPCVoid , JPIMapItem ) ;
//static JResult getMapKeyInterface( IMapKey , JUnsignedInteger , JPIBase ) ;
//static JResult fixedMapKeyItem( \
//	IFixedMapKey , \
//	PCFixedMapKeyUpdater , \
//	JPMapData , \
//	JCPCVoid , \
//	JCPCVoid , \
//	JPIMapItem ) ;
//
//static CMFixedMapKey fixedMapKey = {
//	/* base */
//		.acquire = jagryAcquireStatic ,
//		.getInterface = getMapKeyInterface ,
//		.release = jagryReleaseStatic ,
//	/* mapKey */
//		.add = addFixedMapKeyItem } ;
//static CFixedMapKeyUpdater addFixedMapKeyUpdater = {
//	.createFirst = createFixedMapKeyUpdaterFirst } ;
//static CFixedMapKeyUpdater newFixedMapKeyUpdater = {
//	.createFirst = createFixedMapKeyUpdaterFirst } ;
//static CFixedMapKeyUpdater putFixedMapKeyUpdater = {
//	.createFirst = createPutFixedMapKeyUpdaterFirst } ;
//static CFixedMapKeyUpdater setFixedMapKeyUpdater = {
//	.createFirst = createFixedMapKeyUpdaterFirst } ;
//
//static DFixedMapKey dSignedIntegerMapKey = { ._ = {
//	/* base */ ._ = &fixedMapKey , .owner = jNull , .references = 1 ,
//	/* mapKey */ .size = 8 } } ;
//
//static IMapKey iMapKeys[] = { { ._ = &dSignedIntegerMapKey.base } } ;
//
//JResult addFixedMapKeyItem( \
//	IFixedMapKey self , \
//	JPMapData dataIn , \
//	JCPCVoid keyIn , \
//	JCPCVoid valueIn , \
//	JPIMapItem out ) {
//return fixedMapKeyItem( \
//	self, &addFixedMapKeyUpdater , dataIn , keyIn , valueIn , out ) ;
//}
//
//JResult createFixedMapKeyUpdaterFirst( \
//	IFixedMapKey self , \
//	JPMapData dataIn , \
//	JCPCVoid keyIn , \
//	JCPCVoid valueIn , \
//	JPIMapItem out ) {
//return createValueFixedMapKeyNode( \
//	self , keyIn , self._->_.size , valueIn , out ) ;
//}
//
//JResult createPutFixedMapKeyUpdaterFirst( \
//	IFixedMapKey self , \
//	JPMapData dataIn , \
//	JCPCVoid keyIn , \
//	JCPCVoid valueIn , \
//	JPIMapItem out ) {
//return jItemNotFoundErrorMapResult ;
//}
//
//JResult createValueFixedMapKeyNode( \
//	IFixedMapKey self , \
//	JCPCVoid keyIn , \
//	JSize sizeIn , \
//	JCPCVoid valueIn , \
//	JPIMapItem out ) {
//JResult result ;
//JPValueMapNode node = malloc( sizeof( JValueMapNode ) ) ;
//if( !node )
//	return jNotEnoughtMemoryErrorMapResult ;
//if( !( node->item = malloc( sizeof( IMapItem ) ) ) )
//	return jNotEnoughtMemoryErrorMapResult ;
//if( jResultIsError( result = \
//		jagryInitializeBuffer( &node->buffer , keyIn , sizeIn ) ) )
//	return free( node ) , result ;
//node->type = jValueMapNodeType ;
//return jSuccessMapResult ;
//}
//
//JResult fixedMapKeyItem( \
//	IFixedMapKey self , \
//	PCFixedMapKeyUpdater updaterIn , \
//	JPMapData dataIn , \
//	JCPCVoid keyIn , \
//	JCPCVoid valueIn , \
//	JPIMapItem out ) {
//if( !dataIn->node.base )
//	return updaterIn->createFirst( self , dataIn , keyIn , valueIn , out ) ;
//}
//
//JResult getMapKeyInterface( IMapKey self , JUnsignedInteger in , JPIBase out ) {
//return -1 ;
//}
//
//JResult jagryMapKey( JUnsignedInteger in , JOMapKey out ) {
//}
//
//JResult jagryGetMapKey( JUnsignedInteger in , JOMapKey out ) {
//*out = iMapKeys[ in ] ;
//return jSuccessMapResult ;
//}
//
//JResult newFixedMapKeyItem( \
//	IFixedMapKey self , \
//	JPMapData dataIn , \
//	JCPCVoid keyIn , \
//	JCPCVoid valueIn , \
//	JPIMapItem out ) {
//return fixedMapKeyItem( \
//	self , &newFixedMapKeyUpdater , dataIn , keyIn , valueIn , out ) ;
//}
//
//JResult putFixedMapKeyItem( \
//	IFixedMapKey self , \
//	JPMapData dataIn , \
//	JCPCVoid keyIn , \
//	JCPCVoid valueIn , \
//	JPIMapItem out ) {
//return fixedMapKeyItem( \
//	self , &putFixedMapKeyUpdater , dataIn , keyIn , valueIn , out ) ;
//}
//
//JResult setFixedMapKeyItem( \
//	IFixedMapKey self , \
//	JPMapData dataIn , \
//	JCPCVoid keyIn , \
//	JCPCVoid valueIn , \
//	JPIMapItem out ) {
//return fixedMapKeyItem( \
//	self , &setFixedMapKeyUpdater , dataIn , keyIn , valueIn , out ) ;
//}
//
////JResult jagryMapManagerCopy( \
////	JIFixedMapManager self , JPVoid destinationIn , JCPCVoid sourceIn ) {
////memcpy( destinationIn , sourceIn , self._->size ) ;
////return jSuccessMapResult ;
////}
////
////JVoid jagryMapManagerFree( JCPCIMapManager self , JPVoid objectIn ) { }
////
////JResult jagryMapManagerPointer( \
////	JCPCIMapManager self , JPVoid destinationIn, JCPCVoid sourceIn ) {
////memcpy( destinationIn , &sourceIn , sizeof( JPVoid ) ) ;
////return jSuccessMapResult ;
////}