#ifndef COMMON_H
    #define COMMON_H
#endif

#define TERM_SIZ 1
#define MAX_SIZ 8192
#define MAX_BUF 4096

const static char AUR_PATH[] = "mmgr.aur";
const static char LOCKFILE[] = "lock.pa";
const static char INDEX[] = "index.msx";
const static char LINKS[] = "links.msx";
const static char MMGR[] = ".mix/mmgr";
const static char MIX[] = ".mix";

int Wget(const char pkg[MAX_BUF + TERM_SIZ]);

void CleanAURFolder();
void MakeAURFolder();
void ScriptRunner(char script[]);
void Downloader(char* argv[]);
void AURHelper(char *argv[]);
void Prepare();
void Install();
void Reset();
void Init();
void Sync();
void Help();
void Git(char pkg[], char mode[]);
void Get(const char* src);

