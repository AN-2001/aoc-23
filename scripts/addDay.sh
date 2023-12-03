#! /bin/bash
# Add a new day.
#
# By Abed Naa'ran December 2023

LastDay=`ls day_* -d | cut -d '_' -f 2 | sort -nr | head -1`
NewDay=`echo "$LastDay + 1" | bc`
NewDir=day_$NewDay
NewFile=day_$NewDay
NewHandler=./day$NewDay'Handler.h'
DD="Day$NewDay"
Class="HandlerClass()"
NewHandlerClass="new $DD$Class"
cp -r day_1 $NewDir
cp ./day1Handler.h $NewHandler

sed -i "s/day_1/$NewFile/g" $NewHandler
sed -i "s/day 1/day $NewDay/g" $NewHandler
sed -i "s/DAY_1/DAY_$NewDay/g" $NewHandler
sed -i "s/Day1/Day$NewDay/g" $NewHandler
sed -i "13a#include \"`basename $NewHandler`\"" ./inc.h
sed -i "21a{\"day_$NewDay\", $NewHandlerClass}," ./aoc.cpp

pushd $NewDir
mv day_1.cpp $NewFile.cpp
mv day_1.h $NewFile.h
sed -i "s/day_1/$NewFile/g" *.cpp *.h makefile
sed -i "s/day 1/day $NewDay/g" *.cpp *.h makefile
sed -i "s/DAY_1/DAY_$NewDay/g" *.cpp *.h makefile
sed -i "s/Day1/Day$NewDay/g" *.cpp *.h makefile
popd 

cp -r ./tests/day_1 ./tests/day_$NewDay
