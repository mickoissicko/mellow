#include <stdlib.h>
#include <stdio.h>

void RemovePkgs(const char PKG_NAME[])
{
    char RmCmd[2048];
    int Err;

    snprintf(RmCmd, sizeof(RmCmd), "sudo pacman -Rn '%s'", PKG_NAME);

    printf("Removing package %s\n", PKG_NAME);
    Err = system(RmCmd);

    if (Err != 0)
    {
        printf("Something happened\n");
        perror("@ ");
    }
}

