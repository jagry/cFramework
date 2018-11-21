#define fileLine jNewLine "\t" jStringSpecifier ":" jSignedIntegerSpecifier jNewLine
#define stringify( argument ) #argument

#define callReturnedError jStringSpecifier " returned error " jResultSpecifier fileLine
#define eraseMapReturnedOther "jEraseMap returned " jResultSpecifier ", must be " jResultSpecifier fileLine
#define debugMustBe "jagryDebugEraseByteMap = " jUnsignedIntegerSpecifier ", must be " jUnsignedIntegerSpecifier fileLine
#define valueHasChanged "value has changed to { bytes = " jPointerSpecifier ", size = " jSignedIntegerSpecifier "}" fileLine