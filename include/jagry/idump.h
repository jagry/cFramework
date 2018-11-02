#ifndef JagryDumpInterface
#define JagryDumpInterface

/*typedef struct JDump JDump ;
typedef struct JDumpMethods JDumpMethods ;

typedef JDump const JCDump ;
typedef JDump * JPDump ;

typedef JPDump const JCPDump ;
typedef JCDump * JPCDump ;

typedef JPCDump const JCPCDump ;*/

#define jFlushDumpPointer( type ) JBoolean( *flush )( type* ) ;
#define jFlushDumpAllPointer( type ) void( *flushAll )( type* ) ;
#define jGetDumpSizePointer( type ) JSize( *getSize )( type* ) ;
#define jWriteDumpPointer( type ) void( *write )( type* , JPCByte , JSize ) ;

#define jDumpSelf( flush , flushAll , getSize , write ) \
	jFlushDumpPointer( flush )\
	jFlushDumpAllPointer( flushAll ) \
	jGetDumpSizePointer( getSize ) \
	jWriteDumpPointer( write )

typedef union JDump JDump ;
typedef union JDumpMethods JDumpMethods ;

typedef JDump *JIDump ;

#include "ibase.h"
#include "buffer.h"

#define jDumpEach( acquire , dump , getInterface , release , flush , flushAll , getSize , write ) \
	jBaseEach( acquire , dump , getInterface , release ) \
	jDumpSelf( flush , flushAll , getSize , write )
#define jDumpAll( type ) jDumpEach( type , type , type , type , type , type , type , type )

jInterface( JDump , JBase , jBaseSupers , methods , jDumpAll( JDump ) , JDumpMethods , JBaseMethods , jBaseMethodsSupers )

/*struct JDump {
JDumpMethods *methods ;
} ;

struct JDumpMethods {
JBoolean( *flush )( JPDump ) ;
void( *flushAll )( JPDump ) ;
JSize( *getSize )( JPCDump ) ;
void( *write )( JPDump , JPCByte , JSize ) ;
} ;*/

#define jFlushDump( self ) ( ( self )->methods->flush( self ) )
#define jFlushDumpAll( self ) ( ( self )->methods->flushAll( self ) )
#define jGetDumpSize( self ) ( ( self )->methods->getSize( self ) )
#define jWriteDump( self , bytes , size ) ( ( self )->methods->write( self , bytes , size ) )

#endif