typedef struct Item Item ;
typedef Item * PItem ;

struct Item {
	JBuffer key ; } ;

jHidden( JResult )addMapItem( PIMap , JCPCVoid , JCPCVoid , JPIMapItem ) ;