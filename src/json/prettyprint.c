#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int PrettyPrinter()
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
                               // i also apologise for what you are about to see

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

    char Replacement = '\n';
    char* Sub = "\",";

    while ((Ptr = strstr(PrettyJSONStr, Sub)) != NULL)
    {
        if (strstr(PrettyJSONStr, "\"Description:\""))   continue;
        if (
            strstr(PrettyJSONStr, "\"FirstSubmitted\":") ||
            strstr(PrettyJSONStr, "\"LastModified\":")   ||
            strstr(PrettyJSONStr, "\"resultcount\":")    ||
            strstr(PrettyJSONStr, "\"ID\":")
        ){
            while ((Ptr = strstr(Ptr, ",")) != NULL)
            {
                *Ptr = '\n';
                Ptr++;
            }
        }
    }

    Output = fopen("results.txt", "w");
    fprintf(Output, "%s", PrettyJSONStr);
    fclose(Output);

    free(PrettyJSONStr);
    free(Ptr4);
    free(Ptr3);
    free(Ptr2);
    free(Ptr);
    return 0;
}

