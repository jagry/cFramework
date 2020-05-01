/* !!! */ #include <stdio.h>

#define jBufferMethod jExport

#include <jagry/reader.i.h>
#include <jagry/super.h>
#include <memory.h>
#include <stdlib.h>

typedef struct MBufferReader const CMBufferReader ;
typedef struct IBufferReader IBufferReader ;

typedef CMBufferReader * PCMBufferReader ;
typedef IBufferReader * PIBufferReader ;

typedef PIBufferReader * JPIBufferReader ;

#include <jagry/buffer/free.h>
#include <jagry/buffer/reader.h>

struct IBufferReader {
	jSuperMembers( PCMBufferReader , _ )
	JBuffer buffer ;
	int offset ; } ;
struct MBufferReader {
	jReaderEach( JISuper , PIBufferReader , PIBufferReader , PIBufferReader ) } ;

//union BufferReaderI { BufferReaderPD _ ; } ;

static JResult executeBufferReader( // Чтение байт из объекта
	PIBufferReader , // in: объект буффера
	JPByte buffer , // in: указатель на приемник
	JPSize size ) ; // in: размер буфера в байтах; out - количество считаных байт  
static int releaseBufferCopyReader( // освобождение копирующего объекта
	PIBufferReader ) ; // in: объект буффера
static int releaseBufferInstanceReader( // освобождение не копирующего объекта
	PIBufferReader ) ; // in: объект буффера

static CMBufferReader
	copyMethods = {
		/* base */
			.acquire = jagryAcquireSuper ,
			.release = releaseBufferCopyReader ,
		/*reader */ .execute = executeBufferReader } ,
	instanceMethods = {
		/* base */
			.acquire = jagryAcquireSuper ,
			.release = releaseBufferInstanceReader ,
		/*reader */ .execute = executeBufferReader } ;

JResult executeBufferReader( PIBufferReader self ,
	JPByte buffer , JPSize size ) {
int available = self->buffer.size - self->offset ;
if( !available )
	return jEndErrorReaderResult ;
if( available < *size )
	*size = available ;
memcpy( buffer , self->buffer.bytes + self->offset , *size ) ;
self->offset += *size ;
return 0 ;
}

int jagryBufferCopyReader( JPBuffer in , JPIBufferReader out ) {
if( !( *out = malloc( sizeof( IBufferReader ) ) ) )
	return jNotEnoughtMemoryErrorResult ;
jInitializeSuper( *out , copyMethods , 0 , 1 )
( *out )->buffer = *in ;
( *out )->offset = 0 ;
return jSuccessResult ;
}

int jagryBufferInstanceReader( JPBuffer in , JPIBufferReader out ) {
if( !( *out = malloc( sizeof( IBufferReader ) ) ) )
	return jNotEnoughtMemoryErrorResult ;
jInitializeSuper( *out , instanceMethods , 0 , 1 )
( *out )->buffer = *in ;
( *out )->offset = 0 ;
return jSuccessResult ;
}

int releaseBufferCopyReader( PIBufferReader self ) {
int result = __sync_sub_and_fetch( &self->references , 1 ) ;
if( !result )
	jagryFreeBuffer( &self->buffer ) , free( self ) ;
return result ;
}

int releaseBufferInstanceReader( PIBufferReader self ) {
int result = __sync_sub_and_fetch( &self->references , 1 ) ;
if( !result )
	free( self ) ;
return result ;
}