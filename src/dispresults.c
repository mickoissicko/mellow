#include "../include/imports.h"

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const static char FILE_NAME[] = "results.txt";

void PrintFiles(const int INDEX, const char FILE_PATH[])
{
    int Count = 1;

    char PkgName[2048];
    char* Desc;
    char* Pkg;
    char* Ver;

    while (Count != INDEX)
    {
        snprintf(PkgName, sizeof(PkgName), "pkg%d.txt", Count);

        Desc = GetData(1, PkgName, FILE_PATH);
        Pkg  = GetData(3, PkgName, FILE_PATH);
        Ver  = GetData(4, PkgName, FILE_PATH);

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

void DisplayResults(const char FILE_PATH[])
{
    StripNewlines(FILE_NAME, FILE_PATH);

    if (chdir(FILE_PATH) != 0)
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

    Txt = fopen(FILE_NAME, "r");

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

    PrintFiles(Index, FILE_PATH);
}

