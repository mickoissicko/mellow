#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>

#define FILE_NAME "package.html"
#define LINK_FILE "link.txt"
#define MAX_LINK_LENGTH 1024

void ParseHTML(std::ifstream& File, const char FILE_PATH[])
{
    if (chdir(FILE_PATH) != 0)
    {
        std::cerr << "Could not change directory" << '\n';
        exit(1);
    }

    std::ofstream LinkFile;
    LinkFile.open(LINK_FILE);

    if (!LinkFile.is_open())
    {
        std::cerr << "Unable to open link file" << '\n';
        exit(1);
    }

    const std::string HREF_TAG = "href=\"";
    std::string Line;

    while (std::getline(File, Line))
        if (Line.find("<a class=\"copy\"") != std::string::npos)
        {
            std::size_t HrefPos = Line.find("href=\"");

            if (HrefPos != std::string::npos)
            {
                HrefPos += HREF_TAG.length();

                while (Line[HrefPos] != '\"')
                {
                    LinkFile << Line[HrefPos];

                    HrefPos++;
                }
            }
        }

    LinkFile << '\n';
    LinkFile.close();
}

void GetHTML(const char FILE_PATH[])
{
    if (chdir(FILE_PATH) != 0)
    {
        std::perror("Could not change directory");
        std::exit(1);
    }

    std::ifstream HTMLFile;
    HTMLFile.open(FILE_NAME);

    if (!HTMLFile.is_open())
    {
        std::cout << "Error reading file" << '\n';
        exit(1);
    }

    ParseHTML(HTMLFile, FILE_PATH);
    HTMLFile.close();
}
