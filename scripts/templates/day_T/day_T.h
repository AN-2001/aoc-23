/******************************************************************************\
*  day1.h                                                                      *
*                                                                              *
*  The code for day_T.                                                         *
*                                                                              *
*                                                                              *
*              Written by Abed Na'ran                          December 2023   *
*                                                                              *
\******************************************************************************/

#ifndef DAY_T_H
#define DAY_T_H

#include <string>
#include "config.h"

#define DAY_T_IMPLEMENTED_PART2 

/******************************************************************************\
* DayTPart2                                                                    *
*                                                                              *
*  Solution for part 1.                                                        *
*                                                                              *
* Parameters                                                                   *
*                                                                              *
*  -InputPath: The path to the input file.                                     *
*                                                                              *
* Return                                                                       *
*                                                                              *
*  -ResultType: The result.                                                    *
*                                                                              *
\******************************************************************************/
ResultType DayTPart1(const std::string &InputPath);

/******************************************************************************\
* DayTPart2                                                                    *
*                                                                              *
*  Solution for part 2.                                                        *
*                                                                              *
* Parameters                                                                   *
*                                                                              *
*  -InputPath: The path to the input file.                                     *
*                                                                              *
* Return                                                                       *
*                                                                              *
*  -ResultType: The result.                                                    *
*                                                                              *
\******************************************************************************/
ResultType DayTPart2(const std::string &InputPath);

#endif /* DAY_T_H */
