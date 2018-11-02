typedef struct ByteMapNode ByteMapNode ;
typedef ByteMapNode * PByteMapNode ;
typedef PByteMapNode * PPByteMapNode ;

struct ByteMapNode {
	ByteMapNode* owner ;
	JCounter count ;
	JBuffer key ;
	JPBuffer value ;
	PByteMapNode subs[ jMaxUnsignedInteger1 + 1 ] ; } ;

JResult createByteMapNode( JCPCByte , JSize , JPCBuffer , PByteMapNode , PPByteMapNode ) ;
JResult createEmptyByteMapNode( JCPCByte , JSize , PPByteMapNode ) ;
JVoid freeByteMapNode( PByteMapNode self ) ;