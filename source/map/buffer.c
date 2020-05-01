///* !!! */ #include <stdio.h>
//
//#define jMapMethod jExport
//#define bufferMapNodeCount ( jMaxUnsignedInteger1 + 1 )
//#define baseBufferMapNodeMembers \
//	JBuffer buffer ; \
//	PBaseBufferMapNode owner ; \
//	JByte index ; \
//	JByte type ;
//#define subsBufferMapNodeMembers baseBufferMapNodeMembers \
//	UBufferMapNode subs[ bufferMapNodeCount ] ;
//#define valueBufferMapNodeMembers baseBufferMapNodeMembers \
//	IBufferMapItem item ;
//#define fullBufferMapNodeType  0
//#define valueBufferMapNodeType 1
//#define subBufferMapNodeType   2
//#define subsBufferMapNodeType  3
//
//#include <jagry/buffer.l.h>
//#include <jagry/map.i.h>
//#include <jagry/map/manager.h>
//#include <jagry/super.h>
//#include <memory.h>
//#include <stdlib.h>
//
//typedef struct BufferMapItem BufferMapItem ;
//typedef struct BufferMapModifier const CBufferMapModifier ;
//typedef struct MBufferMap const CMBufferMap ;
//typedef struct MBufferMapItem const CMBufferMapItem ;
//typedef struct BaseBufferMapNode BaseBufferMapNode ;
//typedef union FullBufferMapNode FullBufferMapNode ;
//typedef struct IBufferMap IBufferMap ;
//typedef struct BufferMapItem * IBufferMapItem ;
//typedef JResult( *SetValueBufferMapNodeModifier )( void ) ;
//typedef union SubBufferMapNode SubBufferMapNode ;
//typedef union SubsBufferMapNode SubsBufferMapNode ;
//typedef union UBufferMapNode UBufferMapNode ;
//typedef union ValueBufferMapNode ValueBufferMapNode ;
//
//typedef BaseBufferMapNode * PBaseBufferMapNode ;
//typedef BufferMapItem * PBufferMapItem ;
//typedef CBufferMapModifier * PCBufferMapModifier ;
//typedef FullBufferMapNode * PFullBufferMapNode ;
//typedef CMBufferMap * PCMBufferMap ;
//typedef CMBufferMapItem * PCMBufferMapItem ;
//typedef IBufferMap * PIBufferMap ;
//typedef IBufferMapItem * PIBufferMapItem ;
//typedef SubBufferMapNode * PSubBufferMapNode ;
//typedef SubsBufferMapNode * PSubsBufferMapNode ;
//typedef UBufferMapNode * PUBufferMapNode ;
//typedef ValueBufferMapNode * PValueBufferMapNode ;
//
//typedef PIBufferMap * JLBufferMap ;
//typedef PFullBufferMapNode * PPFullBufferMapNode ;
//typedef PSubBufferMapNode * PPSubBufferMapNode ;
//typedef PSubsBufferMapNode * PPSubsBufferMapNode ;
//typedef PValueBufferMapNode * PPValueBufferMapNode ;
//
//#include <jagry/map/byte.h>
//
//typedef JResult( *InsertValueBufferMapNodeItemModifier )( \
//	PUBufferMapNode , PIBufferMap , JCPCBuffer , JCPCVoid , PIBufferMapItem ) ;
//typedef JResult( *SplitSubBufferMapNodeItemModifier )( \
//	PUBufferMapNode , \
//	JSize , \
//	PIBufferMap , \
//	JCPCBuffer , \
//	JCPCVoid , \
//	PIBufferMapItem ) ;
//
//struct BaseBufferMapNode { baseBufferMapNodeMembers } ;
//struct BufferMapItem {
//	PCMBufferMapItem _ ;
//	PIBufferMap map ;
//	PBaseBufferMapNode node ; 
//	JByte value[] ; } ;
//union IBufferMapItem { PBufferMapItem _ ; /* JIBufferMapItem interface ; */ } ;
//struct MBufferMap { jMapEach( JISuper , PIBufferMap , PIBufferMap ,
//	PIBufferMap , PIBufferMap , PIBufferMap , PIBufferMap , PIBufferMap ,
//	PIBufferMap , PIBufferMap , PIBufferMap , PIBufferMap , PIBufferMap ,
//	JCBuffer , JCPCBuffer , PIBufferMapItem ) } ;
//struct MBufferMapItem { jAllMapItem( IBufferMapItem ) } ;
//union SubBufferMapNode {
//	struct {
//		valueBufferMapNodeMembers
//		PBaseBufferMapNode sub ;
//		JByte subIndex ; } _ ;
//	BaseBufferMapNode base ; } ;
//union UBufferMapNode {
//	PBaseBufferMapNode base ;
//	PFullBufferMapNode full ;
//	PSubBufferMapNode sub ;
//	PSubsBufferMapNode subs ;
//	PValueBufferMapNode value ; } ;
//union ValueBufferMapNode { 
//	struct { valueBufferMapNodeMembers } _ ;
//	BaseBufferMapNode base ; } ;
//
//
//union FullBufferMapNode {
//	struct {
//		subsBufferMapNodeMembers
//		IBufferMapItem item ; } _ ;
//	BaseBufferMapNode base ; } ;
//union SubsBufferMapNode {
//	struct { subsBufferMapNodeMembers } _ ;
//	BaseBufferMapNode base ; } ;
//
//static JResult addBufferMapItem( \
//	PIBufferMap , JCPCBuffer , JCPCVoid , PIBufferMapItem ) ;
//static JResult clearBufferMap( PIBufferMap ) ;
//static JResult createBufferMapItem( \
//	PIBufferMap , JCPCVoid , PBaseBufferMapNode , PIBufferMapItem ) ;
//static JResult createFirstBufferMapItem( \
//	PIBufferMap , JCPCBuffer , JCPCVoid , PIBufferMapItem ) ;
//static JResult createFullBufferMapNode( \
//	JCPCMapManager , \
//	JCPCBuffer , \
//	PBaseBufferMapNode , \
//	JCPCVoid , \
//	PPFullBufferMapNode ) ;
//static JResult createSubBufferMapNode( \
//	PIBufferMap , \
//	JCPCBuffer , \
//	PBaseBufferMapNode , \
//	JCPCVoid , \
//	PPSubBufferMapNode ) ;
//static JResult createSubsBufferMapNode( \
//	PIBufferMap , JCPCBuffer , PBaseBufferMapNode , PPSubsBufferMapNode ) ;
//static JResult createValueBufferMapNode( \
//	PIBufferMap , \
//	JCPCBuffer , \
//	PBaseBufferMapNode , \
//	JCPCVoid , \
//	PPValueBufferMapNode ) ;
//static JResult eraseBufferMapItem( PIBufferMap , JCPCBuffer ) ;
//static JVoid freeBufferMapItem( IBufferMapItem ) ;
//static JVoid freeSubBufferMapNode( PSubBufferMapNode ) ;
//static JVoid freeSubsBufferMapNode( PSubsBufferMapNode ) ;
//static JResult getBufferMapItem( PIBufferMap , JCBuffer , PIBufferMapItem ) ;
//static JCounter getBufferMapItemValue( IBufferMapItem , JPVoid ) ;
//static JResult getBufferMapValue( PIBufferMap , JBuffer , JPVoid ) ;
//static JResult newAddSubsBufferMapNode( \
//	PUBufferMapNode , \
//	PIBufferMap , \
//	JCPCBuffer , \
//	JCPCVoid , \
//	PIBufferMapItem ) ;
//static JResult newAddValueBufferMapNode( \
//	PUBufferMapNode , \
//	PIBufferMap , \
//	JCPCBuffer , \
//	JCPCVoid , \
//	PIBufferMapItem ) ;
//static JResult newBufferMapItem( \
//	PIBufferMap , JCPCBuffer , JCPCVoid , PIBufferMapItem ) ;
//static JResult newInsertValueBufferMapNode( \
//	PUBufferMapNode , PIBufferMap , JCPCBuffer , JCPCVoid , PIBufferMapItem ) ;
//static JResult newSetValueBufferMapNode( void ) ;
//static JResult newSplitSubBufferMapNode( \
//	PUBufferMapNode , \
//	JSize , \
//	PIBufferMap , \
//	JCPCBuffer , \
//	JCPCVoid , \
//	PIBufferMapItem ) ;
//static JCounter releaseBufferMap( PIBufferMap ) ;
//
//static CMBufferMap bufferMap = { \
//	/* base */ \
//		.acquire = jagryAcquireSuper , \
//		.getInterface = 0 , \
//		.release = releaseBufferMap , \
//	/* map */ \
//		.addItem = addBufferMapItem , \
//		.clear = clearBufferMap , \
//		.eraseItem = eraseBufferMapItem , \
//		.getFirst = 0 , \
//		.getItem = getBufferMapItem , \
//		.getLast = 0 , \
//		.getValue = getBufferMapValue , \
//		.newItem = newBufferMapItem } ;
//static CMBufferMapItem bufferMapItem = { \
//	.getValue = getBufferMapItemValue } ;
//static CBufferMapModifier \
//	addBufferMapModifier = { \
//		.addSubsItem = 0 , \
//		.addValueItem = 0 , \
//		.createFirstItem = createFirstBufferMapItem , \
//		.insertValue = 0 , \
//		.setValue = 0 , \
//		.splitSub = 0 } ,
//	newBufferMapModifier = { \
//		.addSubsItem = newAddSubsBufferMapNode , \
//		.addValueItem = newAddValueBufferMapNode , \
//		.createFirstItem = createFirstBufferMapItem , \
//		.insertValue = newInsertValueBufferMapNode , \
//		.setValue = newSetValueBufferMapNode , \
//		.splitSub = newSplitSubBufferMapNode } ;
//
//JResult clearBufferMap( PIBufferMap self ) {
//}
//
//JResult createBufferMapItem( \
//	PIBufferMap mapIn , \
//	JCPCVoid valueIn , \
//	PBaseBufferMapNode ownerIn , \
//	PIBufferMapItem out ) {
//JResult result ;
//if( !( *out =
//		malloc( sizeof( BufferMapItem ) + mapIn->manager->size ) ) )
//	return jNotEnoughtMemoryErrorMapResult ;
//if( jResultIsError( result = mapIn->manager->set(
//		mapIn->manager , &( *out )->value , valueIn ) ) )
//	return free( *out ) , result ;
//( *out )->_ = &bufferMapItem ;
//( *out )->map = mapIn ;
//( *out )->node = ownerIn ;
//return jSuccessResult ;
//}
//
//JResult createFirstBufferMapItem( \
//	PIBufferMap mapIn , \
//	JCPCBuffer keyIn , \
//	JCPCVoid valueIn , \
//	PIBufferMapItem out ) {
//JResult result = createValueBufferMapNode( \
//	mapIn , keyIn , jNull , valueIn , &mapIn->node.value ) ;
//if( jResultIsError( result ) ) return result ;
//if( out ) *out = mapIn->node.value->_.item ;
//mapIn->count = 1 ;
//return jSuccessMapResult ;
//}
//
//// !!! Может быть стоит передавать и субзначение?
//JResult createSubBufferMapNode( \
//	PIBufferMap mapIn , \
//	JCPCBuffer keyIn , \
//	PBaseBufferMapNode ownerIn , \
//	JCPCVoid valueIn , \
//	PPSubBufferMapNode out ) {
//// !!! Не учтена ситуация с генерацией нескольких предупреждений
//JResult result ;
//if( !( *out = malloc( sizeof( SubBufferMapNode ) ) ) ) \
//	return jNotEnoughtMemoryErrorMapResult ;
//if( jResultIsNotError( result = createBufferMapItem( \
//		mapIn , valueIn , &( *out )->base , &( *out )->_.item ) ) )
//	{
//		if( jResultIsNotError( result = jagryInitializeBuffer( \
//				&( *out )->_.buffer , keyIn->bytes , keyIn->size ) ) ) \
//			return \
//				( *out )->_.type = subBufferMapNodeType , \
//				( *out )->_.owner = ownerIn , \
//				jSuccessMapResult ;
//		freeBufferMapItem( ( *out )->_.item ) ;
//	}
//return free( *out ) , result ;
//}
//
//JResult createSubsBufferMapNode( \
//	PIBufferMap mapIn , \
//	JCPCBuffer keyIn , \
//	PBaseBufferMapNode ownerIn , \
//	PPSubsBufferMapNode out ) {
//JResult result ;
//if( !( *out = malloc( sizeof( SubsBufferMapNode ) ) ) ) \
//	return jNotEnoughtMemoryErrorMapResult ;
//if( jResultIsError( result = jagryInitializeBuffer( \
//		&( *out )->_.buffer , keyIn->bytes , keyIn->size ) ) ) \
//	return free( *out ) , result ;
//( *out )->_.type = subsBufferMapNodeType ;
//( *out )->_.owner = ownerIn ;
//memset( ( *out )->_.subs , jNull , sizeof( ( *out )->_.subs ) ) ;
//return result ;
//}
//
//JResult createValueBufferMapNode( \
//	PIBufferMap mapIn , \
//	JCPCBuffer keyIn , \
//	PBaseBufferMapNode ownerIn , \
//	JCPCVoid valueIn , \
//	PPValueBufferMapNode out ) {
//// !!! Не учтена ситуация с генерацией нескольких предупреждений
//JResult result ;
//if( !( *out = malloc( sizeof( ValueBufferMapNode ) ) ) ) \
//	return jNotEnoughtMemoryErrorMapResult ;
//if( jResultIsNotError( result = jagryInitializeBuffer(
//		&( *out )->_.buffer , keyIn->bytes , keyIn->size ) ) )
//	{
//		if( jResultIsNotError( result = createBufferMapItem( \
//				mapIn , valueIn , &( *out )->base , &( *out )->_.item ) ) ) \
//			return \
//				( *out )->_.owner = ownerIn , \
//				( *out )->_.type = valueBufferMapNodeType , \
//				result ;
//		jagryClearBuffer( &( *out )->_.buffer ) ;
//	}
//free( *out ) ;
//return result ;
//}
//
//JResult eraseBufferMapItem( PIBufferMap self , JCPCBuffer in ) {
///*JPMapItem item ;
//JResult status = getByteMapItem( self , in , &item ) ;
//if( jResultIsError( status ) )
//	return status ;
//return jMapItemErase( item ) ;*/
//}
//
//JVoid freeBufferMapItem( IBufferMapItem self ) {
//// !!! Не реализовано
//}
//
//JVoid freeSubBufferMapNode( PSubBufferMapNode self ) {
//// Cтоит переделать это в define???
//jagryClearBuffer( &self->_.buffer ) ;
//freeBufferMapItem( self->_.item ) ;
//free( self ) ;
//}
//
//JVoid freeSubsBufferMapNode( PSubsBufferMapNode self ) {
//// !!! Не реализовано
//}
//
//JResult getBufferMapItem(
//	PIBufferMap self , JBuffer in , PIBufferMapItem out ) {
//UBufferMapNode node = self->node ;
//if( !node.base )
//	return jValueNotFoundErrorMapResult ;
//for( JBuffer key = node.base->buffer ; ; ++in.bytes , --in.size ) \
//	if( key.size )
//		if( in.size )
//			if( *key.bytes != *in.bytes )
//				return jValueNotFoundErrorMapResult ;
//			else
//				++key.bytes , --key.size ;
//		else
//			return jValueNotFoundErrorMapResult ;
//	else
//		if( in.size ) \
//			if( ( node.base->type == fullBufferMapNodeType \
//					|| node.base->type == subsBufferMapNodeType \
//					) && node.subs->_.subs[ *in.bytes ].base ) \
//				key = ( node = node.subs->_.subs[ *in.bytes ] ).subs->_.buffer ;
//			else
//				return jValueNotFoundErrorMapResult ;
//		else
//			switch( node.base->type ) {
//			case fullBufferMapNodeType : \
//				return *out = node.full->_.item , jSuccessMapResult ;
//			case subBufferMapNodeType : \
//				return *out = node.sub->_.item , jSuccessMapResult ;
//			case subsBufferMapNodeType : return jValueNotFoundErrorMapResult ;
//			default : return *out = node.value->_.item , jSuccessMapResult ;
//	}
//}
//
//JResult getBufferMapItemValue( IBufferMapItem self , JPVoid out ) {
//return self->map->manager->get( self->map->manager , out , &self->value ) ;
//}
//
//JResult getBufferMapValue( PIBufferMap self , JBuffer in , JPVoid out ) {
//IBufferMapItem item ;
//JResult result = getBufferMapItem( self , in , &item ) ;
//return jResultIsError( result ) ? result : item->_->getValue( item , out ) ;
//}
//
//static JResult newAddSubsBufferMapNode( \
//	PUBufferMapNode nodeArg ,
//	PIBufferMap mapIn ,
//	JCPCBuffer keyIn ,
//	JCPCVoid valueIn ,
//	PIBufferMapItem out ) {
//}
//
//// !!! Может стоит назвать функцию newAddValueBufferMapNodeSub ?
//JResult newAddValueBufferMapNode(
//	PUBufferMapNode nodeArg ,
//	PIBufferMap mapIn ,
//	JCPCBuffer keyIn ,
//	JCPCVoid valueIn ,
//	PIBufferMapItem out ) {
//PSubBufferMapNode node ;
//JResult result = createSubBufferMapNode(
//	mapIn , keyIn , jNull , nodeArg->value->_.item->value , &node ) ;
//if( jResultIsNotError( result ) )
//	{
//		{
//			JBuffer buffer = node->_.buffer ;
//			node->_.buffer = nodeArg->value->_.buffer ;
//			nodeArg->value->_.buffer = buffer ;
//		}
//		{
//			PBaseBufferMapNode _ = node->_.item->node ;
//			node->_.item->node = nodeArg->value->_.item->node ;
//			nodeArg->value->_.item->node = _ ;
//		}
//		{
//			IBufferMapItem item = node->_.item ;
//			node->_.item = nodeArg->value->_.item ;
//			nodeArg->value->_.item = item ;
//		}
//		node->_.subIndex = nodeArg->value->_.index = *keyIn->bytes ;
//		nodeArg->value->_.owner = &node->base ;
//		node->_.sub = &nodeArg->value->base ;
//		nodeArg->base = &node->base ;
//	}
//return result ;
//}
//
//JResult newBufferMapItem( \
//	PIBufferMap self , \
//	JCPCBuffer keyIn , \
//	JCPCVoid valueIn , \
//	PIBufferMapItem out ) {
//return modifyBufferMapItem(
//	self , &newBufferMapModifier , keyIn , valueIn , out) ;
//}
//
//JResult newInsertValueBufferMapNode(
//	PUBufferMapNode nodeArg ,
//	PIBufferMap mapIn ,
//	JCPCBuffer keyIn ,
//	JCPCVoid valueIn ,
//	PIBufferMapItem out ) {
//PSubBufferMapNode node ;
//{
//	JResult result = createSubBufferMapNode( \
//		mapIn , \
//		&jBuffer( keyIn->bytes + 1 , keyIn->size - 1 ) , \
//		nodeArg->value->_.owner , \
//		valueIn , \
//		&node ) ;
//	if( jResultIsError( result ) ) return result ;
//}
//{
//	JBuffer buffer = node->_.buffer ;
//	node->_.buffer = nodeArg->base->buffer ;
//	nodeArg->base->buffer = buffer ;
//}
//{
//	JPByte bytes = realloc( \
//		node->_.buffer.bytes , node->_.buffer.size -= keyIn->size ) ;
//	if( bytes ) node->base.buffer.bytes = bytes ;
//}
//node->_.subIndex = *keyIn->bytes ;
//node->_.sub = nodeArg->base ;
//nodeArg->base = &node->base ;
//if( out ) *out = ( nodeArg->sub = node )->_.item ;
//return jSuccessMapResult ;
//}
//
//JResult newSetValueBufferMapNode( void ) {
//return jItemAlreadyExistsErrorMapResult ;
//}
//
//JResult newSplitSubBufferMapNode(
//	PUBufferMapNode nodeArg ,
//	JSize sizeIn ,
//	PIBufferMap mapIn,
//	JCPCBuffer keyIn ,
//	JCPCVoid valueIn ,
//	PIBufferMapItem out ) {
//// !!! Не учтена ситуация с генерацией нескольких предупреждений
//// !!! Не возвращается предупреждение о неудачном перевыделение памяти
//PSubsBufferMapNode node ;
//{
//	JResult result = createSubsBufferMapNode(
//		mapIn ,
//		&jBuffer( nodeArg->sub->_.buffer.bytes , sizeIn ) ,
//		nodeArg->sub->_.owner ,
//		&node ) ;
//	if( jResultIsError( result ) ) return result ;
//	if( jResultIsError( result = createValueBufferMapNode(
//			mapIn ,
//			&jBuffer( keyIn->bytes + 1 , keyIn->size - 1 ) ,
//			&node->base ,
//			valueIn ,
//			&node->_.subs[ *keyIn->bytes ].value ) ) )
//		return freeSubsBufferMapNode( node ) , result ;
//}
//node->_.subs[ nodeArg->sub->_.buffer.bytes[ sizeIn ] ].base = nodeArg->base ;
//memcpy(
//	nodeArg->base->buffer.bytes ,
//	nodeArg->base->buffer.bytes + sizeIn + 1,
//	nodeArg->base->buffer.size -= sizeIn + 1 ) ;
//nodeArg->base->owner = &node->base ;
//nodeArg->base->index = nodeArg->sub->_.buffer.bytes[ sizeIn ] ;
//{
//	JPByte bytes ;
//	if( ( bytes = realloc( \
//			nodeArg->base->buffer.bytes , nodeArg->base->buffer.size ) ) ) \
//		nodeArg->base->buffer.bytes = bytes ;
//}
//return nodeArg->subs = node , jSuccessMapResult ;
//}
//
//JCounter releaseBufferMap( PIBufferMap self ) {
//JCounter result = __sync_sub_and_fetch( &self->references , 1 ) ;
//if( !result ) free( self ) ;
//return result ;
//}
