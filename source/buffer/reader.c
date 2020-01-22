#include <jagry/reader.i.h>
#include <jagry/super.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct BufferReaderD BufferReaderD ;
typedef struct BufferReaderM BufferReaderM ;
typedef union BufferReaderI BufferReaderI ;

typedef BufferReaderD * BufferReaderPD ;
typedef BufferReaderM const BufferReaderCM ;
typedef BufferReaderI * BufferReaderPI ;

typedef BufferReaderCM * BufferReaderPCM ;

struct BufferReaderD
{
	jSuperMembers( BufferReaderPCM , methods )
	JBuffer buffer ;
	int offset ;
} ;

struct BufferReaderM {
	jReaderEach( JISuper , BufferReaderI , BufferReaderI , BufferReaderI ) } ;

union BufferReaderI { BufferReaderPD data ; } ;

static JResult executeBufferReader( // Чтение байт из объекта
	BufferReaderI , // in: объект буффера
	JPByte buffer , // in: указатель на приемник
	JPSize size ) ; // in: размер буфера в байтах; out - количество считаных байт  
static int releaseBufferCopyReader( // освобождение копирующего объекта
	BufferReaderI ) ; // in: объект буффера
static int releaseBufferInstanceReader( // освобождение не копирующего объекта
	BufferReaderI ) ; // in: объект буффера

static BufferReaderCM
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

JResult executeBufferReader( BufferReaderI self ,
	JPByte buffer , JPSize size ) {
int available = self.data->buffer.size - self.data->offset ;
if( !available )
	return jEndErrorReaderResult ;
if( available < *size )
	*size = available ;
memcpy( buffer , self.data->buffer.bytes + self.data->offset , *size ) ;
self.data->offset += *size ;
return 0 ;
}

int jagryBufferCopyReader( JPBuffer in , JPIReader out ) {
if( !( out->data = malloc( sizeof( BufferReaderD ) ) ) )
	return jNotEnoughtMemoryErrorResult ;
jInitializeSuper( *( BufferReaderPI )out , copyMethods , 0 , 1 )
( ( BufferReaderPI )out )->data->buffer = *in ;
( ( BufferReaderPI )out )->data->offset = 0 ;
return jSuccessResult ;
}

int jagryBufferInstanceReader( JPBuffer in , JPIReader out ) {
if( !( out->data = malloc( sizeof( BufferReaderD ) ) ) )
	return jNotEnoughtMemoryErrorResult ;
jInitializeSuper( *( BufferReaderPI )out , instanceMethods , 0 , 1 )
( ( BufferReaderPI )out )->data->buffer = *in ;
( ( BufferReaderPI )out )->data->offset = 0 ;
return jSuccessResult ;
}

int releaseBufferCopyReader( BufferReaderI self ) {
int result = __sync_sub_and_fetch( &self.data->references , 1 ) ;
if( !result ) jagryFreeBuffer( &self.data->buffer ) , free( self.data ) ;
return result ;
}

int releaseBufferInstanceReader( BufferReaderI self ) {
int result = __sync_sub_and_fetch( &self.data->references , 1 ) ;
if( !result ) free( self.data ) ;
return result ;
}