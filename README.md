# Advent of code 2023

2023 advent of code implemented in c++.

The code compiles to a single executable called **aoc**.
Run `./aoc --help` to get a summary of run-time options.

Everyday a script runs to add the new day, it will automatically include and link it with **aoc** so that the focus is only on the day and not the **aoc** system.

Unit tests are also provided under the tests directory.

You need to lightly modify `day#Handler.h` (where # is the number of the day) in order to add new unit tests.


## ./scripts/addDay.sh
Add a new day.

## building:
The project is makefile based, everything is tested under linux.
You may port to other systems by editing makefile.flags but there are no guarantees as I've never done it.
