#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int ParseIni(const char INI[], const char FULL_PATH[])
{
    if (chdir(FULL_PATH) != 0)
    {
        printf("Error changing directory to `%s`\n", FULL_PATH);
        perror("An error occurred");
        return 1;
    }

    FILE* IniCfg = fopen(INI, "r");

    // TODO: get value of each field from both cfgs

    fclose(IniCfg);

    return 0;
}

