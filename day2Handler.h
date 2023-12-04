/******************************************************************************\
*  Day2Handler.h                                                               *
*                                                                              *
*  Handles day 1.                                                              *
*                                                                              *
*              Written by Abed Na'ran                          December 2023   *
*                                                                              *
\******************************************************************************/

#ifndef DAY_2_HANDLER
#define DAY_2_HANDLER

#include <iostream>
#include "day.h"
#include "day_2/day_2.h"
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
    *Day2TestPaths[] = {
    "./tests/day_2/test1",
    "./tests/day_2/test2",
    "./tests/day_2/test3",
};
/* Enter the expected results in the same order of the paths.                 */
static int
    Day2ResultsPart1[] = {
    8,
    0,
    0
},
    Day2ResultsPart2[] = {
    2286,
    40,
    60
};


/* Modify to the corresponding day.                                           */
#define PART_1 Day2Part1
#define PART_2 Day2Part2
#define PATHS Day2TestPaths
#define RESULTS1 Day2ResultsPart1
#define RESULTS2 Day2ResultsPart2
#define INPUT "./input/day_2.txt"

#ifdef DAY_2_IMPLEMENTED_PART2
#define HAS_PART_2
#endif

class Day2HandlerClass : public DayHandlerClass {
    public:
        ~Day2HandlerClass() = default;
/* DO NOT MODIFY ANYTHING BELOW.                                              */
        void Run(int Part) const 
        {
            int Output;

            if (Part == -1 || Part == 1) {
                Output = PART_1(INPUT);
                printf("Part 1: %d.\n", Output);
            }

            /* Suppress warning. */
            (void)(Day2ResultsPart2);
#ifdef HAS_PART_2
            if (Part == -1 || Part == 2) {
                Output = PART_2(INPUT);
                printf("Part 2: %d.\n", Output);
            }
#endif /* DAY_2_IMPLEMENTED_PART2 */
        }

        void Test(int Part) const
        {
            int Output;
            size_t i,
                NumTests = sizeof(PATHS) / sizeof(PATHS[0]);

            if (Part == -1 || Part == 1) {
                for (i = 0; i < NumTests; i++) {
                    CurrentTestPath = PATHS[i];
                    Output = Day2Part1(CurrentTestPath);
                    ASSERT_EQ(Output, RESULTS1[i]);
                }
            }

#ifdef HAS_PART_2
            if (Part == -1 || Part == 2) {
                for (i = 0; i < NumTests; i++) {
                    CurrentTestPath = PATHS[i];
                    Output = Day2Part2(CurrentTestPath);
                    ASSERT_EQ(Output, RESULTS2[i]);
                }
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
#endif /* DAY_2_HANDLER */
