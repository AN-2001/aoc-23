#include "day_5.h"
#include "config.h"
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <limits.h>
#include <algorithm>

typedef long TYPE;

static inline TYPE ParseInput(std::fstream &File,
                              std::vector<TYPE> &Seeds,
                              std::vector<std::tuple<TYPE, TYPE, TYPE>> Maps[7]);
static inline ResultType EvalMap(std::vector<std::tuple<TYPE, TYPE, TYPE>> &Map,
                                 ResultType Input);
ResultType Day5Part1(const std::string &InputPath)
{
    std::fstream Stream;
    std::vector<TYPE> Seeds;
    std::vector<std::tuple<TYPE, TYPE, TYPE>> Maps[7];
    ResultType Min, CurrVal;
    size_t i, CurrMap;

    Stream.open(InputPath);
    if (!Stream.is_open())
        return 0;
    ParseInput(Stream, Seeds, Maps);
    Min = LONG_MAX;
    for (i = 0; i < Seeds.size(); i++) {
        CurrMap = 0;
        CurrVal = Seeds[i];
        while (CurrMap < 7) {
            CurrVal = EvalMap(Maps[CurrMap], CurrVal);
            CurrMap++;
        }
        Min = std::min(CurrVal, Min);
    }

    return Min;
}

ResultType Day5Part2(const std::string &InputPath)
{
    std::fstream Stream;
    std::vector<TYPE> Seeds;
    std::vector<std::tuple<TYPE, TYPE, TYPE>> Maps[7];
    ResultType Min;
    size_t i, CurrMap;
    TYPE j, MinJmp, CurrVal;

    Stream.open(InputPath);
    if (!Stream.is_open())
        return 0;
    MinJmp = ParseInput(Stream, Seeds, Maps);
    (void)MinJmp;
    Min = LONG_MAX;
    for (i = 0; i < Seeds.size(); i += 2) {
        for (j = Seeds[i];
             j < Seeds[i] + Seeds[i + 1];
             j = j + 1) {
            CurrMap = 0;
            CurrVal = j;

            while (CurrMap < 7) {
                CurrVal = EvalMap(Maps[CurrMap], CurrVal);
                CurrMap++;
            }
            Min = std::min(CurrVal, Min);
        }
    }

    return Min;
}

static inline TYPE ParseInput(std::fstream &File,
                              std::vector<TYPE> &Seeds,
                              std::vector<std::tuple<TYPE, TYPE, TYPE>> Maps[7])
{
    std::string Line;
    const char *Str;
    TYPE a, b, c, Min;
    int Read, CurrMap;

    std::getline(File, Line);
    Str = Line.c_str() + 7; /* Skip to where numbers start. */
    /* Read required seeds.                                                   */
    while (Str[0]) {
        sscanf(Str, "%ld %ld %n", &a, &b, &Read);
        Str += Read;
        Seeds.push_back(a);
        Seeds.push_back(b);
    }

    CurrMap = 0;
    Min = LONG_MAX;
    /* Read all maps.                                                         */
    do {
        /* Skip lines that don't start with numbers.                          */
        while (!isdigit(Line[0])) std::getline(File, Line);
        if (File.eof())
            break;
        /* Once a line starts with a number parse it until we're out.         */
        while (isdigit(Line[0])) {
            sscanf(Line.c_str(), "%ld %ld %ld", &a, &b, &c);
            Maps[CurrMap].push_back(std::make_tuple(a, b, c));
            std::getline(File, Line);
            Min = std::min(Min, c);
        }
        std::sort(Maps[CurrMap].begin(), Maps[CurrMap].end(),
                  [](const auto &v1, const auto &v2) {
                        return std::get<1>(v1) < std::get<1>(v2);
                  });
        CurrMap++; /* Move to next map.                                       */
    } while(!File.eof());
    return Min;
}

static inline ResultType EvalMap(std::vector<std::tuple<TYPE, TYPE, TYPE>> &Map,
                                 ResultType Input)
{
    /* Find the first source less than Input. */
    int i, Dist;

    for (i = Map.size() - 1; i >= 0 && std::get<1>(Map[i]) > Input; i--);
    /* If there's nothing behind it then it doesn't map.                      */
    if (i < 0)
        return Input;
    /* Now Map[i].src is <= Input */
    Dist = Input - std::get<1>(Map[i]);
    if (Dist < std::get<2>(Map[i]))
        return std::get<0>(Map[i]) + Dist;
    /* If it's not in range then it doesn't map.                              */
    return Input;
}
