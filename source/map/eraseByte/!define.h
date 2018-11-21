#define error "error: " jStringSpecifier ":" jSignedIntegerSpecifier ": "
#define stringify( argument ) #argument

#define callReturnedError error jStringSpecifier " returned error " jResultSpecifier jNewLine
#define eraseMapReturnedOther error "jEraseMap returned " jResultSpecifier ", must be " jResultSpecifier jNewLine
#define returnPointMustBe error "jagryDebugEraseByteMap = " jUnsignedIntegerSpecifier ", must be " jUnsignedIntegerSpecifier jNewLine
#define pointValueMustBe error jStringSpecifier " counter = " jUnsignedInteger8Specifier ", must be " jUnsignedInteger8Specifier jNewLine
#define valueHasChanged error "value has changed to { bytes = " jPointerSpecifier ", size = " jSignedIntegerSpecifier "}" jNewLine