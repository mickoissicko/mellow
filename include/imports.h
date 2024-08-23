#ifndef IMPORTS_H
#define IMPORTS_H
#include <stdio.h>

char* FindPackages(char PackageList[], int LineCount, FILE* InstalledPackages);
char* FormatField(const char FILE_NAME[], const char PATH[], int EraseCommas);
char* GetData(const int VAL, const char FILE_NAME[], const char FILE_PATH[]);
char* ParseIni(const char INI[], const char FULL_PATH[]);
char* Replace(char String[], int Delim);
char* ReadFile(FILE* File, int Mode);
char* Append(char String[]);

void MakeInstallationList(char PackageList[], char InstalledPackageList[], const char PATH[]);
void InstallPackages(const char PACKAGE_LIST[], const char PATH[]);
void Translate(const char GLOBAL[], const char FULL_PATH[]);
void GetFields(const char FILE_NAME[], const char PATH[]);
void DownloadPackage(char Package[], const char PATH[]);

void StripNewlines(const char FILE_NAME[], const char FILE_PATH[]);
void BuildPackage(char PackageName[], const char PATH[]);
void RemoveDeps(char PackageName[], const char PATH[]);
void SplitFiles(const int INDEX, const int START_LINE);
void MkDir(const char DIR_NAME[], const char PATH[]);
void Curl(const char URL[], const char FILE_NAME[]);
void MakePackage(char Package[], const char PATH[]);
void UninstallDeps(char Deps[], const char PATH[]);
void DisplayResults(const char FILE_PATH[]);
void WriteFile(FILE* File, char Line[]);
void RemovePkgs(const char PKG_NAME[]);
void GetPackage(char* PackageName);
void RmDir(const char DIR_NAME[]);
void RemoveQuotes(char* String);
void FiltreResults(void);
void DelTmp(void);
void MkDirs(void);
void MkTmp(void);
void Clear(void);

int CheckInstalled(char PackageList[], const char PATH[]);
int FindExistingPkg(char Pkg[], const char PATH[]);
int Clone(const char URL[], const char PATH[]);
int Mellow(int argc, char* argv[]);
int Scraper(char* PackageName);
int PrettyPrinter(void);
int Setup(void);

#endif // IMPORTS_H

