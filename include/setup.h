#ifndef SETUP_H
#define SETUP_H

void MkDir(const char DIR_NAME[], const char PATH[]);
void Curl(const char URL[], const char FILE_NAME[]);
void RmDir(const char DIR_NAME[]);

int ParseIni(const char INI[], const char FULL_PATH[]);

#endif // SETUP_H

