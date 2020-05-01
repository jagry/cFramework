#ifndef JagryBufferLibrary
#define JagryBufferLibrary

#define jBufferMethod jImport

#include <jagry/result.h>
#include "reader.i.h"

typedef JIReader * JPIBufferReader ;

#include "buffer/add.h"
#include "buffer/clear.h"
#include "buffer/concate.h"
#include "buffer/create.h"
#include "buffer/free.h"
#include "buffer/initialize.h"
#include "buffer/reader.h"
#include "buffer/set.h"

#endif
