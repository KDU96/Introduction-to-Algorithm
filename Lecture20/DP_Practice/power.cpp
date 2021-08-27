#include <iostream>
using namespace std;

int pow(int base, int index){
    int result = 1;
    int table[index+1];
    table[1] = base;
    for(int i=2; i<=index; i++){
        table[i] = base * table[i-1];
    }
    return table[index];
}

int main(){
    cout << pow(2, 10) << endl;
}