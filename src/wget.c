#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TERMINATOR_SIZ 1
#define MAX_LEN 4096

int Wget(const char pkg[MAX_LEN + TERMINATOR_SIZ])
{
    int State = 0;

    if (strlen(pkg) > MAX_LEN)
        return State = 1;

    printf("Connecting...\n");
    
    char Command[MAX_LEN];
    snprintf(Command, sizeof(Command), "wget %s", pkg);

    State = system(Command);

    return State;
}

