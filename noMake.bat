@echo off
rem Please prefer the makefile lol
rem This is mainly for if you don't have make installed on windows

del game.exe
cls

call checkLibPath.bat
echo === Compiling game.exe ===
g++ -std=c++20 -Wall -Wextra -Wpedantic -O0 -g -D _WINDOWS -Wno-unused-parameter -I ./lib -I ./gameSrc game.cpp -o game.exe -L./lib/windows -lFrameworkRelease_x64
