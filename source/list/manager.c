#define jListMethod jExport

#include <jagry/array.i.h>
#include <jagry/list/manager.h>
#include <memory.h>

static JCListManager listPointerManager = {
	.free = jagryListManagerFree ,
	.get = jagryListManagerGetPointer ,
	.set = jagryListManagerSetPointer } ;

JStatus jagryListManagerCopy(
	JCPCListManager managerIn , JPVoid destinationIn , JCPCVoid sourceIn ) {
//memcpy( destinationIn , sourceIn , managerIn->size ) ;
return jSuccessArrayStatus;
}

JVoid jagryListManagerFree(
	JCPCListManager managerIn , JPVoid pointerIn ) { }

JStatus jagryListManagerGetPointer(
	JCPCListManager managerIn , JPVoid destinationIn , JCPCVoid sourceIn ) {
memcpy( destinationIn , &sourceIn , sizeof( JPVoid ) ) ;
return jSuccessArrayStatus ;
}

JStatus jagryListManagerSetPointer(
	JCPCListManager managerIn, JPVoid destinationIn, JCPCVoid sourceIn) {
memcpy( destinationIn , &sourceIn , sizeof( JPVoid ) ) ;
return jSuccessArrayStatus ;
}

JCPCListManager jagryListPointerManager() {
return &listPointerManager ;
}