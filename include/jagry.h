#ifndef Jagry
#define Jagry

/*
__linux__       Defined on Linux
__sun           Defined on Solaris
__FreeBSD__     Defined on FreeBSD
__NetBSD__      Defined on NetBSD
__OpenBSD__     Defined on OpenBSD
__APPLE__       Defined on Mac OS X
__hpux          Defined on HP-UX
__osf__         Defined on Tru64 UNIX (formerly DEC OSF1)
__sgi           Defined on Irix
_AIX            Defined on AIX
*/

#ifdef __linux__
	#define jLinux( argument ) argument
	#define jLinuxSystem
#else
	#define jLinux( argument )
#endif

#ifdef _WIN32
	#define jWindowsSystem
	#define jWindows( argument ) argument
#else
	#define jWindows( argument )
#endif

#define jSystem( appleArg , linuxArg , windowsArg ) jLinux( linuxArg ) jWindows( windowsArg )

#define jNil ( ( JPVoid )0 )
#define jZero 0

#define jExport( type ) __declspec( dllexport )type
#define jHidden( type ) type
#define jImport( type ) __declspec( dllimport )type

#ifdef DEBUG
	#define jAssert( condition ) \
		{ \
			if( condition ) \
				printf( "assert %s:%i" jNewLine , __FILE__ , __LINE__ ) ; \
		}
	#define jIfDebug( argument ) argument
	#define jIfNotDebug( argument )
#else
	#define jAssert( condition )
	#define jIfDebug( argument )
	#define jIfNotDebug( argument ) argument
#endif

#ifdef RELEASE
	#define jRelease( argument ) argument
#else
	#define jRelease( argument )
#endif

#define jPrefixType( prefix , name , define ) \
	typedef define prefix##name ; \
	\
	typedef prefix##name const prefix##C##name ; \
	typedef prefix##name * prefix##P##name ; \
	\
	typedef prefix##P##name const prefix##CP##name ; \
	typedef prefix##C##name * prefix##PC##name ; \
	typedef prefix##P##name * prefix##PP##name ; \
	\
	typedef prefix##PC##name const prefix##CPC##name ; \
	typedef prefix##CP##name * prefix##PCP##name;

#define jType( name , base ) jPrefixType( , name , base )

#define jEndOfLine jSystem( "\r" , "\n" , "\r\n" )

#define jMaxSignedInteger ( ( JSignedInteger )( jMaxUnsignedInteger >> 1 ) )
#define jMaxSignedInteger1 ( ( JSignedInteger1 )( jMaxUnsignedInteger1 >> 1 ) )
#define jMaxSignedInteger2 ( ( JSignedInteger2 )( jMaxUnsignedInteger2 >> 1 ) )
#define jMaxSignedInteger4 ( ( JSignedInteger4 )( jMaxUnsignedInteger4 >> 1 ) )
#define jMaxSignedInteger8 ( ( JSignedInteger8 )( jMaxUnsignedInteger8 >> 1 ) )

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

#define jSignedIntegerDecSpecifier "%i"
#define jSignedInteger1DecSpecifier "%i"
#define jSignedInteger2DecSpecifier "%hi"
#define jSignedInteger4DecSpecifier "%i"
#define jSignedInteger8DecSpecifier "%lli"

#define jUnsignedIntegerDecSpecifier "%u"
#define jUnsignedInteger1DecSpecifier "%u"
#define jUnsignedInteger2DecSpecifier "%hu"
#define jUnsignedInteger4DecSpecifier "%u"
#define jUnsignedInteger8DecSpecifier "%llu"


#define jSignedIntegerHexSpecifier "%i"
#define jSignedInteger1HexSpecifier "%i"
#define jSignedInteger2HexSpecifier "%hi"
#define jSignedInteger4HexSpecifier "%i"
#define jSignedInteger8HexSpecifier "%lli"

#define jUnsignedIntegerHexSpecifier "%u"
#define jUnsignedInteger1HexSpecifier "%u"
#define jUnsignedInteger2HexSpecifier "%hu"
#define jUnsignedInteger4HexSpecifier "%u"
#define jUnsignedInteger8HexSpecifier "%llu"

#define jPointerSpecifier "%p"
#define jString1Specifier "%s"

#define jByteSpecifier jUnsignedInteger1Specifier
#define jCounterSpecifier jSignedIntegerSpecifier
#define jSizeSpecifier jSignedIntegerSpecifier

#include "jagry/_u.h"
#include "jagry/_w.h"

#include <stddef.h>
#include <stdint.h>

jPrefixType( J , Void , void )
jPrefixType( J , Byte , unsigned char )

jPrefixType( J , Character1 , jLinux( char ) jWindows( char ) )
jPrefixType( J , Character2 , jLinux( __uint16_t ) jWindows( wchar_t ) )
jPrefixType( J , Character4 , jLinux( __uint32_t ) jWindows( uint32_t ) )

jPrefixType( J , SignedInteger , signed int )
jPrefixType( J , SignedInteger1 , jLinux( __int8_t ) jWindows( int8_t ) )
jPrefixType( J , SignedInteger2 , jLinux( __int8_t ) jWindows( int8_t ) )
jPrefixType( J , SignedInteger4 , jLinux( __int32_t ) jWindows( int32_t ) )
jPrefixType( J , SignedInteger8 , jLinux( __int64_t ) jWindows( int64_t ) )

jPrefixType( J , UnsignedInteger , unsigned int )
jPrefixType( J , UnsignedInteger1 , jLinux( __uint8_t ) jWindows( uint8_t ) )
jPrefixType( J , UnsignedInteger2 , jLinux( __uint16_t ) jWindows( uint16_t ) )
jPrefixType( J , UnsignedInteger4 , jLinux( __uint32_t ) jWindows( uint32_t ) )
jPrefixType( J , UnsignedInteger8 , jLinux( __uint64_t ) jWindows( uint64_t ) )

jPrefixType( J , Counter , int )
jPrefixType( J , Size , size_t )
jPrefixType( J , Offset , int )
//jPrefixType( J , Count , int )

jPrefixType( J , UnsignedIntegerPointer , uintptr_t )
jPrefixType( J , SignedIntegerPointer , intptr_t )

typedef enum JBoolean {
	jFalse ,
	jTrue } JBoolean ;

#endif
