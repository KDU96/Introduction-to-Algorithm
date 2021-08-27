#include <iostream>
using   namespace   std;

int fibonacci_DP(int n);

int main(){
    cout << "fibo : " << fibonacci_DP(6) << endl;

}

int fibonacci_DP(int n){
    int memo[n+1];
    memo[1] =   1;
    memo[2] =   1;

    for(int i=3; i<=n; i++){
        memo[i] = memo[i-1] + memo[i-2];
    }
    return memo[n];
}