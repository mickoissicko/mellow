cmake_minimum_required(VERSION 3.29)
project(CLion)

set(CMAKE_CXX_STANDARD 17)

# Specify the output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

add_executable(mellow
        src/main.c
        src/dispresults.c
        src/files.cpp
        src/splitfiles.c
        src/web/getpkg.c
        src/web/scraper.c
        src/scripts/build.c
        src/scripts/rmdeps.c
        src/scripts/rmpkgs.c
        src/scripts/uninstall.c
        src/json/filtrejson.c
        src/json/formatjson.c
        src/json/getdata.c
        src/json/prettyprint.c
        src/git/clone.c
)

# Link against libcurl
target_link_libraries(mellow curl)

