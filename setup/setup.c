#include "../include/setup.h"
#include "../include/files.h"
#include "../include/urls.h"

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf("NOTE: Please run this with `-Sc` to clean temp folder if it is not removed normally!\n");

    int UsrDefined = 0;
    char Path[4096];
    char Tmp[4096];

    printf("Preparing for install...\n");

    if (chdir("/tmp") != 0)
    {
        perror("Could not change directory to `/tmp`");

        printf("Already running as `sudo`? Specify a temp path manually or type `q` to quit: ");
        scanf("%s", Tmp);

        if (strcasecmp(Tmp, "q") == 0)
            exit(1);

        UsrDefined = 1;

        if (chdir(Tmp) != 0)
        {
            printf("Could not change directory to `%s`\n", Tmp);
            perror("Unexpected exception");
            exit(1);
        }
    }

    if (UsrDefined)
    {
        snprintf(Path, sizeof(Path), "%s/%s", Tmp, SETUP_TMP);
        RmDir(Path);
        MkDir(SETUP_TMP, Tmp);
    }

    else
    {
        snprintf(Path, sizeof(Path), "/tmp/%s", SETUP_TMP);
        RmDir(Path);
        MkDir(SETUP_TMP, "/tmp");
    }

    if (chdir(Path) != 0)
    {
        printf("Could not change directory to `%s`\n", Path);
        perror("Unexpected exception");
        exit(1);
    }

    if (system("pacman -Q curl") != 0) // curl always checked
    {
        printf("Installing `curl`...\n");
        system("sudo pacman -S curl");
    }

    MkDir("conf", Path);

    if (chdir("conf") != 0)
    {
        perror("Could not change directory to `conf`");
        exit(1);
    }

    Curl(PACKAGE_INI, PACKAGES);

    chdir("..");

    char FullPath[8192];
    snprintf(FullPath, sizeof(FullPath), "%s/conf", Path);

    Translate(PACKAGES, FullPath);

    int Ret = CheckInstalled(FormatField(PACKAGE_RAW, FullPath, 1), Path);

    if (Ret != 0)
    {
        printf("Some dependencies are not installed...\n");

        InstallPackages(FormatField(PACKAGE_RAW, FullPath, 0), Path);
    }

    else
        printf("All dependencies met!\n");

    RmDir(Path);
    return 0;
}

