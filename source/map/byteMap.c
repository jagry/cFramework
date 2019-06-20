#define STRINGIFY2( x ) #x
#define STRINGIFY( x ) STRINGIFY2( x )
#define __LINE_STRING__ STRINGIFY( __LINE__ )

#define addByteMapReturn() \
	{ \
		if( out && jResultIsError( result = jagrySetBuffer( out , valueIn.bytes , valueIn.size ) ) ) \
			freeByteMapNode( node->subs[ *( JPByte )local.bytes ] ) ; \
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

jDebug( DebugEraseByteMap jagryDebugEraseByteMap ; )

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

jStatic( JResult )addByteMap(
	PByteMap self ,
	JCBuffer keyIn ,
	JCBuffer valueIn ,
	JPBuffer out ) {
JResult result ;
PByteMapNode node ;
PPByteMapNode pointer = &self->node ;
if( self->node == 0 )
	{
		if( jResultIsError( result = createByteMapNode( &keyIn , &valueIn , 0 , &self->node ) ) )
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
						jMapValueAlreadyExistsWarningResult :
					jMapValueAlreadyExistsWarningResult :
				jMapValueNotFoundErrorResult ;
		else
			{
				result =
					createByteMapNode(
						&jBuffer( ( *pointer )->key.bytes , ( *pointer )->key.size - local.size ) ,
						&valueIn ,
						( *pointer )->owner ,
						&node ) ;
				if( jResultIsNotError( result ) )
					{
						result =
							createByteMapNode(
								&jBuffer( ( *pointer )->key.bytes , ( *pointer )->key.size - local.size ) ,
								&valueIn ,
								( *pointer )->owner ,
								&node ) ;
						if( jResultIsNotError( result ) )
							addByteMapReturn()
						freeByteMapNode( node ) ;
					}
				return result ;
			}
	else
		if( local.size == 0 )
			if( ( *pointer )->subs [ *( JPByte )argument.bytes ] )
				{
					local = ( *( pointer = &( *pointer )->subs [ *( JPByte )argument.bytes ] ) )->key ;
					continue ;
				}
			else
				{
					result =
						createByteMapNode(
							&jBuffer( ( JPByte )argument.bytes + 1 , argument.size - 1 ) ,
							&valueIn,
							*pointer ,
							&( *pointer )->subs [ *( JPByte )argument.bytes ] ) ;
					if( result == jSuccessResult )
						++self->count ;
					return result ;
				}
		else
			if( *( JPByte )argument.bytes != *( JPByte )local.bytes )
				{
					result =
						createByteMapNode(
							&jBuffer( keyIn.bytes , keyIn.size - argument.size ) ,
							0 ,
							( *pointer )->owner ,
							&node ) ;
					if( jResultIsNotError( result ) )
						{
							result =
								createByteMapNode(
									&jBuffer( ( JPByte )argument.bytes + 1 , argument.size - 1 ) ,
									&valueIn ,
									node ,
									&node->subs[ *( JPByte )argument.bytes ] ) ;
							if( jResultIsNotError( result ) )
								{
									result =
										createByteMapNode(
											&jBuffer( local.bytes + 1 , local.size - 1 ) ,
											( *pointer )->value ,
											node ,
											&node->subs[ *( JPByte )local.bytes ] ) ;
									if( jResultIsNotError( result ) )
										{
											if( out &&
													jResultIsError( result = jagrySetBuffer( out , valueIn.bytes , valueIn.size ) ) )
												freeByteMapNode( node->subs[ *( JPByte )local.bytes ] ) ;
											else
												{
													freeByteMapNode( *pointer ) ;
													*pointer = node ;
													++self->count ;
													return jSuccessResult ;
												}
										}
									freeByteMapNode( node->subs[ *( JPByte )argument.bytes ] ) ;
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
	printf( " " jUnsignedInteger1Specifier , *( JPByte )buffer.bytes ) ;
printf( " ] }" ) ;
}

jStatic( JResult )eraseByteMap( // Удаление элемента словаря
	PByteMap self , // Указатель на словарь
	JBuffer in , // Ключ элемента  !!! сделать const?
	JPBuffer out ) { // Значение элемента
JResult result ;
//PStack stack = 0 ;
{
	PByteMapNode current = self->node ;
	PByteMapNode owner = 0 ;
	if( !current )
		eraseByteMapReturn( eraseByteMapEmptyPoint , jMapValueNotFoundErrorResult )
		//return jDebug( ( jagryDebugEraseByteMap.exit = eraseByteMapEmpty , ) ) jMapValueNotFoundErrorResult ;
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
										//owner->subs
										//if( owner->c )
									}
								else
									self->count = 0 , self->node = 0 ;
								if( out )
									eraseByteMapPoint( eraseByteMapLastNodePoint ) , *out = *current->value , current->value = 0 ;
								// Может стоить продублировать функцию freeByteMapNode  без удаления .value. чтобы не делать current->value = 0
								freeByteMapNode( current ) ;
								return jSuccessResult ;
							}
					}
				else
					eraseByteMapReturn( eraseByteMapNoValuePoint , jMapValueNotFoundErrorResult )
			else
				eraseByteMapReturn( eraseByteMapEndInPoint , jMapValueNotFoundErrorResult )
		else
			if( currentKey.size == 0 )
				if( current->subs[ *( JPByte )in.bytes ] )
					eraseByteMapIncrement( node , owner = current ; currentKey = ( current = current->subs[ *( JPByte )in.bytes ] )->key )
				else
					eraseByteMapReturn( eraseByteMapMissingChildPoint , jMapValueNotFoundErrorResult )
			else
				if( *( JPByte )in.bytes == *( JPByte )currentKey.bytes )
					eraseByteMapIncrement( byte , ++currentKey.bytes ; --currentKey.size )
				else
					eraseByteMapReturn( eraseByteMapNotEqualPoint , jMapValueNotFoundErrorResult )
}
/*while( stack )
	{
		PStack next = stack->next ;
		free( stack ) ;
		stack = next ;
	}*/
return result ;
//{
//	PByteMapNode owner = current->owner ;
//	JPBuffer value = current->value ;
//	//current->value = 0 ;
//	if( current->count == 0 )
//		if( owner )
//			if( owner->value )
//				{
//					JPByte debugBytes = ( JPByte )in.bytes ;
//					owner->subs[ ( ( JPByte )in.bytes )[ -1 - current->key.size ] ] = 0 ;
//					freeByteMapNode( current ) ;
//					// Установить буффер
//					printf( "exit " __FILE__ ":" __LINE_STRING__ jNewLine ) ;
//					exit( -1 ) ;
//					return jSuccesResult ;
//				}
//			else
//				if( owner->count > 2 )
//					{
//						printf( "exit " __FILE__ ":" __LINE_STRING__ jNewLine ) ;
//						exit( -1 ) ;
//					}
//				else
//					{
//						// Элемент найден, 
//						//eraseByteMapBreak( eraseByteMapBreakFounded )
//						printf( "break " __FILE__ ":" __LINE_STRING__ jNewLine ) ;
//						//break ;
//					}
//		else
//			{
//				freeByteMapNode( current ) ;
//				self->node = 0 ;
//				self->count = 0 ;
//				printf( "exit " __FILE__ ":" __LINE_STRING__ jNewLine ) ;
//				exit( -1 ) ;
//				return jSuccesResult ;
//			}
//	else
//		if( current->count == 1 )
//			{
//				printf( "exit " __FILE__ ":" __LINE_STRING__ jNewLine ) ;
//				exit( -1 ) ;
//			}
//		else
//			{
//				printf( "exit " __FILE__ ":" __LINE_STRING__ jNewLine ) ;
//				exit( -1 ) ;
//			}
//	printf( "exit " __FILE__ ":" __LINE_STRING__ jNewLine ) ;
//	exit( -1 ) ;
//	return jSuccesResult ;
//}
/*for( ; ; )
	if( owner )
		if( owner->value )
			if( owner->count == 2 )
				{
					printf( "exit " __FILE__ ":" __LINE_STRING__ jNewLine ) ;
					exit( -1 ) ;
				}
			else
				{
					printf( "exit " __FILE__ ":" __LINE_STRING__ jNewLine ) ;
					exit( -1 ) ;
				}
		else
			if( owner->count == 2 )
				{
					printf( "exit " __FILE__ ":" __LINE_STRING__ jNewLine ) ;
					exit( -1 ) ;
				}
			else
				{
					printf( "exit " __FILE__ ":" __LINE_STRING__ jNewLine ) ;
					exit( -1 ) ;
				}
	else
		{
			printf( "exit " __FILE__ ":" __LINE_STRING__ jNewLine ) ;
			exit( -1 ) ;
		}*/
return jSuccessResult ;
}

static JResult releaseByteMap( PByteMap self ) {
if( --self->count )
	return self->count ;
return self->count ;
}

static ByteMapMethods byteMapMethods = {
	/* base */ .aqcuire = 0 , .dump = 0 , .getInterface = 0 , .release = releaseByteMap ,
	/* map */ .add = addByteMap , .erase = eraseByteMap } ;

JResult jagryByteMap( ByteMap** out ) {
if( ( *out = malloc( sizeof( ByteMap ) ) ) == 0 )
	return jNotEnoughtMemoryErrorResult ;
jInitializeMinimal( *out , byteMapMethods , 0 , 1 )
( *out )->count = 0 , ( *out )->node = 0 ;
return jSuccessResult ;
}

JResult jagryByteMapBase( JBase* in , JBase** out ) {
if( ( *out = malloc( sizeof( ByteMap ) ) ) == 0 )
	return jNotEnoughtMemoryErrorResult ;
jInitializeMinimal( ( ByteMap* )*out , byteMapMethods , in , 1 ) ;
( ( ByteMap* )*out )->count = 0 , ( ( ByteMap* )*out )->node = 0 ;
return jSuccessResult ;
}
