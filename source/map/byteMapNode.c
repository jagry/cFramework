#include <jagry/buffer.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#include "byteMapNode.h"
#include "jagry.h"

JResult createByteMapNode( JCPCByte bytes , JSize size , JPCBuffer value , PByteMapNode owner , PPByteMapNode object ) {
JResult result ;
if( ( *object = malloc( sizeof( ByteMapNode ) ) ) == 0 )
	return jNotEnoughtMemoryErrorResult ;
if( jResultIsNotError( result = jagryInitializeBuffer( &( *object )->key , bytes , size ) ) )
	{
		if( jResultIsNotError( result = jagryCreatePBuffer( value , &( *object )->value ) ) )
			{
				//printf( "=== create self = %p , owner = %p\r\n" , *object , owner ) ;
				if( ( ( *object )->owner = owner ) )
					//printf( "\t" jSignedInteger2Specifier "->" jSignedIntegerSpecifier "\r\n" , ( *object )->owner->count , ( *object )->owner->count + 1 ) ,
					++owner->count ;
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
//printf( "=== free self = %p , owner = %p\r\n" , self , self->owner ) ;
if( self->owner )
	//printf( "\t" jSignedInteger2Specifier "->" jSignedIntegerSpecifier "\r\n" , self->owner->count , self->owner->count - 1 ) ,
	--self->owner->count ;
if( self->value )
	jagryFreeBuffer( self->value ) ;
jagryClearBuffer( &self->key ) ;
free( self ) ;
}