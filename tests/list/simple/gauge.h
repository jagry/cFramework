#include <jagry/status.h>

typedef struct gauge Gauge ;
typedef JVoid GaugeFree( PGauge ) ;
typedef JUnsignedIntegerPointer GuageItem ;

typedef Gauge const CGauge;
typedef GuageItem * PGuageItem ;
typedef Gauge * PGauge ;
typedef GaugeFree * PGaugeFree ;

typedef CGauge * PCGauge;
typedef PGauge * PPGauge ;

struct gauge {
	PGuageItem data ;
	PGaugeFree free ;
	JSize size ; } ;

JStatus gaugeStatic( JSize , JPUnsignedIntegerPointer , PPGauge ) ;
JStatus gaugeRange(
	JUnsignedIntegerPointer ,
	JUnsignedIntegerPointer ,
	JUnsignedIntegerPointer ,
	PPGauge ) ;