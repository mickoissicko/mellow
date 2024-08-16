#ifndef IMPORTS_H
    #define IMPORTS_H
#endif

char* GetData(const int VAL, const char FILE_NAME[], const char FILE_PATH[]);

void StripNewlines(const char FILE_NAME[], const char FILE_PATH[]);
void BuildPackage(char PackageName[], const char PATH[]);
void RemoveDeps(char PackageName[], const char PATH[]);
void SplitFiles(const int INDEX, const int START_LINE);
void UninstallDeps(char Deps[], const char PATH[]);
void DisplayResults(const char FILE_PATH[]);
void RemovePkgs(const char PKG_NAME[]);
void GetPackage(char* PackageName);
void RemoveQuotes(char* String);
void FiltreResults();
void DelTmp();
void MkDirs();
void MkTmp();

int FindExistingPkg(char Pkg[], const char PATH[]);
int Clone(const char URL[], const char PATH[]);
int Scraper(char* PackageName);
int PrettyPrinter();

