#include "day_3.h"
#include <cctype>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/file.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <memory.h>

#define NUM_COLS (141)
#define NUM_ROWS (140)
#define INDEX(r, c) ((c) + (r) * (NUM_COLS))

static inline bool NearSymbol(char *Buff, int r, int c);
static inline bool NearNumber(char *Buff,
                              int r, int c,
                              ResultType &Val);
ResultType Day3Part1(const std::string &InputPath)
{
    int
        fd = open(InputPath.c_str(), O_RDONLY);
    char *Buff, Curr;
    struct stat StatBuff;
    int i, j,
        Num = 0;
    bool 
        IsValid = false;
    ResultType
        Sum = 0;

    if (fd < 0)
        return 0;

    fstat(fd, &StatBuff);
    Buff = static_cast<char*>(mmap(NULL, StatBuff.st_size, PROT_READ,
                                   MAP_SHARED, fd, 0));
    if (!Buff)
        return 0;

    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            Curr = Buff[INDEX(i, j)];

            if (std::isdigit(Curr)) {
                Num = Num * 10 + (Curr - '0');
                IsValid = IsValid || NearSymbol(Buff, i, j);
            } else {
                if (IsValid)
                    Sum += Num;
                Num = 0;
                IsValid = false;
            }
        }
    }

    munmap(Buff, StatBuff.st_size);
    close(fd);
    return Sum;
}

ResultType Day3Part2(const std::string &InputPath)
{
    int
        fd = open(InputPath.c_str(), O_RDONLY);
    char *Buff, Curr;
    struct stat StatBuff;
    int i, j;
    ResultType Val,
        Sum = 0;

    if (fd < 0)
        return 0;

    fstat(fd, &StatBuff);
    Buff = static_cast<char*>(mmap(NULL, StatBuff.st_size, PROT_READ,
                                   MAP_SHARED, fd, 0));
    if (!Buff)
        return 0;

    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            Curr = Buff[INDEX(i, j)];

            if (Curr == '*' && NearNumber(Buff, i, j, Val)) {
                Sum += Val;
            }
        }
    }

    munmap(Buff, StatBuff.st_size);
    close(fd);
    return Sum;
}

static inline bool NearNumber(char *Buff,
                              int r, int c,
                              ResultType &Val)
{
    int i, j, k,
        Num = 0,
        NumFound = 0;
    char Curr;
    bool Mask[3][3];

    memset(Mask, 0, sizeof(Mask));
    Val = 1;
    for (i = std::max(r - 1, 0); i <= std::min(r + 1, NUM_ROWS - 1); i++) {
        for (j = std::max(c - 1, 0); j <= std::min(c + 1, NUM_COLS - 2); j++) {
            Curr = Buff[INDEX(i, j)];
            if (std::isdigit(Curr) && !Mask[i - r + 1][j - c + 1]) {
                k = j;
                /* Go to the far left. */
                while (k >= 0 && std::isdigit(Buff[INDEX(i, k)])) k--;
                k++; /* Skip the first symbol or dot. */

                Num = 0;
                while (std::isdigit(Buff[INDEX(i, k)])) {
                    Mask[i - r + 1][std::min(std::max(k - c + 1, 0), 2)] = true;
                    Num = Num * 10 + Buff[INDEX(i, k)] - '0';
                    k++;
                }
                Val = Val * Num;
                NumFound++;
            }
        }
    }

    return NumFound == 2;
}

static inline bool NearSymbol(char *Buff, int r, int c)
{
    int i, j;
    char Curr;

    for (i = std::max(r - 1, 0); i <= std::min(r + 1, NUM_ROWS - 1); i++) {
        for (j = std::max(c - 1, 0); j <= std::min(c + 1, NUM_COLS - 2); j++) {
            Curr = Buff[INDEX(i, j)];
            if (Curr != '.' && !std::isdigit(Curr))
                return true;
        }
    }

    return false;
}

