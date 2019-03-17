/*
* © Copyright Ulrich Krause. 2019
* 
* Licensed under the Apache License, Version 2.0 (the "License"); 
* you may not use this file except in compliance with the License. 
* You may obtain a copy of the License at:
* 
* http://www.apache.org/licenses/LICENSE-2.0 
* 
* Unless required by applicable law or agreed to in writing, software 
* distributed under the License is distributed on an "AS IS" BASIS, 
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or 
* implied. See the License for the specific language governing 
* permissions and limitations under the License.
*/
#ifndef SSO_TOKEN_DEFS
#define SSO_TOKEN_DEFS

#include <string.h>
#include <stdio.h>

#if defined (_MSC_VER) && !defined (ND64)
#pragma pack(push, 1)
#endif
#include "global.h"
#include "osfile.h"
#include "bsafe.h"
#include "osmisc.h"
#include "osmem.h"
#include "addin.h"
#if defined (_MSC_VER) && !defined (ND64)
#pragma pack(pop) 
#endif

#if defined(LINUX)
extern "C" {
#endif
STATUS LNPUBLIC CreateLtpaToken(char *servername,char *configname,char *orgname,char *username, char *ltpaToken, char *errorMessage);
#if defined(LINUX)
}
#endif

#endif