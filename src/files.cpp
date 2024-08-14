#include "../lib/gethome/gethome.h"

#include <filesystem>
#include <iostream>
#include <unistd.h>

extern "C"
{
    int FindExistingPkg(char Pkg[], const char PATH[]);
    void DelTmp();
    void MkDirs();
    void MkTmp();
}

namespace Fs = std::filesystem;

int FindExistingPkg(char Pkg[], const char PATH[])
{
    int Existence = 0;

    if (chdir(PATH) != 0)
    {
        MkDirs(),
        MkTmp();

        if (chdir(PATH) != 0)
        {
            perror("f.c: Error changing directory");
            exit(1);
        }
    }

    if (Fs::exists(Pkg))
        Existence = 1;

    return Existence;
}

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
        {
            Fs::remove_all(".tmp");
            Fs::create_directory(".tmp");
        }

        else
            return;
    }
}

void DelTmp()
{
    char* Home = gethome();

    if (chdir(Home) != 0)
    {
        std::cerr << "del.c++: Error changing directory" << '\n';
        exit(1);
    }

    chdir(".mix");
    chdir("mellow");

    if (Fs::exists(".tmp"))
        Fs::remove_all(".tmp");

    else
        std::cout << "There is nothing to remove" << '\n';
}

