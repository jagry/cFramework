#ifndef JagryArrayLibrary
#define JagryArrayLibrary

struct VectorArray {
	PIListArrayItem first , last ;
	JPCArrayManager manager ;
	JUnsignedInteger count ; } ;
struct VectorArrayItem {
	PIListArrayItem next , previous ;
	JBuffer buffer ; } ;

#include "array/list.h"

#endif