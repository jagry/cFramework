//#ifndef JAGRY_TOKEN
//#define JAGRY_TOKEN

typedef struct JToken JToken ;
typedef struct JTokenMethods JTokenMethods ;

struct JToken {
    JTokenMethods* methods ;
} ;

struct JTokenMethods {
    int( *close )( JToken* ) ;
    int( *read )( JToken* , char* , int ) ;
    int( *release )( JToken* ) ;
} ;

//#endif