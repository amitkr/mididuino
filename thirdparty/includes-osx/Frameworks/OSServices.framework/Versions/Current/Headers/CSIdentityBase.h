/*
 File:       OSServices/CSIdentityBase.h
 
 Contains:   CSIdentity APIs
 
 Copyright:  � 2006-2010 by Apple Inc., all rights reserved.
 
 Bugs?:      For bug reports, consult the following page on
 the World Wide Web:
 
 http://developer.apple.com/bugreporter/
 
 */
#ifndef __CSIDENTITYBASE__
#define __CSIDENTITYBASE__

#ifndef __COREFOUNDATION__
#include <CoreFoundation/CoreFoundation.h>
#endif

#ifndef __SECBASE__
#include <Security/SecBase.h>
#endif

#include <AvailabilityMacros.h>

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif
	
#pragma pack(push, 2)
	
#include <sys/types.h>
	
/*
 The error domain of all CFErrors reported by Identity Services 
 */
/*
 *  kCSIdentityErrorDomain
 *  
 *  Availability:
 *    Mac OS X:         in version 10.5 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCSIdentityErrorDomain							__OSX_AVAILABLE_STARTING( __MAC_10_5, __IPHONE_5_0 ); 

/*
 *  CSIdentity error codes
 *  
 *  Discussion:
 *    Error codes in the CSIdentity error domain
 */
enum {
	
	/*
	 * The specified authority is not recognized
	 */
	kCSIdentityUnknownAuthorityErr = -1,
	
	/*
	 * The specified authority is currently not accessible
	 */
	kCSIdentityAuthorityNotAccessibleErr = -2,
	
	/*
	 * The caller does not have permission to perform the operation
	 */
	kCSIdentityPermissionErr      = -3,
	
	/*
	 * The requested identity has been deteled
	 */
	kCSIdentityDeletedErr         = -4,
	
	/*
	 * The full name is not valid (length: [1-255])
	 */
	kCSIdentityInvalidFullNameErr = -5,
	
	/*
	 * The full name is aleady assigned to another identity
	 */
	kCSIdentityDuplicateFullNameErr = -6,
	
	/*
	 * The Posix name is not valid (char set: [a-zA-Z0-9_-] length:
	 * [1-255])
	 */
	kCSIdentityInvalidPosixNameErr = -7,
	
	/*
	 * The Posix name is aleady assigned to another identity
	 */
	kCSIdentityDuplicatePosixNameErr = -8,
	
	/*
	 *	The given account does not exist 
	 */
	kCSIdentityUnknownAccountErr = -9,
	
};
	
#pragma pack(pop)
	
#ifdef __cplusplus
}
#endif

#endif /* __CSIDENTITYBASE__ */
