#include "../common/common.h"

#include <string.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc < 2)
        return 1;

    unsigned long BUF = MAX_LEN;
    char Name[MAX_LEN];

    if (!strcmp(argv[1], "get"))
    {
        printf("Fetching...\n");

        if (argc < 3)
            return 1;

        snprintf(Name, BUF, "wget %s", argv[2]);

        Get(Name);
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

    else if (!strcmp(argv[1], "get-tmp"))
    {
        char* Path = GetTempPath();
        printf("%s\n", Path);
    }

    return 0;
}

