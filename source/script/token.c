#include <jagry/buffer.h>
#include "token.h"

JVoid freeToken( PUToken out ) {
switch( out->base.type ) {
case identifierTokenType :
	jagryClearBuffer( &out->identifier.name ) ;
	return ;
}
}