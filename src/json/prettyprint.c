#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int PrettyPrinter(void)
{
    size_t Siz = 0;

    FILE* Output;
    FILE* Input;

    char* PrettyJSONStr;
    char* Ln = NULL;

    Input = fopen("results.txt", "r");

    getline(&Ln, &Siz, Input);
    fclose(Input);

    PrettyJSONStr = malloc(Siz);
    strcpy(PrettyJSONStr, Ln);
    free(Ln);

    char* Ptr = PrettyJSONStr; // ptr for later

    while ((Ptr = strchr(Ptr, '{')) != NULL)
    {
        *Ptr = '\n';
        Ptr++;
    }

    char* Ptr2 = PrettyJSONStr;

    while ((Ptr2 = strchr(Ptr2, '}')) != NULL)
    {
        *Ptr2 = '\n';
        Ptr2++;
    }

    char* Ptr3 = PrettyJSONStr;

    while ((Ptr3 = strchr(Ptr3, '[')) != NULL)
    {
        *Ptr3 = '\n';
        Ptr3++;
    }

    char* Ptr4 = PrettyJSONStr;

    while ((Ptr4 = strchr(Ptr4, ']')) != NULL)
    {
        *Ptr4 = '\n';
        Ptr4++;
    }

    char* SearchPos = PrettyJSONStr;
    char* CommaPos;
    
    while ((CommaPos = strchr(SearchPos, ',')) != NULL)
    {
        if (CommaPos > PrettyJSONStr && *(CommaPos - 1) == '"')
            *CommaPos = '\n';

        SearchPos = CommaPos + 1;
    }

    Output = fopen("results.txt", "w");
    fprintf(Output, "%s", PrettyJSONStr);
    fclose(Output);

    free(PrettyJSONStr);
    return 0;
}

