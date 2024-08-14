#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void BuildPackage(char* PackageName, const char* PATH)
{
    if (chdir(PATH) != 0)
    {
        perror("build.c: Error changing directory");
        exit(1);
    }

    else if (chdir(PackageName) != 0)
    {
        char Buf[8192];
        snprintf(Buf, sizeof(Buf), "%s.git", PackageName);

        if (chdir(Buf) != 0)
        {
            perror("2:build.c: Error changing directory");
            exit(1);
        }
    }

    printf("Building...\n");

    if (system("makepkg -si") != 0)
    {
        perror("3:build.c: Error while making package\n");
        exit(1);
    }
}

