#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>

#define FILE_NAME "package.html"
#define MAX_LINK_LENGTH 1024

class ConstructString {
public:
    void AddChar(char Char)
    {
        Result += Char;
    }

    [[nodiscard]] std::string GetString() const
    {
        return Result;
    }

private:
    std::string Result;
};

void AssembleLink(char Cursor)
{
    ConstructString Construct;
    Construct.AddChar(Cursor);

    std::string String = Construct.GetString();
}

void ParseHTML(std::ifstream& File)
{
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
                    AssembleLink(Line[HrefPos]);

                    HrefPos++;
                }

                std::putchar('\n');
            }
        }
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

    ParseHTML(HTMLFile);
    HTMLFile.close();
}
