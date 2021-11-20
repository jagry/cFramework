#include "data.h"
#include "implementation.h"

JVoid store( Implementation implementationIn , PData dataOut ) {
dataOut->owned = implementationIn.d->owned ,
// dataOut->owner = implementationIn.d->owner ,
dataOut->references = implementationIn.d->r ,
dataOut->value = implementationIn.d->value ;
}