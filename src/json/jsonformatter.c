#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void FormatFile(const char File[], const char FilePath[])
{
    const char FormattedFile[] = "f.results.txt";

    if (chdir(FilePath) != 0)
    {
        perror("jsonf.c: Error changing directory");
        exit(1);
    }

    FILE* Formatted;
    FILE* Raw;
    char Buf[8192];
    int PrevChar = '\n';

    Formatted = fopen(FormattedFile, "w");
    Raw = fopen(File, "r");

    while (fgets(Buf, sizeof(Buf), Raw))
    {
        for (char* Char = Buf; *Char; ++Char)
        {
            if (*Char != '\n')
                fputc(*Char, Formatted);

            else if (PrevChar != '\n')
                fputc(*Char, Formatted);

            PrevChar = *Char;
        }
    }

    fclose(Formatted);
    fclose(Raw);

    remove(File);
    rename(FormattedFile, File);
}

