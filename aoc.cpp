#include <unistd.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include "day.h"
#include "inc.h"
#include <string.h>

const static DayClass Days[] = {
    {"day_1", new Day1HandlerClass()},
    {"", new EmptyHandlerClass()},
};

const static struct option 
    Options[] = {
        {"day", required_argument, 0, 0},
        {"mode", required_argument, 0, 0},
        {"run", no_argument, 0, 0},
        {"test", no_argument, 0, 0},
        {0, 0, 0, 0}
    };
static std::string Day = ""; 
static ModeEnum Mode = MODE_RUN;
static inline void ReadArgs(int argc, char * const *argv);
static inline void HandleDay(const std::string &Day, ModeEnum Mode);
static inline void HandleAllDays(ModeEnum Mode);
int main(int argc, char * const *argv)
{
    ReadArgs(argc, argv);


    if (Day != "")
        HandleDay(Day, Mode); 
    else
        HandleAllDays(Mode);

    return 0;
}

static inline void ReadArgs(int argc, char * const *argv)
{
    int Ret, Index;

    while ((Ret = getopt_long(argc, argv, "", Options, &Index)) != -1) {
        switch (Index) {
            case 0:
                Day = optarg;
                break;
            case 1:
                if (strcmp(optarg, "run") == 0)
                    Mode = MODE_RUN;
                else if (strcmp(optarg, "test") == 0) 
                    Mode = MODE_TEST;
                else {
                    fprintf(stderr, "Unrecognized mode, aborting.\n");
                    std::exit(1);
                }
                break;
            case 2:
                Mode = MODE_RUN;
                break;
            case 3:
                Mode = MODE_TEST;
                break;
        }
    }

}

static inline void HandleDay(const std::string &Day, ModeEnum Mode)
{
    int i;

    for (i = 0; Days[i].Name != ""; i++) {
        if (Days[i].Name == Day) {
            Days[i].Handle(Mode);
            return;
        }
    }
    std::cout << "Invalid day." << std::endl;
}

static inline void HandleAllDays(ModeEnum Mode)
{
    int i;

    for (i = 0; Days[i].Name != ""; i++)
            Days[i].Handle(Mode);
}
