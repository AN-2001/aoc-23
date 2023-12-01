#! /bin/bash

make -j8
./aoc --test
Res=$?
make clean
exit $Res
