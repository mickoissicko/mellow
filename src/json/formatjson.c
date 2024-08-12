#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/********************
Field1 -> 11+3 chars
Field2 -> 10+3 chars
Field3 -> 4+3 chars
Field4 -> 7+3 chars

11+3=14
10+3=13
4+3=7
7+3=10
********************/

void StripNewlines(const char File[], const char FilePath[])
{
    const char FormattedFile[] = "f.results.txt";

    if (chdir(FilePath) != 0)
    {
        perror("jsonf.c: Error changing directory");
        exit(1);
    }

    int PrevChar = '\n';
    FILE* Formatted;
    char Buf[8192];
    FILE* Raw;

    Formatted = fopen(FormattedFile, "w");
    Raw = fopen(File, "r");

    while (fgets(Buf, sizeof(Buf), Raw))
        for (char* Char = Buf; *Char; ++Char)
        {
            if (*Char != '\n')
                fputc(*Char, Formatted);

            else if (PrevChar != '\n')
                fputc(*Char, Formatted);

            PrevChar = *Char;
        }

    fclose(Formatted);
    fclose(Raw);

    remove(File);
    rename(FormattedFile, File);
}

