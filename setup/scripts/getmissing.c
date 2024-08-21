#include "../../include/setup.h"

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char** MakeArray(char* String, int* Count)
{
    char* Token = strtok(String, " ");
    char** Result = NULL;

    int Spaces = 0;

    while (Token)
    {
        Result = realloc(Result, sizeof(char*) * ++Spaces);

        Result[Spaces - 1] = Token;
        Token = strtok(NULL, " ");
    }

    *Count = Spaces;
    return Result;
}

int CheckArray(char* Element, char** Array, int Count)
{
    for (int Index = 0; Index < Count; Index++)
        if (strcmp(Element, Array[Index]) == 0)
            return 1;

    return 0;
}

void MakeInstallationList(char PackageList[], char InstalledPackageList[], const char PATH[])
{
    if (chdir(PATH) != 0)
    {
        perror("Could not change directory");
        exit(1);
    }

    Replace(PackageList, ',');

    int InstalledIndex = 0;
    int DepsIndex = 0;

    char** InstalledArray = MakeArray(InstalledPackageList, &InstalledIndex);
    char** PackageArray = MakeArray(PackageList, &DepsIndex);

    FILE* InstallationList = fopen("install.txt", "w");

    for (int Index = 0; Index < DepsIndex; Index++)
        if (!CheckArray(PackageArray[Index], InstalledArray, InstalledIndex))
            WriteFile(InstallationList, PackageArray[Index]);

    fclose(InstallationList);
}

