//// define
//
////#define ByteMapNodeMembers \
////	PCMByteMapNode methods ; \
////	JBuffer key ; \
////	JPBuffer value ; \
////	IByteMapNode owner ; \
////	IByteMapNode next , previous ;
//
//// 0 include
////#include "byteMap.h"
////jStdDeclareImplementation( ByteMapNode )
//// 0 typedef
////typedef struct ByteMapArrayNode ByteMapArrayNode ;
////typedef struct ByteMapEndNode ByteMapEndNode ;
//typedef struct DByteMapNode DByteMapNode ;
//typedef struct MByteMapNode MByteMapNode ;
//typedef union IByteMapNode IByteMapNode ;
//
//// 1 typedef
////typedef ByteMapArrayNode * PByteMapArrayNode ;
////typedef ByteMapEndNode * PByteMapEndNode ;
//typedef DByteMapNode * PDByteMapNode ;
//typedef IByteMapNode * PIByteMapNode ;
//typedef MByteMapNode const CMByteMapNode ;
//
//typedef CMByteMapNode * PCMByteMapNode ;
////typedef ByteMapNodeMethods * PByteMapNodeMethods ;
////typedef PByteMapArrayNode * PPByteMapArrayNode ;
////typedef PByteMapEndNode * PPByteMapEndNode ;
////typedef PByteMapNode * PPByteMapNode ;
//
//// 1 method
//jInternal( JResult )createByteMapEndNode(
//	JPCBuffer /* in key buffer */ ,
//	JPCBuffer /* in value buffer */ ,
//	IByteMapNode /* in owner node */ ,
//	JUnsignedInteger1 /* in index to owner */ ,
//	PIByteMapNode /* out !!! created node */ ) ;
//jInternal( JVoid )freeByteMapNode(
//	IByteMapNode self ) ;
//
//// 1 struct
//union IByteMapNode {
//	PDByteMapNode data ;
//	JIMapItem interface ; } ;
//struct DByteMapNode {
//	PCMByteMapNode methods ;
//	JBuffer key ;
//	JPBuffer value ;
//	IByteMapNode first , last , next , owner , previous ;
//	IByteMapNode subs[ byteSubCount ] ;
//	JSignedInteger2 count ;
//	JUnsignedInteger1 index ; } ;
//struct MByteMapNode { jAllMapItem( IByteMapNode ) } ;
//
//#define iByteMapNodeNil ( ( IByteMapNode ){ .data = 0 } )
