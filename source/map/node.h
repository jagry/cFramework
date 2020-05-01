typedef struct BaseMapNode BaseMapNode ;
typedef struct FullMapNode FullMapNode ;
typedef struct SubMapNode SubMapNode ;
typedef struct SubsMapNode SubsMapNode ;
typedef union UMapNode UMapNode ;
typedef struct ValueMapNode ValueMapNode ;

typedef BaseMapNode * PBaseMapNode ;
typedef FullMapNode * PFullMapNode ;
typedef SubMapNode * PSubMapNode ;
typedef SubsMapNode * PSubsMapNode ;
typedef UMapNode * PUMapNode ;
typedef ValueMapNode * PValueMapNode ;

union UMapNode {
	PBaseMapNode base ;
	PFullMapNode full ;
	PSubMapNode sub ;
	PSubsMapNode subs ;
	PValueMapNode value ; } ;