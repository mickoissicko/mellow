cmake_minimum_required(VERSION 3.29)
project(mellow)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

add_executable(mellow
    src/main.c
        src/files.cpp
        src/dispresults.c
        src/splitfiles.c
        src/web/getpkg.c
        src/web/scraper.c
        src/scripts/build.c
        src/scripts/rmdeps.c
        src/scripts/rmpkgs.c
        src/scripts/uninstall.c
        src/git/clone.c
        src/json/filtrejson.c
        src/json/formatjson.c
        src/json/getdata.c
        src/json/prettyprint.c
)

target_link_libraries(mellow curl)
