#include <iostream>
#include <limits>
using namespace std;

int making1(int n);
int min(int x, int y, int z);

int main(){
    cout << "ex1 : " << making1(1) << endl;
    cout << "ex2 : " << making1(2) << endl;
    cout << "ex3 : " << making1(3) << endl;
    cout << "ex4 : " << making1(4) << endl;
    cout << "ex5 : " << making1(5) << endl;
    cout << "ex6 : " << making1(6) << endl;
    cout << "ex7 : " << making1(7) << endl;
    cout << "ex8 : " << making1(8) << endl;
    cout << "ex9 : " << making1(9) << endl;
    cout << "ex10 : " << making1(10) << endl;
    cout << "ex100 : " << making1(100) << endl;
}

#if 1
int making1(int n){
    if(n <= 0)    return -1;
    else if(n == 1)    return 0;
    else{
        int table[n+1];
        table[0]    =   -1;
        table[1]    =   0;
        table[2]    =   1;
        table[3]    =   1;
        for(int i=4; i<=n; i++){
            if((i % 3 == 0) && (i % 2 == 0))
                table[i]    =   min(table[i/3], table[i/2], table[i-1]) + 1;
            else if((i % 3 == 0) && (i % 2 != 0))
                table[i]    =   min(table[i/3], numeric_limits<int>::max(), table[i-1]) + 1;
            else if((i % 3 != 0) && (i % 2 == 0))
                table[i]    =   min(numeric_limits<int>::max(), table[i/2], table[i-1]) + 1;
            else
                table[i]    =   table[i-1] + 1;
        }
        return table[n];
    }
}
int min(int x, int y, int z){
    if(x <= y && x <= z)      return x;
    else if(y <= x && y <= z) return y;
    else                    return z;
}
#endif