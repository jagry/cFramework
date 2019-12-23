#ifndef JagryReaderInterface
#define JagryReaderInterface

#define jAcquireReader( argument ) jAcquireBase( argument.super )
#define jGetReaderInterface( self , identifier , out ) jGetBaseInterface( self.super , identifier , out ) 
#define jReleaseReader( argument ) jReleaseBase( argument.super )

#define jExecuteReader( self , bytes , size ) ( self.data->methods->execute( self , bytes , size ) )

#define jEndReaderErrorResult ( -20 )

#define jExecuteReaderPointer( type ) JResult( *execute )( type , JPByte , JPSize ) ;

#define jReaderSelf( execute ) \
	jExecuteReaderPointer( execute )
#define jReaderEach( acquire , getInterface , release , execute ) \
	jBaseEach( acquire , getInterface , release ) \
	jReaderSelf( execute )

#define jReaderAll( type ) jReaderEach( type , type , type , type )

#include "base.i.h"

jPrefixStdDeclareInterface( J , Reader )

#include "buffer.h"

jPrefixStdDefineInterface( J , Reader , jReaderAll( JIReader ) , JIBase )

#endif