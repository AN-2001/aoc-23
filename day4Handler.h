/******************************************************************************\
*  Day4Handler.h                                                               *
*                                                                              *
*  Handles day 4.                                                              *
*                                                                              *
*              Written by Abed Na'ran                          December 2023   *
*                                                                              *
\******************************************************************************/

#ifndef DAY_4_HANDLER
#define DAY_4_HANDLER

#include <iostream>
#include "day.h"
#include "day_4/day_4.h"
#include <assert.h>

#ifdef PART_1 
#undef PART_1
#endif
#ifdef PART_2 
#undef PART_2
#endif
#ifdef PATHS 
#undef PATHS
#endif
#ifdef INPUT 
#undef INPUT
#endif
#ifdef RESULTS1 
#undef RESULTS1
#endif
#ifdef RESULTS2 
#undef RESULTS2
#endif
#ifdef RESULTS2 
#undef HAS_PART_2
#endif

/* Only modify below.                                                         */
/* Enter the paths for the tests.                                             */
static const char 
    *Day4TestPaths[] = {
    "./tests/day_4/test1",
    "./tests/day_4/test2",
    "./tests/day_4/test3",
};
/* Enter the expected results in the same order of the paths.                 */
static int
    Day4ResultsPart1[] = {
    11,
    53,
    22
},
    Day4ResultsPart2[] = {
    11,
    53,
    23
};

/* Modify to the corresponding day.                                           */
#define PART_1 Day4Part1
#define PART_2 Day4Part2
#define PATHS Day4TestPaths
#define RESULTS1 Day4ResultsPart1
#define RESULTS2 Day4ResultsPart2
#define INPUT "./input/day_4.txt"

#ifdef DAY_4_IMPLEMENTED_PART2
#define HAS_PART_2
#endif

class Day4HandlerClass : public DayHandlerClass {
    public:
        ~Day4HandlerClass() = default;
/* DO NOT MODIFY ANYTHING BELOW.                                              */
        void Run() const 
        {
            int Output;
            Output = PART_1(INPUT);
            printf("Part 1: %d.\n", Output);
#ifdef HAS_PART_2
            Output = PART_2(INPUT);
            printf("Part 2: %d.\n", Output);
#else
            (void)RESULTS2; /* Suprress warning. */
#endif /* DAY_4_IMPLEMENTED_PART2 */

        }

        void Test() const
        {
            int Output;
            size_t i,
                NumTests = sizeof(PATHS) / sizeof(PATHS[0]);

            for (i = 0; i < NumTests; i++) {
                CurrentTestPath = PATHS[i];
                Output = Day4Part1(CurrentTestPath);
                ASSERT_EQ(Output, RESULTS1[i]);
            }

#ifdef HAS_PART_2
            for (i = 0; i < NumTests; i++) {
                CurrentTestPath = PATHS[i];
                Output = Day4Part2(CurrentTestPath);
                ASSERT_EQ(Output, RESULTS2[i]);
            }
#endif /* HAS_PART_2 */
        }

};

#undef PART_1
#undef PART_2
#undef PATHS
#undef INPUT
#undef RESULTS1
#undef RESULTS2
#undef HAS_PART_2
#endif /* DAY_4_HANDLER */
