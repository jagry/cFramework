#include <stdio.h>
#include "write.h"

JBoolean jagryRunTest( JPCTestItem itemsIn , JSize countIn ) {
JBoolean status = jTrue ;
for( JSize counter = jZero ; counter < countIn ; ++counter )
	{
		JPVoid data ; JTestResult result ;
		JTest test = { .stack = jNil } ;
		printf( "%s :\n\tinitialize - " , itemsIn[ counter ].name ) ;
		result = itemsIn[ counter ].initialize( &test , &data ) ;
		writeTestResult( &test , &result ) ;
		if( jTestIsError( result ) )
			{
				status = jFalse ;
				continue ;
			}
		printf( "\ttest - " ) ;
		result = itemsIn[ counter ].body( &test , data ) ;
		writeTestResult( &test , &result ) ;
		if( jTestIsError( result ) )
			{
				status = jFalse ;
				continue ;
			}
		printf( "\tfinalize - " ) ;
		itemsIn[ counter ].finalize( &test , data ) ;
		printf( writeSucces ) ;
}
return status ;
}



