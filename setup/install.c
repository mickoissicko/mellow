#include "../include/setup.h"

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define MAX_PACKAGE_LENGTH 1024
#define MAX_PACKAGE_COUNT 10

void InstallMissingPackages(char PackageList[], char InstalledPackages[], int Index)
{
    char* FixedSpace = Append(InstalledPackages);
    char* MissingPackages[MAX_PACKAGE_COUNT];

    int Delim = ' ';

    MissingPackages[Index] = NULL;

    char* Start = FixedSpace;
    char* End = strchr(FixedSpace, Delim);

    if (End == NULL)
        MissingPackages[Index] = FixedSpace;

    else if (Start == End)
        MissingPackages[Index] = End + 1;

    else
    {
        int Length = End - Start;

        MissingPackages[Index] = strndup(Start, Length);
    }

    // TODO: Check if substring MissingPackages[Index] exists in PackageList
    // To do this, check for MissingPackages[Index] against PackageList each
    // Then add the ones not found to makepkg

    printf("%s\n", MissingPackages[Index]);
}

void InstallPackages(const char PACKAGE_LIST[], const char PATH[])
{
    if (chdir(PATH) != 0)
    {
        perror("Could not change directory");
        exit(1);
    }

    char* PackageList = (char*)malloc(sizeof(char) * strlen(PACKAGE_LIST) + 1024);
    strcpy(PackageList, PACKAGE_LIST);

    printf("Installing packages...\n");

    int TotalLines = 0;
    FILE* Installed = fopen("pacman.txt", "r");

    for (int Cursor = getc(Installed); Cursor != EOF; Cursor = getc(Installed))
        if (Cursor == '\n')
        {
            char* InstalledPackages = FindPackages(PackageList, TotalLines, Installed);
            InstallMissingPackages(PackageList, InstalledPackages, TotalLines);

            TotalLines++;
        }

    fclose(Installed);
}

