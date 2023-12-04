#include "day_4.h"
#include "config.h"
#include <cstdio>
#include <fstream>
#include <string>
#include <istream>
#include <set>
#include <vector>
#include <memory.h>

static inline void HandleCard(const std::string &Card,
                              ResultType *NumPoints = NULL,
                              ResultType *NumWinning = NULL);

ResultType Day4Part1(const std::string &InputPath)
{
    std::ifstream File;
    std::string Line;
    ResultType Points,
        Total = 0;

    File.open(InputPath);
    if (!File.is_open())
        return 0;
    while (std::getline(File, Line)) {
        HandleCard(Line, &Points);
        Total += Points;
    }

    return Total;
}

ResultType Day4Part2(const std::string &InputPath)
{
    std::ifstream File;
    std::string Line;
    int Counts[256];
    ResultType NumWinnings,
            Total = 0;
    size_t j,
           i = 0;

    memset(Counts, 0, sizeof(Counts));
    File.open(InputPath);
    if (!File.is_open())
        return 0;
    while (std::getline(File, Line)) {
        HandleCard(Line, NULL, &NumWinnings);
        Counts[i]++;
        Total += Counts[i];
        for (j = i + 1; j <= i + NumWinnings; j++)
            Counts[j] += Counts[i];
        i++;
    }

    return Total;
}

static inline void HandleCard(const std::string &Card,
                              ResultType *NumPoints,
                              ResultType *NumWinning)
{
    int Num, Read;
    const char
        *Str = Card.c_str();
    int Winning[256];

    if (NumWinning)
        *NumWinning = 0;
    if (NumPoints)
        *NumPoints = 0;

    memset(Winning, 0, sizeof(Winning));
    sscanf(Str, "Card %d: %n", &Num, &Read);
    Str += Read;
    while (Str[0] != '|') {
        sscanf(Str, "%d %n", &Num, &Read);
        Str += Read;
        Winning[Num] = 1;
    }
    Str++;
    while (Str[0]) {
        sscanf(Str, "%d %n", &Num, &Read);
        Str += Read;
        if (Winning[Num]) {
            if (NumWinning)
                (*NumWinning)++;
            if (NumPoints) {
                if (!*NumPoints)
                    *NumPoints = 1;
                else
                    (*NumPoints) = *NumPoints * 2;
            }
        }
    }
}
