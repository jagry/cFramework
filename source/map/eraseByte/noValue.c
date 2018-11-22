#define noValue( items , key , value ) return noValueImplementation( items , sizeof( items ) / sizeof( * items ) , &key , value ) ;

#include <jagry/lbase.h>
#include <jagry/lmap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "!define.h"

#include <byteMapNode.h>

#include <byteMap.h>

static JPCharacter1 noValueCurrentRootItems[] = { "0" , "1" } ;
static JPCharacter1 noValueTransitRootItems[] = { "001" , "002" } ;
static JPCharacter1 noValueCurrentSubItems[] = { "0112" , "0113" , "1" } ;
static JPCharacter1 items[] = { "01" , "02" } ;

static JResult noValueImplementation( JPCharacter1 items[] , JSignedInteger count, JPCBuffer key , JPBuffer value ) {
JIMap map ;
JResult result ;
// start debug
JPCharacter1 inChar = key->bytes ;
// finish debug
if( jResultIsError( result = jagryByteMap( &map ) ) )
	{
		printf( callReturnedError , "jagryByteMap", result , __FILE__ , __LINE__ ) ;
		return result ;
	}
for( JSignedInteger counter = 0 ; count > counter ; ++counter )
	if( ( result = jAddMap( map , jStringBuffer( items[ counter ] ) , jStringBuffer( items[ counter ] ) , 0 ) ) != jSuccesResult )
		{
			printf( callReturnedError , "jAddMap" , result , __FILE__ , __LINE__ ) ;
			return result ;
		}
result = jEraseMap( map , *key , value ) ;
jReleaseMap( map ) ;
if( ( result ) != jMapValueNotFoundErrorResult )
	{
		printf( eraseMapReturnedOther , __FILE__ , __LINE__ , result , jMapValueNotFoundErrorResult ) ;
		return result ;
	}
if( !value || ( value->bytes == 0 && value->size == 0 ) )
	return jSuccesResult ;
printf( valueHasChanged , __FILE__ , __LINE__ , value->bytes , value->size ) ;
return -1 ;
}

JResult noValueCurrentRootNull() {
noValue( noValueCurrentRootItems , jEmptyBuffer , 0 )
}

JResult noValueCurrentRootValue() {
JBuffer value = jEmptyBuffer ;
noValue( noValueCurrentRootItems , jEmptyBuffer , &value )
}

JResult noValueCurrentSubNull() {
noValue( noValueCurrentSubItems , jStringBuffer( "02" ) , 0 )
}

JResult noValueCurrentSubValue() {
JBuffer value = jEmptyBuffer ;
noValue( noValueCurrentSubItems , jStringBuffer( "2" ) , &value )
}

JResult noValueTransitRootNull() {
noValue( noValueTransitRootItems , jStringBuffer( "00" ) , 0 )
}

JResult noValueTransitRootValue() {
JBuffer value = jEmptyBuffer ;
noValue( noValueTransitRootItems , jStringBuffer( "00" ) , &value )
}