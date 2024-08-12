#include "../../include/imports.h"

#include <stdio.h>

char* GetDesc()
{
    char* Desc;



    return Desc;
}

char* GetUsr()
{
    char* Usr;
    return Usr;
}

char* GetPkg()
{
    char* Pkg;
    return Pkg;
}

char* GetVer()
{
    char* Ver;
    return Ver;
}

char* GetFileData(int Value)
{
    char* Desc = GetDesc();
    char* Usr  = GetUsr();
    char* Pkg  = GetPkg();
    char* Ver  = GetVer();



    char* f_Desc = FormatFileData(Desc);
    char* f_Usr  = FormatFileData(Usr);
    char* f_Pkg  = FormatFileData(Pkg);
    char* f_Ver  = FormatFileData(Ver);

    switch (Value)
    {
        case 1:
            return Desc;
            break;

        case 2:
            return Usr;
            break;

        case 3:
            return Pkg;
            break;

        case 4:
            return Ver;
            break;

        default:
            // return error if value is out of bounds
            return "int.val.outofbounds";
            break;
    }

    // return error if switch statement fails
    return "switch.statement.fail";
}

