#! /bin/bash
# Add a new day.
#
# By Abed Naa'ran December 2023

LastDay=`ls day_* -d | cut -d '_' -f 2 | sort -nr | head -1`
NewDay=`echo "$LastDay + 1" | bc`
NewDir=day_$NewDay
NewFile=day_$NewDay
cp -r day_1 $NewDir

pushd $NewDir
mv day_1.cpp $NewFile.cpp
mv day_1.h $NewFile.h
sed -i "s/day_1/$NewFile/g" makefile
popd 


