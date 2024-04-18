#include "../include/common.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc < 2)
        Help();

    printf("Loading...\n");

    if (
        !strcmp(argv[1], "/aur")
    ){
        if (argv[2] == NULL)
        {
            printf("You need to supply software name\n");
            exit(1);
        }

        char* Command;
        unsigned long Buf = {MAX_BUF};

        snprintf(Command, Buf, "");
    }

    else if (
        !strcmp(argv[1], "/install")
    ){
        printf("Downloading scripts...\n");
        printf("Installing...\n");
    }

    return 0;
}

