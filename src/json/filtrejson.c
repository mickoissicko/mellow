#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const static char Name[] = "results.txt";

static void FiltreResults()
{
    char* FiltredStr;
    FILE* R_Results;
    FILE* W_Results;
    char* Ln = NULL;
    size_t Siz = 0;
    char* Start;
    char Chars;
    char* End;

    W_Results = fopen(".new.results.txt", "w");
    R_Results = fopen("results.txt", "r");
    while (getc(R_Results) != EOF)
        Siz += 1;

    rewind(R_Results);
    Siz += 1024; // extra size just in case

    while (getline(&Ln, &Siz, R_Results) && !(feof(R_Results)))
    {
        if (
            (Start = strstr(Ln, "\"FirstSubmitted\"")) != NULL ||
            (Start = strstr(Ln, "\"ID\""))             != NULL ||
            (Start = strstr(Ln, "\"LastModified\""))   != NULL ||
            (Start = strstr(Ln, "\"resultcount\""))    != NULL ||
            (Start = strstr(Ln, "\"NumVotes\""))       != NULL ||
            (Start = strstr(Ln, "\"OutOfDate\""))      != NULL ||
            (Start = strstr(Ln, "\"PackageBase\""))    != NULL ||
            (Start = strstr(Ln, "\"PackageBaseID\""))  != NULL ||
            (Start = strstr(Ln, "\"Popularity\""))     != NULL ||
            (Start = strstr(Ln, "\"URL\""))            != NULL ||
            (Start = strstr(Ln, "\"URLPath\""))        != NULL ||
            (Start = strstr(Ln, "\"type\""))           != NULL
        )
            End = strchr(Start, '\n'),
            memmove(Start, End, strlen(End) + 1);

        fprintf(W_Results, "%s", Ln);
    }

    fclose(R_Results);
    fclose(W_Results);
    free(Ln);

    remove("results.txt");
    rename(".new.results.txt", "results.txt");
}

