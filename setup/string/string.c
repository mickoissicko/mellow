// minimal ahh function

char* Replace(char String[], int Delim)
{
    int Shift = 0;
    int Index = 0;
    
    while (String[Index] != '\0')
    {
        if (String[Index] != Delim)
        {
            String[Shift] = String[Index];

            Shift++;
        }

        Index++;
    }

    String[Shift] = '\0';
    return String;
}

