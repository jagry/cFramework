#include "write.h"

static JCTestMethods
	testDataNotEnoughMemoryMethods = {
		.free = jNil ,
		.write = writeNotEnoughMemoryTestResult } ,
	testDataStatusErrorMethods = {
		.free = jNil ,
		.write = writeStatusTestResult } ;

JCTestMethods
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

JPCTestMethods jagryGetNotEnoughMemoryTestMethods( JVoid ) {
return &testDataNotEnoughMemoryMethods ;
}

JPCTestMethods jagryGetStatusErrorTestMethods( JVoid ) {
return &testDataStatusErrorMethods ;
}