#ifndef IMPORTS_H
    #define IMPORTS_H
#endif

char* GetData(const int VAL, const char FILENAME[], const char FILEPATH[]);

void StripNewlines(const char FILENAME[], const char FILEPATH[]);
void BuildPackage(char PackageName[], const char PATH[]);
void RemoveDeps(char PackageName[], const char PATH[]);
void SplitFiles(const int INDEX, const int STARTLINE);
void DisplayResults(const char FILEPATH[]);
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

