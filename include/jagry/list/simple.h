//jPrefixType( J , SimpleList , struct JSimpleList )
//jPrefixType( J , SimpleListItem , struct JSimpleListItem )
//
//struct JSimpleList {
//	JPSimpleListItem first , last ;
//	JPCListManager manager ;
//	JUnsignedInteger count ; } ;
//struct JSimpleListItem {
//	JPSimpleList owner ;
//	JPSimpleListItem next , previous ;
//	JPVoid data ; } ;
//
//jListMethod( JStatus )jagryPushSimpleList(JPSimpleList , JCPCListManager ) ;

jListMethod( JStatus )jagrySimpleList( JCPCListManager , JPISimpleList ) ;
jListMethod( JStatus )jagrySimpleListBase(
	JIBase , JCPCListManager , JPIBase ) ;