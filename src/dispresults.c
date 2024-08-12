#include "../include/imports.h"

#include <complex.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const static char File[] = "results.txt";

void DisplayResults(const char FilePath[])
{
    StripNewlines(File, FilePath);

    if (chdir(FilePath) != 0)
    {
        perror("disp.c: Error changing directory");
        exit(1);
    }

    char f_User[8192];
    char f_Pkg[8192];
    char Buf[8192];

    FILE* Txt;
    Txt = fopen(File, "r");

    char* Desc = GetData(1, File, FilePath);
    char* User = GetData(2, File, FilePath);
    char* Pkg  = GetData(3, File, FilePath);
    char* Ver  = GetData(4, File, FilePath);

    Desc[strcspn(Desc, "\n")] = '\0';
    User[strcspn(User, "\n")] = '\0';
    Pkg[strcspn(Pkg, "\n")] = '\0';
    Ver[strcspn(Ver, "\n")] = '\0';

    int DescLen = strlen(Desc);
    int UserLen = strlen(User);
    int PkgLen  = strlen(Pkg);
    int VerLen  = strlen(Ver);
    char Reject = '"';
    int Index   = 0;
    int Count   = 0;

    for (Count = 0, Index = 0; Index < DescLen; Index++)
        if (Desc[Index] != Reject)
            Desc[Count++] = Desc[Index];
    Desc[Count] = '\0';

    for (Count = 0, Index = 0; Index < UserLen; Index++)
        if (User[Index] != Reject)
            User[Count++] = User[Index];
    User[Count] = '\0';

    for (Count = 0, Index = 0; Index < PkgLen; Index++)
        if (Pkg[Index] != Reject)
            Pkg[Count++] = Pkg[Index];
    Pkg[Count] = '\0';

    for (Count = 0, Index = 0; Index < VerLen; Index++)
        if (Ver[Index] != Reject)
            Ver[Count++] = Ver[Index];
    Ver[Count] = '\0';

    snprintf(f_User, sizeof(f_User), "'%s'", User);
    snprintf(f_Pkg, sizeof(f_Pkg), "'%s'", Pkg);

    snprintf(
        Buf,
        sizeof(Buf),
        "1: %s by %s (v%s)\n%s",
        f_Pkg, f_User, Ver, Desc
    );

    printf("%s", Buf);
    fclose(Txt);
}

