#ifndef COMMON_H
    #define COMMON_H
#endif

#define TERM_SIZ 1
#define MAX_SIZ 8192
#define MAX_BUF 4096

const static char LOCKFILE[] = "lock.pa";
const static char INDEX[] = "index.msx";
const static char LINKS[] = "links.msx";
const static char MMGR[] = ".mix/mmgr";
const static char MIX[] = ".mix";

int Wget(const char pkg[MAX_BUF + TERM_SIZ]);

void Downloader(char* argv[]);
void Prepare();
void Install();
void Reset();
void Init();
void Sync();
void Help();
void Get(const char* src);

