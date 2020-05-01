// methods
int nilCallback( IterationDescription , JPBuffer ) ;
int errorCallback( IterationDescription , JPBuffer ) ;
int valueCallback( IterationDescription , JPBuffer ) ;

// typedef
typedef int( *PCallback )( IterationDescription , JPBuffer ) ;