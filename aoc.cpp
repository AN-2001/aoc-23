/******************************************************************************\
*  aoc.c                                                                       *
*                                                                              *
*  The advent of code day handler.                                             *
*  Runs/Tests advent of code.                                                  *
*                                                                              *
*              Written by Abed Na'ran                          December 2023   *
*                                                                              *
\******************************************************************************/
#include <unistd.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <chrono>
#include "day.h"
#include "inc.h"
#include <string.h>

/* All the supported days.                                                    */
const static DayClass Days[] = {
{"day_4", new Day4HandlerClass()},
{"day_3", new Day3HandlerClass()},
{"day_2", new Day2HandlerClass()},
{"day_1", new Day1HandlerClass()},
{"", new EmptyHandlerClass()},
};

static const char * const
    Usage = "The advent of code runner.\n"
            "Usage:\n"  
            "\t%s {--help} {--day=[day]} {--mode=[test/debug]} {--test} {--run)\n"
            "\thelp: Display this message.\n"
            "\tday: Day to use, uses all days if not specefied.\n"
            "\tmode: Mode to run in, run to run against aot input, test to run tests.\n"
            "\trun: Run aot input.\n"
            "\ttest: Run tests.\n"
            "\ttime: Output the run-time of each day.\n"
            SIGNATURE;
    

const static struct option 
    Options[] = {
        {"day", required_argument, 0, 0}, 
        {"mode", required_argument, 0, 0}, 
        {"run", no_argument, 0, 0},
        {"test", no_argument, 0, 0},
        {"help", no_argument, 0, 0},
        {"time", no_argument, 0, 0},
        {0, 0, 0, 0}
    };
/* Parsed arguments.                                                          */
static std::string Day = ""; 
static bool ShowTime = false;
static ModeEnum Mode = MODE_RUN;

/* Read and parse arguments.                                                  */
static inline void ReadArgs(int argc, char * const *argv);

/* Handle a single day.                                                       */
static inline void HandleDay(const std::string &Day, ModeEnum Mode);

/* Handle all days.                                                            */
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
            case 4:
                printf(Usage, argv[0]);
                exit(0);
                break;
            case 5:
                ShowTime = true;
                break;
        }
    }

}

static inline void HandleDay(const std::string &Day, ModeEnum Mode)
{
    int i;
    std::chrono::steady_clock::time_point Start, End;

    for (i = 0; Days[i].Name != ""; i++) {
        if (Days[i].Name == Day) {
            if (Mode != MODE_TEST)
                std::cout << "Running " << Days[i].Name << "." << std::endl;
            else
                std::cout << "Testing " << Days[i].Name << "." << std::endl;
            Start = std::chrono::steady_clock::now();
            Days[i].Handle(Mode);
            End = std::chrono::steady_clock::now();
            if (Mode == MODE_TEST) 
                std::cout << "Passed all tests." << std::endl;
            if (ShowTime)
                std::cout << "Ran in "
                          << std::chrono::duration_cast<std::chrono::microseconds>(End - Start).count() * 1e-6
                          << " [s]" << std::endl;
            return;
        }
    }
    std::cout << "Invalid day." << std::endl;
}

static inline void HandleAllDays(ModeEnum Mode)
{
    int i;
    std::chrono::steady_clock::time_point Start, End;

    for (i = 0; Days[i].Name != ""; i++) {
        if (Mode != MODE_TEST)
            std::cout << "Running " << Days[i].Name << "." << std::endl;
        else
            std::cout << "Testing " << Days[i].Name << "." << std::endl;
        Start = std::chrono::steady_clock::now();
        Days[i].Handle(Mode);
        End = std::chrono::steady_clock::now();
        if (Mode == MODE_TEST) 
            std::cout << "Passed all tests." << std::endl;
        if (ShowTime)
            std::cout << "Ran in "
                      << std::chrono::duration_cast<std::chrono::microseconds>(End - Start).count() * 1e-6
                      << " [s]" << std::endl;
    }
}
