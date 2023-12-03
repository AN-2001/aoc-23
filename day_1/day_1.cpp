#include "day_1.h"
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

static std::unordered_map<std::string, int> DigitMap;
static inline void LoadDigitMap();

ResultType Day1Part1(const std::string &InputPath)
{
    std::ifstream Stream;
    std::string Line;
    int Nums[2], 
        Sum = 0;
    
    Stream.open(InputPath);
    if (!Stream.is_open())
        return 0;
    while (std::getline(Stream, Line)) {
        Nums[0] = Nums[1] = -1;
        for (char c : Line) {
            if (c >= '0' && c <= '9') {
                if (Nums[0] == -1)
                    Nums[0] = (c - '0');
                Nums[1] = Nums[0] * 10 + (c - '0');
            }
        }
        Sum += Nums[1];
    }

    Stream.close();
    return Sum;
}

ResultType Day1Part2(const std::string &InputPath)
{
    std::ifstream Stream;
    std::string Line, DigitStr;
    int Nums[2], Digit,
        Sum = 0;
    size_t i, j;
    char c;

    Stream.open(InputPath);
    if (!Stream.is_open())
        return 0;
    LoadDigitMap();
    while (std::getline(Stream, Line)) {
        Nums[0] = Nums[1] = -1;
        for (i = 0; i < Line.size(); i++) {
            Digit = -1;
            DigitStr = "";
            c = Line[i];

            if (c >= '0' && c <= '9') {
                Digit = c - '0';
                goto END_DIGIT_PARSE;
            }
            for (j = 3; j < 5; j++) {
                DigitStr = Line.substr(i, j);
                if (DigitMap.find(DigitStr) != DigitMap.end()) {
                    Digit = DigitMap[DigitStr];
                    goto END_DIGIT_PARSE;
                }
            }
END_DIGIT_PARSE:

            if (Digit == -1)
                continue;
            
            if (Nums[0] == -1)
                Nums[0] = Digit;
            Nums[1] = Nums[0] * 10 + Digit;
        }
        Sum += Nums[1];
    }

    Stream.close();
    return Sum;
}

static inline void LoadDigitMap()
{
    DigitMap["one"] = 1;
    DigitMap["two"] = 2;
    DigitMap["three"] = 3;
    DigitMap["four"] = 4;
    DigitMap["five"] = 5;
    DigitMap["six"] = 6;
    DigitMap["seven"] = 7;
    DigitMap["eight"] = 8;
    DigitMap["nine"] = 9;
}
