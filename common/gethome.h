#ifndef GETHOME_H
    #define GETHOME_H
    #define MAX_LEN 4096

    #include <unistd.h>
    #include <string.h>
    #include <stdlib.h>

    #ifdef _WIN32
        static char* Win32_Path()
        {
            unsigned long LEN = MAX_LEN;

            char* HomeDirectory = getenv("USERPROFILE");

            return HomeDirectory;
        }

    #else
        #include <sys/types.h>
        #include <pwd.h>

        static char* Posix_Path()
        {
            struct passwd *Home;

            char* Path = NULL;

            if ((Home = getpwuid(getuid())) != NULL)
            {
                Path = (char*)malloc(MAX_LEN);

                if (Path != NULL)
                {
                    strcpy(Path, Home->pw_dir);
                }
            }

            return Path;
        }
    #endif
#endif

