#include <jagry/idump.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static JByte digits[ 16 ] = { '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' , 'A' , 'B' , 'C' , 'D' , 'E' , 'F' } ;


void jagryDumpByteArray( JPDump dump , JCPCByte bytes , JSize size ) {
jWriteDump( dump , ( ( JByte[ 2 ] ){ '[' , ' ' } ) , 2 ) ;
for( JCounter counter = 0 ; counter < size ; ++counter )
	jWriteDump( dump , &digits[ *bytes >> 4 ] , 1 ) ,
	jWriteDump( dump , &digits[ *bytes & 15 ] , 1 ) ,
	jWriteDump( dump , ( JByte[ 1 ] ){ ' ' } , 1 ) ;
jWriteDump( dump , ( JByte[ 1 ] ){ ']' } , 1 ) ;
}

void jagryDumpDecimalSignedInteger( JCPDump dump , JSignedInteger8 number ) {
JByte text[ 1000 ] ;
JPByte pointer = text ;
if( number == 0 )
	text[ 0 ] = '0' ,
	text[ 1 ] = 0 ;
else
	{
		if( number < 0 )
			*text = '-' ,
			++pointer ,
			number ^= number ;
		*pointer = 0 ;
		for( int size = 1 ; number ; *pointer = '0' + ( JUnsignedInteger8 )number % 10 , number = ( JUnsignedInteger8 )number / 10 , ++size )
			memcpy( pointer + 1 , pointer , size ) ;
	}
jagryDumpString1( dump , pointer ) ;
}

void jagryDumpEscapeString1( JCPDump dump , JPCByte string ) {
for( ; *string != 0 ; ++string )
	if( ' ' <= *string && *string <= '~' && *string != '\\' && *string != '\"' )
		jWriteDump( dump , string , 1 ) ;
	else
		{
			jWriteDump( dump , ( JByte[ 1 ] ){ '\\' } , 1 ) ;
			switch( *string ) {
			case '"': jWriteDump( dump , ( JByte[ 1 ] ){ '\"' } , 1 ) ; break;
			case '\\': jWriteDump( dump , ( JByte[ 1 ] ){ '\\' } , 1 ) ; break;
			case '\n': jWriteDump( dump , ( JByte[ 1 ] ){ '\n' } , 1 ) ; break;
			case '\r': jWriteDump( dump , ( JByte[ 1 ] ){ 'r' } , 1 ) ; break;
			case '\t': jWriteDump( dump , ( JByte[ 1 ] ){ 't' } , 1 ) ; break;
			default:
				jWriteDump( dump , ( JByte[ 1 ] ){ 'x' } , 1 ) ; ;
				jWriteDump( dump , &digits[ *string >> 4 ] , 1 ) ;
				jWriteDump( dump , &digits[ *string & 15 ] , 1 ) ;
			}
		}
}

void jagryDumpString1( JCPDump dump , JPCCharacter1 text ) {
for( ; *text != 0 ; ++text )
	jWriteDump( dump , ( JPByte )text , 1 ) ;
}

/*void jagryDumpString1( int stream , JByte* text ) {
jWriteDump( dump , &( JBuffer ){ .bytes = ( JByte[ 1 ] ){ jDumpStart , 's' , ' t ' , 'r' , 'i' , 'n' , 'g' , '\x'} , .size = 1 } )
jWriteDump( stream , "string(\" " , 9 ) ;
jagryDumpDecimalSignedInteger( stream , strlen( text ) ) ;
jWriteDump( stream , " , \"" , 4 ) ;
jagryDumpString( stream , text ) ;
jWriteDump( stream , "\" )" , 3 ) ;
}*/