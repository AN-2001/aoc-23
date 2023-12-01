#ifndef DAY_H
#define DAY_H

#include <string>

#define ASSERT_EQ(v1, v2) AssertEq(v1, v2)

enum ModeEnum {
    MODE_RUN,
    MODE_TEST
};

extern const char *CurrentTestPath;
void AssertEq(int v1, int v2);

class DayHandlerClass {
    public:
    virtual void Run() const = 0;
    virtual void Test() const = 0;
    virtual ~DayHandlerClass() = default;
};

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
