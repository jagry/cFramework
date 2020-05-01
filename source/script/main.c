/* !!! */ #include <stdio.h>

#include <jagry/array.l.h>
#include <jagry/buffer.l.h>
#include <jagry/map.l.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "reader.h"
#include "result.h"

#include "token.h"

#include "analyzer.h"
#include "factory.h"

#include "initialize.h"

JCharacter1 text[] = " @var a1 , a2 , \\\r\n\ta3   " ;

JSignedInteger main( JSignedInteger countIn , JPPCharacter1 argumentsIn ) {
//JIBufferMap map ;
CMUnitAnalyzer methods = { ._ = { .free = 0 , .push = pushUnitAnalyzer } } ;
CPCMBaseAnalyzer pointer = &methods.base ;
IBaseAnalyzer analizer = &pointer ;
IReader reader = { ._ = &( Reader ){
	._ = &mReader ,
	.buffer = jEmptyBuffer ,
	.offset = jNull } } ;
TokenData data = {
	.endLine = undefineEndLine ,
	.reader = reader.interface ,
	.status = readTokenStatus } ;
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
JResult result = initialize( &data.map ) ;
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
if( jResultIsError( result ) ) return 10 ;
if( write( STDOUT_FILENO , "jl> " , 4 ) != 4 )
	return jReleaseMap( data.map ) , 11 ;
if( jResultIsError( result = loadingReader( reader._ ) ) )
	return jReleaseMap( data.map ) , 12 ;
result = 0 ;
for( ; ; )
	{
		JResult tokenResult  = getToken( &data ) ; 
		if( jResultIsError( tokenResult ) )
			switch( tokenResult ) {
			case jEndErrorReaderResult :
				if( result )
					{
						write( STDOUT_FILENO , "jl-> " , 5 ) ;
						loadingReader( reader._ ) ;
						continue ;
					}
				else
					return 
						printf(
							"DEBUG %s(%i) Ok\n" ,
							__PRETTY_FUNCTION__ , __LINE__ ) ,
						0 ;
			case jNotEnoughtMemoryErrorResult :
				printf(
					"DEBUG %s(%i) Not enougth memory\n" ,
					__PRETTY_FUNCTION__ , __LINE__ ) ;
				return 21 ;
			case missingKeywordErrorResult :
				printf(
					"DEBUG %s(%i) Missing Keyword\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
				return 22 ;
			case unexpectedCharacterErrorResult :
				printf(
					"DEBUG %s(%i) Unexpected character(hex code: %02X)\n" ,
					__PRETTY_FUNCTION__ , __LINE__ , data.character ) ;
				return 23 ;
			default :
				printf(
					"DEBUG %s(%i) Unknown error(code: %x)\n" ,
					__PRETTY_FUNCTION__ , __LINE__ , tokenResult ) ;
				return 24 ;
			}
		if( data.token.base.type == endTokenType )
			{
				switch( data.token.identifier.value ) {
				case escapeLineEndToken :
					printf(
						"DEBUG %s(%i) escapeLineEndToken\n" ,
						__PRETTY_FUNCTION__ , __LINE__ ) ;
					write( STDOUT_FILENO , "jl-> " , 5 ) ;
					loadingReader( reader._ ) ;
					break ;
				}
				continue ;
			}
		result = ( *analizer )->push( &analizer , &data.token ) ;
		freeToken( &data.token ) ;
		if( jResultIsError( result ) )
			switch( result ) {
			case jNotEnoughtMemoryErrorResult :
				printf(
					"DEBUG %s(%i) Not enougth memory\n" ,
					__PRETTY_FUNCTION__ , __LINE__ ) ;
				return 30 ;
			case unexpectedEndErrorResult :
				printf(
					"DEBUG %s(%i) Unexpected end\n" ,
					__PRETTY_FUNCTION__ , __LINE__ ) ;
				return 31 ;
			case unexpectedKeywordErrorResult :
				printf(
					"DEBUG %s(%i) Unexpected keyword\n" ,
					__PRETTY_FUNCTION__ , __LINE__ ) ;
				return 32 ;
			case unexpectedOperatorErrorResult :
				printf(
					"DEBUG %s(%i) Unexpected operator\n" ,
					__PRETTY_FUNCTION__ , __LINE__ ) ;
				return 33 ;
			case unexpectedIdentifierErrorResult :
				printf(
					"DEBUG %s(%i) Unexpected identifier\n" ,
					__PRETTY_FUNCTION__ , __LINE__ ) ;
				return 34 ;
			default :
				printf(
					"DEBUG %s(%i) Unknown error(code: %x)\n" ,
					__PRETTY_FUNCTION__ , __LINE__ , result ) ;
				return 35 ;
			}
		printf(
			"DEBUG %s(%i) Analyzer status %x\n" ,
			__PRETTY_FUNCTION__ , __LINE__ , result ) ;
	}
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
return 0 ;
}
