typedef struct JArrayManager JArrayManager ;
typedef JArrayManager const JCArrayManager ;
typedef JCArrayManager * JPCArrayManager ;
typedef JPCArrayManager const JCPCArrayManager ;
typedef JVoid( *JArrayManagerFree )( JCPCArrayManager , JPVoid ) ; 
typedef JResult( *JArrayManagerCopy )( JCPCArrayManager , JPVoid , JCPCVoid ) ;

struct JArrayManager {
	JArrayManagerFree free ;
	JArrayManagerCopy get ;
	JArrayManagerCopy set ;
	JSize size ; } ;

jArrayMethod( JResult )jagryArrayManagerCopy( \
	JCPCArrayManager , JPVoid , JCPCVoid ) ;
jArrayMethod( JVoid )jagryArrayManagerFree( JCPCArrayManager , JPVoid ) ;
jArrayMethod( JResult )jagryArrayManagerPointer( \
	JCPCArrayManager , JPVoid , JCPCVoid ) ;
