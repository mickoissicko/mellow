#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void RemoveQuotes(char* String)
{
    char* Dest = String;

    while (*String != '\0')
    {
        if (*String != '"')
            *Dest++ = *String;

        String++;
    }

    *Dest = '\0';
}

void SplitText(void)
{
    FILE* Results = fopen("results.txt", "r");
    FILE* Temp    = fopen("tmp.txt", "w");

    char Buf[10000];

    while (fgets(Buf, sizeof(Buf), Results))
    {
        if (strstr(Buf, "\"FirstSubmitted\"") != NULL)
            for (char* Cursor = Buf; *Cursor; Cursor++)
                if (*Cursor == ',')
                    *Cursor = '\n';

        fprintf(Temp, "%s", Buf);
    }

    fclose(Results);
    fclose(Temp);
}

void FiltreResults(void)
{
    char* FiltredStr;
    FILE* R_Results;
    FILE* W_Results;
    char* Ln = NULL;
    size_t Siz = 0;
    char* Start;
    char Chars;
    char* End;

    SplitText();

    W_Results = fopen("results.txt", "w");
    R_Results = fopen("tmp.txt", "r");
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

    remove("tmp.txt");
}

