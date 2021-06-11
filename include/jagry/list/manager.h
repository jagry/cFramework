typedef struct JListManager JListManager ;
typedef JListManager const JCListManager ;
typedef JCListManager * JPCListManager ;
typedef JPCListManager const JCPCListManager ;
typedef JVoid( *JListManagerFree )( JCPCListManager , JPVoid ) ; 
typedef JStatus( *JListManagerCopy )( JCPCListManager , JPVoid , JCPCVoid ) ;

struct JListManager {
	JListManagerFree free ;
	JListManagerCopy get ;
	JListManagerCopy set ; } ;

jListMethod( JStatus )jagryListManagerCopy(
	JCPCListManager , JPVoid , JCPCVoid ) ;
jListMethod( JVoid )jagryListManagerFree( JCPCListManager , JPVoid ) ;
jListMethod( JStatus )jagryListManagerGetPointer(
	JCPCListManager , JPVoid , JCPCVoid ) ;
jListMethod( JStatus )jagryListManagerSetPointer(
	JCPCListManager , JPVoid , JCPCVoid ) ;
jListMethod( JCPCListManager )jagryListPointerManager( ) ;