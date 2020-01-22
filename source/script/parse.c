///* !!! */ #include <stdio.h>
//
//#include <jagry/map.i.h>
//#include <jagry/reader.i.h>
//#include <stdlib.h>
//#include "result.h"
//
//#include "token.h"
//
//#include "builder.h"
//
//#include "parse.h"
//#include "parser.h"
//
//#include "factory.h"
//
//JResult parseUnit( JIMap mapIn , JIReader readerIn , PIParser out ) {
//printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
//JSize size = 1 ;
//ParseData data = { .map = mapIn , .reader = readerIn } ;
//JResult result = jExecuteReader( readerIn , &data.character , &size ) ;
//if( jResultIsError( result ) )
//	return result == jEndErrorReaderResult ?
//		emptyInputErrorResult : result ;
//
//return jSuccessResult ;
//}