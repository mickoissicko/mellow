#include "../../include/setup.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

const char GLOBAL_RAW[] = "global.raw";
const char USER_RAW[] = "usr.raw";

void Translate(const char GLOBAL[], const char USER[], const char FULL_PATH[])
{
    printf("Translating ...\n");

    if (chdir(FULL_PATH) != 0)
    {
        perror("Could not change directory");
        exit(1);
    }

    FILE* Global = fopen(GLOBAL_RAW, "w");
    FILE* User = fopen(USER_RAW, "w");

    int WriteGlobal = 1;

    for (int Mode = 0; Mode < 9; Mode++)
    {
        if (Mode != 7 && WriteGlobal)
            WriteFile(Global, ParseIni(GLOBAL, FULL_PATH, Mode));

        else
        {
            WriteFile(User, ParseIni(USER, FULL_PATH, Mode));
            WriteGlobal = 0;
        }
    }

    fclose(Global);
    fclose(User);
}

