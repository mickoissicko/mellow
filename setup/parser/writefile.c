#include <stdio.h>

void WriteFile(FILE* File, char Line[])
{
    fprintf(File, "%s\n", Line);
}

