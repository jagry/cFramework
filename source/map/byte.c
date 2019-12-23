#define jMapMethod jExport

#include <jagry/super.h>
#include <jagry/map.i.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#include "byteMapNode.h"

#include "byteMap.h"

typedef PIByteMap JPIByteMap , JPIByteMapBase ;

#include <jagry/map/byte.h>

static JResult addByteMapItem(
	IByteMap ,
	JCPCBuffer ,
	JCPCBuffer ,
	JPIMapItem ) ;
static JResult clearByteMap(
	IByteMap ) ;
static JResult eraseByteMapItem(
	IByteMap ,
	JBuffer ) ;
static JResult getByteMapItem(
	IByteMap ,
	JBuffer ,
	JPIMapItem** ) ;
static JCounter releaseByteMap(
	IByteMap ) ;

static MByteMap mByteMap = {
	/* base */
		.acquire      = 0 ,
		.getInterface = 0 ,
		.release      = releaseByteMap ,
	/* map */
		.addItem     = addByteMapItem ,
		.clear       = clearByteMap ,
		.eraseItem   = eraseByteMapItem ,
		.getLastItem = 0 } ;

JResult jagryByteMap( PIByteMap out ) {
if( ( out->data = malloc( sizeof( DByteMap ) ) ) == 0 )
	return jNotEnoughtMemoryErrorResult ;
jInitializeSuper( *out , mByteMap , 0 , 1 )
out->data->count = 0 , out->data->node.data = 0 ;
return jSuccessResult ;
}

JResult jagryByteMapBase( JIBase in , JPIByteMapBase out ) {
if( ( out->data = malloc( sizeof( DByteMap ) ) ) == 0 )
	return jNotEnoughtMemoryErrorResult ;
jInitializeSuper( *out , mByteMap , in.data , 1 )
out->data->count = 0 , out->data->node.data = 0 ;
return jSuccessResult ;
}

JResult addByteMapItem( IByteMap self , JCPCBuffer keyIn ,
	JCPCBuffer valueIn , JPIMapItem out ) {
JResult result ;
//IByteMapNode node ;
PIByteMapNode pointer = &self.data->node ;
if( pointer->data == 0 )
	{
		result = createByteMapNode( keyIn , valueIn , 0 , 0 , &self.data->node ) ;
		if( jResultIsError( result ) )
			return result ;
		if( out )
			*out = self.data->node.interface ;
		++self.data->count ;
		return jSuccessMapResult ;
	}
for(
		JBuffer key = *keyIn , local = pointer->data->key ;
		;
		++key.bytes , --key.size )
	if( key.size == 0 )
		if( local.size == 0 )
			if( pointer->data->value )
				{
					if( out )
						*out = pointer->interface ;
					return jValueAlreadyExistsWarningMapResult ;
				}
			else
				{
					if( jResultIsError( result = jagryCreateBuffer(
							valueIn->bytes , valueIn->size , &pointer->data->value ) ) )
						return result ;
					if( out )
						*out = pointer->interface ;
					return jSuccessMapResult ;
				}
		else
			{
				result = createByteMapNode( &jBuffer( pointer->data->key.bytes ,
					( *pointer )->key.size - local.size ) , &valueIn ,
						( *pointer )->owner , ( *pointer )->key.bytes[ -1 ] , &node ) ;
				if( jResultIsNotError( result ) )
					{
						result =
							createByteMapNode(
								&jBuffer( ( *pointer )->key.bytes , ( *pointer )->key.size - local.size ) ,
								&valueIn ,
								( *pointer )->owner ,
								( *pointer )->key.bytes[ -1 ] ,
								&node ) ;
						if( jResultIsNotError( result ) )
							return result ;
						freeByteMapNode( node ) ;
					}
				return result ;
			}
	else
		if( local.size == 0 )
			if( ( *pointer )->subs[ *key.bytes ] )
				{
					local = ( *( pointer = &( *pointer )->subs [ *key.bytes ] ) )->key ;
					continue ;
				}
			else
				{
					result =
						createByteMapNode(
							&jBuffer( key.bytes + 1 , key.size - 1 ) ,
							&valueIn,
							*pointer ,
							*key.bytes ,
							&( *pointer )->subs [ *key.bytes ] ) ;
					if( result == jSuccessResult )
						++self->count ;
					return result ;
				}
		else
			if( *key.bytes != *local.bytes )
				{
					/*result =
						createByteMapNode(
							&jBuffer( keyIn.bytes , keyIn.size - argument.size ) ,
							0 ,
							( *pointer )->owner ,
							keyIn.bytes[ -1 ] ,
							&node ) ;
					if( jResultIsNotError( result ) )
						{
							result =
								createByteMapNode(
									&jBuffer( argument.bytes + 1 , argument.size - 1 ) ,
									&valueIn ,
									node ,
									*argument.bytes ,
									&node->subs[ *argument.bytes ] ) ;
							if( jResultIsNotError( result ) )
								{
									result =
										createByteMapNode(
											&jBuffer( local.bytes + 1 , local.size - 1 ) ,
											( *pointer )->value ,
											node ,
											*local.bytes ,
											&node->subs[ *local.bytes ] ) ;
									if( jResultIsNotError( result ) )
										{
											if( out &&
													jResultIsError( result = jagrySetBuffer( out , valueIn.bytes , valueIn.size ) ) )
												freeByteMapNode( node->subs[ *local.bytes ] ) ;
											else
												{
													freeByteMapNode( *pointer ) ;
													*pointer = node ;
													++self->count ;
													return jSuccessResult ;
												}
										}
									freeByteMapNode( node->subs[ *argument.bytes ] ) ;
								}
							freeByteMapNode( node ) ;
						}
					return result ;*/
				}
			else
				++local.bytes ,
				--local.size ;
}

JResult clearByteMap( IByteMap self ) {
/*JPMapItem item ;
JResult status = jMapGetFirstItem( self , &item ) ;
if( jResultIsNotError( status ) )
	for( ; ; )
		{
		}
else
	return status == jEmptyErrorMapResult ? jEmptyWarningMapResult : status ;
}

void drawByteMapBuffer( JBuffer bufferIn ) {
printf( "buffer{ size = " jSizeSpecifier " , bytes = %p [" , bufferIn.size , bufferIn.bytes ) ;
for( ; bufferIn.size ; ++bufferIn.bytes , --bufferIn.size )
	printf( " " jUnsignedInteger1Specifier , *bufferIn.bytes ) ;
printf( " ] }" ) ;*/
}

JResult eraseByteMapItem( IByteMap self , JCBuffer in ) {
/*JPMapItem item ;
JResult status = getByteMapItem( self , in , &item ) ;
if( jResultIsError( status ) )
	return status ;
return jMapItemErase( item ) ;*/
}

JResult getByteMapItem( IByteMap self , JBuffer in , JPPMapItem out ) {
/*drawByteMapBuffer( in ) ;
PByteMapNode current = self->node ;
PByteMapNode owner = 0 ;
if( !current )
	eraseByteMapReturn( eraseByteMapEmptyPoint , jValueNotFoundErrorMapResult )
for( JBuffer currentKey = current->key ; ; ++in.bytes , --in.size )
	if( in.size == 0 )
		if( currentKey.size == 0 )
			if( current->value )
				{
					//JPBuffer value = current->value ;
					//current->value = 0 ;
					// !!! Надо вернуть value
					// 1. Если current->count = 0 , то:
					//  а. удалить узел
					//  б. проверить родителя
					// 2. Если current->count = 1 , то объединить узел с единственным ДУ
					// Проверка родителя:
					// А. Очистить указатель на дочерний узел(ДУ)
					// Б. Уменьшить счетчик дочерних узлов(СДУ)
					// В. Если СДУ = 0, то у узла должно быть значение.
					//   Проверить в отладочной сборке и ничего не делать
					// Г. Если СДУ = 1, то:
					//  1. Если у узла есть значение, то ничего не делать
					//  2. Если у узла нет значения, объединить узел с единственным ДУ
					/ *if( current->count == 0 )
						{
							if( owner )
								{
									drawByteMapBuffer( in ) ;
									JUnsignedInteger1 index = *( in.bytes - current->key.size - 1 ) ;
									printf( "dddd %i" jNewLine , index ) ;
									jAssert( owner->count == 1 && owner->value == 0 )
									if( owner->count < 3 && !owner->value )
										{
											PByteMapNode other = owner->last == current ? owner->first : owner->last ;
											JBuffer buffer = { .size = other->key.size + owner->key.size + 1 } ;
											if( !( buffer.bytes = realloc( owner->key.bytes , buffer.size ) ) )
												return jNotEnoughtMemoryErrorMapResult ;
											memcpy( &owner->subs , &other->subs , sizeof( PByteMapNode ) * subCount );
											memcpy( buffer.bytes + owner->key.size + 1 , other->key.bytes , other->key.size ) ;
											memcpy( buffer.bytes , owner->key.bytes , owner->key.size ) ;
											buffer.bytes[ owner->key.size ] = index ;
											owner->first = other->first ;
											owner->value = other->value ;
											owner->last = other->last ;
											owner->key = buffer ;
											printf(
												"!!! sizes other = %i " jNewLine ,
												buffer.bytes[ index ] ) ;
											eraseByteMapPoint( eraseByteMapConcateParentPoint ) ;
										}
									else
										eraseByteMapPoint( eraseByteMapNotModifyOwnerPoint ) ,
										owner->subs[ index ] = 0 ,
										--owner->count ;
								}
							else
								eraseByteMapPoint( eraseByteMapLastNodePoint ) , self->count = 0 , self->node = 0 ;
							if( out )
								eraseByteMapPoint( eraseByteMapSetValuePoint ) , *out = *current->value , current->value = 0 ;
							// Может стоить продублировать функцию freeByteMapNode без удаления .value. чтобы не делать
							// current->value = 0
							freeByteMapNode( current ) ;
							return jSuccessMapResult ;
						}
					else
						if( current->count == 1 )
							{
								PByteMapNode other = owner->last == current ? owner->first : owner->last ;
							}* /
				}
			else
				eraseByteMapReturn( eraseByteMapNoValuePoint , jValueNotFoundErrorMapResult )
		else
			eraseByteMapReturn( eraseByteMapEndInPoint , jValueNotFoundErrorMapResult )
	else
		if( currentKey.size == 0 )
			/ *if( current->subs[ *in.bytes ] )
				eraseByteMapIncrement(
					node ,
					owner = current ; currentKey = ( current = current->subs[ *in.bytes ] )->key )
			else
				eraseByteMapReturn( eraseByteMapMissingChildPoint , jValueNotFoundErrorMapResult )* / ;
		else
			if( *in.bytes == *currentKey.bytes )
				eraseByteMapIncrement( byte , ++currentKey.bytes ; --currentKey.size )
			else
				eraseByteMapReturn( eraseByteMapNotEqualPoint , jValueNotFoundErrorMapResult )
//return jSuccessResult ;*/
}

JCounter releaseByteMap( IByteMap self ) {
int result = __sync_sub_and_fetch( &self.data->references , 1 ) ;
if( !result )
	free( self.data ) ;
return result ;
}