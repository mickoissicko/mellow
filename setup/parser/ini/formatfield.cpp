#include <iostream>
#include <unistd.h>
#include <cstring>
#include <fstream>
#include <string>

#define MAX_LINE_LENGTH 1024

extern "C"
{
    char* FormatField(const char FILE_NAME[], const char PATH[]);
}

char* FormatField(const char FILE_NAME[], const char PATH[])
{
    if (chdir(PATH) != 0)
    {
        std::cerr << "Could not change directory: " << strerror(errno) << '\n';
        exit(1);
    }

    char* C_Line = (char*)malloc(sizeof(char) * MAX_LINE_LENGTH);
    std::string PkgArray;
    std::string Quotes;
    std::string Line;

    std::ifstream Ini(FILE_NAME);
    std::getline(Ini, Line);

    Line = Line.substr(0, Line.size() - 2);
    Line.erase(0, strlen("REQUIRED = { "));

    int Index = 0;

    while (Index < Line.size())
    {
        if (Line[Index] != '\'')
            Quotes += Line[Index];

        Index++;
    }

    Index = 0;

    while (Index < Quotes.size())
    {
        if (Quotes[Index] != ',')
            PkgArray += Quotes[Index];

        Index++;
    }

    snprintf(C_Line, MAX_LINE_LENGTH, "%s", PkgArray.c_str());

    Ini.close();
    return C_Line;
}

