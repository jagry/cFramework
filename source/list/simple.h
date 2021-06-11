#define jUListArrayItemNil ( ( USimpleListItem ){ ._ = 0 } )

typedef struct mSimpleList MSimpleList ;
typedef struct sSimpleList SSimpleList ;
typedef union uSimpleList USimpleList ;
typedef struct mSimpleListItem MSimpleListItem ;
typedef struct sSimpleListItem SSimpleListItem ;
typedef union uSimpleListItem USimpleListItem ;

typedef USimpleList * JPISimpleList ;
typedef MSimpleList const CMSimpleList ;
typedef SSimpleList * PSSimpleList ;
typedef MSimpleListItem const CMSimpleListItem ;
typedef SSimpleListItem * PSSimpleListItem ;

typedef CMSimpleList * PCMSimpleList ;
typedef CMSimpleListItem * PCMSimpleListItem ;

typedef USimpleListItem * JPISimpleListItem ;

#include <jagry/list/simple.h>

struct mSimpleList { jEachSimpleArrayMethods(
	JISuper ,
	USimpleList ,
	USimpleList ,
	USimpleList ,
	USimpleList ,
	USimpleList ,
	USimpleList ,
	USimpleList ,
	USimpleList ,
	USimpleList ,
	USimpleList ,
	USimpleList ,
	USimpleList ,
	USimpleList ,
	USimpleList ,
	USimpleList ) } ;
union uSimpleList { PSSimpleList _ ; JISimpleArray i ; } ;
union uSimpleListItem { PSSimpleListItem _ ; JISimpleArrayItem i ; } ;

struct sSimpleList {
	jDynamicMembers( PCMSimpleList , _ )
	USimpleListItem first , last ;
	JPCListManager manager ;
	JSize count ; } ;
struct mSimpleListItem { jAllSimpleArrayItemMethods( USimpleListItem ) } ;
struct sSimpleListItem {
	PCMSimpleListItem _ ;
	PSSimpleList owner ;
	USimpleListItem next , previous ;
	JPVoid data ; } ;