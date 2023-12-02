#! /bin/bash
# Performs the following tests:
# -static analysis
# -compliation
# -unit tests
# -valgrind memcheck
#
# By Abed Naa'ran December 2023

make analyze > /dev/null
Res=$?
if test $Res -ne 0; then
    echo 'Failed static analysis, check file.'
    make clean > /dev/null
    exit $Res
fi

make > /dev/null
Res=$?
if test $Res -ne 0; then
    echo 'Failed compilation.'
    make clean > /dev/null
    exit $Res
fi

valgrind --leak-check=full --show-reachable=yes --error-exitcode=10 \
         --log-file="valgrind.out" ./aoc --test
Res=$?
if test $Res -ne 0; then
    case $Res in
    1) echo 'Failed tests.' ;;
    10) echo 'Failed valgrind check, check file.' ;;
    esac
fi

make clean > /dev/null
exit $Res
