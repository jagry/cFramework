#include <jagry/reader.i.h>

typedef union IReader IReader ;
typedef struct MReader MReader ;
typedef struct Reader Reader ;

typedef Reader * PReader ;
typedef MReader const * PCMReader ;

union IReader { PReader _ ; JIReader interface ; } ;
struct MReader { jReaderEach( IReader , IReader , IReader , IReader ) } ;
struct Reader { PCMReader _ ; JBuffer buffer ; JSize offset ; } ;

jInternal( JResult )loadingReader( PReader ) ;

extern IReader iReader ;
extern MReader mReader ;
