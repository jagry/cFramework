#include <jagry/status.h>

typedef struct gauge Gauge ;
typedef JVoid GaugeFree( PGauge ) ;
typedef JUnsignedIntegerPointer GaugeItem ;

typedef Gauge const CGauge;
typedef GaugeItem * PGaugeItem ;
typedef Gauge * PGauge ;
typedef GaugeFree * PGaugeFree ;

typedef CGauge * PCGauge;
typedef PGauge * PPGauge ;

struct gauge {
	PGaugeItem data ;
	PGaugeFree free ;
	JSize size ; } ;

JStatus gaugeStatic( JSize , JPUnsignedIntegerPointer , PPGauge ) ;
JStatus gaugeRange(
	JUnsignedIntegerPointer ,
	JUnsignedIntegerPointer ,
	JUnsignedIntegerPointer ,
	PPGauge ) ;