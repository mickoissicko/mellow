#include <stdlib.h>
#include <stdio.h>

#define MAX_LEN 4096

void ScriptRunner(char script[])
{
    printf("Processing...\n");

    #ifdef _WIN32
        char Buffer[MAX_LEN];
        snprintf(Buffer, sizeof(Buffer), "%s.bat", script);

        system(Buffer);
    #else
        char Exec_Buffer[MAX_LEN];
        char Perm_Buffer[MAX_LEN];

        snprintf(Perm_Buffer, sizeof(Perm_Buffer), "chmod +x %s.sh", script);
        snprintf(Exec_Buffer, sizeof(Exec_Buffer), "./%s.sh", script);
        
        system(Perm_Buffer);
        system(Exec_Buffer);
    #endif
}

