#include "day.h"
#include <cstdio>

const char *CurrentTestPath = NULL;
void AssertEq(int v1, int v2)
{
    if (v1 == v2)
        return;

    fprintf(stderr, "Assert failed on test %s : %d != %d.\n",
                CurrentTestPath, v1, v2);
    std::exit(1);
}

DayClass::DayClass(const std::string &Name, const DayHandlerClass *Handler)
    : Name(Name), Handler(Handler)
{
}

/******************************************************************************\
* DayClass:Handle                                                              *
*                                                                              *
*  Handles the day, either runs it to produce the output or tests it against   *
*  our provided tests.                                                         *
*                                                                              *
* Parameters                                                                   *
*                                                                              *
*  -Mode: The run mode.                                                        *
*                                                                              *
* Return                                                                       *
*                                                                              *
*  -void.                                                                      *
*                                                                              *
\******************************************************************************/
void DayClass::Handle(ModeEnum Mode, int Part) const
{
    switch (Mode) {
        case MODE_RUN:
            Handler -> Run(Part);
            break;
        case MODE_TEST:
            Handler -> Test(Part);
            break;
    }
}

/******************************************************************************\
*  DayClass:~DayClass                                                          *
*                                                                              *
*  Destructor for DayClass.                                                    *
*                                                                              *
*              Written by Abed Na'ran                          <date>          *
*                                                                              *
\******************************************************************************/
DayClass::~DayClass() 
{
    /* Just free the handler.                                                 */
    delete Handler;
}
