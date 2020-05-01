/* !!! */ #include <stdio.h>

#define keywordTokenCharacter dollarCharacter

#define readTokenByte \
	{ \
		JSize size = 1 ; \
		jReturnIfResultIsError( \
			result , jExecuteReader( arg->reader , &arg->character , &size ) ) \
	}
#define endLineTokehHit( endLineArg ) \
	{ \
		if( arg->endLine == undefineEndLine ) arg->endLine = endLineArg ; \
		else if( arg->endLine != endLineArg && arg->endLine != warningEndLine ) \
			printf( \
				"!! WARNING %s(%i): end line\n" , __PRETTY_FUNCTION__ , __LINE__ ) , \
			arg->endLine = warningEndLine ; \
	}

#include <jagry/array.l.h>
#include <jagry/buffer.l.h>
#include <stdlib.h>
#include "character.h"
#include "result.h"
#include "token.h"

#include "factory.h"

// !!! Не подходящее имя
//static JResult arrayManagerCopy( JCPCArrayManager , JPVoid , JCPCVoid ) ;
static JResult getTokenIdentifier( PTokenData ) ;

// !!! Не подходящее имя
//static JCArrayManager declareVariableManager = {
//	.free = jagryArrayManagerFree ,
//	.get = arrayManagerCopy ,
//	.set = arrayManagerCopy ,
//	.size = sizeof( JBuffer ) } ;

//JResult arrayManagerCopy(
//	JCPCArrayManager managerIn , JPVoid destinationIn , JCPCVoid surceIn ) {
//return jSuccessResult ;
//}

JVoid freeToken( PUToken out ) {
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
if( out->base.type == identifierTokenType ||
		out->base.type == variableTokenType )
	jagryClearBuffer( &out->name.value ) ;
}

JResult getToken( PTokenData arg ) {
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
JResult result ;
for( ; ; )
	{
		if( arg->status == readTokenStatus )
			readTokenByte
		printf(
			"DEBUG %s(%i): character=%02X\n" ,
			__PRETTY_FUNCTION__ , __LINE__ , arg->character ) ;
		if( characterIsBlank( arg->character ) ) arg->status = readTokenStatus ;
		else if( arg->character == lowLineCharacter \
				|| characterIsLetter( arg->character ) )
			{
				arg->token.name.type = identifierTokenType ;
				if( jResultIsError( result = jagryInitializeBuffer( \
						&arg->token.name.value , &arg->character , 1 ) ) )
					return result ;
				return getTokenIdentifier( arg ) ;
			}
		else switch( arg->character ) {
		case commaCharacter : 
			arg->status = readTokenStatus ;
			arg->token.name.type = operatorTokenType ;
			arg->token.identifier.value = commaOperatorToken ;
			return jSuccessResult ;
		case keywordTokenCharacter :
			{
				PFactoryDescription description ;
				arg->token.name.value = jEmptyBuffer ;
				jReturnIfResultIsError( result , getTokenIdentifier( arg ) )
				jReturnIfResultIsError(
					result ,
					jGetMapValue( arg->map , arg->token.name.value , &description ) )
				return description->method( description->argument , &arg->token ) ;
			}
		case reverseSolidusCharacter :
			{
				JSize size = 1 ;
				if( jResultIsError(
						result = jExecuteReader( arg->reader , &arg->character , &size ) ) )
					return result == jEndErrorReaderResult ?
						unexpectedEndErrorResult :
						result ;
			}
			switch( arg->character ) {
			case carriageReturnCharacter :
				readTokenByte
				if( arg->character == lineFeedCharacter )
					{
						endLineTokehHit( windowsEndLine )
						arg->status = readTokenStatus ;
					}
				else
					{
						endLineTokehHit( appleEndLine )
						arg->status = currentTokenStatus ;
					}
				break ;
			case lineFeedCharacter :
				endLineTokehHit( linuxEndLine )
				arg->status = readTokenStatus ;
				break ;
			default: return unexpectedCharacterErrorResult ;
			}
			arg->status = readTokenStatus ;
			arg->token.name.type = endTokenType ;
			arg->token.identifier.value = escapeLineEndToken ;
			return jSuccessResult ;
		default : return unexpectedCharacterErrorResult ;
		}
	}
}

JResult getTokenIdentifier( PTokenData arg ) {
JResult result ;
for( ; ; )
	{
		{
			JSize size = 1 ;
			if( jResultIsError( result = jExecuteReader( \
					arg->reader , &arg->character , &size ) ) ) \
				return ( result == jEndErrorReaderResult ) ? \
					( arg->status = endTokenStatus , jSuccessResult ) : \
					result ;
		}
		if( characterIsNotLetter( arg->character ) \
				&& characterIsNotDigit( arg->character ) \
				&& arg->character != lowLineCharacter )
			return arg->token.name.value.size ?
				( arg->status = currentTokenStatus , jSuccessResult ) :
				missingKeywordErrorResult ;
		else
			if( jResultIsError( result = jagryAddBufferByte(
					&arg->token.name.value , arg->character ) ) )
				return /* !!! jagryClearBuffer( &arg->token.name.value ) , */ result ;
	}
}
