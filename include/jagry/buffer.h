#ifndef JagryBuffer
#define JagryBuffer

#define jEmptyBuffer jBuffer( 0 , 0 )
#define jBuffer( bytesIn , sizeIn ) ( ( JBuffer ){ .bytes = bytesIn , .size = sizeIn } )
#define jStringBuffer( in ) ( ( JCBuffer ){ .bytes = in , .size = strlen( in ) } )
#define jMethodBuffer( in ) ( ( JCBuffer ){ .bytes = ( JPByte )&in , .size = sizeof( &in ) } )

#include <jagry/result.h>
#include <string.h>
#include "reader.i.h"

jPrefixType( J , Buffer , struct JBuffer )

struct JBuffer {
	JPByte bytes ;
	JSize size ; } ;

jExport( JResult )jagryAddBufferByte(
	JPBuffer ,
	JByte ) ;
jExport( JResult )jagryBufferCopyReader(
	JPBuffer ,
	JPIReader ) ;
jExport( JResult )jagryBufferInstanceReader(
	JPBuffer ,
	JPIReader ) ;
jExport( JVoid )jagryClearBuffer(
	JPBuffer ) ;
jExport( JResult )jagryConcateBuffer(
	JCPCBuffer ,
	JCPCBuffer ,
	JPBuffer ) ;
jExport( JResult )jagryCreatePBuffer(
	JCPCBuffer ,
	JPPBuffer ) ;
jExport( JResult )jagryCreateBuffer(
	JPCByte ,
	JSize ,
	JPPBuffer ) ;
jExport( JVoid )jagryFreeBuffer(
	JPBuffer ) ;
jExport( JResult )jagryInitializeBuffer(
	JPBuffer ,
	JCPCVoid ,
	JSize ) ;
jExport( JResult )jagrySetBuffer(
	JPBuffer ,
	JPVoid ,
	JSize ) ;

#endif
