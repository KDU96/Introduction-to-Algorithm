#ifndef _FINGERING_HPP_
#define _FINGERING_HPP_

#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int StringFingeringCost[5][5] = {{0, 1, 2, 3, 4},
                                       {4, 0, 1, 2, 3},
                                       {3, 4, 0, 1, 2},
                                       {2, 3, 4, 0, 1},
                                       {1, 2, 3, 4, 0}};
enum GuitarString{
    FIRST,
    SECOND,
    THIRD,
    FOURTH,
    FIFTH,
};
enum FingerNumber{
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
};
struct FingerAndCostMsg{
    unsigned int fingerNum;
    int cost;
};

bool Compare(const FingerAndCostMsg& A, const FingerAndCostMsg& B);

class Fingering{
    private :
        vector<unsigned int> NoteSequence;
        int NoteSequenceSize;
        FingerAndCostMsg *optimalFingering;
        int findOptimalFingering(); 
        FingerAndCostMsg costFunction(int index, int f);

    public  :
        Fingering(const int& size);
        ~Fingering();
        void printFingering() const;

};

#endif
