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

void DayClass::Handle(ModeEnum Mode) const
{
    switch (Mode) {
        case MODE_RUN:
            Handler -> Run();
            break;
        case MODE_TEST:
            Handler -> Test();
            break;
    }
}

DayClass::~DayClass() 
{
    delete Handler;
}
