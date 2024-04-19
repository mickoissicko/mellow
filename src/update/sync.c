#include "../../include/common.h"
#include "../../include/links.h"
#include "../../lib/gethome.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void Sync()
{
    char* Path = gethome();
    chdir(Path);

    if (chdir(MMGR) != 0)
    {
        printf("There was an error\n");
        printf("Try running '/setup' first\n");

        exit(1);
    }

    FILE* Lock;

    Lock = fopen(LOCKFILE, "r");

    if (Lock == NULL)
    {
        printf("Run '/setup' first!\n");
        exit(1);
    }

    FILE* Index;
    FILE* Links;

    Index = fopen(INDEX, "r");
    Links = fopen(LINKS, "r");

    if (Index != NULL)
    {
        fclose(Index);
        remove(INDEX);
    }

    if (Links != NULL)
    {
        fclose(Links);
        remove(LINKS);
    }

    Wget(INDEX_MSX);
    Wget(LINKS_MSX);

    free(Path);
}

