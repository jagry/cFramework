#include <jagry/array.i.h>

#define baseAnalyzer JByte type ;
#define childAnalyzer baseAnalyzer UAnalyzer parent ;

#define declareVariableAnalyzerType 0
#define unitAnalyzerType 1

#define builderBaseMethods( arg ) \
	JVoid( *free )( I##arg ) ; \
	JResult( *push )( PI##arg , PUToken ) ;
#define builderChildMethods( name ) union M##name { \
	struct { builderBaseMethods( name ) } _ ; \
	CMBaseAnalyzer base ; } ;

typedef union IChildAnalyzer * IChildAnalyzer ;
typedef union ICircleBracketAnalyzer ICircleBracketAnalyzer ;
typedef union IDeclareVariableAnalyzer IDeclareVariableAnalyzer ;
typedef struct DeclareVariableAnalyzer DeclareVariableAnalyzer ;
typedef union IUnitAnalyzer IUnitAnalyzer ;

typedef struct MBaseAnalyzer const CMBaseAnalyzer ;
typedef struct MCircleBracketAnalyzer const CMCircleBracketAnalyzer ;
typedef struct MDeclareVariableAnalyzer const CMDeclareVariableAnalyzer ;
typedef union MUnitAnalyzer const CMUnitAnalyzer ;
typedef CMBaseAnalyzer * PCMBaseAnalyzer ;
typedef CMUnitAnalyzer * PCMUnitAnalyzer ;
typedef IUnitAnalyzer * PIUnitAnalyzer ;

typedef CMDeclareVariableAnalyzer * PCMDeclareVariableAnalyzer ;
typedef ICircleBracketAnalyzer * PICircleBracketAnalyzer ;
typedef IDeclareVariableAnalyzer * PIDeclareVariableAnalyzer ;
typedef PCMBaseAnalyzer const CPCMBaseAnalyzer ;
typedef PCMUnitAnalyzer const CPCMUnitAnalyzer ;

typedef CPCMBaseAnalyzer * IBaseAnalyzer ;

typedef IBaseAnalyzer * PIBaseAnalyzer ;

struct MBaseAnalyzer { builderBaseMethods( BaseAnalyzer ) ; } ;
struct MCircleBracketAnalyzer {
	builderBaseMethods( CircleBracketAnalyzer ) ; } ;
struct MDeclareVariableAnalyzer {
	builderBaseMethods( DeclareVariableAnalyzer ) ; } ;
//struct MUnitAnalyzer { builderBaseMethods( UnitAnalyzer ) ; } ;
builderChildMethods( UnitAnalyzer ) ;

struct DeclareVariableAnalyzer {
	PCMDeclareVariableAnalyzer _ ;
	IBaseAnalyzer owner ;
	JIArray items ; } ;

union IDeclareVariableAnalyzer {
	DeclareVariableAnalyzer * _ ;
	IBaseAnalyzer base ; } ;
union IUnitAnalyzer {
	PCMUnitAnalyzer _ ;
	IBaseAnalyzer base ; } ;

jInternal( JResult )pushUnitAnalyzer( PIUnitAnalyzer , PUToken ) ;
