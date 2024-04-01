#include <stdio.h>
#include <stdlib.h>

void clrscr()
{
    #ifdef _WIN32
        int Status = system("cls");
    #else
        int Status = system("clear");
    #endif

    if (Status != 0)
    {
        printf("unable to clear screen\n");
        exit(1);
    }
}

