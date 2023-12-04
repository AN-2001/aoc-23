#ifndef EMPTY_H
#define EMPTY_H
#include "day.h"

class EmptyHandlerClass : public DayHandlerClass {
    public:
        void Run(int Part) const 
        {
            (void)Part;
        }

        void Test(int Part) const
        {
            (void)Part;
        }
        
        ~EmptyHandlerClass() = default;
};

#endif /* EMPTY_H */
