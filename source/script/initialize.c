#include <jagry/map.l.h>
#include "token.h"

#include "factory.h"

#include "initialize.h"

static struct {
	JPCharacter1 character ;
	KeywordFactory factory ; } pairs[] = {
		{ .character = "var" , .factory = declareVariableKeywordFactory } ,
		{ .character = "variable" , .factory = declareVariableKeywordFactory } ,
		{ .character = "zDebug" , .factory = debugTestKeywordFactory } } ;

jInternal( JResult )initialize( JPIMap out ) {
JResult result = jagryByteMap( out ) ;
if( jResultIsError( result ) )
	return result ;
for( JCounter counter = 0 ;
		counter < sizeof( pairs ) / sizeof( *pairs ) ; ++counter )
	{
		JPCBuffer buffer = &jMethodBuffer( pairs[ counter ].factory ) ;
		result = jAddMapItem( *out , &jStringBuffer( "var" ) , buffer , 0 ) ;
		if( jResultIsError( result ) )
			return jReleaseMap( *out ) , result ;
	}
return jSuccessResult ;
}