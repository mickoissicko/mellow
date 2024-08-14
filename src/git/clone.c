#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int Clone(const char URL[], const char PATH[])
{
    if (chdir(PATH) != 0) // path is preconcatenated
        return 2;

    char Buf[8192];
    snprintf(Buf, sizeof(Buf), "git clone %s", URL);

    if (system(Buf) != 0)
        return 1;

    else
        return 0;
}

