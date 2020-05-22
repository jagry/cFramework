//#define jMapMethod jExport
//
//#include "method.h"
//#include <jagry/map.if>
//#include <jagry/dynamic.lb>
//#include "node.h"
//
//#include "key.h"
//
//#include "@.h"
//
//#include "modify.h"
//
//JResult modifyMap( \
//	PIMap self , \
//	JPCMapKeyMethods methodsIn , \
//	JCPCVoid keyIn , \
//	JCPCVoid valueIn , \
//	JPIMapItem out ) {
//PUMapNode node = &self->data.node ;
//if( !node->base )
//	return methodsIn->createFirst( self , keyIn , valueIn , out ) ;
//// !!! Сбита разметка для for
////for( JBuffer key = *keyIn , buffer = node->base->buffer ; ;
////		++key.bytes , --key.size )
////	if( key.size == jNull )
////		if( buffer.size == jNull )
////			switch( node->base->type ) {
////			case valueBufferMapNodeType :
////				return modifierIn->setValue( ) ;
////			default :
////				printf( "NOT IMPLEMENT %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
////				exit( -1 ) ;
////			}
////		else
////			switch( node->base->type ) {
////			case valueBufferMapNodeType : return \
////				modifierIn->insertValue( node , self , &buffer , valueIn , out ) ;
////			default :
////				printf( "NOT IMPLEMENT %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
////				exit( -1 ) ;
////			}
////	else
////		if( buffer.size == jNull )
////			switch( node->base->type ) {
////			case subsBufferMapNodeType :
////				return modifierIn->addSubsItem( node , self , &key , valueIn , out ) ;
////			case valueBufferMapNodeType :
////				return modifierIn->addValueItem( node , self , &key , valueIn , out ) ;
////			default :
////				printf( "NOT IMPLEMENT %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
////				exit( -1 ) ;
////			}
////		else
////			if( *key.bytes != *buffer.bytes )
////				switch( node->base->type ) {
////				case subBufferMapNodeType :
////					/* !!! Можно сократить количество строк путем сокращения
////						node->sub->_.buffer.size - local.size */
////					return modifierIn->splitSub(
////						node ,
////						node->sub->_.buffer.size - buffer.size ,
////						self ,
////						&key ,
////						valueIn ,
////						out ) ;
////				default :
////					printf( "NOT IMPLEMENT %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
////					exit( -1 ) ;
////				}
////			else
////				++buffer.bytes ,
////				--buffer.size ;
//}