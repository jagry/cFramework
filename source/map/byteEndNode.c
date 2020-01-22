#include <jagry/buffer.h>
#include <jagry/map.i.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#include "byteMapNode.h"

// 1 method declare
//jStatic( JResult )initializeByteMapNode(
//	PByteMapNode ,
//	JPCBuffer ,
//	JPCBuffer ,
//	PByteMapArrayNode ,
//	JUnsignedInteger1 ) ;

// 

/*JResult createByteMapEndNode( JPCBuffer keyIn , JPCBuffer valueIn ,
	PByteMapArrayNode ownerIn , JUnsignedInteger1 indexIn , PPByteMapNode out ) {
JResult status ;
if( ( *out = malloc( sizeof( ByteMapEndNode ) ) ) == 0 )
	return jNotEnoughtMemoryErrorMapResult ;
if( jResultIsNotError( status = initializeByteMapNode( *out , keyIn, valueIn , ownerIn , indexIn ) ) )
	return status ;
free( *out ) ;
return status ;
}*/

/*JResult createByteMapNode2( JPCBuffer key1 , JPCBuffer key2 ,
	JPCBuffer value , PByteMapNode owner , PPByteMapNode object ) {
JResult result ;
if( ( *object = malloc( sizeof( ByteMapNode ) ) ) == 0 )
	return jNotEnoughtMemoryErrorResult ;
if( ( ( *object )->key.bytes = malloc( ( *object )->key.size = key1->size + key2->size ) ) )
	{
		if( jResultIsNotError( result = jagryCreatePBuffer( value , &( *object )->value ) ) )
			{
				if( ( ( *object )->owner = owner ) )
					{
						++owner->count ;
					}
				memcpy( ( *object )->key.bytes , key1->bytes , key1->size ) ;
				memcpy( ( *object )->key.bytes + key1->size , key2->bytes , key2->size ) ;
				memset( ( *object )->subs , 0 , sizeof( ( *object )->subs ) ) ;
				( *object )->count = 0 ;
				return jSuccessResult ;
			}
		jagryFreeBuffer( ( *object )->value ) ;
	}
free( *object ) ;
*object = 0 ;
return result ;
}
/*JResult createEmptyByteMapNode( JCPCByte bytes , JSize size , PPByteMapNode object ) {
JResult result ;
if( ( *object = malloc( sizeof( ByteMapNode ) ) ) == 0 )
	return jNotEnoughtMemoryErrorResult ;
if( jResultIsNotError( result = jagryInitializeBuffer( &( *object )->key , bytes , size ) ) )
	return jSuccesResult ;
free( *object ) ;
*object = 0 ;
return result ;
}*/

JVoid freeByteMapNode( IByteMapNode self ) {
//printf( "=== free self = %p , owner = %p\r\n" , self , self->owner ) ;
/*if( self->owner )
	//printf( "\t" jSignedInteger2Specifier "->" jSignedIntegerSpecifier "\r\n" , self->owner->count , self->owner->count - 1 ) ,
	--self->owner->count ;
if( self->value )
	jagryFreeBuffer( self->value ) ;
jagryClearBuffer( &self->key ) ;
free( self ) ;*/
}

/*JResult initializeByteMapNode( PByteMapNode self , JPCBuffer keyIn ,
	JPCBuffer valueIn , PByteMapArrayNode ownerIn , JUnsignedInteger1 indexIn ) {
JResult status = jagryInitializeBuffer( &self->key , keyIn->bytes , keyIn->size ) ;
if( jResultIsError( status ) )
	return status ;
if( jResultIsNotError( status = jagryCreatePBuffer( valueIn , &self->value ) ) )
	{
		if( ( self->owner = ownerIn ) )
			{
				if( ( self->previous = ownerIn->last ) )
					ownerIn->last->next = self ;
				else
					ownerIn->first = self ;
				ownerIn->last = self ;
				++ownerIn->count ;
			}
		else
			self->previous = 0 ;
		self->next = 0 ;
		// !!! ( *out )->index = indexIn ;
		return jSuccessMapResult ;
	}
jagryFreeBuffer( &self->key ) ;
return status ;
}*/