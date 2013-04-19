// @@@LICENSE
//
// Copyright (c) 2007-2012 Hewlett-Packard Development Company, L.P.
// Copyright (c) 2013 LG Electronics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// LICENSE@@@


/**
* @brief  This header file specifies the private interface to PmLogLib
*
* @file PmLogLibPrv.h
* <hr>
**/

#ifndef PMLOGLIBPRV_H
#define PMLOGLIBPRV_H


#include "PmLogLib.h"


#ifdef __cplusplus
extern "C"
{
#endif


// For now put the public context info at the top of the struct so the
// pointers are the same. If that is changed, revise PmLogGetContext and
// PrvResolveContextaccordingly.
typedef struct
{
	PmLogContextInfo	info;
	char				component[ PMLOG_MAX_CONTEXT_NAME_LEN + 1 ];
}
PmLogContext_;


// value for globals->signature.  If it does not match the
// expected value then the client must abort.
#define PMLOG_SIGNATURE			0x504C6702	// 'PLg' + 0x02


// Flag values for per context and global flags
enum
{
	kPmLogFlag_LogProcessIds = 0x0001,
	kPmLogFlag_LogThreadIds  = 0x0002,
	kPmLogFlag_LogToConsole  = 0x0004,
	kPmLogFlag_Overridden    = 0x0008  /* context flags differ from the global ones */
};


// settings to control std output
typedef struct
{
	int	stdErrMinLevel;
	int	stdErrMaxLevel;
	int	stdOutMinLevel;
	int	stdOutMaxLevel;
}
PmLogConsole;


// This is the globals data structure that is allocated as a shared
// memory segment.  The size should be kept reasonable, e.g. < 16K. 
typedef struct
{
	uint32_t        signature;
	int             reserved;
	int             maxUserContexts;
	int             numUserContexts;
	int             kvValidateFlag;

	PmLogConsole    consoleConf;

	PmLogContext_   globalContext;
	PmLogContext_   userContexts[ PMLOG_MAX_NUM_CONTEXTS ];
}
PmLogGlobals;


/*********************************************************************/
/* PmLogPrvGlobals */
/**
@brief  Returns the pointer to the globals.
**********************************************************************/
PmLogGlobals* PmLogPrvGlobals(void);


/*********************************************************************/
/* PmLogPrvLock */
/**
@brief  Acquires the semaphore for write access to the PmLog shared
		memory context.  This should be held as briefly as possible,
		then released by calling PmLogPrvUnlock.
**********************************************************************/
void PmLogPrvLock(void);


/*********************************************************************/
/* PmLogPrvUnlock */
/**
@brief  Releases the semaphore for write access to the PmLog shared
		memory context, as previously acquired via PmLogPrvLock.
**********************************************************************/
void PmLogPrvUnlock(void);


/*********************************************************************/
/* PmLogPrvTest */
/**
@brief  This is a private function to be used only by PmLog components
		for test and development purposes.
**********************************************************************/
PmLogErr PmLogPrvTest(const char* cmd, void* data);


/*********************************************************************/
/* PmLogPrvReadConfigs */
/**
@brief  Reads all the config files from @WEBOS_INSTALL_SYSCONFDIR@/pmlog.d
        directory and executes the supplied function on each of the config
        file. This API is only required for pmlogdaemon for reading config
        files.

@param  fn_ptr fn_ptr is a pointer to a function which acceptes a file_name
        as a constant string and returns a boolean. PmLogPrvReadConfigs() will
        call (*fn_ptr) function for each file obtained from the /etc/pmlog.d
        directory.
**********************************************************************/
bool PmLogPrvReadConfigs(bool (*fn_ptr)(const char *file_name));

#ifdef __cplusplus
}
#endif


#endif // PMLOGLIBPRV_H
