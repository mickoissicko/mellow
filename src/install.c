#include "../include/scripts/wget.h"
#include "../include/common.h"
#include "../include/links.h"
#include "../lib/gethome.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void Install()
{
    Prepare();

    char* Path = gethome();
    char AbsPath[MAX_SIZ];

    snprintf(AbsPath, sizeof(AbsPath), "%s/%s", Path, MMGR);
    if (chdir(AbsPath) != 0)
    {
        printf("Unexpected error\n");
        exit(1);
    }

    FILE* bat;
    FILE* sh;

    #ifdef _WIN32
        bat = fopen("wget.bat", "w");
        fprintf(bat, "%s\n", WgetBat);
        fclose(bat);
    #else
        sh = fopen("wget.sh", "w");
        fprintf(sh, "%s\n", WgetSh);
        fclose(sh);

        system("chmod +x wget.sh");
        system("./wget.sh");
    #endif

    printf("If the installation fails, you may need to install wget manually\n");

    int Stat;

    #ifdef _WIN32
        Stat = Wget(BATCH_SCRIPT);
    #else
        Stat = Wget(SHELL_SCRIPT);
    #endif

    if (Stat != 0)
    {
        printf("Err\n");
        printf("Please refer to wiki for troubleshooting\n");
        printf("https://mick.gdn/wiki/mmgr\n");

        exit(Stat);
    }
}

