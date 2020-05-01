#include <jagry/result.h>
#include <stdio.h>

void showResult( JResult in ) {
if( in )
	printf( jResultIsError( in ) ? "error %X\n" : "warning %X\n" , in ) ;
else
	printf( "done\n" ) ;
}