/******************************************************************************\
*  DayTHandler.h                                                               *
*                                                                              *
*  Handles day T.                                                              *
*                                                                              *
*              Written by Abed Na'ran                          December 2023   *
*                                                                              *
\******************************************************************************/

#ifndef DAY_T_HANDLER
#define DAY_T_HANDLER

#include <iostream>
#include "day.h"
#include "day_T/day_T.h"
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
    *DayTTestPaths[] = {
    "./tests/day_T/test1",
};
/* Enter the expected results in the same order of the paths.                 */
static int
    DayTResultsPart1[] = {
    0,
},
    DayTResultsPart2[] = {
    0,
};

/* Modify to the corresponding day.                                           */
#define PART_1 DayTPart1
#define PART_2 DayTPart2
#define PATHS DayTTestPaths
#define RESULTS1 DayTResultsPart1
#define RESULTS2 DayTResultsPart2
#define INPUT "./input/day_T.txt"

#ifdef DAY_T_IMPLEMENTED_PART2
#define HAS_PART_2
#endif

class DayTHandlerClass : public DayHandlerClass {
    public:
        ~DayTHandlerClass() = default;
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
#endif /* DAY_T_IMPLEMENTED_PART2 */

        }

        void Test() const
        {
            int Output;
            size_t i,
                NumTests = sizeof(PATHS) / sizeof(PATHS[0]);

            for (i = 0; i < NumTests; i++) {
                CurrentTestPath = PATHS[i];
                Output = DayTPart1(CurrentTestPath);
                ASSERT_EQ(Output, RESULTS1[i]);
            }

#ifdef HAS_PART_2
            for (i = 0; i < NumTests; i++) {
                CurrentTestPath = PATHS[i];
                Output = DayTPart2(CurrentTestPath);
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
#endif /* DAY_T_HANDLER */
