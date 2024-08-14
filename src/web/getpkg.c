#include "../../lib/gethome/gethome.h"
#include "../../include/imports.h"

#include <stdio.h>

void GetPackage(char* PackageName)
{
    char* Home = gethome();
    char Path[8192];
    char Buf[8192];

    if (chdir(Home) != 0)
    {
        perror("pkg.c: Error changing directory");
        exit(1);
    }

    else if (chdir(".mix") != 0 || chdir("mellow") != 0 || chdir(".tmp") != 0)
    {
        perror("m:pkg.c: Error changing directory");
        exit(1);
    }

    snprintf(Path, sizeof(Path), "%s/.mix/mellow/.tmp", Home);
    snprintf(Buf, sizeof(Buf), "https://aur.archlinux.org/%s.git", PackageName);

    int Err = Clone(Buf, Path);

    if (Err != 0)
    {
        if (Err == 1)
        {
            printf("No AUR Package found for '%s'\n", PackageName);
            printf("--> Quitting...\n");

            return;
        }

        else if (Err == 2)
        {
            printf("Error changing path\n");
            exit(1);
        }

        else if (Err == 3)
        {
            printf("No directory at '.mix/mellow/.tmp'\n");
            exit(1);
        }
    }
}

