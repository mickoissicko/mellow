#include "../lib/gethome/gethome.h"

#include <filesystem>
#include <iostream>
#include <unistd.h>

namespace Fs = std::filesystem;

void MkDirs()
{
    char* Path = gethome();

    if (chdir(Path) != 0)
    {
        std::cerr << "Error changing directory" << '\n';
        exit(1);
    }

    if (!Fs::exists(".mix"))
        Fs::create_directory(".mix");

    if (chdir(".mix") != 0)
    {
        std::cerr << "Error" << '\n';
        exit(1);
    }

    if (!Fs::exists("mellow"))
        Fs::create_directory("mellow");
}

void MkTmp(char Path[])
{
    char Ui;

    if (
        chdir(Path)     != 0 &&
        chdir(".mix")   != 0 &&
        chdir("mellow") != 0
    ){
        std::cerr << "Error changing directory" << '\n';
        exit(1);
    }

    if (!Fs::exists(".tmp"))
    {
        std::cout << "Remove temp folder? [y/n]" << '\n';
        std::cin >> Ui;

        if (Ui == 'y' || Ui == 'Y')
            Fs::remove_all(".tmp");

        else
            exit(0);
    }
}

