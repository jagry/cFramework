#include <jagry/lbase.h>
#include <jagry/lmap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <byteMapNode.h>

#include <byteMap.h>

#define indent "   "

#define jStringify( argument ) #argument

JResult emptyNull() ;
JResult emptyValue() ;

JResult main() {
emptyNull() ;
emptyValue() ;
}