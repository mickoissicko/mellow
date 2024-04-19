#include "../../include/common.h"
#include "../../include/links.h"
#include "../../lib/gethome.h"

#include <stdio.h>

void Init()
{
    char* Path = gethome();
    chdir(Path);

    if (chdir(MIX) != 0 || chdir(MMGR) != 0)
    {
        printf("There was an error\n");
        printf("Try running '/setup' first\n");

        exit(1);
    }

    FILE* Index;
    FILE* Links;

    Index = fopen(INDEX, "r");
    Links = fopen(LINKS, "r");

    if (Index != NULL || Links != NULL)
    {
        printf("Already initialised\n");
        printf("Run '/sync' if you wanted to update\n");

        exit(0);
    }

    Wget(INDEX_MSX);
    Wget(LINKS_MSX);

    free(Path);
}

