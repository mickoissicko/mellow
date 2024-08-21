#include "../lib/gethome/gethome.h"
#include "../include/imports.h"

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void Clear(void)
{
    while (getchar() != '\n');
}

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
            printf("ic: Error changing directory");
            exit(1);
        }

        else if (chdir(".mix") != 0)
            MkDirs(),
            MkTmp();

        chdir("mellow");
        chdir(".tmp");

        char PATH[8192];
        snprintf(PATH, sizeof(PATH), "%s/.mix/mellow/.tmp", Home);

        int PkgExists = FindExistingPkg(argv[2], PATH);

        if (PkgExists)
        {
            char Ui;

            printf("Rebuild '%s' from scratch? [y/n]: ", argv[2]);
            scanf("%c", &Ui);

            if (Ui == 'y' || Ui == 'Y')
                DelTmp(),
                MkTmp();
        }

        int Ui;

        GetPackage(argv[2]);
        BuildPackage(argv[2], PATH);

        printf("Remove Make dependencies? [y/n]: ");

        if (PkgExists)
        {
            Clear();
            Ui = getchar();
        }

        else
            scanf("%c", &Ui);

        if (Ui == 'y' || Ui == 'Y')
            RemoveDeps(argv[2], PATH);
    }

    return 0;
}

