#define capitalAParserCharacter 'A'
#define capitalFParserCharacter 'F'
#define capitalZParserCharacter 'Z'
#define carriageReturnParserCharacter '\r'
#define commercialAtParserCharacter '@'
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

#define keywordParserCharacter commercialAtParserCharacter

#define isParserBlank( character ) \
	( character == carriageReturnParserCharacter \
	|| character == lineFeedParserCharacter \
	|| character == spaceParserCharacter \
	|| character == tabParserCharacter )
#define isParserCapital( character ) \
	( character >= capitalAParserCharacter \
	&& character <= capitalZParserCharacter )
#define isParserDigit( character ) \
	( character >= digit0ParserCharacter && character <= digit9ParserCharacter )
#define isParserFirst6Capital( character ) \
	( character >= capitalAParserCharacter \
	&& character <= capitalFParserCharacter )
#define isParserFirst6Letter( character ) \
	( isParserFirst6Capital( character ) || isParserFirst6Small( character ) )
#define isParserFirst6Small( character ) \
	( character >= smallAParserCharacter && character <= smallFParserCharacter )
#define isParserLast20Capital( character ) \
	( character > capitalFParserCharacter \
	&& character <= capitalZParserCharacter )
#define isParserLast20Letter( character ) \
	( isParserFirst6Capital( character ) || isParserFirst6Small( character ) )
#define isParserLast20Small( character ) \
	( character > smallFParserCharacter && character <= smallZParserCharacter )
#define isParserLetter( character ) \
	( isParserCapital( character ) || isParserSmall( character ) )
#define isParserSmall( character ) \
	( character >= smallAParserCharacter && character <= smallZParserCharacter )

#include <jagry/map.i.h>
#include <jagry/reader.i.h>
#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include "result.h"

#include "builder.h"
#include "factory.h"

#include "parser.h"

static JResult executeIdentifierParser(
	IParser ,
	JCharacter1 ,
	PFactory ) ;
static JResult executeKeywordParser(
	IParser ,
	JCharacter1 ,
	PFactory ) ;
static JResult executeNumberParser(
	IParser ,
	JCharacter1 ,
	PFactory ) ;
static JResult executeStartParser(
	IParser ,
	JCharacter1 ,
	PFactory ) ;
static JVoid freeParser(
	IParser ) ;
static JResult readParserStream(
	JIReader ,
	JPByte ) ;

static CMParser
	identifierParser = {
		.execute = executeIdentifierParser ,
		.free = freeParser } ,
	keywordParser = { .execute = executeKeywordParser , .free = freeParser } ,
	startParser = { .execute = executeStartParser , .free = freeParser } ;

JResult executeIdentifierParser(
	IParser self , JCharacter1 in , PFactory out ) {
JResult result ;
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
if( isParserLetter( in ) || isParserDigit( in )
		|| in == lowLineParserCharacter )
	return
		jResultIsError( result = jagryAddBufferByte( &self.data->buffer , in ) ) ?
			result :
			( *out = identifierFactory , nextCharacterParserResult ) ;
*out = 0 ;
self.data->methods = &startParser ;
return currentCharacterParserResult ;
}

JResult executeKeywordParser( IParser self , JCharacter1 in , PFactory out ) {
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
JResult result ;
JBuffer buffer = jEmptyBuffer ;
//if( isParserLetter( in ) )
//	return
//		jResultIsError( result = jagryAddBufferByte( &self.data->buffer , in ) ) ?
//			result :
//			( *out = keywordFactory , nextCharacterParserResult ) ;
//if( !self.data->buffer.size )
//	return unexpectedCharacterErrorResult ;
//*out = 0 ;
//self.data->methods = &startParser ;
//return currentCharacterParserResult ;
return isParserLetter( in ) ?
	jResultIsError( result = jagryAddBufferByte( &self.data->buffer , in ) ) ?
		result :
		( *out = keywordFactory , nextCharacterParserResult ) :
	self.data->buffer.size ?
		( *out = 0 , self.data->methods = &startParser ,
			currentCharacterParserResult ) :
		unexpectedCharacterErrorResult ;
}

JResult executeNumberParser( IParser self , JCharacter1 in , PFactory out ) {
}

JResult executeStartParser( IParser self , JCharacter1 in , PFactory out ) {
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
if( isParserLetter( in ) || in == lowLineParserCharacter )
	{ // !!! ?:
		JResult result = jagrySetBuffer( &self.data->buffer , &in , 1 ) ;
		if( jResultIsError( result ) )
			return result ;
		*out = identifierFactory ;
		self.data->methods = &identifierParser ;
		return nextCharacterParserResult ;
	}
if( isParserBlank( in ) )
	return
		*out = 0 ,
		nextCharacterParserResult ;					
if( isParserDigit( in ) )
	{
		printf( "DEBUG %s(%i) %X\n" , __PRETTY_FUNCTION__ , __LINE__ , in ) ;
		puts( "start number" ) ;
		exit( 2 ) ;
	}
else
	switch( in )
		{
		case keywordParserCharacter :
			*out = 0 ;
			self.data->methods = &keywordParser ;
			return nextCharacterParserResult ;
		default :
			printf( "unknown char %X" , in ) ;
			exit( 2 ) ;
		}
}

JVoid freeParser( IParser self ) {
jagryClearBuffer( &self.data->buffer ) ;
free( self.data ) ;
}

int parser( JIMap in , PIParser out ) {
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
if( !( out->data = malloc( sizeof( DParser ) ) ) )
	return jNotEnoughtMemoryErrorResult ;
out->data->buffer = jEmptyBuffer ;
out->data->map = in ;
out->data->methods = &startParser ;
return jSuccessResult ;
}