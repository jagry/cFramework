// !!! Объеденить методы jagryGet*TestMethods в один jagryGetTestMethods( in )
#define jTestMethod jStaticExport

#include "write.h"

static JCTestMethods
	testDataNotEnoughMemoryMethods = {
		.free = jNil ,
		.write = writeNotEnoughMemoryTestResult } ,
	testDataEmptyErrorTestMethods = {
		.free = jNil ,
		.write = writeEmptyTestResult } ,
	testDataInterfaceEquals = {
		.free = jNil ,
		.write = writeInterfaceEqualsTestResult } ,
	testDataPointerEquals = {
		.free = jNil ,
		.write = writePointerEqualsTestResult } ,
	testDataInterfaceNotEquals = {
		.free = jNil ,
		.write = writeInterfaceNotEqualsTestResult } ,
	testDataPointerNotEquals = {
		.free = jNil ,
		.write = writePointerNotEqualsTestResult } ,
	testDataStatusErrorMethods = {
		.free = jNil ,
		.write = writeStatusTestResult } ,
	testDataTextErrorMethods = {
		.free = jNil ,
		.write = writeTextTestResult } ;

jHidden( JCTestMethods )
	alreadyHasErrorTestMethods = {
		.free = jNil ,
		.write = writeAlreadyHasErrorTestResult } ,
	invalidStackTestMethods = {
		.free = jNil ,
		.write = writeInvalidStackTestResult } ,
	notInitializeDataTestMethods = {
		.free = jNil ,
		.write = writeNotInitializeDataTestResult } ,
	notInitializeStackTestMethods = {
		.free = jNil ,
		.write = writeNotInitializeStackTestResult } ;

jTestMethod( JPCTestMethods )jagryGetEmptyTestMethods( JVoid ) { return &testDataEmptyErrorTestMethods ; }
jTestMethod( JPCTestMethods )jagryGetInterfaceEqualTestMethods( JVoid ) { return &testDataInterfaceEquals ; } ;
jTestMethod( JPCTestMethods )jagryGetPointerEqualTestMethods( JVoid ) { return &testDataPointerEquals ; } ;
jTestMethod( JPCTestMethods )jagryGetInterfaceNotEqualsTestMethods( JVoid ) { return &testDataInterfaceNotEquals ; } ;
jTestMethod( JPCTestMethods )jagryGetPointerNotEqualsTestMethods( JVoid ) { return &testDataPointerNotEquals ; } ;
jTestMethod( JPCTestMethods )jagryGetNotEnoughMemoryTestMethods( JVoid ) { return &testDataNotEnoughMemoryMethods ; }
jTestMethod( JPCTestMethods )jagryGetStatusTestMethods( JVoid ) { return &testDataStatusErrorMethods ; }
jTestMethod( JPCTestMethods )jagryGetTextTestMethods( JVoid ) { return &testDataTextErrorMethods ; }