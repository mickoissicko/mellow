#include "../../include/setup.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void Translate(const char GLOBAL[], const char USER[], const char FULL_PATH[])
{
    printf("Translating ...\n");

    char* FallbackPath;
    char* CppStandard;
    char* CppFallback;
    char* CppCompiler;
    char* CFallback;
    char* CCompiler;
    char* HomePath;
    char* Compile;

    int Mode = 0; // 0
    Compile = ParseIni(GLOBAL, FULL_PATH, Mode);

    Mode += 1; // 1
    CppFallback = ParseIni(GLOBAL, FULL_PATH, Mode);

    Mode += 1; // 2
    CFallback = ParseIni(GLOBAL, FULL_PATH, Mode);

    Mode += 1; // 3
    CppStandard = ParseIni(GLOBAL, FULL_PATH, Mode);

    Mode += 1; // 4
    CCompiler = ParseIni(GLOBAL, FULL_PATH, Mode);

    Mode += 1; // 5
    CppCompiler = ParseIni(GLOBAL, FULL_PATH, Mode);

    Mode += 1; // 6
    HomePath = ParseIni(GLOBAL, FULL_PATH, Mode);

    Mode += 1; // 7
    FallbackPath = ParseIni(GLOBAL, FULL_PATH, Mode);

    if (chdir(FULL_PATH) != 0)
    {
        perror("Could not change directory");
        exit(1);
    }
}

