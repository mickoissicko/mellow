cmake_minimum_required(VERSION 3.29)
project(mellow)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/home/mickey/Documents/projects/CLion/mellow/build/")
set(OBJECT_DIR "${CMAKE_SOURCE_DIR}/obj")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)
add_compile_options(-Ofast)

add_executable(mellow
        src/files.cpp
        src/mellow.c
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
        src/setup/setup.c
        src/setup/mkdir.cpp
        src/setup/curl.c
        src/parser/ini.c
        src/setup/rmdir.cpp
        src/setup/scripts/translate.c
        src/setup/fileio/writefile.c
        src/setup/scripts/formatfield.cpp
        include/files.h
        src/setup/install.c
        src/setup/checkpkgs.c
        src/setup/string/string.cpp
        src/setup/tools/makepkg.c
        src/setup/scripts/getmissing.c
        src/setup/string/string.c
        src/setup/fileio/readfile.c
        src/setup/tools/downloadpkg.c
        src/main.c
        src/parser/html.cpp
)

target_link_libraries(mellow curl git2)

add_custom_command(TARGET mellow POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_BINARY_DIR}/CMakeFiles/mellow.dir ${OBJECT_DIR}/mellow
)

