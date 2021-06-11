#include <stdio.h>
#include <jagry/array.l.h>

void showError( JCPCCharacter1 textIn , JResult resultIn ) {
printf( "Error : " jString1Specifier " - " jResultHeximalSpecifier , textIn , resultIn ) ;
}

int main() {
JIArray array ;
JResult result = jagryListArray( jagryArrayPointerManager() , &array ) ;
if( jResultIsError( result ) )
	return showError( "create array" , result ) , -1 ;
jPushArrayForward( array , ( JPVoid )0 , 0 ) ;
jPushArrayForward( array , ( JPVoid )1 , 0 ) ;
jPushArrayForward( array , ( JPVoid )2 , 0 ) ;
jReleaseArray( array ) ;
return 0 ;
}