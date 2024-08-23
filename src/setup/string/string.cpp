#include <iostream>
#include <cstring>
#include <string>

extern "C"
{
    char* Append(char String[]);
}

// idk how this works
char* Append(char String[])
{
    char* C_AppendedStr = (char*)malloc(sizeof(char) * strlen(String) + 1);
    std::string AppendedStr = String;

    AppendedStr.append(" ");
    strcpy(C_AppendedStr, AppendedStr.c_str());

    return C_AppendedStr;
}

