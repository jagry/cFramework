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
				return jSuccesResult ; \
			} \
	}

#include <jagry/imap.h>
#include <jagry/lbase.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#include "byteMapNode.h"

#include "byteMap.h"

#ifdef DEBUG
	JDebugEraseByteMap jagryDebugEraseByteMap ;
#endif

	static JResult setByteMapOut( JPCBuffer in , JPBuffer out ) {
//return out ? jagrySetBuffer( out , in->bytes , in->size ) : jSuccesResult ;
if( out )
	return jagrySetBuffer( out , in->bytes , in->size ) ;
else
	return jSuccesResult ;
}

static JResult addByteMap( PByteMap self , JCBuffer keyIn , JCBuffer valueIn , JPBuffer out ) {
JResult result ;
PByteMapNode node ;
PPByteMapNode pointer = &self->node ;
if( self->node == 0 )
	{
		if( jResultIsError( result = createByteMapNode( keyIn.bytes , keyIn.size , &valueIn , 0 , &self->node ) ) )
			return result ;
		if( jResultIsError( result = out ? jagrySetBuffer( out , valueIn.bytes , valueIn.size ) : jSuccesResult ) )
			freeByteMapNode( self->node ) ,
			self->node = 0 ;
		else
			++self->count ;
		return result ;
	}
for( JBuffer argument = keyIn , local = ( *pointer )->key ; ; ++argument.bytes , --argument.size )
	if( argument.size == 0 )
		if( local.size == 0 )
			return node->value ?
				out ? jResultIsError( result = jagrySetBuffer( out , valueIn.bytes , valueIn.size ) ) ? result : jMapValueAlreadyExistsWarningResult : jMapValueAlreadyExistsWarningResult :
				jMapValueNotFoundErrorResult ;
		else
			{
				if( jResultIsNotError( result = createByteMapNode( ( *pointer )->key.bytes , ( *pointer )->key.size - local.size , &valueIn , ( *pointer )->owner , &node ) ) )
					{
						if( jResultIsNotError( result = createByteMapNode( local.bytes + 1 , local.size - 1 , ( *pointer )->value , node , &node->subs[ *( JPByte )local.bytes ] ) ) )
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
					if( ( result = createByteMapNode( ( JPByte )argument.bytes + 1 , argument.size - 1 , &valueIn, *pointer , &( *pointer )->subs [ *( JPByte )argument.bytes ] ) ) == jSuccesResult )
						++self->count ;
					return result ;
				}
		else
			if( *( JPByte )argument.bytes != *( JPByte )local.bytes )
				{
					if( jResultIsNotError( result = createByteMapNode( keyIn.bytes , keyIn.size - argument.size , 0 , ( *pointer )->owner , &node ) ) )
						{
							if( jResultIsNotError( result = createByteMapNode( ( JPByte )argument.bytes + 1 , argument.size - 1 , &valueIn , node , &node->subs[ *( JPByte )argument.bytes ] ) ) )
								{
									if( jResultIsNotError( result = createByteMapNode( local.bytes + 1 , local.size - 1 , ( *pointer )->value , node , &node->subs[ *( JPByte )local.bytes ] ) ) )
										{
											if( out && jResultIsError( result = jagrySetBuffer( out , valueIn.bytes , valueIn.size ) ) )
												freeByteMapNode( node->subs[ *( JPByte )local.bytes ] ) ;
											else
												{
													freeByteMapNode( *pointer ) ;
													*pointer = node ;
													++self->count ;
													return jSuccesResult ;
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

void drawByteMapBuffer( JBuffer buffer ) {
printf( "buffer{ size = " jSizeSpecifier " , bytes = %p [" , buffer.size , buffer.bytes ) ;
for( ; buffer.size ; ++buffer.bytes , --buffer.size )
	printf( " " jUnsignedInteger1Specifier , *( JPByte )buffer.bytes ) ;
printf( " ] }" ) ;
}

static JResult eraseByteMap( PByteMap self , JBuffer in , JPBuffer out ) {
PByteMapNode current = self->node ;
/*printf( "Enter = " ) ;
drawByteMapBuffer( in ) ;
printf( jNewLine ) ;*/
if( !current )
	eraseByteMapReturn( eraseByteMapPointReturnEmpty , jMapValueNotFoundErrorResult )
//owner = current->owner ;
for( JBuffer currentKey = current->key ; ; ++in.bytes , --in.size )
	{
		// start debug
		JPCharacter1 inChar = in.bytes ;
		JPCharacter1 currentChar = currentKey.bytes ;
		// finish debug
		/*printf( "Itertion" jNewLine "   current key = " ) ;
		drawByteMapBuffer( currentKey ) ;
		printf( jNewLine "   in = " ) ;
		drawByteMapBuffer( in ) ;
		printf( jNewLine ) ;*/
		if( in.size == 0 )
			if( currentKey.size == 0 )
				if( current->value )
					break ;
				else
					eraseByteMapReturn( eraseByteMapPointReturnNoValue , jMapValueNotFoundErrorResult )
			else
				eraseByteMapReturn( eraseByteMapPointReturnEndIn , jMapValueNotFoundErrorResult )
		else
			if( currentKey.size == 0 )
				if( ( current = current->subs[ *( JPByte )in.bytes ] ) )
					++jagryDebugEraseByteMap.byte ,
					currentKey = current->key ;
				else
					return jMapValueNotFoundErrorResult ;
			else
				if( *( JPByte )in.bytes == *( JPByte )currentKey.bytes )
					++jagryDebugEraseByteMap.node ,
					++currentKey.bytes ,
					--currentKey.size ;
				else
					return jMapValueNotFoundErrorResult ;
	}
{
	PByteMapNode owner = current->owner ;
	JPBuffer value = current->value ;
	//current->value = 0 ;
	if( current->count == 0 )
		if( owner )
			if( owner->value )
				{
					JPByte debugBytes = ( JPByte )in.bytes ;
					owner->subs[ ( ( JPByte )in.bytes )[ -1 - current->key.size ] ] = 0 ;
					freeByteMapNode( current ) ;
					// Установить буффер
					printf( "exit " __FILE__ ":" __LINE_STRING__ jNewLine ) ;
					exit( -1 ) ;
					return jSuccesResult ;
				}
			else
				if( owner->count > 2 )
					{
						printf( "exit " __FILE__ ":" __LINE_STRING__ jNewLine ) ;
						exit( -1 ) ;
					}
				else
					{
						// Элемент найден, 
						//eraseByteMapBreak( eraseByteMapBreakFounded )
						printf( "break " __FILE__ ":" __LINE_STRING__ jNewLine ) ;
						//break ;
					}
		else
			{
				freeByteMapNode( current ) ;
				self->node = 0 ;
				self->count = 0 ;
				printf( "exit " __FILE__ ":" __LINE_STRING__ jNewLine ) ;
				exit( -1 ) ;
				return jSuccesResult ;
			}
	else
		if( current->count == 1 )
			{
				printf( "exit " __FILE__ ":" __LINE_STRING__ jNewLine ) ;
				exit( -1 ) ;
			}
		else
			{
				printf( "exit " __FILE__ ":" __LINE_STRING__ jNewLine ) ;
				exit( -1 ) ;
			}
	printf( "exit " __FILE__ ":" __LINE_STRING__ jNewLine ) ;
	exit( -1 ) ;
	return jSuccesResult ;
}
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
return jSuccesResult ;
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
return jSuccesResult ;
}

JResult jagryByteMapBase( JBase* in , JBase** out ) {
if( ( *out = malloc( sizeof( ByteMap ) ) ) == 0 )
	return jNotEnoughtMemoryErrorResult ;
jInitializeMinimal( ( ByteMap* )*out , byteMapMethods , in , 1 ) ;
( ( ByteMap* )*out )->count = 0 , ( ( ByteMap* )*out )->node = 0 ;
return jSuccesResult ;
}