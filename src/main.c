#include "../lib/gethome/gethome.h"
#include "../include/imports.h"

#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    MkDirs();

    if (argc < 2)
    {
        printf("Read the wiki @ mick.gdn/wiki/mellow for help\n");
        exit(1);
    }

    if (strcasecmp(argv[1], "-Ss") == 0 && argc > 2)
    {
        printf("Searching for '%s'...\n", argv[2]);

        char* Home = gethome();
        chdir(Home);

        MkTmp(Home);
        if(
            chdir(Home)          != 0 ||
            chdir(".mix/mellow") != 0 ||
            chdir(".tmp")        != 0
        ){
            perror("Error changing directory ");
            exit(1);
        }

        Scraper(argv[2]);
        PrettyPrinter();
        FiltreResults();
    }

    return 0;
}

