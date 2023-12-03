/******************************************************************************\
*  Day3Handler.h                                                               *
*                                                                              *
*  Handles day 3.                                                              *
*                                                                              *
*              Written by Abed Na'ran                          December 2023   *
*                                                                              *
\******************************************************************************/

#ifndef DAY_3_HANDLER
#define DAY_3_HANDLER

#include <iostream>
#include "day.h"
#include "day_3/day_3.h"
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
    *Day3TestPaths[] = {
    "./tests/day_3/test1",
    "./tests/day_3/test2",
    "./tests/day_3/test3",
};
/* Enter the expected results in the same order of the paths.                 */
static int
    Day3ResultsPart1[] = {
    4361,
    4,
    0
},
    Day3ResultsPart2[] = {
    467835,
    0,
    0
};

/* Modify to the corresponding day.                                           */
#define PART_1 Day3Part1
#define PART_2 Day3Part2
#define PATHS Day3TestPaths
#define RESULTS1 Day3ResultsPart1
#define RESULTS2 Day3ResultsPart2
#define INPUT "./input/day_3.txt"

#ifdef DAY_3_IMPLEMENTED_PART2
#define HAS_PART_2
#endif

class Day3HandlerClass : public DayHandlerClass {
    public:
        ~Day3HandlerClass() = default;
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
#endif /* HAS_PART_2 */
        }

        void Test() const
        {
            int Output;
            size_t i,
                NumTests = sizeof(PATHS) / sizeof(PATHS[0]);

            for (i = 0; i < NumTests; i++) {
                CurrentTestPath = PATHS[i];
                Output = Day3Part1(CurrentTestPath);
                ASSERT_EQ(Output, RESULTS1[i]);
            }

#ifdef HAS_PART_2
            for (i = 0; i < NumTests; i++) {
                CurrentTestPath = PATHS[i];
                Output = Day3Part2(CurrentTestPath);
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
#endif /* DAY_3_HANDLER */
