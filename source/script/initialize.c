#include <jagry/map.l.h>
#include "token.h"

#include "factory.h"

#include "initialize.h"

typedef struct InitializePair InitializePair ;
typedef struct InitializeTask InitializeTask ;
typedef InitializePair * PInitializePair ;

struct InitializePair {
	JPCharacter1 character ;
	PFactoryDescription factory ; } ;

static JCMapManager manager = {
	.free = jagryMapManagerFree ,
	.get = jagryMapManagerCopy ,
	.set = jagryMapManagerCopy ,
	.size = sizeof( PFactoryDescription ) } ;

static FactoryDescription initializeBeginFactory = {
	.argument = { .keyword = {
		.identifier = beginKeywordToken ,
		.type = keywordTokenType } } ,
	.method = standardFactory } ;
static FactoryDescription initializeEndFactory = {
	.argument = { .keyword = {
		.identifier = endKeywordToken ,
		.type = keywordTokenType } } ,
	.method = standardFactory } ;
static FactoryDescription initializeVariableFactory = {
	.argument = { .keyword = {
		.identifier = variableKeywordToken ,
		.type = keywordTokenType } } ,
	.method = standardFactory } ;
static InitializePair initializePairs[] = {
	{ .character = "begin" , .factory = &initializeBeginFactory } ,
	{ .character = "end" , .factory = &initializeEndFactory } ,
	{ .character = "finish" , .factory = &initializeEndFactory } ,
	{ .character = "start" , .factory = &initializeBeginFactory } ,
	{ .character = "var" , .factory = &initializeVariableFactory } ,
	{ .character = "variable" , .factory = &initializeVariableFactory } } ;

jInternal( JResult )initialize( JPIBufferMap out ) {
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
JResult result = jagryBufferMap( &manager , out ) ;
PInitializePair current =
	initializePairs + sizeof( initializePairs ) / sizeof( InitializePair ) ;
if( jResultIsError( result ) )
	return result ;
do
	{
		printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
		--current ;
		if( jResultIsError( result = jNewMapItem(
				*out ,
				&jStringBuffer( current->character ) ,
				&current->factory ,
				jNull ) ) )
			return jReleaseMap( *out ) , result ;
	} while( current != initializePairs ) ;
return jSuccessResult ;
}
