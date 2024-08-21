#include <filesystem>

namespace Fs = std::filesystem;

extern "C"
{
    void RmDir(const char* DIRECTORY);
}

void RmDir(const char* DIRECTORY)
{
    if (Fs::exists(DIRECTORY))
        Fs::remove_all(DIRECTORY);
}

