#include "../include/imports.h"

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const static char FILENAME[] = "results.txt";

void PrintFiles(const int INDEX, const char FILEPATH[])
{
    int Count = 1;

    char PkgName[2048];
    char* Desc;
    char* Pkg;
    char* Ver;

    while (Count != INDEX)
    {
        snprintf(PkgName, sizeof(PkgName), "pkg%d.txt", Count);

        Desc = GetData(1, PkgName, FILEPATH);
        Pkg  = GetData(3, PkgName, FILEPATH);
        Ver  = GetData(4, PkgName, FILEPATH);

        Desc[strcspn(Desc, "\n")] = '\0';
        Pkg[strcspn(Pkg, "\n")] = '\0';
        Ver[strcspn(Ver, "\n")] = '\0';

        RemoveQuotes(Desc);
        RemoveQuotes(Pkg);
        RemoveQuotes(Ver);

        printf("aur/%s %s\n", Pkg, Ver);
        printf("    %s\n\n", Desc);

        free(Desc);
        free(Ver);
        free(Pkg);
        Count++;
    }
}

void DisplayResults(const char FILEPATH[])
{
    StripNewlines(FILENAME, FILEPATH);

    if (chdir(FILEPATH) != 0)
    {
        perror("disp.c: Error changing directory");
        exit(1);
    }

    char f_User[8192];
    char f_Pkg[8192];
    char Buf[8192];
    char* Discard;

    FILE* Results;
    FILE* Txt;

    int CurrentLine = 1;
    int Index = 1;
    int Count = 1;

    Txt = fopen(FILENAME, "r");

    while (fgets(Discard, sizeof(Buf), Txt))
    {
        if (strstr(Discard, ",\n") != NULL)
        {
            SplitFiles(Index, CurrentLine);
            Index++;
        }

        CurrentLine++;
    }

    fclose(Txt);

    PrintFiles(Index, FILEPATH);
}

