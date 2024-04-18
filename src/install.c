#include "../include/scripts/wget.h"
#include "../include/common.h"
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

    FILE* bat;
    FILE* sh;

    #ifdef _WIN32
        bat = fopen("installer.bat", "w");
        fprintf(bat, "%s\n", WgetBat);
        fclose(bat);
    #else
        sh = fopen("installer.sh", "w");
        fprintf(sh, "%s\n", WgetSh);
        fclose(sh);

        system("chmod +x installer.sh");
        system("./installer.sh");
    #endif
}

