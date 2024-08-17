#include <filesystem>

extern "C"
{
    void RmDir(const char DIRECTORY[]);
}

namespace Fs = std::filesystem;

void RmDir(const char DIRECTORY[])
{
    if (Fs::exists(DIRECTORY))
        Fs::remove_all(DIRECTORY);
}

