#define STRINGIFY2( x ) #x
#define STRINGIFY( x ) STRINGIFY2( x )
#define __LINE_STRING__ STRINGIFY( __LINE__ )

#define addByteMapReturn() \
	{ \
		if( out && jResultIsError( result = jagrySetBuffer( out , valueIn.bytes , valueIn.size ) ) ) \
			freeByteMapNode( node->subs[ *local.bytes ] ) ; \
		else \
			{ \
				freeByteMapNode( *pointer ) ; \
				*pointer = node ; \
				++self->count ; \
				return jSuccessResult ; \
			} \
	}

#include <jagry/imap.h>
#include <jagry/lbase.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#include "byteMapNode.h"

#include "byteMap.h"

jIfDebug( DebugEraseByteMap jagryDebugEraseByteMap ; )

typedef struct Stack Stack ;
typedef Stack * PStack ;

struct Stack {
	PByteMapNode value ;
	PStack next ;
} ;

/*jStatic( JResult )setByteMapOut( JPCBuffer in , JPBuffer out ) {
//return out ? jagrySetBuffer( out , in->bytes , in->size ) : jSuccesResult ;
if( out )
	return jagrySetBuffer( out , in->bytes , in->size ) ;
else
	return jSuccesResult ;
}*/

jStatic( JResult )addByteMap( PByteMap self , JCBuffer keyIn , JCBuffer valueIn , JPBuffer out ) {
JResult result ;
PByteMapNode node ;
PPByteMapNode pointer = &self->node ;
if( self->node == 0 )
	{
		if( jResultIsError( result = createByteMapNode( &keyIn , &valueIn , 0 , 0 , &self->node ) ) )
			return result ;
		if( jResultIsError( result = out ? jagrySetBuffer( out , valueIn.bytes , valueIn.size ) : jSuccessResult ) )
			freeByteMapNode( self->node ) , self->node = 0 ;
		else
			++self->count ;
		return result ;
	}
for( JBuffer argument = keyIn , local = ( *pointer )->key ; ; ++argument.bytes , --argument.size )
	if( argument.size == 0 )
		if( local.size == 0 )
			return node->value ?
				out ?
					jResultIsError( result = jagrySetBuffer( out , valueIn.bytes , valueIn.size ) ) ?
						result :
						jValueAlreadyExistsWarningMapResult :
					jValueAlreadyExistsWarningMapResult :
				jValueNotFoundErrorMapResult ;
		else
			{
				result =
					createByteMapNode(
						&jBuffer( ( *pointer )->key.bytes , ( *pointer )->key.size - local.size ) ,
						&valueIn ,
						( *pointer )->owner ,
						( *pointer )->key.bytes[ -1 ] ,
						&node ) ;
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
							addByteMapReturn( )
						freeByteMapNode( node ) ;
					}
				return result ;
			}
	else
		if( local.size == 0 )
			if( ( *pointer )->subs [ *argument.bytes ] )
				{
					local = ( *( pointer = &( *pointer )->subs [ *argument.bytes ] ) )->key ;
					continue ;
				}
			else
				{
					result =
						createByteMapNode(
							&jBuffer( argument.bytes + 1 , argument.size - 1 ) ,
							&valueIn,
							*pointer ,
							*argument.bytes ,
							&( *pointer )->subs [ *argument.bytes ] ) ;
					if( result == jSuccessResult )
						++self->count ;
					return result ;
				}
		else
			if( *argument.bytes != *local.bytes )
				{
					result =
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
					return result ;
				}
			else
				++local.bytes ,
				--local.size ;
}

void drawByteMapBuffer(
	JBuffer buffer ) {
printf( "buffer{ size = " jSizeSpecifier " , bytes = %p [" , buffer.size , buffer.bytes ) ;
for( ; buffer.size ; ++buffer.bytes , --buffer.size )
	printf( " " jUnsignedInteger1Specifier , *buffer.bytes ) ;
printf( " ] }" ) ;
}

jStatic( JResult )eraseByteMap( // Удаление элемента словаря
	PByteMap self , // Указатель на словарь
	JBuffer in , // Ключ элемента  !!! сделать const?
	JPBuffer out ) { // Значение элемента
printf( "!!! in = %s\n" , in.bytes ) ; 
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
					if( current->count == 0 )
						{
							if( owner )
								{
									JUnsignedInteger1 index = *( in.bytes - current->key.size - 1 ) ;
									jAssert( owner->count == 1 && owner->value == 0 )
									if( owner->count == 2 && !owner->value )
										{
											PByteMapNode other = owner->last == current ? owner->first : owner->last ;
											JBuffer buffer = { .size = other->key.size + owner->key.size + 1 } ;
											if( !( buffer.bytes = realloc( owner->key.bytes , buffer.size ) ) )
												return jNotEnoughtMemoryErrorMapResult ;
											memcpy( buffer.bytes + owner->key.size + 1 , other->key.bytes , other->key.size ) ;
											memcpy( buffer.bytes , owner->key.bytes , owner->key.size ) ;
											buffer.bytes[ owner->key.size ] = index ;
											owner->first = other->first ;
											owner->value = other->value ;
											owner->last = other->last ;
											owner->subs = other->subs ;
											owner->key = buffer ;
											printf(
												"!!! sizes other = %i " jNewLine ,
												buffer.bytes[ owner->key.size ] ) ;
											
											eraseByteMapPoint( eraseByteMapNotModifyOwnerPoint ) ;
										}
									else
										eraseByteMapPoint( eraseByteMapNotModifyOwnerPoint ) ;
									owner->subs[ index ] = 0 ;
									--owner->count ;
								}
							else
								eraseByteMapPoint( eraseByteMapLastNodePoint ) , self->count = 0 , self->node = 0 ;
							if( out )
								eraseByteMapPoint( eraseByteMapSetValuePoint ) , *out = *current->value , current->value = 0 ;
							// Может стоить продублировать функцию freeByteMapNode без удаления .value. чтобы не делать
							// current->value = 0
							freeByteMapNode( current ) ;
							return jSuccessResult ;
						}
					printf( "not implement %s:%i" jNewLine , __FILE__ , __LINE__ ) ;
					exit( 2 ) ;
				}
			else
				eraseByteMapReturn( eraseByteMapNoValuePoint , jValueNotFoundErrorMapResult )
		else
			eraseByteMapReturn( eraseByteMapEndInPoint , jValueNotFoundErrorMapResult )
	else
		if( currentKey.size == 0 )
			if( current->subs[ *in.bytes ] )
				eraseByteMapIncrement(
					node ,
					owner = current ; currentKey = ( current = current->subs[ *in.bytes ] )->key )
			else
				eraseByteMapReturn( eraseByteMapMissingChildPoint , jValueNotFoundErrorMapResult )
		else
			if( *in.bytes == *currentKey.bytes )
				eraseByteMapIncrement( byte , ++currentKey.bytes ; --currentKey.size )
			else
				eraseByteMapReturn( eraseByteMapNotEqualPoint , jValueNotFoundErrorMapResult )
//return jSuccessResult ;
}

static JResult releaseByteMap( PByteMap self ) {
if( --self->count )
	return self->count ;
return self->count ;
}

static ByteMapMethods byteMapMethods = {
	/* base */ .acquire = 0 , .dump = 0 , .getInterface = 0 , .release = releaseByteMap ,
	/* map */ .add = addByteMap , .erase = eraseByteMap } ;

jExport( JResult )jagryCreateByteMap( ByteMap** out ) {
if( ( *out = malloc( sizeof( ByteMap ) ) ) == 0 )
	return jNotEnoughtMemoryErrorResult ;
jInitializeMinimal( *out , byteMapMethods , 0 , 1 )
( *out )->count = 0 , ( *out )->node = 0 ;
return jSuccessResult ;
}

jExport( JResult )jagryCreateByteMapBase( JBase* in , ByteMap** out ) {
if( ( *out = malloc( sizeof( ByteMap ) ) ) == 0 )
	return jNotEnoughtMemoryErrorResult ;
jInitializeMinimal( ( ByteMap* )*out , byteMapMethods , in , 1 ) ;
( ( ByteMap* )*out )->count = 0 , ( ( ByteMap* )*out )->node = 0 ;
return jSuccessResult ;
}