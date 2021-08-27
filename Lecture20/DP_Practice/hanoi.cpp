#include <iostream>
using namespace std;

void hanoi_Recursion(int n, char fron, char mid, char rear);

int main(){
    cout << "Recursion Example 1" << endl;
    hanoi_Recursion(1, 'A', 'B', 'C');
    cout << endl;

    cout << "Recursion Example 2 " << endl;
    hanoi_Recursion(50, 'A', 'B', 'C');

    cout << "DP Example 1" << endl;

}

void hanoi_Recursion(int n, char front, char mid, char rear){
    if(n < 1)   return;
    else if(n == 1){
        cout << "disk1 from " << front << " to " << mid << ' ' << endl;
        cout << "disk1 from " << mid << " to " << rear << ' ' << endl;
    }
    else{
        hanoi_Recursion(n-1, front, mid, rear);
        cout << "disk" << n << ' ' << "from " << front << " to " << mid << endl;
        hanoi_Recursion(n-1, rear, mid, front);
        cout << "disk" << n << ' ' << "from " << mid << " to " << rear << endl;
        hanoi_Recursion(n-1, front, mid, rear);
    }
}
