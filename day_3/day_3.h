/******************************************************************************\
*  day1.h                                                                      *
*                                                                              *
*  The code for day_3.                                                         *
*                                                                              *
*                                                                              *
*              Written by Abed Na'ran                          December 2023   *
*                                                                              *
\******************************************************************************/

#ifndef DAY_3_H
#define DAY_3_H

#include <string>
#include "config.h"

#define DAY_3_IMPLEMENTED_PART2 

/******************************************************************************\
* Day3Part2                                                                    *
*                                                                              *
*  Finds the part numbers in the engine map.                                   *
*                                                                              *
* Parameters                                                                   *
*                                                                              *
*  -InputPath: The path to the input file.                                     *
*                                                                              *
* Return                                                                       *
*                                                                              *
*  -ResultType: The sum of all part numbers.                                   *
*                                                                              *
\******************************************************************************/
ResultType Day3Part1(const std::string &InputPath);

/******************************************************************************\
* Day3Part2                                                                    *
*                                                                              *
*  Finds all the gears and calculates their gear ratio.                        *
*                                                                              *
* Parameters                                                                   *
*                                                                              *
*  -InputPath: The path to the input file.                                     *
*                                                                              *
* Return                                                                       *
*                                                                              *
*  -ResultType: The sum of all gear ratios.                                    *
*                                                                              *
\******************************************************************************/
ResultType Day3Part2(const std::string &InputPath);

#endif /* DAY_3_H */
