# Advent of code

2023 advent of code implemented in c++.

The code compiles to a single executable called **aoc**.
Run {./aoc --help} to get a summary of run-time options.
Adding days is automated, each day a script is ran to add a new day.
The new day is implemented and automatically included in **aoc**.
Unit tests are also provided.

## ./scripts/addDay.sh
Add a new day.

## building:
The project is makefile based, everything is tested under linux.
You may port to other systems by editing makeflags but there are no guarantees as I've never done it.

By Abed Na'aran
