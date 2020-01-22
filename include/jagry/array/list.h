#define jInitializeListArray( self , in ) \
	( self ).first = self.last = 0 ; \
	( self ).count = 0 ; \
	( self ).manager = in ;

#define jListArray( argument ) \
	( ( JListArray ){ .count = 0 , .first = 0 , .last = 0 , .manager = argument )

typedef struct JListArray JListArray ;
typedef struct JListArray JListArrayItem ;

typedef JListArray * JPListArray ;
typedef JListArrayItem * JPListArrayItem ;

struct JListArray {
	PIListArrayItem first , last ;
	JPCArrayManager manager ;
	JUnsignedInteger count ; } ;
struct JListArrayItem {
	PIListArrayItem next , previous ;
	JBuffer buffer ; } ;

jArrayMethod( JResult )jagryCreateListArray( JCPCArrayManager , JPIListArray ) ;
jArrayMethod( JResult )jagryCreateListArrayBase(
	JIBase , JCPCArrayManager , JPIListArray ) ;
jArrayMethod( JPVoid )jagryInitializeListArray(
	JPListArray self , JCPCArrayManager in ) ;
jArrayMethod( JResult )jagryPushListArrayBackward(
	JPListArray self , JCPCVoid in , JPListArrayItem out ) ;
