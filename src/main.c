#include "../lib/gethome/gethome.h"
#include "../include/imports.h"

#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    char* Home = gethome();
    MkDirs();

    if (argc < 2)
    {
        printf("Read the wiki @ mick.gdn/wiki/mellow for help\n");
        exit(1);
    }

     if (strcasecmp(argv[1], "-Ss") == 0 && argc > 2)
    {
        printf("Searching for '%s'...\n", argv[2]);

        char Buf[8192];
        MkTmp();

        if(
            chdir(Home)               != 0 ||
            chdir(".mix/mellow/.tmp") != 0
        ){
            perror("c: Error changing directory");
            exit(1);
        }

        snprintf(Buf, sizeof(Buf), "%s/.mix/mellow/.tmp", Home);

        Scraper(argv[2]);
        DisplayResults(Buf);
    }

    else if (strcasecmp(argv[1], "-Sc") == 0)
        DelTmp();

    else if (strcasecmp(argv[1], "-S") == 0)
    {
        if (argc <= 2)
        {
            printf("Insufficient arguments\n");
            exit(1);
        }

        if (chdir(Home) != 0)
        {
            printf("sc: Error changing directory");
            exit(1);
        }

        else if (chdir(".mix") != 0)
            MkDirs(),
            MkTmp();

        chdir(".mix");
        chdir("mellow");
        chdir(".tmp");

        char Buf[8192];
        snprintf(Buf, sizeof(Buf), "%s/.mix/mellow/.tmp", Home);

        Scraper(argv[2]);
        DisplayResults(Buf);
    }

    return 0;
}

