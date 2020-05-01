#include <jagry/buffer.l.h>
#include <unistd.h>
#include "character.h"
#include "reader.h"

static JResult executeReader( IReader , JPByte , JPSize ) ;

// !!! Нужен константный тип
MReader mReader = { .execute = executeReader } ;
IReader iReader = { ._ = &( Reader ){
	._ = &( MReader ){ .execute = executeReader } } } ;

JResult executeReader( IReader self , JPByte in , JPSize arg ) {
if( self._->buffer.size == self._->offset )
	return jEndErrorReaderResult ;
if( self._->buffer.size - self._->offset < *arg )
	*arg = self._->buffer.size - self._->offset ;
memcpy( in , self._->buffer.bytes + self._->offset , *arg ) ;
self._->offset += *arg ;
return jSuccessResult ;
}

JResult loadingReader( PReader arg ) {
//JSize size = arg->buffer.size - arg->offset ;
//JPByte bytes = arg->buffer.bytes + arg->offset ;
//memcpy( arg->buffer.bytes , arg->buffer.bytes + arg->offset , size ) ;
//size = read(
//	STDIN_FILENO , arg->buffer.bytes + size , arg->buffer.size - size ) ;
//if( arg->size == size )
//	size
//arg->size = size ;
JResult result ;
JCharacter1 character ;
arg->offset = 0 ;
jagryClearBuffer( &arg->buffer ) ;
do
	{
		read( STDIN_FILENO , &character , 1 ) ;
		if( jResultIsError( result = jagryAddBufferByte(
				&arg->buffer , character ) ) )
			return result ;
	} while( character != lineFeedCharacter ) ;
return jSuccessResult ;
}