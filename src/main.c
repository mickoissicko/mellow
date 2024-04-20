#include "../include/common.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc < 2)
        Help();

    printf("Loading...\n");

    if (
        !strcmp(argv[1], "/aur") ||
        !strcmp(argv[2], "--rebuild")
    ){
        if (
            !strcmp(argv[1], "/aur") && argv[2] == NULL ||
            !strcmp(argv[2], "--nc") && argv[3] == NULL
        ){
            printf("No software was named\n");
            exit(1);
        }

        AURHelper(argv);
    }

    else if (
        !strcmp(argv[1], "/setup")
    ){
        printf("Preparing...\n");
        Install();
    }

    else if (
        !strcmp(argv[1], "/get")
    ){
        if (argc < 3)
        {
            printf("No program?\n");
            printf("View the program repository at the MMGR repo list\n");
            printf("You can also download the list via /download mmgr_repo_list\n");
            printf("The list can be seen at: https://mick.gdn/software/mmgr/list\n");

            exit(1);
        }

        Downloader(argv);
    }

    else if (
        !strcmp(argv[1], "/init")
    ){
        printf("Fetching...\n");
        Init();
    }

    else if (
        !strcmp(argv[1], "/sync")
    ){
        printf("Synchronising database...\n");
        printf("Connecting...\n");
        Sync();
    }

    else if (
        !strcmp(argv[1], "/reset")
    ){
        printf("Resetting...\n");
        printf("NOTE: the '.mix' folder will not be deleted\n");

        Reset();
    }

    return 0;
}

