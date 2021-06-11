#ifndef JagryImplementation
#define JagryImplementation

#define jDeclareBaseImplementation( \
		interface , \
		interfaceP , \
		methods , \
		methodsC , \
		methodsPC , \
		methodsCPC , \
		data , \
		dataP ) \
	typedef union interface interface ; \
	typedef interface * interfaceP ; \
	typedef struct methods methods ; \
	typedef methods const methodsC ; \
	typedef methodsC * methodsPC ; \
	typedef methodsPC const methodsCPC ; \
	typedef struct data data ; \
	typedef data * dataP ;

#define jDeclareChildImplementation( \
		interface , \
		interfaceP , \
		methods , \
		methodsC , \
		methodsPC , \
		methodsCPC , \
		data , \
		dataP ) \
	typedef union interface interface ; \
	typedef interface * interfaceP ; \
	typedef struct methods methods ; \
	typedef methods const methodsC ; \
	typedef methodsC * methodsPC ; \
	typedef methodsPC const methodsCPC ; \
	typedef union data data ; \
	typedef data * dataP ;

#endif