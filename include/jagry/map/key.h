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

#define jMapKeyAll( self ) \
	jMapKeyEach( self , self , self , self , self , self , self )
#define jMapKeyEach( \
		acquire , getInterface , release , add , new , put , set ) \
	jBaseEach( acquire , getInterface , release ) \
	jMapKeySelf( add , new , put , set )
#define jMapKeySelf( addArg , newArg , putArg , setArg ) \
	JResult( *add )( addArg , JPMapData , JCPCVoid , JCPCVoid , JPIMapItem ) ; \
	JResult( *new )( newArg , JPMapData , JCPCVoid , JCPCVoid , JPIMapItem ) ; \
	JResult( *put )( putArg , JPMapData , JCPCVoid , JCPCVoid , JPIMapItem ) ; \
	JResult( *set )( setArg , JPMapData , JCPCVoid , JCPCVoid , JPIMapItem ) ;

#define jAcquireMapKey( self ) jAcquireBase( ( self ).super )
#define jGetMapKeyInterface( self , in , out ) \
	jGetBaseInterface( ( self ).super , in , out )
#define jReleaseMapKey( self ) jReleaseBase( ( self ).super )

jDeclarePrefixStandardInterface( J , MapKey )
jPrefixStdDefineInterface( J , MapKey , jMapKeyAll( JCIMapKey ) , JIBase )

jMapMethod( JResult )jagryMapKey( JUnsignedInteger , JOMapKey ) ;
jMapMethod( JResult )jagryGetMapKey( JUnsignedInteger , JOMapKey ) ;
