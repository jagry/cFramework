#define error "error: " jNewLine "\t" jStringSpecifier ":" jSignedIntegerSpecifier jNewLine "\t"
#define stringify( argument ) #argument

#define callReturnedError error jStringSpecifier " returned error " jResultSpecifier
#define eraseMapReturnedOther error "jEraseMap returned " jResultSpecifier ", must be " jResultSpecifier
#define debugMustBe error "jagryDebugEraseByteMap = " jUnsignedIntegerSpecifier ", must be " jUnsignedIntegerSpecifier
#define valueHasChanged error "value has changed to { bytes = " jPointerSpecifier ", size = " jSignedIntegerSpecifier "}"