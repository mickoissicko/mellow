#include "../include/links.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_BUF 4096

void Clone(char pkg[])
{
    const char GIT_STR[] = ".git";

    char CloneCommand[MAX_BUF];
    char AppendedStr[MAX_BUF];

    snprintf(AppendedStr, MAX_BUF, "%s/%s%s", AUR_LINK, pkg, GIT_STR);
    snprintf(CloneCommand, MAX_BUF, "git clone %s", AppendedStr);

    system(CloneCommand);
}

void Git(char pkg[], char mode[])
{
    if (!strcmp(mode, "clone"))
        Clone(pkg);
}

