cmake_minimum_required(VERSION 3.29)
project(mellow)

set(OBJECT_DIR "${CMAKE_SOURCE_DIR}/obj")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)
add_compile_options(-Ofast)

add_executable(setup
        setup/setup.c
        setup/mkdir.cpp
        setup/curl.c
        setup/parser/ini.c
        setup/rmdir.cpp
        setup/parser/translate.c
        setup/parser/writefile.c
        setup/parser/ini/formatfield.cpp
        include/files.h
        setup/install.c
        setup/checkpkgs.c
        setup/string/string.cpp
        setup/tools/makepkg.c
        setup/scripts/getmissing.c
        setup/string/string.c
        setup/parser/readfile.c
        setup/tools/downloadpkg.c
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

target_link_libraries(setup curl git2)
target_link_libraries(mellow curl)

add_custom_command(TARGET setup POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_BINARY_DIR}/CMakeFiles/setup.dir ${OBJECT_DIR}/setup
)

add_custom_command(TARGET mellow POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_BINARY_DIR}/CMakeFiles/mellow.dir ${OBJECT_DIR}/mellow
)

