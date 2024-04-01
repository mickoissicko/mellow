#include <filesystem>

void MakeFolder(char* path)
{
    std::filesystem::create_directories(path);
}

void RemoveDownloads(char* path)
{
    std::filesystem::remove_all(path);
}

