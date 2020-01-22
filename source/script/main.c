#include <jagry/map.l.h>
#include <jagry/base.i.h>
#include <jagry/buffer.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "result.h"

#include "token.h"

#include "builder.h"
#include "factory.h"

#include "initialize.h"
#include "parser.h"

int main(int argc, char** argv) {
char* text = " @var ba := 0    " ;
IParser consoleParser ;
JIReader reader ;
JResult result ;
JIMap map ;
UBuilder builder ;
//builder = memalloc( )
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
result = initialize( &map ) ;
builder.unit.data = &dUnitBuilder ;
if( jResultIsError( result = jagryBufferInstanceReader( \
		&( JBuffer ){ .bytes = text , .size = 10 } , &reader ) ) )
	return -1 ;
if( jResultIsNotError( result = parser( map , &consoleParser ) ) )
	{
		JCharacter1 character ;
		{ // reading character
			JSize size = 1 ;
			result = jExecuteReader( reader , &character , &size ) ;
		}
		{
			Factory factory ;
			if( jResultIsNotError( result ) )
				for( ; ; )
					{
						Factory nextFactory ;
						if( jResultIsError( result = jExecuteParser( \
								consoleParser , character , nextFactory ) ) )
							if( jEndErrorReaderResult == result )
								if( factory )
									printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ,
									exit( 101 ) ;
								else
									printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ,
									exit( 102 ) ;
							else
								printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ,
								exit( 103 ) ;
						else
							if( nextCharacterParserResult == result )
								{
									JSize size = 1 ;
									result = jExecuteReader( reader , &character , &size ) ;
									if( jResultIsError( result ) )
										break ;
								}
							else
								{
									UToken token ;
									if( jResultIsNotError( result = factory( map , \
											&consoleParser.data->buffer , &token ) ) )
										{
											printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
											result = ( *builder.base.methods )->push( \
												builder.base , token ) ;
											printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
											freeToken( &token ) ;
											printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
											if( jResultIsError( result ) )
												break ;
											printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
										}
								}
						factory = nextFactory ;
						printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
					}
		}
	}
return 0 ;
}