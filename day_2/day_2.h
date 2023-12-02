/******************************************************************************\
*  day1.h                                                                      *
*                                                                              *
*  The code for day_2.                                                         *
*                                                                              *
*                                                                              *
*              Written by Abed Na'ran                          December 2023   *
*                                                                              *
\******************************************************************************/


#ifndef DAY_2_H
#define DAY_2_H

#include <string>

#define DAY_2_IMPLEMENTED_PART2 

/******************************************************************************\
* Day2Part2                                                                    *
*                                                                              *
*  Finds the invalid rows I.E rows that don't conform to the specefied         *
*  constraints.                                                                *
*                                                                              *
* Parameters                                                                   *
*                                                                              *
*  -InputPath: The path to the input file.                                     *
*                                                                              *
* Return                                                                       *
*                                                                              *
*  -int: The sum of the IDs of the valid rows.                                 *
*                                                                              *
\******************************************************************************/
int Day2Part1(const std::string &InputPath);

/******************************************************************************\
* Day2Part2                                                                    *
*                                                                              *
*  Finds the sum of the powers of minimoum sets of cubes.                      *
*                                                                              *
* Parameters                                                                   *
*                                                                              *
*  -InputPath: The path to the input file.                                     *
*                                                                              *
* Return                                                                       *
*                                                                              *
*  -int: The sum of the IDs of the valid rows.                                 *
*                                                                              *
\******************************************************************************/
int Day2Part2(const std::string &InputPath);

#endif /* DAY_2_H */
