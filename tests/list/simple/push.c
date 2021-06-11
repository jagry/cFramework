#include <jagry/list.l.h>
#include <jagry/test.h>

//JTestStatus push( JISimpleArray arrayIn , JPTestArgument testArg ) {
////JISimpleArray array = jISimpleArrayNil ;
////JStatus status = jagrySimpleList( jagryListPointerManager() , &array ) ;
////if( jStatusIsError( status ) )
////	return showError( "Create array" , status ) , status ;
////for( JUnsignedInteger push = 0 ; 9 > push ; ++push )
////	{
////		JISimpleArrayItem item = jISimpleArrayItemNil ;
////		status = jPushSimpleArrayForward( array , ( JPVoid )push , 0 ) ;
////		if( jStatusIsError( status ) )
////			return showError( "Adding item" , status ) , status ;
////		item = jGetSimpleArrayFirst( array ) ;
////		for(
////				JUnsignedInteger test = push ;
////				item ;
////				item = jGetSimpleArrayItemNext(item) )
////			{
////				JPVoid data = ( JPVoid )-1 ;
////				status = jGetSimpleArrayItemValue( item , &data ) ;
////				if( jStatusIsError( status ) )
////					return showError( "Get value" , status ) , status ;
////				if( data != ( JPVoid )test-- )
////					return showError( "Invalid value" , status ) , status ;
////			}
////	}
////jReleaseArray( array ) ;
//return jSuccessArrayStatus ;
//}