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

#define jMapKeyAll( self ) jMapKeyEach( self , self , self , self , self )
#define jMapKeyEach( acquire , getInterface , release , get , set ) \
	jBaseEach( acquire , getInterface , release ) \
	jMapKeySelf( get , set )
#define jMapKeySelf( getArg , setArg ) \
	JResult( *get )( getArg ) ; \
	JResult( *set )( setArg ) ;

#define jAcquireMapKey( self ) jAcquireBase( ( self ).super )
#define jGetMapKeyInterface( self , in , out ) \
	jGetBaseInterface( ( self ).super , in , out )
#define jReleaseMapKey( self ) jReleaseBase( ( self ).super )

jPrefixStdDeclareInterface( J , MapKey )
jPrefixStdDefineInterface( J , MapKey , jMapKeyAll( JIMapKey ) , JIBase )

jMapMethod( JResult )jagryMapKey( JUnsignedInteger , JOMapKey ) ;
jMapMethod( JResult )jagryGetMapKey( JUnsignedInteger , JOMapKey ) ;
