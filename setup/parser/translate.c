#include "../../include/setup.h"
#include "../../include/files.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void Translate(const char PACKAGES[], const char FULL_PATH[])
{
    printf("Translating ...\n");
    printf("Applying your settings...\n");

    if (chdir(FULL_PATH) != 0)
    {
        perror("Could not change directory");
        exit(1);
    }

    FILE* PkgIndex = fopen(PACKAGE_RAW, "w");
    WriteFile(PkgIndex, ParseIni(PACKAGES, FULL_PATH));
    fclose(PkgIndex);
}

