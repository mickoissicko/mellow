#ifndef IMPORTS_H
    #define IMPORTS_H
#endif

char* GetData(const int Val, const char File[], const char FilePath[]);

void StripNewlines(const char File[], const char FilePath[]);
void DisplayResults(const char FilePath[]);
void FiltreResults();
void DelTmp();
void MkDirs();
void MkTmp();

int Scraper(char* PackageName);
int PrettyPrinter();

