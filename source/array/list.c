#define jArrayMethod jExport

#include <jagry/array.i.h>
#include <jagry/super.h>
#include <stdlib.h>

jStdDeclareImplementation( ListArray )
jStdDeclareImplementation( ListArrayItem )

typedef struct MArrayItem MArrayItem ;

typedef MArrayItem const CMArrayItem ;

typedef CMArrayItem * PCMArrayItem ;

typedef PIListArray JPIListArray ;
typedef PIListArrayItem JPIListArrayItem ;

#include <jagry/array/list.h>

struct DListArray {
	jSuperMembers( PCMListArray , methods )
	JListArray _ ; } ;
struct MListArray { jEachArray( JISuper , IListArray , IListArray ,
	IListArray , IListArray , IListArray , IListArray , IListArray ,
	IListArray , IListArray , IListArray , IListArray , IListArray ,
	IListArray , IListArray , IListArray , JPIArrayItem ) } ;	
union IListArray {
	PDListArray implementation ; } ;
struct DListArrayItem {
	PCMArrayItem methods ;
	PIListArrayItem next , previous ;
	JBuffer buffer ; } ;
struct MListArrayItem { jAllArrayItem( IListArrayItem ) } ;
union IListArrayItem {
	PDListArrayItem implementation ;
	/* !!! нужен ли интерфейс? */ JIArrayItem interface ; } ;

static JResult pushListArrayBackward(
	IListArray , JCPCVoid , JPIArrayItem ) ;

static MListArray mListArray = {
	/*base */
		.acquire = jagryAcquireSuper ,
	/* ListArray */
		.pushBackward = pushListArrayBackward } ;

JResult jagryCreateListArray( JCPCArrayManager in , JPIListArray out ) {
JResult result ;
if( !( out->implementation = malloc( sizeof( DListArray ) ) ) )
	return jNotEnoughtMemoryErrorArrayResult ;
jInitializeSuper( *out , implementation , mListArray , 0 , 1 )
jagryInitializeListArray( &out->implementation->_ , in ) ;
return jSuccessArrayResult ;
}

JResult jagryPushListArrayBackward( JPListArray self , \
	JCPCVoid in , JPListArrayItem out ) {
*out = malloc( sizeof( JListArrayItem ) ) ;
if( self->last ) ;
	
}

JResult pushListArrayBackward( IListArray self ,
	JCPCVoid in , JPIArrayItem out ) {
JResult result =
	jagryPushListArrayBackward( &self.implementation->_ , in, out ) ;
if( jSuccessArrayResult != result )
	return result ;

}
