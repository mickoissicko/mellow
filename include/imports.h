#ifndef IMPORTS_H
    #define IMPORTS_H
#endif

void StripNewlines(const char File[], const char FilePath[]);
void DisplayResults(const char FilePath[]);
void FiltreResults();
void DelTmp();
void MkDirs();
void MkTmp();

char* FormatFileData(const char Data[]);
char* GetFileData(const int Value);

int Scraper(char* PackageName);
int PrettyPrinter();

