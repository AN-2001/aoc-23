/******************************************************************************\
*  Day5Handler.h                                                               *
*                                                                              *
*  Handles day 5.                                                              *
*                                                                              *
*              Written by Abed Na'ran                          December 2023   *
*                                                                              *
\******************************************************************************/

#ifndef DAY_5_HANDLER
#define DAY_5_HANDLER

#include <iostream>
#include "day.h"
#include "day_5/day_5.h"
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
    *Day5TestPaths[] = {
    "./tests/day_5/test1",
};
/* Enter the expected results in the same order of the paths.                 */
static int
    Day5ResultsPart1[] = {
    35,
},
    Day5ResultsPart2[] = {
    46,
};

/* Modify to the corresponding day.                                           */
#define PART_1 Day5Part1
#define PART_2 Day5Part2
#define PATHS Day5TestPaths
#define RESULTS1 Day5ResultsPart1
#define RESULTS2 Day5ResultsPart2
#define INPUT "./input/day_5.txt"

#ifdef DAY_5_IMPLEMENTED_PART2
#define HAS_PART_2
#endif

class Day5HandlerClass : public DayHandlerClass {
    public:
        ~Day5HandlerClass() = default;
/* DO NOT MODIFY ANYTHING BELOW.                                              */
        void Run(int Part) const 
        {
            int Output;

            if (Part == -1 || Part == 1) {
                Output = PART_1(INPUT);
                printf("Part 1: %d.\n", Output);
            }
#ifdef HAS_PART_2
            if (Part == -1 || Part == 2) {
                Output = PART_2(INPUT);
                printf("Part 2: %d.\n", Output);
            }
#else
            (void)RESULTS2; /* Suprress warning. */
#endif /* DAY_5_IMPLEMENTED_PART2 */

        }

        void Test(int Part) const
        {
            int Output;
            size_t i,
                NumTests = sizeof(PATHS) / sizeof(PATHS[0]);

            if (Part == -1 || Part == 1) {
                std::cout << "Testing part 1:" << std::endl;
                for (i = 0; i < NumTests; i++) {
                    CurrentTestPath = PATHS[i];
                    Output = Day5Part1(CurrentTestPath);
                    ASSERT_EQ(Output, RESULTS1[i]);
                }
            }

#ifdef HAS_PART_2
            if (Part == -1 || Part == 2) {
                std::cout << "Testing part 2:" << std::endl;
                for (i = 0; i < NumTests; i++) {
                    CurrentTestPath = PATHS[i];
                    Output = Day5Part2(CurrentTestPath);
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
#endif /* DAY_5_HANDLER */
