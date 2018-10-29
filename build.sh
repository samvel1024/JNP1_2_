#!/usr/bin/env bash
set -e

gcc=$1
gpp=$2

${gcc} -Wall -Wextra -O2 -std=c11 -c main.c -o main_exec_c.o
${gpp} -Wall -Wextra -O2 -std=c++17 -c strset.cc -o strset.o
${gpp} -Wall -Wextra -O2 -std=c++17 -c strsetconst.cc -o strsetconst.o
${gpp} main_exec_c.o strsetconst.o strset.o -o main_exec_c


${gpp} -Wall -Wextra -O2 -std=c++17 -c main.cc -o main_exec_cpp.o
${gpp} main_exec_cpp.o strsetconst.o strset.o -o main_exec_cpp



${gpp} -Wall -Wextra -O2 -std=c++17 -c strset_test2a.cc -o 2acc.o
${gpp} 2acc.o strsetconst.o strset.o -o 2acc_exec


${gpp} -Wall -Wextra -O2 -std=c++17 -c strset_test2b.cc -o 2bcc.o
${gpp} 2bcc.o strsetconst.o strset.o -o 2bcc_exec

