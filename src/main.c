#include "../common/common.h"

#include <string.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc < 2)
        return 1;

    unsigned long BUF = MAX_LEN;
    char Name[MAX_LEN];

    if (
        !strcmp(argv[1], "get")  ||
        !strcmp(argv[1], "init") ||
        !strcmp(argv[1], "sync")
    ){
        if (argc > 2)
            strcpy(Name, argv[2]);

        Get(Name, argv);
    }

    else if (
        !strcmp(argv[1], "download")
    ){
        if (argc < 3)
            exit(1);

        strcpy(Name, argv[2]);

        PackageDownloader(Name);
        return 0;
    }

    else if (
        !strcmp(argv[1], "--aur")        ||
        !strcmp(argv[1], "--aur-nc")     ||
        !strcmp(argv[1], "--aur-ng")     ||
        !strcmp(argv[1], "--aur-ng-nc")  ||
        !strcmp(argv[1], "--daur-ng")    ||
        !strcmp(argv[1], "--daur-ng-nc") ||
        !strcmp(argv[1], "--daur-nc")    ||
        !strcmp(argv[1], "--daur")
    ){
        AurHelper(argc, argv);
        return 0;
    }

    else if (
        !strcmp(argv[1], "get-tmp")
    ){
        char* Path = GetTempPath();
        printf("%s\n", Path);
    }

    else if (
        !strcmp(argv[1], "rm-cache")
    ){
        char* DownloadDir = GetDownloadDir();
        DeleteTemp();
        RemoveDownloads(DownloadDir);
    }

    return 0;
}

