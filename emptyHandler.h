#ifndef EMPTY_H
#define EMPTY_H
#include "day.h"

class EmptyHandlerClass : public DayHandlerClass {
    public:
        void Run() const 
        {
        }

        void Test() const
        {
        }
        
        ~EmptyHandlerClass() = default;
};

#endif /* EMPTY_H */
