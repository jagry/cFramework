typedef struct ParseData ParseData ;
typedef ParseData * PParseData ;

struct ParseData {
	UBuilder builder ;
	JIMap map ;
	JIReader reader ;
	JCharacter1 character ; } ;