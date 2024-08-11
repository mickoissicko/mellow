#!/usr/bin/env bash

BinFolder='build'
SrcFolder='src'
ObjFolder='obj'

for SrcFile in "$SrcFolder"/*.c; do
    Base=$(basename "$SrcFile" .c)

    Out="${ObjFolder}/${Base}.o"

    gcc -c "$SrcFile" -o "$Out"
done

for SrcFile in "$SrcFolder"/*.cpp; do
    Base=$(basename "$SrcFile" .cpp)

    Out="${ObjFolder}/${Base}.o"

    g++ -c "$SrcFile" -o "$Out"
done

for SrcFile in "$SrcFolder"/scraper/*.c; do
    Base=$(basename "$SrcFile" .c)

    Out="${ObjFolder}/${Base}.o"

    gcc -c "$SrcFile" -o "$Out"
done

for SrcFile in "$SrcFolder"/json/*.c; do
    Base=$(basename "$SrcFile" .c)

    Out="${ObjFolder}/${Base}.o"

    gcc -c "$SrcFile" -o "$Out"
done

