#ifndef SETUP_H
#define SETUP_H

void Translate(const char GLOBAL[], const char USER[], const char FULL_PATH[]);
void MkDir(const char DIR_NAME[], const char PATH[]);
void Curl(const char URL[], const char FILE_NAME[]);
void RmDir(const char DIR_NAME[]);

char* ParseIni(const char INI[], const char FULL_PATH[], const int MODE);

#endif // SETUP_H

