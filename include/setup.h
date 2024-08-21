#ifndef SETUP_H
#define SETUP_H
#include <stdio.h>

char* FindPackages(char PackageList[], int LineCount, FILE* InstalledPackages);
char* FormatField(const char FILE_NAME[], const char PATH[], int EraseCommas);
char* ParseIni(const char INI[], const char FULL_PATH[]);
char* Replace(char String[], int Delim);
char* Append(char String[]);
char* ReadFile(FILE* File);

void MakeInstallationList(char PackageList[], char InstalledPackageList[], const char PATH[]);
void InstallPackages(const char PACKAGE_LIST[], const char PATH[]);
void Translate(const char GLOBAL[], const char FULL_PATH[]);
void GetFields(const char FILE_NAME[], const char PATH[]);
void MkDir(const char DIR_NAME[], const char PATH[]);
void Curl(const char URL[], const char FILE_NAME[]);
void WriteFile(FILE* File, char Line[]);
void RmDir(const char DIR_NAME[]);
void MakePackage(char Package[]);

int CheckInstalled(char PackageList[], const char PATH[]);

#endif // SETUP_H

