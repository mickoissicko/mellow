#include "../lib/gethome/gethome.h"
#include "../include/setup.h"

#include <strings.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

const char SETUP_TMP[] = "mellow";

int main()
{
    int UsrDefined = 0;
    char Tmp[4096];

    printf("Preparing for install...\n");

    if (chdir("/tmp") != 0)
    {
        perror("Could not change directory to `/tmp`");

        printf("Already running as `sudo`? Specify a temp path manually or type `q` to quit: ");
        scanf("%s", Tmp);

        if (strcasecmp(Tmp, "q") == 0)
            exit(1);

        else
            UsrDefined = 1;

        if (chdir(Tmp) != 0)
        {
            printf("Could not change directory to `%s`\n", Tmp);
            perror("Unexpected exception");
            exit(1);
        }
    }

    if (UsrDefined)
        MkDir(SETUP_TMP, Tmp);

    else
        MkDir(SETUP_TMP, "/tmp");

    if (chdir(SETUP_TMP) != 0)
    {
        perror("Error creating folder or moving to folder");
        exit(1);
    }

    if (system("pacman -Q curl") != 0) // curl always checked
    {
        printf("Installing `curl`...\n");
        system("sudo pacman -S curl");
    }

    

    return 0;
}

