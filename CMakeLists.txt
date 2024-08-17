cmake_minimum_required(VERSION 3.29)
project(mellow)

set(CMAKE_CXX_STANDARD 17)

add_executable(setup
        setup/setup.c
        setup/mkdir.cpp
        setup/curl.c
        setup/parser/ini.c
        setup/rmdir.cpp
        setup/parser/translate.c
)

add_executable(mellow
        src/files.cpp
        src/main.c
        src/splitfiles.c
        src/dispresults.c
        src/web/getpkg.c
        src/web/scraper.c
        src/scripts/build.c
        src/scripts/rmdeps.c
        src/scripts/rmpkgs.c
        src/scripts/uninstall.c
        src/json/filtrejson.c
        src/json/formatjson.c
        src/json/prettyprint.c
        src/json/getdata.c
        src/git/clone.c
)

target_link_libraries(setup curl)
target_link_libraries(mellow curl)
