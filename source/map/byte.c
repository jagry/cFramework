#define jMapMethod jExport

#include <jagry/super.h>
#include <jagry/map.i.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#include "byteMapNode.h"

jStdDeclareImplementation( ByteMap )

union IByteMap {
	PDByteMap data ; } ;
		
struct DByteMap {
	jSuperMembers( PCMByteMap , methods )
	IByteMapNode node ;
	JUnsignedInteger count ; } ;
	
struct MByteMap { jEachMap( JISuper , IByteMap , IByteMap ,
	IByteMap , IByteMap , IByteMap , IByteMap , IByteMap ,
	IByteMap , IByteMap , IByteMap , IByteMap , IByteMap ) } ;

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
	JPIMapItem ) ;
static JResult getByteMapValue(
	IByteMap ,
	JBuffer ,
	JPBuffer ) ;
static JCounter releaseByteMap(
	IByteMap ) ;

static JResult createByteMapNode(
	JCPCBuffer /* in key buffer */ ,
	JCPCBuffer /* in value buffer */ ,
	IByteMapNode /* in owner node */ ,
	PIByteMapNode /* out !!! created node */ ) ;
static JCounter getByteMapNodeValue(
	IByteMapNode ,
	JPBuffer ) ;

static MByteMap mByteMap = {
	// base
		.acquire      = jagryAcquireSuper ,
		.getInterface = 0 ,
		.release      = releaseByteMap ,
	// map
		.addItem     = addByteMapItem ,
		.clear       = clearByteMap ,
		.eraseItem   = eraseByteMapItem ,
		.getItem     = getByteMapItem ,
		.getLastItem = 0 ,
		.getValue    = getByteMapValue } ;
static MByteMapNode mByteMapNode = {
	.getValue = getByteMapNodeValue } ;

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
PIByteMapNode pointer = &self.data->node ;
if( pointer->data == 0 )
	{
		if( jResultIsError( result = createByteMapNode( keyIn ,
				valueIn , iByteMapNodeNil , &self.data->node ) ) )
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
				IByteMapNode node ;
				if( jResultIsError( result = createByteMapNode( &jBuffer(
						pointer->data->key.bytes , pointer->data->key.size - local.size ) ,
						valueIn , pointer->data->owner , &node ) ) )
					return result ;
				result = createByteMapNode( &jBuffer( local.bytes , local.size ) ,
					pointer->data->value , node , &node.data->subs[ *local.bytes ] ) ;
				if( jResultIsError( result ) )
					return freeByteMapNode( node ) , result ;
				if( node.data->owner.data )
					node.data->owner.data->subs[ *node.data->owner.data->key.bytes ] =
						node ;
				else
					self.data->node = node ;
				return result ;
			}
	else
		if( local.size == 0 )
			if( pointer->data->subs[ *key.bytes ].data )
				local = ( pointer = &pointer->data->subs[ *key.bytes ] )->data->key ;
			else
				{
					if( ( result = createByteMapNode( &key , valueIn , *pointer ,
							&pointer->data->subs[ *key.bytes ] ) ) == jSuccessResult )
						++self.data->count ;
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

JResult getByteMapItem( IByteMap self , JBuffer in , JPIMapItem out ) {
IByteMapNode current = self.data->node ;
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
if( !current.data )
	return jValueNotFoundErrorMapResult ;
for( JBuffer currentKey = current.data->key ; ; ++in.bytes , --in.size )
{
	printf( "DEBUG %s(%i) %c %c\n" , __PRETTY_FUNCTION__ , __LINE__ , *currentKey.bytes , *in.bytes ) ;
	if( currentKey.size )
		if( in.size )
			if( *currentKey.bytes != *in.bytes ) return jValueNotFoundErrorMapResult ;
			else ++currentKey.bytes , --currentKey.size ;
		else return jValueNotFoundErrorMapResult ;
	else
		if( in.size )
			if( current.data->subs[ *currentKey.bytes ].data )
				current = current.data->subs[ *currentKey.bytes ] ,
				currentKey.bytes = current.data->key.bytes + 1 ,
				currentKey.size =  current.data->key.size - 1 ;
			else return jValueNotFoundErrorMapResult ;
		else
			if( current.data->value )
				return *out = current.interface , jSuccessMapResult ;
			else return jValueNotFoundErrorMapResult ;
}
}

JResult getByteMapValue( IByteMap self , JBuffer in , JPBuffer out ) {
JIMapItem item ;
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
JResult result = getByteMapItem( self , in , &item ) ;
if( jResultIsError( result ) ) return result ;
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
printf( "DEBUG %s(%i) %p\n" , __PRETTY_FUNCTION__ , __LINE__ , item.data ) ;
printf( "DEBUG %s(%i) %p\n" , __PRETTY_FUNCTION__ , __LINE__ , item.data->methods ) ;
printf( "DEBUG %s(%i) %p\n" , __PRETTY_FUNCTION__ , __LINE__ , item.data->methods->getValue ) ;
return item.data->methods->getValue( item , out ) ;
}

JCounter releaseByteMap( IByteMap self ) {
int result = __sync_sub_and_fetch( &self.data->references , 1 ) ;
if( !result ) free( self.data ) ;
return result ;
}

JResult createByteMapNode( JCPCBuffer keyIn , JCPCBuffer valueIn ,
	IByteMapNode ownerIn , PIByteMapNode out ) {
JResult result ;
if( !( out->data = malloc( sizeof( DByteMapNode ) ) ) )
	return jNotEnoughtMemoryErrorMapResult ;
if( jResultIsNotError( result = jagryInitializeBuffer(
		&out->data->key , keyIn->bytes , keyIn->size ) ) )
	{
		result = jagryCreatePBuffer( valueIn , &out->data->value ) ;
		if( jResultIsNotError( result ) )
			{
				if( ( out->data->owner = ownerIn ).data )
					{
						if( ( out->data->previous = ownerIn.data->last ).data )
							ownerIn.data->last.data->next = *out ;
						else
							ownerIn.data->first = *out ;
						ownerIn.data->last = *out ;
						++ownerIn.data->count ;
					}
				else
					out->data->next.data = out->data->previous.data = 0 ;
				memset( out->data->subs , 0 , sizeof( out->data->subs ) ) ;
				out->data->first.data = out->data->last.data =
					out->data->next.data = 0 ;
				out->data->count = 0 ;
				out->data->methods = &mByteMapNode ;
				return jSuccessMapResult ;
			}
		jagryFreeBuffer( out->data->value ) ;
	}
free( out->data ) ;
*out = iByteMapNodeNil ;
return result ;
}

JResult getByteMapNodeValue( IByteMapNode self , JPBuffer out ) {
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
printf( "DEBUG %s(%i) %p\n" , __PRETTY_FUNCTION__ , __LINE__ , self.data->value ) ;
printf( "DEBUG %s(%i) %li\n" , __PRETTY_FUNCTION__ , __LINE__ , self.data->value->size ) ;
printf( "DEBUG %s(%i) %p\n" , __PRETTY_FUNCTION__ , __LINE__ , self.data->value->bytes ) ;
return jagrySetBuffer( out , self.data->value->bytes , self.data->value->size ) ;
}