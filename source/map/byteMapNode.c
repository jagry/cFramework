#include <jagry/buffer.h>
#include <memory.h>
#include <stdlib.h>

#include "byteMapNode.h"

JResult createByteMapNode( JCPCByte bytes , JSize size , JPCBuffer value , PByteMapNode owner , PPByteMapNode object ) {
JResult result ;
if( ( *object = malloc( sizeof( ByteMapNode ) ) ) == 0 )
	return jNotEnoughtMemoryErrorResult ;
if( jResultIsNotError( result = jagryInitializeBuffer( &( *object )->key , bytes , size ) ) )
	{
		if( jResultIsNotError( result = jagryCreatePBuffer( value , &( *object )->value ) ) )
			{
				if( ( ( *object )->owner = owner ) )
					++owner->count;
				memset( ( *object )->subs , 0 , sizeof( ( *object )->subs ) ) ;
				( *object )->count = 0 ;
				return jSuccesResult ;
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

JVoid freeByteMapNode( PByteMapNode self ) {
if( self->value )
	jagryFreeBuffer( self->value ) ;
if( self->owner )
	--self->owner->count ;
jagryFreeBuffer( &self->key ) ;
free( self ) ;
}