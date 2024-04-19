#include "../include/common.h"
#include "../lib/gethome.h"

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void Downloader(char* Flag[])
{
    char* Path = gethome();

    if(chdir(Path) != 0)
    {
        printf("Error changing directory..\n");
        printf("See manual at https://mick.gdn/wiki/mmgr\n");

        exit(1);
    }

    else if(chdir(MMGR) != 0)
    {
        Prepare();

        if (chdir(MMGR) != 0)
        {
            printf("Unprecedented fault\n");
            exit(1);
        }
    }

    for (int i = 2; Flag[i] != NULL;)
    {
        Get(Flag[i]);
        i++;
    }
}

