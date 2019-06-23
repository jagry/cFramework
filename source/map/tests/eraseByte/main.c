#define _POSIX_C_SOURCE 199309L

#include <jagry/lbase.h>
#include <jagry/lmap.h>
#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include "message.h"
#include "time.h"

#include <byteMapNode.h>
#include "iteration.h"

#include <byteMap.h>

JUnsignedInteger1 mainDebug = 0 ;

JResult main() {
JResult result ;
JCounter errors = 0 ;
struct timespec time ;
clock_gettime( CLOCK_REALTIME , &time ) ;
printf( "> start test 'eraseByteMap'" jNewLine ) ;
{
	IterationDescription description[] = {
		/* initializeIterationDescription(
			eraseByteMapLastNodePoint ,
			0 ,
			0 ,
			"last node(no byte)" ,
			( JAPCharacter1 ){ "" } ,
			jStringBuffer( "" ) ) ,
		initializeIterationDescription(
			eraseByteMapLastNodePoint ,
			2 ,
			0 ,
			"last node(byte)" ,
			( JAPCharacter1 ){ "00" } ,
			jStringBuffer( "00" ) ) ,
		initializeIterationDescription(
			eraseByteMapNotModifyOwnerPoint ,
			0 ,
			1 ,
			"has value(no byte)" ,
			( ( JAPCharacter1 ){ "" , "0" } ) ,
			jStringBuffer( "0" ) ) ,
		initializeIterationDescription(
			eraseByteMapNotModifyOwnerPoint ,
			2 ,
			1 ,
			"has value(byte)" ,
			( ( JAPCharacter1 ){ "" , "011" } ) ,
			jStringBuffer( "011" ) ) ,
		initializeIterationDescription(
			eraseByteMapNotModifyOwnerPoint ,
			2 ,
			1 ,
			"sub node(no byte)" ,
			( ( JAPCharacter1 ){ "00" , "001" } ) ,
			jStringBuffer( "001" ) ) , */
		initializeIterationDescription(
			eraseByteMapConcateParentPoint ,
			0 ,
			1 ,
			"sub node(byte)" ,
			( ( JAPCharacter1 ){ "0" , "1" } ) ,
			jStringBuffer( "0" ) ) } ;
	for( JSignedInteger1 counter = 0 ; ( sizeof( description ) / sizeof( *description ) ) > counter ; ++counter )
		{
			JBuffer value ;
			printf( messageIndent "call " jStringSpecifier " with null: " , description[ counter ].text ) ;
			if( iteration( description[ counter ] , 0 , nilCallback , jSuccessMapResult ) )
				++errors ;
			printf( messageIndent "call " jStringSpecifier " with value: " , description[ counter ].text ) ;
			description[ counter ].point |= eraseByteMapSetValuePoint ;
			if( iteration( description[ counter ] , &value , nilCallback , jSuccessMapResult ) )
				++errors ;
		}
}
{
	JPCharacter1
		endInItemsB[] = { "00" } ,
		endInItemsBN[] = { "00122" , "003" } ,
		endInItemsN[] = { "011" , "2" } ,
		endInItemsNB[] = { "011" , "2" } ,
		missingChildItems[] = { "0" , "1" } ,
		missingChildItemsB[] = { "001" , "002" } ,
		missingChildItemsBN[] = { "0012" , "0013" , "004"} ,
		missingChildItemsN[] = { "01" , "02" , "3"} ,
		missingChildItemsNB[] = { "0112" , "0113" , "4" } ,
		noValueItemsB[] = { "001" , "002" } ,
		noValueItemsBN[] = { "0012" , "0013" , "004" } ,
		noValueItemsN[] = { "01" , "02" , "3" } ,
		noValueItemsNB[] = { "0112" , "0113" , "4" } ;
	const IterationDescription description[] = {
		initializeIterationDescription(
			eraseByteMapEmptyPoint ,
			0 ,
			0 ,
			"empty node" ,
			( JAPCharacter1 ){ } ,
			jEmptyBuffer ) ,
		initializeIterationDescription(
			eraseByteMapEndInPoint ,
			0 ,
			0 ,
			"end argument buffer root node(no byte)" ,
			( JAPCharacter1 ){ "00" } ,
			jStringBuffer( "" ) ) ,
		initializeIterationDescription(
			eraseByteMapEndInPoint ,
			1 ,
			0 ,
			"end argument buffer root node(byte)" ,
			endInItemsB ,
			jStringBuffer( "0" ) ) ,
		initializeIterationDescription(
			eraseByteMapEndInPoint ,
			0 ,
			1 ,
			"end argument buffer sub node(no byte)" ,
			endInItemsN ,
			jStringBuffer( "0" ) ) ,
		initializeIterationDescription(
			eraseByteMapEndInPoint ,
			2 ,
			1 ,
			"end argument buffer sub node(root byte)" ,
			endInItemsBN ,
			jStringBuffer( "001" ) ) ,
		initializeIterationDescription(
			eraseByteMapEndInPoint ,
			1 ,
			1 ,
			"end argument buffer sub node(sub byte)" ,
			endInItemsNB ,
			jStringBuffer( "01" ) ) ,
		initializeIterationDescription(
			eraseByteMapMissingChildPoint ,
			0 ,
			0 ,
			"missing child root(no byte)" ,
			missingChildItems ,
			jStringBuffer( "2" ) ) ,
		initializeIterationDescription(
			eraseByteMapMissingChildPoint ,
			2 ,
			0 ,
			"missing child root(byte)" ,
			missingChildItemsB ,
			jStringBuffer( "003" ) ) ,
		initializeIterationDescription(
			eraseByteMapMissingChildPoint ,
			0 ,
			1 ,
			"missing child sub(no byte)" ,
			missingChildItemsN ,
			jStringBuffer( "03" ) ) ,
		initializeIterationDescription(
			eraseByteMapMissingChildPoint ,
			2 ,
			1 ,
			"missing child sub(root byte)" ,
			missingChildItemsBN ,
			jStringBuffer( "0014" ) ) ,
		initializeIterationDescription(
			eraseByteMapMissingChildPoint ,
			2 ,
			1 ,
			"missing child sub(sub byte)" ,
			missingChildItemsNB ,
			jStringBuffer( "0114" ) ) ,
		initializeIterationDescription(
			eraseByteMapNotEqualPoint ,
			0 ,
			0 ,
			"not equal root node(no byte)" ,
			( ( JAPCharacter1 ){ "00" } ) ,
			jStringBuffer( "1" ) ) ,
		initializeIterationDescription(
			eraseByteMapNotEqualPoint ,
			1 ,
			0 ,
			"not equal root node(no byte)" ,
			( ( JAPCharacter1 ){ "00" } )
			,
			jStringBuffer( "01" ) ) ,
		initializeIterationDescription(
			eraseByteMapNotEqualPoint ,
			0 ,
			1 ,
			"not equal sub node(no byte)" ,
			( ( JAPCharacter1 ){ "011" , "2"} ) ,
			jStringBuffer( "02" ) ) ,
		initializeIterationDescription(
			eraseByteMapNotEqualPoint ,
			2 ,
			1 ,
			"not equal sub node(root byte)" ,
			( ( JAPCharacter1 ){ "00122" , "002"} ) ,
			jStringBuffer( "0013" ) ) ,
		initializeIterationDescription(
			eraseByteMapNotEqualPoint ,
			1 ,
			1 ,
			"not equal sub node(sub byte)" ,
			( ( JAPCharacter1 ){ "011" , "2"} ) ,
			jStringBuffer( "012" ) ) ,
		initializeIterationDescription(
			eraseByteMapNoValuePoint ,
			0 ,
			0 ,
			"no value root node(no byte)" ,
			( ( JAPCharacter1 ){ "011" , "233" } ) ,
			jStringBuffer( "" ) ) ,
		initializeIterationDescription(
			eraseByteMapNoValuePoint ,
			2 ,
			0 ,
			"no value root node(byte)" ,
			noValueItemsB ,
			jStringBuffer( "00" ) ) ,
		initializeIterationDescription( eraseByteMapNoValuePoint , 0 , 1 , "no value sub node(no byte)" , noValueItemsN , jStringBuffer( "0" ) ) ,
		initializeIterationDescription( eraseByteMapNoValuePoint , 2 , 1 , "no value sub node(root byte)" , noValueItemsBN , jStringBuffer( "001" ) ) ,
		initializeIterationDescription( eraseByteMapNoValuePoint , 2 , 1 , "no value sub node(sub byte)" , noValueItemsNB , jStringBuffer( "011" ) ) } ;
	for( JSignedInteger1 counter = 0 ; ( sizeof( description ) / sizeof( *description ) ) > counter ; ++counter )
		{
			printf( messageIndent "call " jStringSpecifier ": " , description[ counter ].text ) ;
			if( iteration( description[ counter ] , 0 , nilCallback , jValueNotFoundErrorMapResult ) )
				++errors ;
		}
}
printf( "< finish test 'eraseByteMap' " ) ;
time = GetDuration( &time ) ;
if( errors == 0 )
	{
		printf( "succesfully %li.%09li" jNewLine , time.tv_sec , time.tv_nsec ) ;
		return 0 ;
	}
if( errors == 1 )
	printf( "with error %li.%09li" jNewLine , time.tv_sec , time.tv_nsec ) ;
else
	printf( "with errors(" jCounterSpecifier ") %li.%09li" jNewLine , errors , time.tv_sec , time.tv_nsec ) ;
return -1 ;
}