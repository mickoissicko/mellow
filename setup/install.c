#include "../include/setup.h"

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define MAX_LINE_LENGTH 1024

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
    char* InstalledPackagesList = 0;

    FILE* Installed = fopen("pacman.txt", "r");

    for (int Cursor = getc(Installed); Cursor != EOF; Cursor = getc(Installed))
        if (Cursor == '\n')
        {
            char* InstalledPackages = FindPackages(PackageList, TotalLines, Installed);
            char* Temp = Append(InstalledPackages);

            if (InstalledPackagesList == NULL)
                InstalledPackagesList = Temp;

            else
                InstalledPackagesList = strcat(InstalledPackagesList, Temp);

            TotalLines++;
        }

    fclose(Installed);
    GetMissingPackages(PackageList, InstalledPackagesList);
}

