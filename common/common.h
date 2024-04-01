#ifndef COMMON_H
    #define COMMON_H
#endif

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LEN 3096
#define MAX_LEN 2048

const static char Aur[] = "https://aur.archlinux.org/";

int AurHelper(int argc, char** argv);

void CreateTemp();
void DeleteTemp();

void PackageDownloader(const char* pkg);
void RemoveDownloads(char* path);
void MakeFolder(char* path);
void Get(char* n, char* argv[]);

void clrscr();

char* GetDownloadDir();
char* GetTempPath();
static char* Win32_Path();
static char* Posix_Path();

