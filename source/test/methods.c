#include "write.h"

static JCTestMethods
	testDataNotEnoughMemoryMethods = {
		.free = jNil ,
		.write = writeNotEnoughMemoryTestResult } ,
	testDataEmptyErrorTestMethods = {
		.free = jNil ,
		.write = writeEmptyTestResult } ,
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

JPCTestMethods jagryGetEmptyTestMethods( JVoid ) { return &testDataEmptyErrorTestMethods ; }

JPCTestMethods jagryGetNotEnoughMemoryTestMethods( JVoid ) { return &testDataNotEnoughMemoryMethods ; }

JPCTestMethods jagryGetStatusTestMethods( JVoid ) { return &testDataStatusErrorMethods ; }