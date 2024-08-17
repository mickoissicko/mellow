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

    char CppStandard[1024];
    char CppFallback[1024];
    char CppCompiler[1024];
    char CFallback[1024];
    char CCompiler[1024];
    char Compile[1024];
    char Line[2048];

    while(fgets(Line, sizeof(Line), IniCfg) != NULL)
    {
        if (
            strstr(Line, "COMPILE = FALSE") != NULL ||
            strstr(Line, "COMPILE = TRUE")  != NULL
        ){
            Line[strcspn(Line, "\n")] = 0;
            strcpy(Compile, Line);
        }

        if (strstr(Line, "FALLBACK_CXX") != NULL)
        {
            Line[strcspn(Line, "\n")] = 0;
            strcpy(CppFallback, Line);
        }

        if (strstr(Line, "FALLBACK_C") != NULL)
        {
            Line[strcspn(Line, "\n")] = 0;
            strcpy(CFallback, Line);
        }

        if (strstr(Line, "CXX_STANDARD") != NULL)
        {
            Line[strcspn(Line, "\n")] = 0;
            strcpy(CppStandard, Line);
        }

        if (strstr(Line, "C_COMPILER") != NULL)
        {
            Line[strcspn(Line, "\n")] = 0;
            strcpy(CCompiler, Line);
        }

        if (strstr(Line, "CXX_COMPILER") != NULL)
        {
            Line[strcspn(Line, "\n")] = 0;
            strcpy(CppCompiler, Line);
        }
    }

    fclose(IniCfg);

    printf("%s\n", Compile);
    printf("%s\n", CppFallback);
    printf("%s\n", CFallback);
    printf("%s\n", CppStandard);
    printf("%s\n", CppCompiler);
    printf("%s\n", CCompiler);

    return 0;
}

