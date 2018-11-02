#ifndef Jagry
#define Jagry

#ifdef NDEBUG
	#define jDebug( argument )
	#define jRelease( argument ) { argument }
#else
	#define jDebug( argument ) { argument }
	#define jRelease( argument )
#endif

#define jNewLine "\r\n"

#define jMaxSignedInteger ( ( JSignedInteger )( JUnsignedInteger >> 1 ) )
#define jMaxSignedInteger1 ( ( JSignedInteger1 )( JUnsignedInteger1 >> 1 ) )
#define jMaxSignedInteger2 ( ( JSignedInteger2 )( JUnsignedInteger2 >> 1 ) )
#define jMaxSignedInteger4 ( ( JSignedInteger4 )( JUnsignedInteger3 >> 1 ) )
#define jMaxSignedInteger8 ( ( JSignedInteger8 )( JUnsignedInteger4 >> 1 ) )

#define jMaxUnsignedInteger ( ( JUnsignedInteger )~0 )
#define jMaxUnsignedInteger1 ( ( JUnsignedInteger1 )~0 )
#define jMaxUnsignedInteger2 ( ( JUnsignedInteger2 )~0 )
#define jMaxUnsignedInteger4 ( ( JUnsignedInteger4 )~0 )
#define jMaxUnsignedInteger8 ( ( JUnsignedInteger8 )~0 )

#define jMinSignedInteger ( ~jMaxSignedInteger )
#define jMinSignedInteger1 ( ~jMaxSignedInteger1 )
#define jMinSignedInteger2 ( ~jMaxSignedInteger2 )
#define jMinSignedInteger4 ( ~jMaxSignedInteger4 )
#define jMinSignedInteger8 ( ~jMaxSignedInteger8 )

#define jSignedIntegerSpecifier "%li"
#define jSignedInteger1Specifier "%i"
#define jSignedInteger2Specifier "%i"
#define jSignedInteger4Specifier "%i"
#define jSignedInteger8Specifier "%li"

#define jUnsignedIntegerSpecifier "%lu"
#define jUnsignedInteger1Specifier "%u"
#define jUnsignedInteger2Specifier "%u"
#define jUnsignedInteger4Specifier "%u"
#define jUnsignedInteger8Specifier "%lu"

#define jByteSpecifier jUnsignedInteger1Specifier
#define jCounterSpecifier jSignedIntegerSpecifier
#define jSizeSpecifier jSignedIntegerSpecifier

typedef unsigned char JByte ;

typedef char JCharacter1 ;
typedef short JCharacter2 ;
typedef int JCharacter4 ;

typedef signed char JSignedInteger1 ;
typedef signed short JSignedInteger2 ;
typedef signed int JSignedInteger4 ;
typedef signed long JSignedInteger8 ;

typedef unsigned char JUnsignedInteger1 ;
typedef unsigned short JUnsignedInteger2 ;
typedef unsigned int JUnsignedInteger4 ;
typedef unsigned long JUnsignedInteger8 ;

typedef void JVoid ;

#ifdef _LP64
	typedef JSignedInteger8 JSignedInteger ;
	typedef JUnsignedInteger8 JUnsignedInteger ;
	typedef JUnsignedInteger8 jPointerInteger ;
#else
	typedef JSignedInteger4 JSignedInteger ;
	typedef JUnsignedInteger4 JUnsignedInteger ;
	typedef JUnsignedInteger4 jPointerInteger ;
#endif

typedef enum JBoolean JBoolean ;

enum JBoolean {
	jFalse ,
	jTrue } ;

typedef JSignedInteger JCounter , JSize ;

typedef JByte const JCByte ;
typedef JCharacter1 const JCCharacter1 ;
typedef JVoid const JCVoid ;

typedef JByte * JPByte ;
typedef JCharacter1 * JPCharacter1 ;
typedef JVoid * JPVoid ;

typedef JPByte const JCPByte ;
typedef JPCharacter1 const JCPCharacter1 ;
typedef JPVoid const JCPVoid ;

typedef JCByte * JPCByte ;
typedef JCCharacter1 * JPCCharacter1 ;
typedef JCVoid * JPCVoid ;

typedef JPCByte const JCPCByte ;
typedef JPCCharacter1 const JCPCCharacter1 ;
typedef JPCVoid const JCPCVoid ;

// !!! Расставить все типы JC, JCP, JCPC, JP, JPC

#endif