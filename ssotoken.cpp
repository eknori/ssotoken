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
#include "ssotoken.h"

#if defined(LINUX)
extern "C" {
#endif

 STATUS LNPUBLIC CreateLtpaToken(char *servername,char *configname,char *orgname,char *username, char *ltpaToken, char *errorMessage)
	{

	STATUS errorStatus = NOERROR;
	char notesError[255];
	MEMHANDLE mhToken;

	if (errorStatus = NotesInit()) {

		OSLoadString(NULLHANDLE, ERR(errorStatus), notesError, 255);
		printf("%s\n", notesError);
		strcpy(errorMessage, notesError);
		
		return errorStatus;
		}

	errorStatus = SECTokenGenerate(servername, orgname, configname, username, NULL, NULL, &mhToken, (DWORD)0, (void *)NULL);
	
	if(errorStatus != NOERROR) {

		OSLoadString(NULLHANDLE, ERR(errorStatus), notesError, 255);
		printf("%s\n", notesError);
		strcpy(errorMessage, notesError);

		NotesTerm();

		return errorStatus;

		} else {
			SSO_TOKEN *ssoToken = (SSO_TOKEN*)OSMemoryLock(mhToken);
			char *pData = (char*)OSMemoryLock(ssoToken->mhData);
			strcpy(ltpaToken, pData);
			SECTokenFree(&mhToken);
		}

		OSLoadString(NULLHANDLE, ERR(errorStatus), notesError, 255);
		printf("%s\n", notesError);
		strcpy(errorMessage, notesError);

	NotesTerm();

	return errorStatus;

	}
#if defined(LINUX)
}
#endif
