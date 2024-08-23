#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_LINE_LENGTH 1024

char* ReadFile(FILE* File, int Mode)
{
    char* Line = (char*)malloc(sizeof(char) * MAX_LINE_LENGTH);

    if (fgets(Line, MAX_LINE_LENGTH, File) != NULL)
    {
        if (Mode == 1)
        {
            Line[strcspn(Line, "\n")] = 0;
            return Line;
        }

        return Line;
    }

    return "read.fail";
}

