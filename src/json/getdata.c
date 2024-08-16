#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char* GetData(const int VAL, const char FILE_NAME[], const char FILE_PATH[])
{
    int Siz = 8192;
    int Index = 0;
 
    char* Ln = malloc(Siz * sizeof(char));
    FILE* Results;

    if (chdir(FILE_PATH) != 0)
    {
        perror("gd.c: Error changing directory");
        exit(1);
    }

    Results = fopen(FILE_NAME, "r");

    /////////////////////////////////////////////

    while (Index != 14)
    {
        fgetc(Results);
        Index++;
    } Index = 0;

    fgets(Ln, Siz, Results);

    if (VAL == 1)
    {
        fclose(Results);
        return Ln;
    }

    /////////////////////////////////////////////

    while (Index != 13)
    {
        fgetc(Results);
        Index++;
    } Index = 0;

    fgets(Ln, Siz, Results);

    if (VAL == 2)
    {
        fclose(Results);
        return Ln;
    }

    /////////////////////////////////////////////

    while (Index != 7)
    {
        fgetc(Results);
        Index++;
    } Index = 0;

    fgets(Ln, Siz, Results);

    if (VAL == 3)
    {
        fclose(Results);
        return Ln;
    }

    /////////////////////////////////////////////

    while (Index != 10)
    {
        fgetc(Results);
        Index++;
    } Index = 0;

    fgets(Ln, Siz, Results);

    if (VAL == 4)
    {
        fclose(Results);
        return Ln;
    }

    /////////////////////////////////////////////

    free(Ln);
    return "load.fail";
}

