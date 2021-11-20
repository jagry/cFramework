#include <jagry/base.i.h>

typedef struct data Data ;
typedef Data * PData ;
struct data {
	JIBase owned , owner ;
	JUnsignedInteger references , value ; } ;