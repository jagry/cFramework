#include <jagry/lbase.h>
#include <jagry/lmap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../byteMapNode.h"

#include "../../byteMap.h"

#define indent "   "

JPCharacter1 addItems[] = { "AbbbCdddEfff" , "AbbbGhhh" , "AbbbCddd" } ;
JPCharacter1 eraseItems[] = { "AbbbGhhh" , "AbbbCddd" , "AbbbCdddEfff" } ;

/*ByteMapNode byteMapNodes[] = { { .count = 0 , .owner = 0 } } ;
const ByteMap byteMaps[] = {
	{ .count = 0 , .node = 0 , .methods = 0 } ,
	{ .count = 1 , .node = &byteMapNodes[ 0 ] , .methods = 0 } } ;*/

void drawBuffer( JBuffer buffer , JCounter level ) {
printf( "buffer{ size = " jSizeSpecifier " , bytes = %p [" , buffer.size , buffer.bytes ) ;
for( ; buffer.size ; ++buffer.bytes , --buffer.size )
	printf( " " jUnsignedInteger1Specifier , *( JPByte )buffer.bytes ) ;
printf( " ] }" ) ;
}

void drawNode( ByteMapNode* node , JCounter level ) {
printf( "mapNode{\r\n" ) ;
for( JCounter indentCounter = level ; indentCounter ; --indentCounter )
	printf( "%s" , indent ) ;
printf( "%scount = " jSignedInteger2Specifier jNewLine , indent , node->count  ) ;
for( JCounter indentCounter = level ; indentCounter ; --indentCounter )
	printf( "%s" , indent ) ;
printf( "%skey = " , indent ) ;
drawBuffer( node->key , level ) ;
printf( jNewLine ) ;
for( JCounter indentCounter = level ; indentCounter ; --indentCounter )
	printf( "%s" , indent ) ;
printf( "%sowner = %p" jNewLine , indent , node->owner ) ;
for( JCounter indentCounter = level ; indentCounter ; --indentCounter )
	printf( "%s" , indent ) ;
printf( "%svalue = %p" , indent , node->value ) ;
if( node->value )
	printf( "->" ) ,
	drawBuffer( *node->value , level ) ;
for( JCounter counter = 0 ; counter <= jMaxUnsignedInteger1 ; ++counter )
	if( node->subs[ counter ] )
		{
			printf( jNewLine ) ;
			for( JCounter indentCounter = level ; indentCounter ; --indentCounter )
				printf( "%s" , indent ) ;
			printf( "%s[ " jCounterSpecifier " ] = %p->" , indent , counter , node->subs[ counter ] ) ;
			drawNode( node->subs[ counter ] , level + 1 ) ;
		}
printf( " }" ) ;
}

void draw( ByteMap* map ) {
printf( "map{" jNewLine indent "count = " jSignedIntegerSpecifier jNewLine indent "node = %p", map->count , map->node ) ;
if( map->node )
	printf( "->" ) ,
	drawNode( map->node , 1 ) ;
printf( " }" jNewLine ) ;
}

JResult main() {
JIMap map ;
JResult result = jagryByteMap( &map ) ;
if( jResultIsError( result ) )
	return -1 ;
if( map == 0 )
	exit( -2 ) ;
draw( ( ByteMap* )map ) ;
for( JSize counter = 0 ; ( sizeof( addItems ) / sizeof( *addItems ) ) > counter ; ++counter )
	{
		JBuffer
			key = jBuffer( addItems[ counter ] , strlen( addItems[ counter ] ) ) ,
			value = jBuffer( addItems[ counter ] , strlen( addItems[ counter ] ) ) ;
		jAddMap( map , key , value , 0 ) ;
		draw( ( ByteMap* )map ) ;
	}
{
	JBuffer value1 = jEmptyBuffer( ) ;
	for( JSize counter = 0 ; ( sizeof( eraseItems ) / sizeof( *eraseItems ) ) > counter ; ++counter )
		{
			JBuffer key = jBuffer( eraseItems[ counter ] , strlen( eraseItems[ counter ] ) ) ;
			jEraseMap( map , key , &value1 ) ;
			draw( ( ByteMap* )map ) ;
		}
	jagryClearBuffer( &value1 ) ;
}
return 0 ;
}