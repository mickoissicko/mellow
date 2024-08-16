#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void SplitFiles(const int INDEX, const int START_LINE)
{
    int CurrentLine = 1;
    int LineCount = 0;
    char* Lines[8192];
    char Line[8192];
    char Buf[8192];
    int StartIndex;

    FILE* Tracker;
    FILE* Output;
    FILE* Input;

    snprintf(Buf, sizeof(Buf), "pkg%d.txt", INDEX);

    Output = fopen(Buf, "w");
    Input = fopen("results.txt", "r");

    while (CurrentLine != START_LINE)
    {
        if (fgets(Line, sizeof(Line), Input))
        {
            if (LineCount < 8192)
            {
                Lines[LineCount] = strdup(Line);
                LineCount++;
            }
        }

        CurrentLine++;
    }

    if (LineCount > 4)
        StartIndex = LineCount - 4;

    else
        StartIndex = 0;

    for (int Count = StartIndex; Count < LineCount; Count++)
    {
        fprintf(Output, "%s", Lines[Count]);
        free(Lines[Count]);
    }

    fprintf(Output, "\n");
    fclose(Output);
    fclose(Input);

    Tracker = fopen("trackfile.txt", "w");
    fprintf(Tracker, "%d\n", INDEX);
    fclose(Tracker);
}

