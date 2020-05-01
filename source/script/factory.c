/* !!! */ #include <stdio.h>

#include "token.h"

#include "factory.h"

JResult standardFactory( UFactoryArgument in , PUToken arg ) {
printf( "DEBUG %s(%i)\n" , __PRETTY_FUNCTION__ , __LINE__ ) ;
freeToken( arg ) ;
arg->identifier.type = in.keyword.type ;
arg->identifier.value = in.keyword.identifier ;
return jSuccessResult ;
}
