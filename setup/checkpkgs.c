#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
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

    printf("%s\n", MissingPackageList);
    return MissingPackageList;
}

int CheckInstalled(char PackageList[], const char PATH[])
{
    int Missing = 0;

    if (chdir(PATH) != 0)
    {
        perror("Could not change directory");
        exit(1);
    }

    char Buffer[1024];
    snprintf(Buffer, sizeof(Buffer), "pacman -Q %s", PackageList);

    int Results = open("pacman.txt", O_CREAT | O_WRONLY, S_IRWXU | S_IRWXG);
    int StdOut = dup(STDOUT_FILENO);

    dup2(Results, STDOUT_FILENO);
    close(Results);

    if (system(Buffer) != 0)
        Missing = 1;

    dup2(StdOut, STDOUT_FILENO);
    close(StdOut);

    if (!Missing)
        return 0;

    return 1;
}

