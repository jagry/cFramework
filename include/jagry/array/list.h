//#define jInitializeListArray( self , in ) \
//	( self ).first = self.last = 0 ; \
//	( self ).count = 0 ; \
//	( self ).manager = in ;
//
//#define jListArray( argument ) \
//	( ( JListArray ){ .count = 0 , .first = 0 , .last = 0 , .manager = argument )

//typedef struct JListArray JListArray ;
//typedef struct JListArrayItem JListArrayItem ;
//
//typedef JListArray * JPListArray ;
//typedef JListArrayItem jArrayConst JCListArrayItem ;
//typedef JListArrayItem * JPListArrayItem ;
//
//typedef JCListArrayItem * JPCListArrayItem ;
//
//typedef JPCListArrayItem * JPPCListArrayItem ;
//
//struct JListArray {
//	JPListArrayItem first , last ;
//	JPCArrayManager manager ;
//	JUnsignedInteger count ; } ;
//struct JListArrayItem {
//	JPListArrayItem next , previous ;
//	JByte data[] ; } ;

jArrayMethod( JResult )jagryListArray( JCPCArrayManager , JPIListArray ) ;
jArrayMethod( JResult )jagryListArrayBase(
	JIBase , JCPCArrayManager , JPIListArray ) ;
