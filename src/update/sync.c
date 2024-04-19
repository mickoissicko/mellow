#include "../../include/common.h"
#include "../../include/links.h"
#include "../../lib/gethome.h"

#include <stdlib.h>
#include <stdio.h>

void Sync()
{
    FILE* Lock;

    Lock = fopen(LOCKFILE, "r");

    if (Lock == NULL)
    {
        printf("Run '/setup' first!\n");
        exit(1);
    }

    char* Path = gethome();
    chdir(Path);

    FILE* Index;
    FILE* Links;

    Index = fopen(INDEX, "r");
    Links = fopen(LINKS, "r");

    if (Index != NULL)
    {
        fclose(Index);
        remove(INDEX);
    }

    else if (Links != NULL)
    {
        fclose(Links);
        remove(LINKS);
    }

    Wget(INDEX_MSX);
    Wget(LINKS_MSX);

    free(Path);
}

