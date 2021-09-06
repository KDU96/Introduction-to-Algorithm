#include "knapsack.hpp"

KnapSack::KnapSack(const int& KSize, const int& itemSize)
:KnapSackSize(KSize)
{ 
    srand(time(NULL));
    RandomItemCreation(itemSize);
    sort(BunchOfItem.begin(), BunchOfItem.end(), Compare);
 
}
KnapSack::~KnapSack(){
}
void KnapSack::RandomItemCreation(const int& itemSize){
    Item tmp;
    for(int i=0; i<itemSize; i++){
        tmp.size    =   rand() % DIVSION + DIVSION;
        tmp.value   =   rand() % DIVSION;
        BunchOfItem.push_back(tmp);
    }
}

int KnapSack::findMaxValue(){
    showItem();
    int sumOfValue = 0;
    int sumOfSize  = 0;
    for(int i = BunchOfItem.size() - 1; i >= 0; i--){
        if(BunchOfItem.at(i).size + sumOfSize <= KnapSackSize){
            sumOfSize += BunchOfItem.at(i).size;
            sumOfValue += BunchOfItem.at(i).value;
        }
    }
    return sumOfValue;
}
void KnapSack::showItem() const{
    for(int i=0; i < BunchOfItem.size(); i++)
        cout << "size : " << BunchOfItem.at(i).size << "  value : " << BunchOfItem.at(i).value << endl;
}
bool Compare(const Item& x, const Item& y){
    return x.value < y.value;
}
