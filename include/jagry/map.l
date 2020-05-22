#ifndef JagryMapLibrary
#define JagryMapLibrary

#define jMapConst const
#define jMapMethod jImport
#define JOMap JPIMap
#define JOMapKey JPIMapKey

#include "buffer.i"
#include "map.i"

#include "map/node"

#include "map/data.h"

#include "map/key.h"

jMapMethod( JResult )jagryMap( JCIMapKey in , JOMap out ) ;

#endif
