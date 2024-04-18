#ifdef _WIN32
    #include <windows.h>
    #include <iostream>
    #include <stdlib.h>

    #pragma comment(lib, "Urlmon.lib")
    
    void _win32get()
    {
        const wchar_t URL[] = {}; // L"X"
        const wchar_t DEST[] = {}; // L"Y"

        if (S_OK == URLDownloadToFile(NULL, URL, DEST, 0, NULL))
            std::cout << "Downloaded files" << '\n';

        else
        {
            std::cout << "Unexpected error" << '\n';
            exit(1);
        }
    }
#endif

