#define ownerMembers jDynamicMembers( JPCMDynamic , _ ) JUnsignedInteger value ;
#define ownerMethods \
	jBaseEachMethods( JDynamic , IOwner , IOwner ) \
	JUnsignedInteger( *increment )( JDynamic , JUnsignedInteger ) ;
//#define ownerInterfaceIdentifier1 ( ( JInterfaceIdentifier )1 )
//#define ownerInterfaceIdentifier2 ( ( JInterfaceIdentifier )2 )

#define ownerCheck() { \
	u.result = check( testIn , argumentIn[ 0 ] , data[ 0 ] ) ; \
	jReturnTestIfError( stack , u.result ) \
	u.result = check( testIn , argumentIn[ 1 ] , data[ 1 ] ) ; \
	jReturnTestIfError( stack , u.result ) ; }

#include "data.h"
#include "implementation.h"
#include <jagry/dynamic.l.h>
#include <jagry/test.h>

typedef union { JTestStatusData _ ; } OwnerStack ;

JTestResult check( JPTest , Implementation , Data ) ;
JVoid store( Implementation implementationIn , PData dataOut ) ;

JTestResult owner( JPTest testIn , PImplementation argumentIn ) {
struct Iteration {
	JInterfaceIdentifier identifier ; 
	JUnsignedInteger referenses ; } ;
Data data[ 2 ] ; JIBase base , etalon ; JPTestStack stack ; union { JTestResult result ; JStatus status ; } u ;
struct Iteration iterations[] = {
	{ .identifier = jBaseInterfaceIdentifier } ,
	{ .identifier = ownedImplementationInterfaceIdentifier } ,
	{ .identifier = ownerImplementationInterfaceIdentifier } } ;
/* инициализация тест - стека */ {
	u.result = jPushTest( testIn , sizeof( OwnerStack ) , stack ) ;
	jReturnTestIfError( stack , u.result )
}
store( argumentIn[ 0 ] , &data[ 0 ] ) ;
store( argumentIn[ 1 ] , &data[ 1 ] ) ;
/* !!! ( sizeof( iterations ) / ( sizeof( *iterations ) ) ) переделать в jArraySize */
for( JCounter counter = 0 ; counter < ( sizeof( iterations ) / ( sizeof( *iterations ) ) ) ; ++counter )
	{
		/* !!! сделать стек для циклов
		надо как то выводить номер итерации при возникновении ошибки */
		/* Получение стартового интерфейса */ {
			u.status = jGetBaseInterface( argumentIn[ 0 ].i , iterations[ counter ].identifier, etalon ) ;
			jReturnTestStatusIfError( stack , OwnerStack , _ , u.status )
			jReturnEmptyTestIf( stack , argumentIn[ 0 ].i.b.t != etalon.t && argumentIn[ 1 ].i.b.t != etalon.t )
			data[ 0 ].references++ ;
			ownerCheck()
		}
		/* Запрос не существующего интерфеса */ {
			u.status = jGetBaseInterface( etalon , missingImplementationInterfaceIdentifier , base ) ;
			jReturnTestStatusIf( stack , u.status != jNoInterfaceErrorBaseStatus , OwnerStack , _ , u.status )
			u.result = check( testIn , argumentIn[ 0 ] , data[ 0 ] ) ;
			jReturnTestIfError( stack , u.result )
			u.result = check( testIn , argumentIn[ 1 ] , data[ 1 ] ) ;
			jReturnTestIfError( stack , u.result )
		}
		/* Запрос базового интерфеса */ {
			u.status = jGetBaseInterface( etalon , jBaseInterfaceIdentifier , base ) ;
			jReturnTestStatusIfError( stack , OwnerStack , _ , u.status )
			jReturnEmptyTestIf( stack , argumentIn[ 0 ].i.b.t != base.t )
			data[ 0 ].references++ ;
			u.result = check( testIn , argumentIn[ 0 ] , data[ 0 ] ) ;
			jReturnTestIfError( stack , u.result )
			u.result = check( testIn , argumentIn[ 1 ] , data[ 1 ] ) ;
			jReturnTestIfError( stack , u.result )
		}
		/* Запрос расширяющего интерфейса */ {
			u.status = jGetBaseInterface( etalon , ownedImplementationInterfaceIdentifier , base ) ;
			jReturnTestStatusIfError( stack , OwnerStack , _ , u.status )
			jReturnEmptyTestIf( stack , argumentIn[ 1 ].i.b.t != base.t )
			data[ 0 ].references++ ;
			u.result = check( testIn , argumentIn[ 0 ] , data[ 0 ] ) ;
			jReturnTestIfError( stack , u.result )
			u.result = check( testIn , argumentIn[ 1 ] , data[ 1 ] ) ;
			jReturnTestIfError( stack , u.result )
		}
		/* Запрос интерфейса владельца */ {
			u.status = jGetBaseInterface( etalon , ownerImplementationInterfaceIdentifier , base ) ;
			jReturnTestStatusIfError( stack , OwnerStack , _ , u.status )
			jReturnEmptyTestIf( stack , argumentIn[ 0 ].i.b.t != base.t )
			data[ 0 ].references++ ;
			u.result = check( testIn , argumentIn[ 0 ] , data[ 0 ] ) ;
			jReturnTestIfError( stack , u.result )
			u.result = check( testIn , argumentIn[ 1 ] , data[ 1 ] ) ;
			jReturnTestIfError( stack , u.result )
		}
	}
return jPopTest( testIn , stack ) ;
}