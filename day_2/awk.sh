# !/bin/bash

cat ../input/day_2.txt | awk  '''
    {
        R = 0;
        G = 0;
        B = 0;
        Failed = 0;
        split($0, Game, ":");
        split(Game[2], Subsets, ";");

        split(Game[1], ID, " ");
        for (i in Subsets) {
            split(Subsets[i], AsCol, ",");
            for (j in AsCol) {
                split(AsCol[j], Pair, " ");
                if (Pair[2] == "red") {
                    if (Pair[1] > R)
                        R = Pair[1];
                    if (Pair[1] > 12)
                        Failed = 1;
                }

                if (Pair[2] == "green") {
                    if (Pair[1] > G)
                        G = Pair[1];
                    if (Pair[1] > 13)
                        Failed = 1;
                }

                if (Pair[2] == "blue") {
                    if (Pair[1] > B)
                        B = Pair[1];
                    if (Pair[1] > 14)
                        Failed = 1;
                }
            }

        }

        if (Failed == 0)
            Sum += ID[2];
        PowerSum += R * G * B;
    }

    END {
        printf("The total is %d\n", Sum);
        printf("The power sum is %d\n", PowerSum);
    }

'''
