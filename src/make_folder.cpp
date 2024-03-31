#include <filesystem>

void MakeFolder(char* path)
{
    std::filesystem::create_directories(path);
}

