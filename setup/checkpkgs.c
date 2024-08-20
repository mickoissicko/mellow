#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define MAX_LINE_LENGTH 1024

char* FindPackages(char PackageList[], int LineCount, FILE* InstalledPackages)
{
    rewind(InstalledPackages);

    char* MissingPackageList = (char*)malloc(sizeof(char) * strlen(PackageList) + 1);
    char Line[MAX_LINE_LENGTH];

    int CurrentLine = 0;

    while (fgets(Line, sizeof(Line), InstalledPackages) != NULL)
    {
        char* LinePtr;

        if ((LinePtr = strchr(Line, ' ')) != NULL)
            *LinePtr = '\0';

        if (CurrentLine == LineCount)
        {
            strcpy(MissingPackageList, Line);
            return MissingPackageList;
        }

        CurrentLine++;
    }

    return MissingPackageList;
}

int CheckInstalled(char PackageList[], const char PATH[])
{
    if (chdir(PATH) != 0)
    {
        perror("Could not change directory");
        exit(1);
    }

    char Buffer[1024];
    snprintf(Buffer, sizeof(Buffer), "pacman -Q %s > pacman.txt", PackageList);

    if (system(Buffer) != 0)
        return 1;

    return 0;
}


