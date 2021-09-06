#ifndef __KNAPSACK_HPP_
#define __KNAPSACK_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#define DIVSION 15

using namespace std;

class Item{
    public :
        int size;
        int value;
};

bool Compare(const Item& x, const Item& y);

class KnapSack{
    private :
        int KnapSackSize;
        vector<Item> BunchOfItem;
        void RandomItemCreation(const int& itemSize);
    public :
        KnapSack(const int& kSize, const int& itemSize = 10);
        ~KnapSack();
        void showItem() const;
        int findMaxValue();
};
        






#endif
