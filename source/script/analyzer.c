/* !!! */ #include <stdio.h>

#include <jagry/array.l.h>
#include <stdlib.h>
#include "result.h"
#include "token.h"

#include "analyzer.h"

static JResult pushAnalyzer( PUToken ) ;
static JResult pushCircleBracketAnalyzer(
	PICircleBracketAnalyzer , PUToken ) ;
static JResult pushDeclareVariableAnalyzer(
	PIDeclareVariableAnalyzer , PUToken ) ;
static JResult pushDeclareVariableItemAnalyzer(
	PIDeclareVariableAnalyzer , PUToken ) ;

static CMCircleBracketAnalyzer circleBracketAnalyzer = {
	.push = pushCircleBracketAnalyzer } ;
static CMDeclareVariableAnalyzer variableAnalyzer = {
	.push = pushDeclareVariableAnalyzer } ;
static CMDeclareVariableAnalyzer variableItemAnalyzer = {
	.push = pushDeclareVariableItemAnalyzer } ;

JResult pushAnalyzer( PUToken in ) {
switch( in->base.type ) {
case keywordTokenType : return unexpectedKeywordErrorResult ;
case operatorTokenType : return unexpectedOperatorErrorResult ;
default : return unexpectedIdentifierErrorResult ;
}
}

static JResult pushCircleBracketAnalyzer(
	PICircleBracketAnalyzer self , PUToken in ) {
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
return pushAnalyzer( in ) ;
}

JResult pushDeclareVariableAnalyzer(
	PIDeclareVariableAnalyzer self , PUToken in ) {
printf(
	"DEBUG %s(%i): type=%i\n" ,
	__PRETTY_FUNCTION__ , __LINE__ , in->base.type ) ;
switch( in->base.type ) {
case identifierTokenType :
	switch( in->identifier.value ) {
	case variableKeywordToken :
		{
			JResult result =
				jPushArrayBackward( self->_->items , &in->identifier.value , 0 ) ;
			if( jResultIsError( result ) )
				return result ;
			self->_->_ = &variableItemAnalyzer ;
			return successResult ;
		}
		break ;
	}
}
return pushAnalyzer( in ) ;
}

JResult pushDeclareVariableItemAnalyzer(
	PIDeclareVariableAnalyzer self , PUToken in ) {
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
switch( in->base.type ) {
case operatorTokenType :
	switch( in->identifier.value ) {
	case commaOperatorToken :
		{
			self->_->_ = &variableAnalyzer ;
			return notReadyAnalyzerWarningResult ;
		}
	}
	break ;
}
return pushAnalyzer( in ) ;
}

JResult pushUnitAnalyzer( PIUnitAnalyzer self , PUToken in ) {
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
switch( in->base.type ) {
case identifierTokenType :
	printf( "NOT IMPLEMENT %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
	exit( 1000 );
	break ;
case keywordTokenType :
	switch( in->identifier.value ) {
	case variableKeywordToken :
		{
			JResult result ;
			IDeclareVariableAnalyzer variable ;
			if( !( variable._ = malloc( sizeof( DeclareVariableAnalyzer ) ) ) )
				return jNotEnoughtMemoryErrorResult ;
			if( jResultIsError( result = jagryListArray( 0 , &variable._->items ) ) )
				return free( variable._ ) , result ;
			variable._->_ = &variableAnalyzer ;
			variable._->owner = self->base ;
			self->base = variable.base ;
			return notReadyAnalyzerWarningResult ;
		}
		break ;
	}
	break ;
}
return pushAnalyzer( in ) ;
}
