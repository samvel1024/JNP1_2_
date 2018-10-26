#!/usr/bin/env bash
set -e


gcc-8 -Wall -Wextra -O2 -std=c11 -c main.c -o main_c.o
g++-8 -Wall -Wextra -O2 -std=c++17 -c strset.cc -o strset.o
g++-8 -Wall -Wextra -O2 -std=c++17 -c hidden.cc -o hidden.o

g++-8 main_c.o strset.o hidden.o -o executable_c


g++-8 -Wall -Wextra -O2 -std=c++17 -c main.cc -o main_cpp.o
g++-8 main_cpp.o strset.o hidden.o -o executable_cpp
