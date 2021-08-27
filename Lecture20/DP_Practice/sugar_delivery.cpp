#include    <iostream>
#include    <vector> 
#include    <algorithm>
using namespace std;

int Sugar_Delivery(int N);

int main(){
    cout << "ex 1 : " << Sugar_Delivery(18) << endl;
    cout << "ex 2 : " << Sugar_Delivery(6) << endl;
    cout << "ex 3 : " << Sugar_Delivery(11) << endl;
 }

int Sugar_Delivery(int N){
    int count_3kg = 0, count_5kg = 0;
    int sum;
    vector<int> table;
    
    while(count_3kg <= N / 3){
        count_5kg   =   (N - (count_3kg * 3)) / 5;
        sum         =   count_3kg + count_5kg;
        if(N - (count_3kg * 3 + count_5kg * 5) > 0) sum++;
        table.push_back(sum);
        count_3kg++;   
    }
    sort(table.begin(), table.end());

    return table.at(0);

}