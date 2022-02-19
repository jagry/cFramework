#define jTestMethod jStaticExport

#include <stdio.h>
#include "write.h"

JBoolean jagryRunTest( JPCTestItem itemsIn , JSize countIn ) {
JBoolean status = jTrue ;
for( JSize counter = jZero ; counter < countIn ; ++counter )
	{
		JPVoid data ; JTestResult result ;
		JTest test = { .stack = jNil } ;
		printf( "%s :\n" , itemsIn[ counter ].name ) ;
		if( itemsIn[ counter ].initialize )
			{
				printf( "\tinitialize - " ) ;
				result = itemsIn[ counter ].initialize( &test , &data ) ;
				writeTestResult( &test , &result ) ;
				if( jTestIsError( result ) )
					{
						status = jFalse ;
						continue ;
					}
			}
		else data = jNil ;
		printf( "\ttest - " ) ;
		result = itemsIn[ counter ].body( &test , data ) ;
		writeTestResult( &test , &result ) ;
		if( jTestIsError( result ) )
			status = jFalse ;
		if( itemsIn[ counter ].finalize )
			{
				printf( "\tfinalize - " ) ;
				itemsIn[ counter ].finalize( &test , data ) ;
				printf( writeSuccess ) ;
			}
}
return status ;
}