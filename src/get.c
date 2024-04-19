#include "../include/common.h"
#include "../lib/gethome.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void Get(const char* Pkg)
{
    char* Path = gethome();
    chdir(Path);

    if (chdir(MMGR) != 0)
    {
        printf("Error changing directory\n");
        exit(1);
    }

    FILE* Indexfile;
    FILE* Linksfile;

    Indexfile = fopen(INDEX, "r");
    Linksfile = fopen(LINKS, "r");

    int LinePosition = 1;
    int Found = 0;
    int i = 1;

    char* Link = (char*)malloc(MAX_BUF);

    while (fgets(Link, MAX_BUF, Indexfile))
    {
        Link[strcspn(Link, "\n")] = '\0';

        if (!strcasecmp(Link, Pkg))
        {
            Found = 1;
            break;
        }
    }

    if (Found == 0)
    {
        printf("No package with that name\n");
        exit(1);
    }

    rewind(Indexfile);
    while (fgets(Link, MAX_BUF, Indexfile))
    {
        Link[strcspn(Link, "\n")] = '\0';

        if (!strcmp(Link, Pkg))
            break;

        i++;
    }

    rewind(Linksfile);
    while (fgets(Link, MAX_BUF, Linksfile) && LinePosition < i)
    {
        Link[strcspn(Link, "\n")] = '\0';
        LinePosition++;
    }

    fclose(Indexfile);
    fclose(Linksfile);

    char WgetCmd[MAX_SIZ];

    snprintf(WgetCmd, sizeof(WgetCmd), "wget %s", Link);

    Wget(WgetCmd);
}

