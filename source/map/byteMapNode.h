// define
#define subCount ( jMaxUnsignedInteger1 + 1 )
#define ByteMapNodeMembers \
	PByteMapNodeMethods methods ; \
	JBuffer key ; \
	JPBuffer value ; \
	PByteMapNode owner ; \
	PByteMapNode next , previous ;

// 0 include
//#include "byteMap.h"

// 0 typedef
typedef struct ByteMapArrayNode ByteMapArrayNode ;
typedef struct ByteMapEndNode ByteMapEndNode ;
typedef struct ByteMapNode ByteMapNode ;
typedef struct ByteMapNodeMethods ByteMapNodeMethods ;

// 1 typedef
typedef ByteMapArrayNode * PByteMapArrayNode ;
typedef ByteMapEndNode * PByteMapEndNode ;
typedef ByteMapNode * PByteMapNode ;
typedef ByteMapNodeMethods * PByteMapNodeMethods ;
typedef PByteMapArrayNode * PPByteMapArrayNode ;
//typedef PByteMapEndNode * PPByteMapEndNode ;
typedef PByteMapNode * PPByteMapNode ;

// 1 method
jHidden( JResult )createByteMapNode(
	JPCBuffer /* in key buffer */ ,
	JPCBuffer /* in value buffer */ ,
	PByteMapNode /* in owner node */ ,
	JUnsignedInteger1 /* in index to owner */ ,
	PPByteMapNode /* out !!! created node */ ) ;
jHidden( JResult )createByteMapEndNode(
	JPCBuffer /* in key buffer */ ,
	JPCBuffer /* in value buffer */ ,
	PByteMapNode /* in owner node */ ,
	JUnsignedInteger1 /* in index to owner */ ,
	PPByteMapNode /* out !!! created node */ ) ;
jHidden( JVoid )freeByteMapNode(
	PByteMapNode self ) ;

// 1 struct
struct ByteMapArrayNode {
	ByteMapNodeMembers
	PByteMapNode first , last ;
	PByteMapNode subs[ subCount ] ;
	JSignedInteger2 count ;
	JUnsignedInteger1 index ; } ;
struct ByteMapEndNode {
	ByteMapNodeMembers } ;
struct ByteMapNode {
	PByteMapNodeMethods methods ;
	JBuffer key ;
	JPBuffer value ;
	PByteMapNode first , last , next , owner , previous ;
	PByteMapNode subs[ subCount ] ;
	JSignedInteger2 count ;
	JUnsignedInteger1 index ; } ;