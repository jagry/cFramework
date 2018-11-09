typedef struct ByteMapNode ByteMapNode ;
typedef ByteMapNode * PByteMapNode ;
typedef PByteMapNode * PPByteMapNode ;

struct ByteMapNode {
	JBuffer key ;
	JPBuffer value ;
	PByteMapNode owner ;
	PByteMapNode subs[ jMaxUnsignedInteger1 + 1 ] ;
	JSignedInteger2 count ; } ;

JResult createByteMapNode( JCPCByte , JSize , JPCBuffer , PByteMapNode , PPByteMapNode ) ;
JResult createEmptyByteMapNode( JCPCByte , JSize , PPByteMapNode ) ;
JVoid freeByteMapNode( PByteMapNode self ) ;