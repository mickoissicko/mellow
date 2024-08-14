#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void RemoveDeps(char PackageName[], const char PATH[])
{
    if (chdir(PATH) != 0)
    {
        perror("rmd.c: Error changing directory");
        exit(1);
    }

    char GitBuf[8192];
    char Buf[8192];

    snprintf(Buf, sizeof(Buf), "%s/%s", PATH, PackageName);

    if (chdir(Buf) != 0)
    {
        snprintf(GitBuf, sizeof(GitBuf), "%s/%s.git", PATH, PackageName);

        if (chdir(GitBuf) != 0)
        {
            perror("2:rmd.c: Error finding package");
            exit(1);
        }
    }

    FILE* BuildFile;

    BuildFile = fopen("PKGBUILD", "r");

    //

    fclose(BuildFile);
}

