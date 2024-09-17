#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE_LENGTH 8192

char* ParseIni(const char INI[], const char FULL_PATH[])
{
    if (chdir(FULL_PATH) != 0)
    {
        printf("Error changing directory to `%s`\n", FULL_PATH);
        perror("An error occurred");
        exit(1);
    }

    char* Line = (char*)malloc(sizeof(char) * 8192);
    FILE* IniCfg = fopen(INI, "r");

    while(fgets(Line, MAX_LINE_LENGTH, IniCfg) != NULL)
        if (strstr(Line, "REQUIRED") != NULL)
        {
            Line[strcspn(Line, "\n")] = 0;

            return Line;
        }

    fclose(IniCfg);
    return 0;
}

