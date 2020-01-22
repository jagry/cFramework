#define capitalACharacter 'A'
#define capitalFCharacter 'F'
#define capitalZCharacter 'Z'
#define carriageReturnCharacter '\r'
#define commercialAtCharacter '@'
#define digit0Character '0'
#define digit9Character '9'
#define dollarCharacter '$'
#define lineFeedCharacter '\n'
#define lowLineCharacter '_'
#define smallACharacter 'a'
#define smallFCharacter 'f'
#define smallZCharacter 'z'
#define spaceCharacter ' '
#define tabCharacter '\t'

#define characterIsBlank( argument ) \
	( argument == carriageReturnCharacter || argument == lineFeedCharacter  \
	|| argument == spaceCharacter  || argument == tabCharacter )
#define characterIsCapital( argument ) \
	( argument >= capitalACharacter && argument <= capitalZCharacter )
#define characterIsNotCapital( argument ) \
	( argument < capitalACharacter || argument > capitalZCharacter )
#define characterIsDigit( argument ) \
	( argument >= digit0Character && argument <= digit9Character )
#define characterIsFirst6Capital( argument ) \
	( argument >= capitalACharacter && argument <= capitalFCharacter )
#define characterIsFirst6Letter( argument ) \
	( characterIsFirst6Capital( argument ) || characterIsFirst6Small( argument ) )
#define characterIsFirst6Small( argument ) \
	( argument >= smallACharacter && argument <= smallFCharacter )
#define characterIsLetter( argument ) \
	( characterIsCapital( argument ) || characterIsSmall( argument ) )
#define characterIsNotLetter( argument ) \
	( characterIsNotCapital( argument ) && characterIsNotSmall( argument ) )
#define characterIsSmall( argument ) \
	( argument >= smallACharacter && argument <= smallZCharacter )
#define characterIsNotSmall( argument ) \
	( argument < smallACharacter || argument > smallZCharacter )
