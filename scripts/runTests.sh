#! /bin/bash

make analyze
Res=$?
if test $Res -ne 0; then
    make clean
    exit $Res
fi
make -j8
./aoc --test
Res=$?
make clean
exit $Res
