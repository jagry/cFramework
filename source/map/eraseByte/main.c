#define initializeTest( byteIn , nodeIn , exitIn , methodIn ) { .byte = byteIn , .node = nodeIn , .exit = exitIn , .method = methodIn , .text = stringify( methodIn ) }

#include <jagry/lbase.h>
#include <jagry/lmap.h>
#include <jagry/buffer.h>
#include <stdio.h>
#include "!define.h"

#include <byteMapNode.h>

#include <byteMap.h>

JResult emptyNull( JVoid ) ;
JResult emptyValue( JVoid ) ;
JResult noValueCurrentRootNull( JVoid ) ;
JResult noValueCurrentRootValue( JVoid ) ;
JResult noValueCurrentSubNull( JVoid ) ;
JResult noValueCurrentSubValue( JVoid ) ;
JResult noValueTransitRootNull( JVoid ) ;
JResult noValueTransitRootValue( JVoid ) ;

const struct {
JResult( *method )() ;
JPCCharacter1 text ;
JUnsignedInteger8 byte ;
JUnsignedInteger8 node ;
JUnsignedInteger1 exit ;
} mainTests[] = {
	initializeTest( 0 , 0 , eraseByteMapPointReturnEmpty , emptyNull ) ,
	initializeTest( 0 , 0 , eraseByteMapPointReturnEmpty , emptyValue ) ,
	initializeTest( 0 , 0 , eraseByteMapPointReturnNoValue , noValueCurrentRootNull ) ,
	initializeTest( 0 , 0 , eraseByteMapPointReturnNoValue , noValueCurrentRootValue ) ,
	initializeTest( 0 , 0 , eraseByteMapPointReturnNoValue , noValueCurrentSubNull ) ,
	initializeTest( 0 , 0 , eraseByteMapPointReturnNoValue , noValueCurrentSubValue ) ,
	initializeTest( 0 , 0 , eraseByteMapPointReturnNoValue , noValueTransitRootNull ) ,
	initializeTest( 0 , 0 , eraseByteMapPointReturnNoValue , noValueTransitRootValue ) /*,
	initializeTest( 0 , 0 , eraseByteMapPointReturnNoValue , noValueTransitSubNull ) ,
	initializeTest( 0 , 0 , eraseByteMapPointReturnNoValue , noValueTransitSubValue ) */ } ;

JUnsignedInteger1 mainDebug = 0 ;

JResult main() {
JResult callResult ;
JResult result = 0 ;
printf( "start test 'eraseByteMap'" jNewLine ) ;
for( JSignedInteger1 counter = 0 ; ( sizeof( mainTests ) / sizeof( *mainTests ) ) > counter ; ++counter )
	{
		printf( "call '" jStringSpecifier "': " , mainTests[ counter ].text ) ;
		jagryDebugEraseByteMap = ( JDebugEraseByteMap ){ .byte = 0 , .node =0 , .exit = 0 } ;
		if( !( callResult = mainTests[ counter ].method() ) )
			{
				if( jagryDebugEraseByteMap.exit == mainTests[ counter ].exit )
					mainDebug |= jagryDebugEraseByteMap.exit ,
					printf( "done" jNewLine ) ;
				else
					printf( debugMustBe , mainTests[ counter ].exit , jagryDebugEraseByteMap.exit , __FILE__ , __LINE__ ) ,
					result = -1 ;
			}
	}
printf( "finish test 'eraseByteMap': " jResultSpecifier jNewLine , result ) ;
return result ;
}