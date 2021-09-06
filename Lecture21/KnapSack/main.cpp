#include "knapsack.hpp"

int main(){
    KnapSack myClass(100);
    
    int result = myClass.findMaxValue();
    cout << "result : " << result << endl;
}
