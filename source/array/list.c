/* !!! */ #include <stdio.h>

#define jArrayMethod jExport
#define jArrayConst

#include <jagry/array.i.h>
#include <jagry/super.h>
#include <stdlib.h>

typedef struct MListArray const CMListArray ;
typedef struct MListArrayItem const CMListArrayItem ;
typedef struct IListArray IListArray ;
typedef struct IListArrayItem IListArrayItem ;

typedef CMListArray * PCMListArray ;
typedef CMListArrayItem * PCMListArrayItem ;
typedef IListArray * PIListArray ;
typedef IListArrayItem * PIListArrayItem ;

typedef PIListArray * JPIListArray ;
typedef PIListArrayItem * JPIListArrayItem ;

#include <jagry/array/manager.h>

#include <jagry/array/list.h>

struct IListArray {
	jSuperMembers( PCMListArray , _ )
	JCounter count ;
	PIListArrayItem first , last ;
	JCPCArrayManager manager ; } ;
struct MListArray { jEachArray( JISuper , IListArray , IListArray ,
	IListArray , IListArray , IListArray , IListArray , IListArray ,
	IListArray , IListArray , IListArray , IListArray , IListArray ,
	IListArray , IListArray , IListArray , PIListArrayItem ) } ;
struct MListArrayItem { jAllArrayItem( IListArrayItem ) } ;
struct IListArrayItem {
	PCMListArrayItem methods ;
	PIListArrayItem next , previous ;
	JBuffer buffer ; } ;
static JResult pushListArrayBackward(
	IListArray , JCPCVoid , PIListArrayItem ) ;

static CMListArray mListArray = {
	/*base */
		.acquire = jagryAcquireSuper ,
	/* ListArray */
		.pushBackward = pushListArrayBackward } ;

JResult jagryListArray( JCPCArrayManager in , JPIListArray out ) {
JResult result ;
if( !( *out = malloc( sizeof( IListArray ) ) ) )
	return jNotEnoughtMemoryErrorArrayResult ;
jInitializeSuper( *out , mListArray , 0 , 1 )
// !!! jagryInitializeListArray( &out->data->_ , in ) ;
return jSuccessArrayResult ;
}

JResult pushListArrayBackward( \
	IListArray self , JCPCVoid in , PIListArrayItem out ) {
//if( !( *out = malloc( sizeof( JIListArrayItem ) ) ) )
//	return jNotEnoughtMemoryErrorArrayResult ;
//( *out )->previous = self->last ;
//if( self->last )
//	self->last->next = *out ;
//else
//	self->first = *out ;
//self->last = *out ;
return jSuccessArrayResult ;
}
