#include "../common/common.h"
#include "../common/gethome.h"

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

void CreateTemp()
{
    system("mkdir ~/aur.gelper_tmp");
}

void DeleteTemp()
{
    system("rm -rf ~/aur.gelper_tmp");
}

char* GetTempPath()
{
    #ifdef _WIN32
        char* Path = Win32_Path();
    #else
        char* Path = Posix_Path();
    #endif

    unsigned long LEN = MAX_LEN;

    char Buf[MAX_LEN];
    char* TempPath;

    TempPath = (char*)malloc(MAX_LEN);

    #ifdef _WIN32
        snprintf(Buf, LEN, "%s\\mmgr.tmp", Path);
    #else
        snprintf(Buf, LEN, "%s/mmgr.tmp", Path);
    #endif

    strcpy(TempPath, Buf); // cant return array

    return TempPath;
}

