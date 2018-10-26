#!/usr/bin/env bash
set -e




gcc-8 -Wall -Wextra -O2 -std=c11 -c main.c -o main_c.o
g++-8 -Wall -Wextra -O2 -std=c++17 -c strset.cc -o strset.o
g++-8 -Wall -Wextra -O2 -std=c++17 -c hidden.cc -o hidden.o
echo "Building C exec"
g++-8 main_c.o hidden.o strset.o -o c_executable


g++-8 -Wall -Wextra -O2 -std=c++17 -c main.cc -o main_cpp.o
echo "Building C++ exec"
g++-8 main_cpp.o hidden.o strset.o -o cpp_executable

