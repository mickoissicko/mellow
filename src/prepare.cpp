#include "../lib/gethome.h"
#include "../include/common.h"

#include <filesystem>
#include <unistd.h>
#include <iostream>
#include <cstdlib>

void Prepare()
{
    char* Path = (char*)malloc(MAX_SIZ);

    Path = gethome();
    chdir(Path);

    if (!std::filesystem::exists(MIX))
        std::filesystem::create_directories(MIX);

    if (chdir(MIX) != 0)
    {
        std::cout << "Permission denied or other error" << '\n';
        std::cout << "Please manually create '.mix/mmgr' directory" << '\n';
        std::cout << "Make sure to create in home directory" << '\n';

        exit(1);
    }

    if (!std::filesystem::exists("mmgr"))
        std::filesystem::create_directories("mmgr");

    if (chdir("mmgr") != 0)
    {
        std::cout << "Permission denied or other error" << '\n';
        std::cout << "Please manually create '.mix/mmgr' directory" << '\n';
        std::cout << "Make sure to create in home directory" << '\n';

        exit(1);
    }

    chdir(Path);
    free(Path);
}

void MakeAURFolder()
{
    char* Path = gethome();

    chdir(Path);

    if (chdir(MMGR) != 0)
    {
        std::cout << "Run /init or /setup first" << '\n';
        exit(1);
    }

    if (!std::filesystem::exists(AUR_PATH))
        std::filesystem::create_directories(AUR_PATH);
}

void CleanAURFolder()
{
    char* Path = gethome();

    chdir(Path);

    if (chdir(MMGR) != 0)
    {
        std::cout << "Run /init or /setup first" << '\n';
        exit(1);
    }

    char Command[MAX_BUF];

    snprintf(Command, MAX_BUF, "rm -rf %s", AUR_PATH);
    system(Command);
}

