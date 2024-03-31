#include "../common/common.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int AurHelper(int argc, char** argv)
{
    char Ui;
    int Status;

    unsigned long LEN = MAX_LEN;

    char FormattedCdCommand[MAX_LEN];
    char FormattedRepoAddr[MAX_LEN];
    char FormattedCommand[MAX_LEN];
    char FormattedCheck[MAX_LEN];
    char Repo[MAX_LEN];
    char User[MAX_LEN];
    char Soft[MAX_LEN];

    if (strcmp(argv[1], "--daur") == 0)
    {
        strcpy(Soft, argv[2]);
        CreateTemp();
        snprintf(FormattedCheck, LEN, "cd ~/aur.gelper_tmp/%s", Soft);

        Status = system(FormattedCheck);

        if (Status != 0)
        {
            snprintf(FormattedRepoAddr, LEN, "git clone %s%s.git", Aur, Soft);
            snprintf(FormattedCommand, LEN, "cd ~/aur.gelper_tmp && %s", FormattedRepoAddr);
            snprintf(FormattedCdCommand, LEN, "cd ~/aur.gelper_tmp/%s && makepkg -si", Soft);

            system(FormattedCommand);
            system(FormattedCdCommand);
        }

        else
        {
            snprintf(FormattedCheck, LEN, "cd ~/aur.gelper_tmp/%s && makepkg -si", Soft);

            while (Ui != 'Y' && Ui != 'y' && Ui != 'N' && Ui != 'n')
            {
                printf("Software repository found! Build? [y/n]: ");
                scanf(" %c", &Ui);
            }
            switch (Ui)
            {
                case 'y':
                case 'Y':
                    system(FormattedCheck);
                break;

                case 'N':
                case 'n':
                break;
            }
        }
        DeleteTemp();
    }

    if (strcmp(argv[1], "--daur-nc"))
    {
        strcpy(Soft, argv[2]);
        CreateTemp();
        snprintf(FormattedCheck, LEN, "cd ~/aur.gelper_tmp/%s", Soft);

        Status = system(FormattedCheck);

        if (Status != 0)
        {
            snprintf(FormattedRepoAddr, LEN, "git clone %s%s.git", Aur, Soft);
            snprintf(FormattedCommand, LEN, "cd ~/aur.gelper_tmp && %s", FormattedRepoAddr);
            snprintf(FormattedCdCommand, LEN, "cd ~/aur.gelper_tmp/%s && makepkg -si", Soft);

            system(FormattedCommand);
            system(FormattedCdCommand);
        }

        else
        {
            snprintf(FormattedCheck, LEN, "cd ~/aur.gelper_tmp/%s && makepkg -si", Soft);

            while (Ui != 'Y' && Ui != 'y' && Ui != 'N' && Ui != 'n')
            {
                printf("Software repository found! Build? [y/n]: ");
                scanf(" %c", &Ui);
            }
            switch (Ui)
            {
                case 'y':
                case 'Y':
                    system(FormattedCheck);
                break;

                case 'N':
                case 'n':
                break;
            }
        }
    }

    if (strcmp(argv[1], "--daur-ng") == 0)
    {
        strcpy(Soft, argv[2]);
        CreateTemp();
        snprintf(FormattedCheck, LEN, "cd ~/aur.gelper_tmp/%s", Soft);

        Status = system(FormattedCheck);

        if (Status != 0)
        {
            snprintf(FormattedRepoAddr, LEN, "git clone %s%s", Aur, Soft);
            snprintf(FormattedCommand, LEN, "cd ~/aur.gelper_tmp && %s", FormattedRepoAddr);
            snprintf(FormattedCdCommand, LEN, "cd ~/aur.gelper_tmp/%s && makepkg -si", Soft);

            system(FormattedCommand);
            system(FormattedCdCommand);
        }

        else
        {
            snprintf(FormattedCheck, LEN, "cd ~/aur.gelper_tmp/%s && makepkg -si", Soft);

            while (Ui != 'Y' && Ui != 'y' && Ui != 'N' && Ui != 'n')
            {
                printf("Software repository found! Build? [y/n]: ");
                scanf(" %c", &Ui);
            }
            switch (Ui)
            {
                case 'y':
                case 'Y':
                    system(FormattedCheck);
                break;

                case 'N':
                case 'n':
                break;
            }
        }
        DeleteTemp();
    }

    if (strcmp(argv[1], "--daur-ng-nc"))
    {
        strcpy(Soft, argv[2]);
        CreateTemp();
        snprintf(FormattedCheck, LEN, "cd ~/aur.gelper_tmp/%s", Soft);

        Status = system(FormattedCheck);

        if (Status != 0)
        {
            snprintf(FormattedRepoAddr, LEN, "git clone %s%s", Aur, Soft);
            snprintf(FormattedCommand, LEN, "cd ~/aur.gelper_tmp && %s", FormattedRepoAddr);
            snprintf(FormattedCdCommand, LEN, "cd ~/aur.gelper_tmp/%s && makepkg -si", Soft);

            system(FormattedCommand);
            system(FormattedCdCommand);
        }

        else
        {
            snprintf(FormattedCheck, LEN, "cd ~/aur.gelper_tmp/%s && makepkg -si", Soft);

            while (Ui != 'Y' && Ui != 'y' && Ui != 'N' && Ui != 'n')
            {
                printf("Software repository found! Build? [y/n]: ");
                scanf(" %c", &Ui);
            }
            switch (Ui)
            {
                case 'y':
                case 'Y':
                    system(FormattedCheck);
                break;

                case 'N':
                case 'n':
                break;
            }
        }
    }

    if (strcmp(argv[1], "--aur") == 0)
    {
        CreateTemp();

        printf("Software: ");
        scanf("%s", Soft);

        snprintf(FormattedCheck, LEN, "cd ~/aur.gelper_tmp/%s", Soft);

        Status = system(FormattedCheck);

        if (Status != 0)
        {
            snprintf(FormattedRepoAddr, LEN, "git clone %s%s.git", Aur, Soft);
            snprintf(FormattedCommand, LEN, "cd ~/aur.gelper_tmp && %s", FormattedRepoAddr);
            snprintf(FormattedCdCommand, LEN, "cd ~/aur.gelper_tmp/%s && makepkg -si", Soft);

            system(FormattedCommand);
            system(FormattedCdCommand);
        }

        else
        {
            snprintf(FormattedCheck, LEN, "cd ~/aur.gelper_tmp/%s && makepkg -si", Soft);

            while (Ui != 'Y' && Ui != 'y' && Ui != 'N' && Ui != 'n')
            {
                printf("Software repository found! Build? [y/n]: ");
                scanf(" %c", &Ui);
            }
            switch (Ui)
            {
                case 'y':
                case 'Y':
                    system(FormattedCheck);
                break;

                case 'N':
                case 'n':
                break;
            }
        }

        DeleteTemp();

        return 0;
    }

    if (strcmp(argv[1], "--aur-nc") == 0)
    {
        CreateTemp();

        printf("Software: ");
        scanf("%s", Soft);

        snprintf(FormattedCheck, LEN, "cd ~/aur.gelper_tmp/%s", Soft);

        Status = system(FormattedCheck);

        if (Status != 0)
        {
            snprintf(FormattedRepoAddr, LEN, "git clone %s%s.git", Aur, Soft);
            snprintf(FormattedCommand, LEN, "cd ~/aur.gelper_tmp && %s", FormattedRepoAddr);
            snprintf(FormattedCdCommand, LEN, "cd ~/aur.gelper_tmp/%s && makepkg -si", Soft);

            system(FormattedCommand);
            system(FormattedCdCommand);
        }

        else
        {
            snprintf(FormattedCheck, LEN, "cd ~/aur.gelper_tmp/%s && makepkg -si", Soft);

            while (Ui != 'Y' && Ui != 'y' && Ui != 'N' && Ui != 'n')
            {
                printf("Software repository found! Build? [y/n]: ");
                scanf(" %c", &Ui);
            }
            switch (Ui)
            {
                case 'y':
                case 'Y':
                    system(FormattedCheck);
                break;

                case 'N':
                case 'n':
                break;
            }
        }
    }

    if (strcmp(argv[1], "--aur-ng-nc") == 0)
    {
        CreateTemp();

        printf("Software: ");
        scanf("%s", Soft);

        snprintf(FormattedCheck, LEN, "cd ~/aur.gelper_tmp/%s", Soft);

        Status = system(FormattedCheck);

        if (Status != 0)
        {
            snprintf(FormattedRepoAddr, LEN, "git clone %s%s", Aur, Soft);
            snprintf(FormattedCommand, LEN, "cd ~/aur.gelper_tmp && %s", FormattedRepoAddr);
            snprintf(FormattedCdCommand, LEN, "cd ~/aur.gelper_tmp/%s && makepkg -si", Soft);

            system(FormattedCommand);
            system(FormattedCdCommand);
        }

        else
        {
            snprintf(FormattedCheck, LEN, "cd ~/aur.gelper_tmp/%s && makepkg -si", Soft);

            while (Ui != 'Y' && Ui != 'y' && Ui != 'N' && Ui != 'n')
            {
                printf("Software repository found! Build? [y/n]: ");
                scanf(" %c", &Ui);
            }
            switch (Ui)
            {
                case 'y':
                case 'Y':
                    system(FormattedCheck);
                break;

                case 'N':
                case 'n':
                break;
            }
        }
    }

    if (strcmp(argv[1], "--aur-ng") == 0)
    {
        CreateTemp();

        printf("Software: ");
        scanf("%s", Soft);

        snprintf(FormattedCheck, LEN, "cd ~/aur.gelper_tmp/%s", Soft);

        Status = system(FormattedCheck);

        if (Status != 0)
        {
            snprintf(FormattedRepoAddr, LEN, "git clone %s%s", Aur, Soft);
            snprintf(FormattedCommand, LEN, "cd ~/aur.gelper_tmp && %s", FormattedRepoAddr);
            snprintf(FormattedCdCommand, LEN, "cd ~/aur.gelper_tmp/%s && makepkg -si", Soft);

            system(FormattedCommand);
            system(FormattedCdCommand);
        }

        else
        {
            snprintf(FormattedCheck, LEN, "cd ~/aur.gelper_tmp/%s && makepkg -si", Soft);

            while (Ui != 'Y' && Ui != 'y' && Ui != 'N' && Ui != 'n')
            {
                printf("Software repository found! Build? [y/n]: ");
                scanf(" %c", &Ui);
            }
            switch (Ui)
            {
                case 'y':
                case 'Y':
                    system(FormattedCheck);
                break;

                case 'N':
                case 'n':
                break;
            }
        }
    }

    return 0;
}

