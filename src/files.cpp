#include "../lib/gethome/gethome.h"

#include <filesystem>
#include <iostream>
#include <unistd.h>

extern "C"
{
    void MkDirs();
    void MkTmp();
}

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

    chdir(Path);
}

void MkTmp()
{
    char* Home = gethome();
    char Ui;

    if (chdir(Home) != 0)
    {
        std::cerr << "c++: Error changing directory" << '\n';
        exit(1);
    }

    chdir(".mix");
    chdir("mellow");

    if (!Fs::exists(".tmp"))
        Fs::create_directory(".tmp");

    else if (Fs::exists(".tmp"))
    {
        std::cout << "Remove temp folder? [y/n]" << '\n';
        std::cin >> Ui;

        if (Ui == 'y' || Ui == 'Y')
            Fs::remove_all(".tmp");

        else
            return;
    }
}

