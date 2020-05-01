#include <jagry/buffer.i.h>
#include <jagry/result.h>

//typedef JResult( *Factory )( JIBufferMap , JPBuffer , PUToken ) ;
typedef struct FactoryDescription FactoryDescription ;
typedef struct KeywordFactoryArgument KeywordFactoryArgument ;
typedef union UFactoryArgument UFactoryArgument ;

//typedef Factory * PFactory ;
typedef FactoryDescription * PFactoryDescription ;

typedef JResult( *KeywordFactory )( UFactoryArgument , PUToken ) ;

struct KeywordFactoryArgument {
	JByte type ;
	JByte identifier ; } ;

union UFactoryArgument {
	KeywordFactoryArgument keyword ; } ;

struct FactoryDescription {
	KeywordFactory method ;
	UFactoryArgument argument ; } ;

jInternal( JResult )standardFactory( UFactoryArgument in , PUToken arg ) ;
