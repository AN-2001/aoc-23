#include "day_2.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

#define MAX_RED (12)
#define MAX_GREEN (13)
#define MAX_BLUE (14)

/* For a more robust solution do a top-down parser, the grammar is very       */
/* simple.                                                                    */
/* There's no point here as the input is always valid.                        */
/* We'll just implement it in a co-routine style.                             */
/* One function parses and supplies input, the other validates.               */

struct RevealStruct {
    int ID, NumRed, NumGreen, NumBlue, IsNewGame;

    RevealStruct() : ID(-1), NumRed(0), NumGreen(0), NumBlue(0), IsNewGame(0){}
};

struct ContextStruct {
    std::string Row;
    size_t Column, LastID;
    RevealStruct Last;

    ContextStruct() : Row(""), Column(0), LastID(0), Last() {}
};

static inline RevealStruct GetNextReveal(std::ifstream &Stream,
                                         ContextStruct &C0ntext);

ResultType Day2Part1(const std::string &InputPath)
{
    std::ifstream Stream;
    ContextStruct Context;
    RevealStruct Reveal;
    int Sum = 0, Failed = 1;

    Stream.open(InputPath);
    if (!Stream.is_open())
        return 0;
    do {
        Reveal = GetNextReveal(Stream, Context);
        if (Reveal.IsNewGame) {
            if (!Failed)
                Sum += Context.LastID;
            Failed = 0;
        }
        if (Reveal.NumRed > MAX_RED ||
            Reveal.NumGreen > MAX_GREEN ||
            Reveal.NumBlue > MAX_BLUE)
            Failed = 1;
    } while (Reveal.ID != -1);
    return Sum;
}

ResultType Day2Part2(const std::string &InputPath)
{
    std::ifstream Stream;
    ContextStruct Context;
    RevealStruct Reveal;
    int Sum = 0, R, G, B;

    R = G = B = 0;
    Stream.open(InputPath);
    if (!Stream.is_open())
        return 0;
    do {
        Reveal = GetNextReveal(Stream, Context);
        if (Reveal.IsNewGame) {
            Sum += R * G * B;
            R = G = B = 0;
        }
        R = std::max(R, Reveal.NumRed);
        G = std::max(G, Reveal.NumGreen);
        B = std::max(B, Reveal.NumBlue);
    } while (Reveal.ID != -1);
    return Sum;

}

static inline RevealStruct GetNextReveal(std::ifstream &Stream,
                                         ContextStruct &Context)
{
    RevealStruct Ret;
    int NumCubes, Read;

    if (Context.Column >= Context.Row.size()) {
        Context.LastID = Context.Last.ID;
        Context.Column = 0;
        Ret.ID = -1;
        Ret.IsNewGame = true;
        if (!std::getline(Stream, Context.Row))
            return Ret;
    } else {
        Ret.ID = Context.Last.ID;
    }

    if (Ret.IsNewGame) {
        std::sscanf(Context.Row.c_str() + Context.Column,
                    "Game %d: %n", &Ret.ID, &Read);
        Context.Column += Read;
    }

    while (1) {
        /* Now we know we're at a number, read it and check which colour.     */
        std::sscanf(Context.Row.c_str() + Context.Column,
                    "%d %n", &NumCubes, &Read);
        Context.Column += Read;
        switch (Context.Row[Context.Column]) {
            case 'r':
                Ret.NumRed = NumCubes;
                Context.Column += 3;
                break;
            case 'b':
                Ret.NumBlue = NumCubes;
                Context.Column += 4;
                break;
            case 'g':
                Ret.NumGreen = NumCubes;
                Context.Column += 5;
        }

        if (Context.Column >= Context.Row.size())
            goto END;
        switch (Context.Row[Context.Column]) {
            case ',':
                Context.Column += 2;
                break;
            case ';':
                Context.Column += 2;
                goto END;
        }
    }

END:
    Context.Last = Ret;
    return Ret;
}
