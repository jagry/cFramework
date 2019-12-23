#define capitalAParserCharacter 'A'
#define capitalFParserCharacter 'F'
#define capitalZParserCharacter 'Z'
#define carriageReturnParserCharacter '\r'
#define digit0ParserCharacter '0'
#define digit9ParserCharacter '9'
#define dollarCharacter '$'
#define lineFeedParserCharacter '\n'
#define lowLineParserCharacter '_'
#define smallAParserCharacter 'a'
#define smallFParserCharacter 'f'
#define smallZParserCharacter 'z'
#define spaceParserCharacter ' '
#define tabParserCharacter '\t'

#define isParserBlank( character ) ( character == carriageReturnParserCharacter || \
	character == lineFeedParserCharacter || character == spaceParserCharacter || character == tabParserCharacter )
#define isParserCapital( character ) ( character >= capitalAParserCharacter && character <= capitalZParserCharacter )
#define isParserDigit( character ) ( character >= digit0ParserCharacter && character <= digit9ParserCharacter )
#define isParserFirst6Capital( character ) ( character >= capitalAParserCharacter && character <= capitalFParserCharacter )
#define isParserFirst6Letter( character ) ( isParserFirst6Capital( character ) || isParserFirst6Small( character ) )
#define isParserFirst6Small( character ) ( character >= smallAParserCharacter && character <= smallFParserCharacter )
#define isParserLast20Capital( character ) ( character > capitalFParserCharacter && character <= capitalZParserCharacter )
#define isParserLast20Letter( character ) ( isParserFirst6Capital( character ) || isParserFirst6Small( character ) )
#define isParserLast20Small( character ) ( character > smallFParserCharacter && character <= smallZParserCharacter )
#define isParserLetter( character ) ( isParserCapital( character ) || isParserSmall( character ) )
#define isParserSmall( character ) ( character >= smallAParserCharacter && character <= smallZParserCharacter )

#include <jagry/base.i.h>
#include <stdio.h>
#include <stdlib.h>
#include <jagry/reader.i.h>
#include "result.h"
#include "token.h"

#include "parser.h"

static JResult createTextParser( IParser , JCPCBuffer , PCMBaseStateParser ) ;
static JResult executeDollarParser( IParser , PIBaseToken ) ;
static JResult executeIdentificatorParser( IParser , PIBaseToken ) ;
static JResult executeKeywordParser( IParser , PIBaseToken ) ;
static JResult executeNumberParser( IParser , PIBaseToken ) ;
static JResult executeParser( IParser , PIBaseToken ) ;
static JResult executeStartParser( IParser , PIBaseToken ) ;
static JVoid freeDollarParser( IParser ) ;
static JVoid freeParser( IParser ) ;
static JVoid freeStartParser( IParser ) ;
static JResult parserDispatch( IParser , JByte , PIBaseToken ) ;
static JResult readParserStream( JIReader , JPByte ) ;
static JResult tokenStartParser( IParser , IBaseToken ) ;

static CMBaseStateParser
	dollarParserMethods = { .execute = executeDollarParser , .free = freeDollarParser , .token = 0 } ,
	identificatorParserMethods = { .execute = executeIdentificatorParser , .free = freeDollarParser , .token = 0 } ,
	keywordParserMethods = { .execute = executeKeywordParser , .free = freeDollarParser , .token = 0 } ,
	numberParserMethods = { .execute = executeNumberParser , .free = freeDollarParser , .token = 0 } ,
	startParserMethods = { .execute = executeStartParser , .free = freeStartParser , .token = tokenStartParser } ;
static CMParser parserMethods = { .execute = executeParser , .free = freeParser } ;

static DStartStateParser startParserData = { .methods = &startParserMethods } ;

static IStartStateParser startParserInstance = { .data = &startParserData } ;

JResult createTextParser(
	IParser self ,
	JCPCBuffer bufferIn ,
	PCMBaseStateParser methodsIn )
{
	ITextStateParser text ;
	if( !( text.data = malloc( sizeof( DTextStateParser ) ) ) )
		return jNotEnoughtMemoryErrorResult ;
	text.data->buffer = *bufferIn ;
	text.data->methods = methodsIn ;
	text.data->previous = self.data->current ;
	self.data->current = text.base ;
	return jSuccessResult ;
}

JResult executeDollarParser(
	IParser self ,
	PIBaseToken out )
{
	JByte character ;
	union {
		JSize size ;
		PIKeywordToken token ;
	} data = { .size = 1 } ;
	printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
	for( ; ; )
		{
			JResult result = jExecuteReader( self.data->reader , &character , &data.size ) ;
			if( jResultIsError( result ) )
				return result ;
			// ??? Надо ли проверять размер
			out->data = 0 ;
			if( isParserDigit( character ) )
				{
					self.data->current.data->methods = &numberParserMethods ;
					return jSuccessResult ;
				}
			if( isParserLetter( character ) )
				{ // сжать в &:
					if( jResultIsError( result = jagryAddBufferByte( &( ( ITextStateParser )self.data->current ).data->buffer, character ) ) )
						return result ;
					self.data->current.data->methods = &keywordParserMethods ;
					return jSuccessResult ;
				}
			return unexpectedCharacterParserErrorResult ;
		}
}

static JResult executeIdentificatorParser(
	IParser self ,
	PIBaseToken out )
{
}

JResult executeKeywordParser(
	IParser self ,
	PIBaseToken out )
{
	JByte character ;
	union {
		JSize size ;
		PIKeywordToken token ;
	} data = { .size = 1 } ;
	printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
	for( ; ; )
		{
			JResult result = jExecuteReader( self.data->reader , &character , &data.size ) ;
			if( jResultIsError( result ) )
				return result ;
			// ??? Надо ли проверять размер
			if( !isParserLetter( character ) )
				if( out->data = malloc( sizeof( IKeywordToken ) ) ) 
					{
						( ( PDKeywordToken )out->data )->buffer = ( ( ITextStateParser )self.data->current ).data->buffer ;
						( ( PDKeywordToken )out->data )->type = keywordTokenType ;
						( ( ITextStateParser )self.data->current ).data->buffer = jEmptyBuffer ;
						return jSuccessResult ;
					}
				else
					return jNotEnoughtMemoryErrorResult ;
			if( jResultIsError( result = jagryAddBufferByte( &( ( ITextStateParser )self.data->current ).data->buffer , character ) ) )
				return result ;
		}
}

JResult executeNumberParser(
	IParser self ,
	PIBaseToken out )
{
	JByte character ;
	union {
		JSize size ;
		PIKeywordToken token ;
	} data = { .size = 1 } ;
	printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
	for( ; ; )
		{
			JResult result = jExecuteReader( self.data->reader , &character , &data.size ) ;
			if( jResultIsError( result ) )
				return result ;
			// ??? Надо ли проверять размер
			if( !isParserLetter( character ) )
				if( out->data = malloc( sizeof( DKeywordToken ) ) ) 
					{
						( ( PDKeywordToken )out->data )->buffer = ( ( ITextStateParser )self.data->current ).data->buffer ;
						out->data->type = keywordTokenType ;
						( ( ITextStateParser )self.data->current ).data->buffer = jEmptyBuffer ;
						return jSuccessResult ;
					}
				else
					return jNotEnoughtMemoryErrorResult ;
			if( jResultIsError( result = jagryAddBufferByte( &( ( ITextStateParser )self.data->current ).data->buffer , character ) ) )
				return result ;
		}
}

JResult executeParser(
	IParser self ,
	PIBaseToken token )
{
	printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
	for( ; ; )
		{
			{
				JResult result = jExecuteStateParser( self.data->current , self , token ) ;
				if( jResultIsError( result ) )
					return result ;
			}
			if( token->data )
			{
				{
					IBaseStateParser stateParser = self.data->current.data->previous ; 
					self.data->current.data->methods->free( self ) ;
					self.data->current = stateParser ;
				}
				{
					self.data->current.data->methods->token( self , *token ) ;
				}
			}
		}
}

JResult executeStartParser(
	IParser self ,
	PIBaseToken out )
{
	JByte character ;
	JSize size = 1 ;
	printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
	JResult result = jExecuteReader( self.data->reader , &character , &size ) ;
	if( jResultIsError( result ) )
		return result ;
	return parserDispatch( self , character , out ) ;
}

JVoid freeDollarParser(
	IParser self )
{
	jagryClearBuffer( &( ( ITextStateParser )self.data->current ).data->buffer ) ;
	free( self.data->current.data ) ;
}

JVoid freeParser(
	IParser self )
{
	IBaseStateParser parser ;
	jReleaseReader( self.data->reader ) ;
	while( self.data->current.data )
		{
			parser = self.data->current.data->previous ;
			self.data->current.data->methods->free( self ) ;
			self.data->current = parser ;
		}
}

JVoid freeStartParser(
	IParser self )
{ }

int parser(
	JIReader in ,
	PIParser out )
{
	printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
	return ( out->data = malloc( sizeof( DParser ) ) ) ?
		( out->data->current.data = malloc( sizeof( DStartStateParser ) ) ) ?
			( out->data->reader = in , out->data->current = startParserInstance.base ,
				out->data->current.data->previous.data = 0 , out->data->methods = &parserMethods , jAcquireReader( in ) , jSuccessResult ) :
			( free( out->data ) , jNotEnoughtMemoryErrorResult ) :
		jNotEnoughtMemoryErrorResult ;
}

JResult parserDispatch(
	IParser self ,
	JByte in ,
	PIBaseToken out )
{
	printf( "DEBUG %s(%i) %X\n" , __PRETTY_FUNCTION__ , __LINE__ , in ) ;
	for( ; ; )
		if( isParserLetter( in ) || in == lowLineParserCharacter )
			{ // !!! ?:
				JBuffer buffer ;
				JResult result ;
				if( jResultIsError( result = jagryInitializeBuffer( &buffer , &in , 1 ) ) )
					return result ;
				out->data = 0 ;
				if( jResultIsNotError( result = createTextParser( self , &buffer , &identificatorParserMethods ) ) )
					return jSuccessResult ;
				jagryClearBuffer( &buffer ) ;
				return result ;
			}
		else
			if( isParserDigit( in ) )
				{
					puts( "start number" ) ;
					exit( 2 ) ;
				}
			else
				if( isParserBlank( in ) )
					return out->data = 0 , jSuccessResult ;					
				else
					switch( in )
						{
						case dollarCharacter :
							out->data = 0 ;
							return createTextParser( self , &jEmptyBuffer , &dollarParserMethods ) ;
						default :
							printf( "unknown char %X" , in ) ;
							exit( 2 ) ;
						}
}

JResult readParserStream(
	JIReader in ,
	JPByte out )
{
	// ??? Надо ли проверять размер
	JSize size = 1 ;
	return jExecuteReader( in , out , &size ) ;
}

JResult tokenStartParser(
	IParser self ,
	IBaseToken in )
{
	printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
}