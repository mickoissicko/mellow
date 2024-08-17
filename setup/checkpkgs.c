#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char* FindPackages(char PackageList[])
{
    char* MissingPackageList = (char*)malloc(sizeof(char) * strlen(PackageList) + 1);



    return MissingPackageList;
}

int CheckInstalled(char PackageList[], const char PATH[])
{
    if (chdir(PATH) != 0)
    {
        perror("Could not change directory");
        exit(1);
    }

    char Buffer[1024];
    snprintf(Buffer, sizeof(Buffer), "pacman -Q %s", PackageList);

    int Results = open("pacman.txt", O_CREAT | O_WRONLY, S_IRWXU | S_IRWXG);
    int StdOut = dup(STDOUT_FILENO);

    dup2(Results, STDOUT_FILENO);
    close(Results);

    system(Buffer);

    dup2(StdOut, STDOUT_FILENO);
    close(StdOut);

    return 0;
}

