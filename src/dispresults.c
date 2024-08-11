#include "../include/imports.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

const char File[] = "results.txt";

void DisplayResults(const char FilePath[])
{
    if (chdir(FilePath) != 0)
    {
        perror("disp.c: Error changing directory\n");
        exit(1);
    }

    FormatFile(File, FilePath);


}

