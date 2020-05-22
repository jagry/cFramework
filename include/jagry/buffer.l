#ifndef JagryBufferLibrary
#define JagryBufferLibrary

#define jBufferMethod jImport

#include <jagry/result.h>
#include "reader.i.h"

typedef JIReader * JPIBufferReader ;

#include "buffer/add"
#include "buffer/clear"
#include "buffer/concate"
#include "buffer/create"
#include "buffer/free"
#include "buffer/initialize"
#include "buffer/reader"
#include "buffer/set"

#endif
