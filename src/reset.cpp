#include "../include/common.h"
#include "../lib/gethome.h"

#include <filesystem>
#include <iostream>
#include <unistd.h>

void Reset()
{
    char* Path = gethome();
    chdir(Path);

    if (chdir(MIX) != 0)
    {
        std::cout << "Error changing directory" << '\n';
        exit(1);
    }

    if (std::filesystem::exists("mmgr"))
        std::filesystem::remove_all("mmgr");

    else
        std::cout << "No '.mix/mmgr' directory?" << '\n';
}

