#ifndef JagryStreamInterface
#define JagryStreamInterface

#include "base.i.h"

#include "buffer.h"

#define jCloseStreamPointer( type ) JBoolean( *close )( type ) ;
#define jReadStreamPointer( type ) JResult( *read )( type ) ;
#define jWriteStreamPointer( type ) JResult( *write )( type ) ;

#define jStreamSelf( close, read, write ) \
	jCloseStreamPointer( close ) \
	jReadStreamPointer( read ) \
	jWriteStreamPointer( write )
#define jStreamEach( acquire , getInterface , release , close, read, write ) \
	jBaseEach( acquire , getInterface , release ) \
	jStreamSelf( close, read, write )
#define jStreamAll( type ) jStreamEach( type , type , type , type , type , type )

jStdDeclareInterface( JStream )
jStdDeclareInterface( JInputStream )
jStdDeclareInterface( JOutputStream )

jStdDefineInterface( JStream , jStreamAll( JStreamI ) , JBaseI )

//int jagryBufferInputStream( const JBuffer const* , JInputStream** ) ;

#endif