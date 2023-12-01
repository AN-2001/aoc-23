/******************************************************************************\
*  day1.h                                                                      *
*                                                                              *
*  The code for day_1.                                                         *
*                                                                              *
*                                                                              *
*              Written by Abed Na'ran                          December 2023   *
*                                                                              *
\******************************************************************************/


#ifndef DAY_1_H
#define DAY_1_H

#include <string>

#define DAY_1_IMPLEMENTED_PART2 

/******************************************************************************\
* Day1Part2                                                                    *
*                                                                              *
*  Solves the first digit, last digit problem without string parsing.          *
*                                                                              *
* Parameters                                                                   *
*                                                                              *
*  -InputPath: The path to the input file.                                     *
*                                                                              *
* Return                                                                       *
*                                                                              *
*  -int: The sum of all 2 digit numbers in the file.                           *
*                                                                              *
\******************************************************************************/
int Day1Part1(const std::string &InputPath);

/******************************************************************************\
* Day1Part2                                                                    *
*                                                                              *
*  Solves the first digit, last digit problem with string parsing.             *
*                                                                              *
* Parameters                                                                   *
*                                                                              *
*  -InputPath: The path to the input file.                                     *
*                                                                              *
* Return                                                                       *
*                                                                              *
*  -int: The sum of all 2 digit numbers in the file.                           *
*                                                                              *
\******************************************************************************/
int Day1Part2(const std::string &InputPath);

#endif /* DAY_1_H */
