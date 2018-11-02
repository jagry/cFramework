#ifndef JagryDumpLibrary
#define JagryDumpLibrary

#define jNormalDumpMode 0
#define jIndentDumpMode 1
#define jTransitDumpMode 2

#define jDeclareMainDump( streamArgument , bufferArgument , indentArgument ) { \
	.afterColon = { .bytes = ( JByte[] ){ 'A' , 'C' } , .size = 2 } , \
	.beforeColon = { .bytes = ( JByte[] ){ 'B' , 'C' } , .size = 2 } , \
	.buffer = { .bytes = bufferArgument , .size = 0 } , \
	.indent = { .bytes = indentArgument , .size = sizeof( indentArgument ) } , \
	.level = 0 , \
	.methods = &staticMainMethods , \
	.mode = 0 , \
	.offset = 0 , \
	.size = sizeof( bufferArgument ) >> 1 , \
	.stream = streamArgument }

typedef struct JArrayDump JArrayDump ;
typedef struct JMainDump JMainDump ;
typedef struct JMapDump JMapDump ;

typedef JArrayDump *JPArrayDump ;
typedef JMainDump *JPMainDump ;
typedef JMapDump *JPMapDump ;

#include "idump.h"

struct JArrayDump {
JDumpMethods *methods ;
JBuffer buffer ;
} ;

struct JMainDump {
JDumpMethods *methods ;
JBuffer afterColon , beforeColon , buffer , indent ;
JCounter level ;
JSize offset , size ;
int stream ;
JByte mode ;
} ;

struct JSubDump {
JDumpMethods *methods ;
JBuffer buffer ;
} ;

//void jagryDump( JCPDump , JPCByte ) ;
void jagryDumpByteArray( JCPDump , JCPCByte , JSize ) ;
void jagryDumpDecimalSignedInteger( JCPDump , JSignedInteger8 ) ;
//void jagryDumpString( JCPDump , JPCByte ) ;
void jagryDumpString1( JCPDump , JPCCharacter1 ) ;
void jagryInitializeArrayDump( JPMainDump , JPCBuffer , JPCBuffer ) ;
void jagryInitializeMainDump( JPMainDump , JPCBuffer , JPCBuffer ) ;
void jagryInitializeMapDump( JPMainDump , JPCBuffer , JPCBuffer ) ;

extern JDumpMethods staticMainMethods ;

#endif