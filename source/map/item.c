#define jMapMethod jExport

#include <jagry/buffer.i.h>
#include <jagry/map.i.h>
#include <jagry/super.h>
#include "node.h"

#include "key.h"

#include "@.h"

#include "modify.h"
#include "item.h"

JResult addMapItem( \
	PIMap self , JCPCVoid keyIn , JCPCVoid valueIn , JPIMapItem out ) {
return modifyMap( self , /*( *self->key._ )->add()*/ jNull , keyIn , valueIn , out) ;
}
