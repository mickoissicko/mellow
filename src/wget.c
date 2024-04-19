#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TERMINATOR_SIZ 1
#define MAX_LEN 4096

int Wget(char src[MAX_LEN + TERMINATOR_SIZ])
{
    int State = 0;

    if (strlen(src) > MAX_LEN)
        return State = 1;

    printf("Connecting...\n");
    
    char Command[MAX_LEN];
    snprintf(Command, sizeof(Command), "wget %s", src);

    State = system(Command);

    return State;
}

