/* !!! */ #include <stdio.h>

#include <jagry/map.i.h>
#include <jagry/buffer.h>
#include <stdlib.h>
#include "result.h"
#include "token.h"

#include "builder.h"
#include "factory.h"

static JResult pushUnitBuilder( PIUnitBuilder , PUToken ) ;
static JResult pushVariableBuilder( PIVariableBuilder , PUToken ) ;
static JResult pushVariableItemBuilder( PIVariableItemBuilder , PUToken ) ;

static CMUnitBuilder unitBuilder = { .push = pushUnitBuilder } ;
static CMVariableBuilder variableBuilder = { .push = pushVariableBuilder } ;
static CMVariableItemBuilder variableItemBuilder = {
	.push = pushVariableItemBuilder } ;

DUnitBuilder dUnitBuilder = { .methods = &unitBuilder , .owner = 0 } ;

JResult pushUnitBuilder( PIUnitBuilder self , PUToken in ) {
switch( in->base.type ) {
case identifierTokenType :
	printf( "NOT IMPLEMENT %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
	exit( 1000 );
case keywordTokenType :
	switch( in->keyword.identifier ) {
	case variableKeywordToken :
		{
			IVariableBuilder variable ;
			if( !( variable.data = malloc( sizeof( DVariableBuilder ) ) ) )
				return jNotEnoughtMemoryErrorResult ;
			variable.data->methods = &variableBuilder ;
			variable.data->owner = self->base ;
			self->base = variable.base ;
			return notReadyWarningBuilderResult ;
		}
	default :
		return unexpectedKeywordErrorResult ;
	}
}
exit( 1000 ) ;
return jSuccessResult ;
}

JResult pushVariableBuilder( PIVariableBuilder self , PUToken in ) {
switch( in->base.type ) {
case identifierTokenType :
	switch( in->keyword.identifier ) {
	case variableKeywordToken :
		{
			IVariableBuilder variable ;
			if( !( variable.data = malloc( sizeof( DVariableBuilder ) ) ) )
				return jNotEnoughtMemoryErrorResult ;
			variable.data->methods = &variableBuilder ;
			variable.data->owner = self->base ;
			self->base = variable.base ;
			return notReadyWarningBuilderResult ;
		}
	default :
		return unexpectedKeywordErrorResult ;
	}
case keywordTokenType :
	return unexpectedKeywordErrorResult ;
}
exit( 1000 ) ;
return jSuccessResult ;
}

JResult pushVariableItemBuilder( PIVariableItemBuilder self , PUToken in ) {
switch( in->base.type ) {
case identifierTokenType :
	switch( in->keyword.identifier ) {
	case variableKeywordToken :
		{
			IVariableBuilder variable ;
			if( !( variable.data = malloc( sizeof( DVariableBuilder ) ) ) )
				return jNotEnoughtMemoryErrorResult ;
			variable.data->methods = &variableBuilder ;
			variable.data->owner = self->base ;
			self->base = variable.base ;
			return notReadyWarningBuilderResult ;
		}
	default :
		return unexpectedKeywordErrorResult ;
	}
case keywordTokenType :
	return unexpectedKeywordErrorResult ;
}
exit( 1000 ) ;
return jSuccessResult ;
}
