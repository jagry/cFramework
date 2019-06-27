#define message "error: " jStringSpecifier ":" jSignedIntegerSpecifier ": "
#define messageIndent " "

#define callReturnedErrorMessage message jStringSpecifier " returned error " jResultSpecifier jNewLine
#define eraseMapReturnedOtherMessage message "jEraseMap returned " jResultSpecifier ", must be " jResultSpecifier jNewLine
#define returnPointMustBeMessage message "jagryDebugEraseByteMap = " jUnsignedIntegerSpecifier ", must be " jUnsignedIntegerSpecifier jNewLine
#define pointValueMustBeMessage message jStringSpecifier " counter = " jUnsignedIntegerSpecifier ", must be " jUnsignedIntegerSpecifier jNewLine
#define valueHasChangedMessage message "value has changed to { bytes = " jPointerSpecifier ", size = " jSignedIntegerSpecifier "}" jNewLine