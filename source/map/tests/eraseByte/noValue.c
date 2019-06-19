//#define noValue( items , key , value ) return noValueImplementation( items , sizeof( items ) / sizeof( * items ) , &key , value ) ;
//
//#include <jagry/lbase.h>
//#include <jagry/lmap.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "#.h"
//
//#include <byteMapNode.h>
//
//#include <byteMap.h>
//
//static JPCharacter1 noValueItems[] = { "0" , "1" } ;
//static JPCharacter1 noValueBItems[] = { "001" , "002" } ;
//static JPCharacter1 noValueBNItems[] = { "0012" , "0012" } ;
//static JPCharacter1 noValueNItems[] = { "0" , "1" } ;
//static JPCharacter1 noValueNBItems[] = { "011" , "233" } ;
//
//JResult noValueValue() {
//JBuffer value = jEmptyBuffer ;
//noValue( noValueItems , jEmptyBuffer , &value )
//}
//
//JResult noValueBNull() {
//noValue( noValueItems , jEmptyBuffer , 0 )
//}
//
//JResult noValueBValue() {
//JBuffer value = jEmptyBuffer ;
//noValue( noValueItems , jEmptyBuffer , &value )
//}
//JResult noValueBNNull() {
//noValue( noValueItems , jEmptyBuffer , 0 )
//}
//
//JResult noValueBNValue() {
//JBuffer value = jEmptyBuffer ;
//noValue( noValueItems , jEmptyBuffer , &value )
//}
//JResult noValueNNull() {
//noValue( noValueItems , jEmptyBuffer , 0 )
//}
//
//JResult noValueNValue() {
//JBuffer value = jEmptyBuffer ;
//noValue( noValueItems , jEmptyBuffer , &value )
//}
//
//JResult noValueNBNull() {
//noValue( noValueItems , jEmptyBuffer , 0 )
//}
//
//JResult noValueNBValue() {
//JBuffer value = jEmptyBuffer ;
//noValue( noValueItems , jEmptyBuffer , &value )
//}