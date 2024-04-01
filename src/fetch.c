#include "../common/gethome.h"
#include "../common/common.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void Get(char* n, char** argv)
{
    FILE* Pkglist;
    FILE* Linklist;

    unsigned long Buf = MAX_LEN;

    const static char PackageIndex[] = 
        "https://raw.githubusercontent.com/mickoissicko/mixmgr/main/packages/index_mmgr";
    const static char PackageLinks[] =
        "https://raw.githubusercontent.com/mickoissicko/mixmgr/main/packages/links_mmgr";

    char UpdatePackagesIndex[MAX_LEN];
    char UpdatePackagesLink[MAX_LEN];
    char FormattedPath[MAX_PATH_LEN];
    char DownloadPath[MAX_PATH_LEN];
    char WgetCommand[MAX_LEN];

    char* Path;

    int Status;
    int i = 1;

    snprintf(WgetCommand, Buf, "wget %s", n);

    #ifdef _WIN32
        Path = Win32_Path();
        snprintf(FormattedPath, Buf, "%s\\mmgr", Path);
    #else
        Path = Posix_Path();
        snprintf(FormattedPath, Buf, "%s/mmgr", Path);
    #endif

    snprintf(UpdatePackagesIndex, Buf, "wget %s", PackageIndex);
    snprintf(UpdatePackagesLink, Buf, "wget %s", PackageLinks);

    if (strcmp(argv[1], "init") == 0)
    {
        MakeFolder(FormattedPath);
        chdir(FormattedPath);
        exit(0);
    }

    else if (strcmp(argv[1], "sync") == 0)
    {
        chdir(FormattedPath);
        remove("index_mmgr");
        remove("links_mmgr");
        system(UpdatePackagesIndex);
        system(UpdatePackagesLink);
        exit(0);
    }

    char IndexFilePath[MAX_PATH_LEN];
    char LinksFilePath[MAX_PATH_LEN];
    char ProgramName[MAX_LEN];

    bool IsNotZero = true;

    snprintf(IndexFilePath, Buf, "%s/index_mmgr", FormattedPath);
    snprintf(LinksFilePath, Buf, "%s/links_mmgr", FormattedPath);

    Pkglist = fopen(IndexFilePath, "r");

    int pos = {1};

    char* Lineptr;

    Lineptr = (char*)malloc(MAX_PATH_LEN);

    while (fgets(Lineptr, Buf, Pkglist))
    {
        Lineptr[strcspn(Lineptr, "\n")] = '\0';

        if (!strcmp(argv[2], Lineptr))
        {
            break;
        }

        pos++;
    }

    Linklist = fopen(LinksFilePath, "r");

    if (pos == 1)
    {
        fgets(Lineptr, Buf, Linklist);
        Lineptr[strcspn(Lineptr, "\n")] = '\0';

        IsNotZero = false;
    }

    else if (IsNotZero)
    {
        while (fgets(Lineptr, Buf, Linklist))
        {
            i++;
            Lineptr[strcspn(Lineptr, "\n")] = '\0';

            if (i == pos)
            {
                fgets(Lineptr, Buf, Linklist);
                break;
            }
        }
    }

    snprintf(WgetCommand, Buf, "wget %s", Lineptr);

    fclose(Linklist);
    fclose(Pkglist);

    free(Lineptr);

    char CdToDownloadPath[MAX_PATH_LEN];

    snprintf(DownloadPath, Buf, "%s/downloads", FormattedPath);
    snprintf(CdToDownloadPath, Buf, "cd %s", DownloadPath);

    Status = system(CdToDownloadPath);
    if (Status != 0)
    {
        MakeFolder(DownloadPath);
    }

    chdir(DownloadPath);

    Status = system(WgetCommand);
    if (Status != 0)
    {
        printf("%s\n", n);

        printf("There was an unexpected error\n");
        printf("Do you have 'wget' installed?\n");
        exit(1);
    }

    
}

