#ifndef DAY_1_HANDLER
#define DAY_1_HANDLER

#include <iostream>
#include "day.h"
#include "day_1/day_1.h"
#include <assert.h>

class Day1HandlerClass : public DayHandlerClass {
    public:
        void Run() const 
        {
            int Output;

            Output = Day1Part1("./inputs/day_1.txt");
            printf("Day 1 part 1 output is %d.\n", Output);
#ifdef DAY_1_IMPLEMENTED_PART2
            Output = Day1Part2("./inputs/day_1.txt");
            printf("Day 1 part 2 output is %d.\n", Output);
#endif /* DAY_1_IMPLEMENTED_PART2 */
        }

        void Test() const
        {
            const char 
                *TestPaths[] = {
                "./tests/day_1/test1",
                "./tests/day_1/test2",
                "./tests/day_1/test3",
            };
            int
                ResultsPart1[] = {
                11,
                53,
                22
            },
                ResultsPart2[] = {
                11,
                53,
                23
            };

            int Output;
            size_t i,
                NumTests = sizeof(TestPaths) / sizeof(TestPaths[0]);

            for (i = 0; i < NumTests; i++) {
                CurrentTestPath = TestPaths[i];
                Output = Day1Part1(CurrentTestPath);
                ASSERT_EQ(Output, ResultsPart1[i]);
            }

#ifdef DAY_1_IMPLEMENTED_PART2
            for (i = 0; i < NumTests; i++) {
                CurrentTestPath = TestPaths[i];
                Output = Day1Part2(CurrentTestPath);
                ASSERT_EQ(Output, ResultsPart2[i]);
            }
#endif /* DAY_1_IMPLEMENTED_PART2 */
        }

        ~Day1HandlerClass() = default;
};


#endif /* DAY_1_HANDLER */
