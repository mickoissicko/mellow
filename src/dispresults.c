#include "../include/imports.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const char File[] = "results.txt";

void DisplayResults(const char FilePath[])
{
    if (chdir(FilePath) != 0)
    {
        perror("disp.c: Error changing directory\n");
        exit(1);
    }

    FILE* Results;
    size_t* Siz;
    char* Start;
    char* Ln;
    int Val;

    StripNewlines(File, FilePath);

    Results = fopen(File, "r");

    char* Desc = GetFileData(Val);
    char* Usr  = GetFileData(Val);
    char* Pkg  = GetFileData(Val);
    char* Ver  = GetFileData(Val);

    printf("%s\n", Desc);

    fclose(Results);
}

