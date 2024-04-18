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

    else if (!std::filesystem::exists(MMGR))
        std::filesystem::create_directories(MMGR);

    if (chdir(MIX) != 0)
    {
        std::cout << "Permission denied or other error" << '\n';
        std::cout << "Please manually create '.mix/mmgr' directory" << '\n';
        std::cout << "Make sure to create in home directory" << '\n';

        exit(1);
    }

    else if (chdir("mmgr") != 0)
    {
        std::cout << "Permission denied or other error" << '\n';
        std::cout << "Please manually create '.mix/mmgr' directory" << '\n';
        std::cout << "Make sure to create in home directory" << '\n';

        exit(1);
    }

    chdir(Path);
    free(Path);
}

