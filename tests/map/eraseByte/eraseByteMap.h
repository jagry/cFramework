#define fileLine jNewLine "\t" jStringSpecifier ":" jSignedIntegerSpecifier jNewLine
#define stringify( argument ) #argument

#define factoryReturnedError jStringSpecifier " returned error " jResultSpecifier fileLine
#define eraseMapReturnedOther "jEraseMap returned " jResultSpecifier ", must be " jResultSpecifier fileLine
#define debugMustBe "jagryDebugEraseByteMap = " jUnsignedInteger8Specifier ", must be " jResultSpecifier fileLine