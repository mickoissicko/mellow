#include "../../include/setup.h"

#include <stdio.h>

void GetMissingPackages(char PackageList[], char InstalledPackageList[])
{
    Replace(PackageList, ',');

    printf("%s\n%s\n", PackageList, InstalledPackageList);
}

