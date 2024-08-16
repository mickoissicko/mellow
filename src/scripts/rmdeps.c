#include "../../include/imports.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void RemoveDeps(char PackageName[], const char PATH[])
{
    if (chdir(PATH) != 0)
    {
        perror("rmd.c: Error changing directory");
        exit(1);
    }

    char GitBuf[8192];
    char Deps[8192];
    char Line[8192];
    char Buf[8192];

    snprintf(Buf, sizeof(Buf), "%s/%s", PATH, PackageName);

    if (chdir(Buf) != 0)
    {
        snprintf(GitBuf, sizeof(GitBuf), "%s/%s.git", PATH, PackageName);

        if (chdir(GitBuf) != 0)
        {
            perror("2:rmd.c: Error finding package");
            exit(1);
        }
    }

    int FoundDepends = 0;
    FILE* BuildFile;

    BuildFile = fopen("PKGBUILD", "r");

    while (fgets(Line, 8192, BuildFile) != NULL)
    {
        if (strstr(Line, "makedepends") != NULL)
        {
            FoundDepends = 1;

            size_t Len = strlen(Line);

            if (Len > 0 && Line[Len - 1] == '\n')
                Line[Len - 1] = '\0';

            strcpy(Deps, Line);
            memset(Line, 0, sizeof(Line));

            break;
        }

        if (!FoundDepends)
        {
            if (fgets(Line, sizeof(Line), BuildFile) == NULL)
            {
                printf("No Make dependencies to remove\n");
                return;
            }
        }
    }

    fclose(BuildFile);
    UninstallDeps(Deps, Buf);
}

