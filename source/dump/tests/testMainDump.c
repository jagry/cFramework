#include <stdio.h>
#include <stdlib.h>
#include <jagry/ldump.h>

#define bufferSize 20

int main(int argc, char** argv) {
JByte buffer[ bufferSize ] ;
JByte indent[ 2 ] = { ' ' , ' ' } ;
JCPCCharacter1 text = "0123:4567:89AB:DEFGH" ;
JMainDump dump = jDeclareMainDump( 2 , buffer , indent ) ;
jagryInitializeMainDump( &dump , 0 , 0 ) ;
jWriteDump( ( JPDump )&dump , text , 20 ) ;
jWriteDump( ( JPDump )&dump , "\n" , 1 ) ;
jFlushDumpAll( ( JPDump )&dump ) ;
return ( EXIT_SUCCESS  );
}
