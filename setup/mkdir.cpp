#include <filesystem>
#include <unistd.h>
#include <iostream>
#include <cstdlib>

extern "C"
{
    void MkDir(const char DIR_NAME[], const char PATH[]);
}

namespace Fs = std::filesystem;

void MkDir(const char DIR_NAME[], const char PATH[])
{
    if (chdir(PATH) != 0)
    {
        std::cout << "Could not change directory" << '\n';
        exit(1);
    }

    if (Fs::exists(DIR_NAME))
    {
        std::cout << "Directory already exists" << '\n';
        return;
    }

    else
        Fs::create_directories(DIR_NAME);
}

