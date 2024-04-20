#include "../../include/scripts/wget.h"
#include "../../include/common.h"
#include "../../include/links.h"
#include "../../lib/gethome.h"

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_CMD_LEN 2048
#define MAX_ARGS 256

void VerifyInstallation()
{
    const char* PATH = gethome();

    printf("Checking requirements...\n");

    FILE* lock;
    lock = fopen("lock.pa", "r");

    if (lock == NULL)
    {
        printf("Run /setup first!\n");
        exit(1);
    }

    else
        fclose(lock);

    FILE* wgetsh;
    FILE* wgetbat;

    #ifdef _WIN32
        wgetbat = fopen("wget.bat", "r");

        if (wgetbat == NULL)
        {
            wgetbat = fopen("wget.bat", "w");

            fprintf(wgetbat, "%s\n", WgetBat);
            fclose(wgetbat);

            system("wget.bat");
        }

        else
        {
            fclose(wgetbat);
            system("wget.bat");
        }
    #else
        wgetsh = fopen("wget.sh", "r");

        if (wgetsh == NULL)
        {
            wgetsh = fopen("wget.sh", "w");

            fprintf(wgetsh, "%s\n", WgetSh);
            fclose(wgetsh);

            system("chmod +x wget.sh");
            system("./wget.sh");
        }

        else
        {
            fclose(wgetsh);

            system("chmod +x wget.sh");
            system("./wget.sh");
        }
    #endif

    printf("Attempting to fetch scripts...\n");
    printf("If fetching fails, you will need to manually install wget\n");
    printf("If it is installed, make sure you can run it via typing 'wget' in the terminal\n");

    sleep(2);

    char Cmd[MAX_CMD_LEN];

    // double check
    chdir(PATH);
    chdir(MMGR);

    #ifdef _WIN32
        FILE* getgit;
        getgit = fopen("getgit.bat", "r");

        if (getgit != NULL)
        {
            fclose(getgit);
            remove("getgit.bat");
        }

        Wget(GET_GIT_BAT);
    #else
        FILE* getgit;
        getgit = fopen("getgit.sh", "r");

        if (getgit != NULL)
        {
            fclose(getgit);
            remove("getgit.sh");
        }

        Wget(GET_GIT_SH);
    #endif

    printf("Checking git...\n");
    ScriptRunner("getgit");

    printf("Verifying...\n");

    FILE* aursucess;
    aursucess = fopen("lock.aur.pa", "w");

    if (aursucess == NULL)
    {
        printf("Error creating file.");
        printf("Manually create lock.aur.pa\n");
    }

    else
        fclose(aursucess);
}

void AURHelper(char** Repo)
{
    if (!strcmp(Repo[2], "--reset"))
    {
        CleanAURFolder();
        exit(0);
    }

    const char* PATH = gethome();
    chdir(PATH);

    if (chdir(MMGR) != 0)
    {
        printf("Error changing directory\n");
        printf("Make sure to confirm if MMGR installed correctly\n");

        exit(1);
    }

    FILE* readlock;
    readlock = fopen("lock.aur.pa", "r");

    if (readlock == NULL)
        VerifyInstallation();

    else
        fclose(readlock);

    printf("Initialising...\n");

    if (
        !strcmp(Repo[1], "/aur") &&
        !!strcmp(Repo[2], "--rebuild")
    ){
        MakeAURFolder();

        if (chdir(AUR_PATH) != 0)
        {
            printf("Error creating directory\n");
            printf("Try manually creating\n");

            exit(1);
        }

        int FlagTwoExists = 0;

        if (!!strcmp(Repo[2], "--nc")) // if flag doesn't exist
        {
            CleanAURFolder();
            MakeAURFolder();

            FlagTwoExists = 1;
        }

        chdir(AUR_PATH);

        if (FlagTwoExists == 0)
            for (int i = 3; Repo[i] != NULL;)
            {
                Git(Repo[i], "clone");

                if (chdir(Repo[i]) != 0)
                    printf("Error switching directory\n");

                system("makepkg -si");

                chdir("..");
                i++;
            }

        else if (FlagTwoExists == 1)
            for (int i = 2; Repo[i] != NULL;)
            {
                Git(Repo[i], "clone");

                if (chdir(Repo[i]) != 0)
                    printf("Error switching directory\n");

                system("makepkg -si");

                chdir("..");
                i++;
            }

        if (!!strcmp(Repo[2], "--nc"))
        {
            chdir("..");
            CleanAURFolder();
        }
    }

    else if (
        !strcmp(Repo[2], "--rebuild") &&
        !strcmp(Repo[1], "/aur")
    ){
        printf("Searching...\n");

        chdir(PATH);
        chdir(MMGR);

        if (chdir(AUR_PATH) != 0)
        {
            printf("No packages found\n");
            exit(1);
        }

        int FlagTwoExists = 1;

        if (!!strcmp(Repo[3], "--nc"))
            FlagTwoExists = 0;

        if (FlagTwoExists == 1)
            for (int i = 4; Repo[i] != NULL;)
            {
                chdir(Repo[i]);

                system("makepkg -si");

                chdir("..");
                i++;
            }

        else if (FlagTwoExists == 0)
        {
            for (int i = 3; Repo[i] != NULL;)
            {
                chdir(Repo[i]);

                system("makepkg -si");

                chdir("..");
                i++;
            }

            CleanAURFolder();
        }
    }
}

