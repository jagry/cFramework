#include <jagry/imap.h>
#include <jagry/lbase.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#include "byteMapNode.h"

#include "byteMap.h"

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
		if( jResultIsError( result = setByteMapOut( &valueIn , out ) ) )
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

static JResult eraseByteMap( PByteMap self , JBuffer in , JPBuffer out ) {
PByteMapNode current = self->node ;
if( !current )
	return jMapValueNotFoundErrorResult ;
for( JBuffer local = current->key ; ; ++in.bytes , --in.size )
	if( in.size == 0 )
		if( local.size == 0 )
			if( current->value )
				{
					JPBuffer value = current->value;
					current->value = 0 ;
					if( current->count == 0 )
						{
							PByteMapNode owner = current->owner ;
							if( owner )
								{
									if( owner->value || owner->count > 1 )
										{
											owner->subs[ ( ( JPByte )in.bytes )[ -1 - current->key.size ] ] = 0 ;
											current->value = 0 ;
											freeByteMapNode( current ) ;
											return jSuccesResult ;
										}
									else
										{
										}
								}
							else
								{
									self->node = 0 ;
									self->count = 0 ;
									current->value = 0 ;
									freeByteMapNode( current ) ;
									return jSuccesResult ;
								}
						}
					return jSuccesResult ;
				}
			else
				return jMapValueNotFoundErrorResult ;
		else
			return jMapValueNotFoundErrorResult ;
	else
		if( local.size == 0 )
			local = ( current = current->subs[ *( JPByte )in.bytes ] )->key ;
		else
			if( *( JPByte )in.bytes != *( JPByte )local.bytes )
				return jMapValueNotFoundErrorResult ;
			else
				++local.bytes ,
				--local.size ;
}

static ByteMapMethods byteMapMethods = {
	/* base */ .aqcuire = 0 , .dump = 0 , .getInterface = 0 , .release = 0 ,
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