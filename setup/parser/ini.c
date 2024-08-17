#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE_LENGTH 8192

char* ParseIni(const char INI[], const char FULL_PATH[], const int MODE)
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
    {
        if (
            strstr(Line, "COMPILE = FALSE") != NULL ||
            strstr(Line, "COMPILE = TRUE")  != NULL
        ){
            Line[strcspn(Line, "\n")] = 0;

            if (MODE == 0)
                return Line;
        }

        if (strstr(Line, "FALLBACK_CXX") != NULL)
        {
            Line[strcspn(Line, "\n")] = 0;

            if (MODE == 1)
                return Line;
        }

        if (strstr(Line, "FALLBACK_C") != NULL)
        {
            Line[strcspn(Line, "\n")] = 0;

            if (MODE == 2)
                return Line;
        }

        if (strstr(Line, "CXX_STANDARD") != NULL)
        {
            Line[strcspn(Line, "\n")] = 0;

            if (MODE == 3)
                return Line;
        }

        if (strstr(Line, "C_COMPILER") != NULL)
        {
            Line[strcspn(Line, "\n")] = 0;

            if (MODE == 4)
                return Line;
        }

        if (strstr(Line, "CXX_COMPILER") != NULL)
        {
            Line[strcspn(Line, "\n")] = 0;

            if (MODE == 5)
                return Line;
        }

        if (
            strstr(Line, "FALLBACK_PATH") == NULL &&
            strstr(Line, "PATH")          != NULL
        ){
            Line[strcspn(Line, "\n")] = 0;

            if (MODE == 6)
                return Line;
        }

        if (
            strstr(Line, "FALLBACK_PATH") != NULL
        ){
            Line[strcspn(Line, "\n")] = 0;

            if (MODE == 7)
                return Line;
        }
    }

    fclose(IniCfg);
    return Line;
}

