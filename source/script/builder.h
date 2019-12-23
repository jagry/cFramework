//#define jExecuteBuilder( self , out ) ( self.data->methods->execute( self , &out ) )
//#define jFreeBuilder( self ) ( self.data->methods->free( self ) )
//#define jExecuteStateBuilder( self , builder , out ) ( self.data->methods->execute( builder , out ) )
//
//#define continueResult 1
//
//#define defineImplementation( name , members ) \
//	struct name##D { name##PCM methods ; members } ; \
//	union name##I { JBaseStateBuilderI base ; name##PD data ; } ; \
//	struct name##M { JResult( *execute )( JBuilderI , JBaseTokenPI ) ; JVoid( *free )( JBuilderI ) ; } ;
//
//jStdDeclareInterface( JBuilder )
//jStdDeclareInterface( JBaseStateBuilder )
//jStdDeclareInterface( JKeywordStateBuilder )
//jStdDeclareInterface( JStartStateBuilder )
//
////#include <jagry/reader.i.h>
//#include "token.h"
//
//
//int builder( JReaderI , JBuilderPI ) ;