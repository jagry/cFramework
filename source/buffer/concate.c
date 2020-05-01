#define jBufferMethod jExport

#include <jagry/buffer.i.h>
#include <jagry/result.h>
#include <memory.h>
#include <stdlib.h>

#include <jagry/buffer/clear.h>
#include <jagry/buffer/concate.h>

JResult jagryConcateBuffer( JCPCBuffer in1 , JCPCBuffer in2 , JPBuffer out ) {
JBuffer local ;
jagryClearBuffer( out ) ;
if( ( local.bytes = malloc( local.size = in1->size + in2->size ) ) == 0 )
	return jNotEnoughtMemoryErrorResult ;
*out = local ;
memcpy( local.bytes , in1->bytes , in1->size ) ;
memcpy( local.bytes + in1->size , in2->bytes , in2->size ) ;
return jSuccessResult ;
}
