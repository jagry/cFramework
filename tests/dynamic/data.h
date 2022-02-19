#include <jagry/base.i.h>

typedef struct data Data ;
typedef Data * PData ;
struct data {
	JIPCMBase methods , self ;
	JIBase owned , owner ;
	JUnsignedInteger references , value ; } ;