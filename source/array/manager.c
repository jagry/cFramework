#define jArrayMethod jExport

#include <jagry/array.i.h>
#include <jagry/array/manager.h>

JResult jagryArrayManagerCopy( \
	JCPCArrayManager managerIn , JPVoid destinationIn , JCPCVoid sourceIn ) {
memcpy( destinationIn , sourceIn , managerIn->size ) ;
return jSuccessArrayResult ;
}

JVoid jagryArrayManagerFree( JCPCArrayManager managerIn , JPVoid pointerIn ) { }

JResult jagryArrayManagerPointer( \
	JCPCArrayManager managerIn , JPVoid destinationIn , JCPCVoid sourceIn ) {
memcpy( destinationIn , &sourceIn , sizeof( JPVoid ) ) ;
return jSuccessArrayResult ;
}