#include <jagry/buffer.i.h>
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
#else
	#define jLinux( argument )
#endif

#define jNull 0

#define jExport( type ) type
#define jHidden( type ) type
#define jImport( type ) type

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
	typedef prefix##name * prefix##P##name ; \
	typedef prefix##name const prefix##C##name ; \
	\
	typedef prefix##C##name * prefix##PC##name ; \
	typedef prefix##P##name * prefix##PP##name ; \
	typedef prefix##P##name const prefix##CP##name ; \
	\
	typedef prefix##PC##name const prefix##CPC##name ;
#define jType( name , base ) jPrefixType( , name , base )

#define jNewLine "\r\n"

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

#define jSignedIntegerSpecifier "%i"
#define jSignedInteger1Specifier "%i"
#define jSignedInteger2Specifier "%hi"
#define jSignedInteger4Specifier "%i"
#define jSignedInteger8Specifier "%lli"

#define jUnsignedIntegerSpecifier "%u"
#define jUnsignedInteger1Specifier "%u"
#define jUnsignedInteger2Specifier "%hu"
#define jUnsignedInteger4Specifier "%u"
#define jUnsignedInteger8Specifier "%llu"

#define jPointerSpecifier "%p"
#define jStringSpecifier "%s"

#define jByteSpecifier jUnsignedInteger1Specifier
#define jCounterSpecifier jSignedIntegerSpecifier
#define jSizeSpecifier jSignedIntegerSpecifier

#include <stddef.h>
#include <stdint.h>

jPrefixType( J , Void , void )
jPrefixType( J , Byte , unsigned char )

jPrefixType( J , Character1 , __uint8_t )
jPrefixType( J , Character2 , __uint16_t )
jPrefixType( J , Character4 , __uint32_t )

jPrefixType( J , SignedInteger , signed int )
jPrefixType( J , SignedInteger1 , __int8_t )
jPrefixType( J , SignedInteger2 , __int16_t )
jPrefixType( J , SignedInteger4 , __int32_t )
jPrefixType( J , SignedInteger8 , __int64_t )

jPrefixType( J , UnsignedInteger , unsigned int )
jPrefixType( J , UnsignedInteger1 , __uint8_t )
jPrefixType( J , UnsignedInteger2 , __uint16_t )
jPrefixType( J , UnsignedInteger4 , __uint32_t )
jPrefixType( J , UnsignedInteger8 , __uint64_t )

jPrefixType( J , Counter , int )
jPrefixType( J , Size , size_t )

typedef enum JBoolean {
	jFalse ,
	jTrue } JBoolean ;

#endif
