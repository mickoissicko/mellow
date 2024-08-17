#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../include/setup.h"

void InstallPackages(const char PACKAGE_LIST[], const char PATH[])
{
    char* PackageList = (char*)malloc(sizeof(char) * strlen(PACKAGE_LIST) + 1);
    strcpy(PackageList, PACKAGE_LIST);

    printf("Checking for installed packages...\n");

    if (CheckInstalled(PackageList, PATH) == 0)
    {
        printf("All dependencies met!\n");
        return;
    }

    printf("Installing packages...\n");

    char* MissingPackages = FindPackages(PackageList);

    printf("%s\n", MissingPackages);
}

