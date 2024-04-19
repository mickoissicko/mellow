#ifndef COMMON_H
    #define COMMON_H
#endif

#define TERM_SIZ 1
#define MAX_SIZ 8192
#define MAX_BUF 4096

const static char MMGR[] = ".mix/mmgr";
const static char MIX[] = ".mix";

int Wget(char src[MAX_BUF + TERM_SIZ]);

void Prepare();
void Install();
void Help();

