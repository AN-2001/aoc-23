/******************************************************************************\
*  day.h                                                                       *
*                                                                              *
*  Implements the day handler class and the day class                          *
*  Both of which are responsible for running and testing days.                 *
*                                                                              *
*                                                                              *
*              Written by Abed Na'ran                          December 2023   *
*                                                                              *
\******************************************************************************/
#ifndef DAY_H
#define DAY_H

#include <string>

/* For tests, tests equality.                                                 */
#define ASSERT_EQ(v1, v2) AssertEq(v1, v2)

/* Current run mode.                                                          */
enum ModeEnum {
    MODE_RUN,
    MODE_TEST
};

/* Saves the path to the current test.                                        */
extern const char *CurrentTestPath;

/******************************************************************************\
* AssertEq                                                                     *
*                                                                              *
*  Does nothing if v1 == v2, otherwise reports an error and exits with code 1. *
*                                                                              *
* Parameters                                                                   *
*                                                                              *
*  -v1: The first value.                                                       *
*  -v2: The second value.                                                      *
*                                                                              *
* Return                                                                       *
*                                                                              *
*  -void.                                                                      *
*                                                                              *
\******************************************************************************/
void AssertEq(int v1, int v2);

/* The day handler interface, runs or tests a day.                            */
/* All the handlers should implement this interface.                          */
class DayHandlerClass {
    public:
    virtual void Run() const = 0;
    virtual void Test() const = 0;
    virtual ~DayHandlerClass() = default;
};

/* The day class, stores the name and the corresponding handler.              */
class DayClass {
    public:
        std::string Name;
    private:
        const DayHandlerClass *Handler;   
    public:
        DayClass(const std::string &Name, const DayHandlerClass *Handler);
        void Handle(ModeEnum Mode) const;
        ~DayClass();
};

#endif /* DAY_H */
