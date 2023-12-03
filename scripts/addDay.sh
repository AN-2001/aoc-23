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
cp -r ./scripts/templates/day_T $NewDir
cp ./scripts/templates/dayTHandler.h $NewHandler

sed -i "s/day_T/$NewFile/g" $NewHandler
sed -i "s/day T/day $NewDay/g" $NewHandler
sed -i "s/DAY_T/DAY_$NewDay/g" $NewHandler
sed -i "s/DayT/Day$NewDay/g" $NewHandler
sed -i "13a#include \"`basename $NewHandler`\"" ./inc.h
sed -i "22a{\"day_$NewDay\", $NewHandlerClass}," ./aoc.cpp

pushd $NewDir
mv day_T.cpp $NewFile.cpp
mv day_T.h $NewFile.h
sed -i "s/day_T/$NewFile/g" *.cpp *.h makefile
sed -i "s/day T/day $NewDay/g" *.cpp *.h makefile
sed -i "s/DAY_T/DAY_$NewDay/g" *.cpp *.h makefile
sed -i "s/DayT/Day$NewDay/g" *.cpp *.h makefile
popd 

cp -r ./scripts/templates/day_T_test ./tests/day_$NewDay
