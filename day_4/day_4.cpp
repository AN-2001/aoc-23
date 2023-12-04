#include "day_4.h"
#include "config.h"
#include <cstdio>
#include <fstream>
#include <string>
#include <istream>
#include <set>
#include <vector>

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
    std::vector<int> Winnings, Counts;
    ResultType NumWinnings,
            Total = 0;
    size_t i, j;

    File.open(InputPath);
    if (!File.is_open())
        return 0;
    while (std::getline(File, Line)) {
        HandleCard(Line, NULL, &NumWinnings);
        Winnings.push_back(NumWinnings);
        Counts.push_back(1);
    }

    for (i = 0; i < Winnings.size(); i++)
        for (j = i + 1; j <= i + Winnings[i]; j++)
            Counts[j] += Counts[i];
    for (i = 0; i < Counts.size(); i++)
        Total += Counts[i];
    return Total;
}

static inline void HandleCard(const std::string &Card,
                              ResultType *NumPoints,
                              ResultType *NumWinning)
{
    int Num, Read;
    const char
        *Str = Card.c_str();
    std::set<int> Winning;

    if (NumWinning)
        *NumWinning = 0;
    if (NumPoints)
        *NumPoints = 0;

    std::sscanf(Str, "Card %d: %n", &Num, &Read);
    Str += Read;
    while (Str[0] != '|') {
        std::sscanf(Str, "%d %n", &Num, &Read);
        Str += Read;
        Winning.insert(Num);
    }
    Str++;
    while (Str[0]) {
        std::sscanf(Str, "%d %n", &Num, &Read);
        Str += Read;
        if (Winning.count(Num)) {
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
