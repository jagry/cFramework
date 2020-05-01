#define capitalACharacter 'A'
#define capitalFCharacter 'F'
#define capitalZCharacter 'Z'
#define carriageReturnCharacter '\r'
#define commaCharacter ','
#define commercialAtCharacter '@'
#define digit0Character '0'
#define digit9Character '9'
#define dollarCharacter '$'
#define lineFeedCharacter '\n'
#define lowLineCharacter '_'
#define reverseSolidusCharacter '\\'
#define smallACharacter 'a'
#define smallFCharacter 'f'
#define smallZCharacter 'z'
#define spaceCharacter ' '
#define tabCharacter '\t'

#define characterIsBlank( arg ) ( arg == carriageReturnCharacter || \
	arg == lineFeedCharacter || arg == spaceCharacter || arg == tabCharacter )
#define characterIsCapital( arg ) \
	( arg >= capitalACharacter && arg <= capitalZCharacter )
#define characterIsNotCapital( arg ) \
	( arg < capitalACharacter || arg > capitalZCharacter )
#define characterIsDigit( arg ) \
	( arg >= digit0Character && arg <= digit9Character )
#define characterIsFirst6Capital( arg ) \
	( arg >= capitalACharacter && arg <= capitalFCharacter )
#define characterIsFirst6Letter( arg ) \
	( characterIsFirst6Capital( arg ) || characterIsFirst6Small( arg ) )
#define characterIsFirst6Small( arg ) \
	( arg >= smallACharacter && arg <= smallFCharacter )
#define characterIsLetter( arg ) \
	( characterIsCapital( arg ) || characterIsSmall( arg ) )
#define characterIsNotLetter( arg ) \
	( characterIsNotCapital( arg ) && characterIsNotSmall( arg ) )
#define characterIsNotDigit( arg ) \
	( arg < digit0Character || arg > digit9Character )
#define characterIsSmall( arg ) \
	( arg >= smallACharacter && arg <= smallZCharacter )
#define characterIsNotSmall( arg ) \
	( arg < smallACharacter || arg > smallZCharacter )
