#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void MakePackage(char Package[], const char PATH[])
{
    if (chdir(PATH) != 0)
    {
        perror("Could not change directory");
        exit(1);
    }

    if (chdir(Package) != 0)
    {
        printf("Folder `%s` does not exist\n", Package);
        printf("Please check if you have a stable internet connection\n");
        printf("Maybe there was an error with the cloning process?\n");
        perror("Could not change directory");

        exit(1);
    }

    if (system("makepkg -si") != 0)
    {
        perror("Error while making package (via makepkg)");
        printf("Retry? [y/n]: \n");
        int Ui = getchar();

        if (Ui == 'y' || Ui == 'Y')
            if (system("makepkg -s") != 0)
            {
                perror("Could not make package");
                exit(1);
            }
    }
}

