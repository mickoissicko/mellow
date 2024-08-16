#include "../../include/imports.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_PKG_LEN 1024

void UninstallDeps(char Deps[], const char PATH[])
{
    char PkgName[MAX_PKG_LEN];
    char* Depends = Deps;

    if (chdir(PATH) != 0)
    {
        perror("rn.c: Error changing directory");
        exit(1);
    }

    while (1)
    {
        char* Double = strstr(Depends, "\"");
        char* Single = strstr(Depends, "'");

        if (Double == NULL && Single == NULL)  
            break;

        char* DoubleEnd = NULL;
        char* SingleEnd = NULL;

        if (Double != NULL)
            DoubleEnd = strstr(Double + 1, "\"");

        if (Single != NULL)
            SingleEnd = strstr(Single + 1, "'");

        if (DoubleEnd == NULL && SingleEnd == NULL)
            break;

        if (Double != NULL && DoubleEnd != NULL && (Single == NULL || Double < Single))
        {
            size_t Length = DoubleEnd - Double - 1;

            if (Length >= MAX_PKG_LEN)
                Length = MAX_PKG_LEN - 1;

            strncpy(PkgName, Double + 1, Length);
            PkgName[Length] = '\0';

            RemovePkgs(PkgName);
            Depends = DoubleEnd + 1;
        }

        else if (Single != NULL && SingleEnd != NULL)
        {
            size_t Length = SingleEnd - Single - 1;

            if (Length >= MAX_PKG_LEN)
                Length = MAX_PKG_LEN - 1;

            strncpy(PkgName, Single + 1, Length);
            PkgName[Length] = '\0';

            RemovePkgs(PkgName);
            Depends = SingleEnd + 1;
        }
    }
}
