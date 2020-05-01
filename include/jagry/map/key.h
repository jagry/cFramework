#define jMapKey( argument ) ( ( JMapKey ){ \
	.free = jagryMapKeyFree , \
	.get = jagryMapKeyCopy , \
	.set = jagryMapKeyCopy , \
	.size = argument } )
#define jMapKeyPointer( ) ( ( JMapKey ){ \
	.free = jagryMapKeyFree , \
	.get = jagryMapKeyCopy , \
	.set = jagryMapKeyPointer , \
	.size = sizeof( JPVoid ) } )

#define jMapKeyAll( self ) jMapKeyEach( self , self , self , self )
#define jMapKeyEach( acquire , getInterface , release , first ) \
	jBaseEach( acquire , getInterface , release ) \
	jMapKeySelf( )
#define jMapKeySelf( ) \
	JPCMapKeyMethods( *add )( ) ; \
	JPCMapKeyMethods( *new )( ) ; \
	JPCMapKeyMethods( *put )( ) ; \
	JPCMapKeyMethods( *set )( ) ;

#define jAcquireMapKey( self ) jAcquireBase( ( self ).super )
#define jGetMapKeyInterface( self , in , out ) \
	jGetBaseInterface( ( self ).super , in , out )
#define jReleaseMapKey( self ) jReleaseBase( ( self ).super )

typedef struct JMapKeyMethods JMapKeyMethods ;
typedef JResult( *JCreateMapKeyFirst )( ) ;

typedef JMapKeyMethods const JCMapKeyMethods ;

typedef JCMapKeyMethods * JPCMapKeyMethods ;

jPrefixStdDeclareInterface( J , MapKey )
jPrefixStdDefineInterface( J , MapKey , jMapKeyAll( JIMapKey ) , JIBase )

struct JMapKeyMethods {
	JCreateMapKeyFirst createFirst ; } ;

jMapMethod( JResult )jagryMapKey( JUnsignedInteger , JOMapKey ) ;
jMapMethod( JResult )jagryGetMapKey( JUnsignedInteger , JOMapKey ) ;
