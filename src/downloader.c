#include "../include/common.h"
#include "../lib/gethome.h"

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

    char* UnfilteredLink = MatchName(Flag);

    if (!strcmp(UnfilteredLink, "NULL"))
    {
        printf("There was an error\n");
        printf("See manual for more info at https://mick.gdn/wiki/mmgr\n");

        exit(1);
    }

    Wget(UnfilteredLink);
}

