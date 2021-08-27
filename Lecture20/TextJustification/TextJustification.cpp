#include    <iostream>
#include    <string>
#include    <vector>
#include    <limits>
#include    <cmath>
using namespace std;

int TextJustification_Sub(const vector<string>& arr, int WidthConstraint, int start);
void TextJustification_main(const vector<string>& arr, int WidthConstraint);

int main(){
    vector<string> array1;
    cout << "ex1" << endl;
    array1.push_back("This");
    array1.push_back("is");
    array1.push_back("array");
    array1.push_back("for");
    array1.push_back("text");
    array1.push_back("justification");

    TextJustification_main(array1, 16);

    vector<string> array2;
    cout << "ex2" << endl;
    array2.push_back("What");
    array2.push_back("must");
    array2.push_back("be");
    array2.push_back("acknowledgment");
    array2.push_back("shall be");

    TextJustification_main(array2, 16);

    vector<string> array3;
    cout << "ex3" << endl;
    array3.push_back("Science");
    array3.push_back("is");
    array3.push_back("what");
    array3.push_back("we");
    array3.push_back("understand");
    array3.push_back("well");
    array3.push_back("enough");
    array3.push_back("to");
    array3.push_back("explain");
    array3.push_back("to");
    array3.push_back("a");
    array3.push_back("computer.");
    array3.push_back(" Art");
    array3.push_back("is");
    array3.push_back("everything");
    array3.push_back("else");
    array3.push_back("we");
    array3.push_back("do");
    TextJustification_main(array3, 20);
}

void TextJustification_main(const vector<string>& arr, int WidthConstraint){//  total time : O(n^2)
    int startIndex  =   0;
    int tmp =   startIndex;
    while(startIndex < arr.size()){     // # of subproblems : O(arr.size()) =>  O(n)
        if((startIndex  =   TextJustification_Sub(arr, WidthConstraint, startIndex)) == -1){
            for(int i=tmp; i<arr.size(); i++)
                cout << arr[i]  <<  ' ';
            cout << endl;
            break;
        }
        for(int i=tmp; i<=startIndex; i++)
            cout << arr[i] << ' ';

        cout << endl;
        startIndex++;   tmp =   startIndex;
    }
}

int TextJustification_Sub(const vector<string>& arr, int WidthConstraint, int start){
    // n : arr.size()       only use single for loop    ->      O(n)
    vector<int>  length;
    int least, sum=0;
    for(int i=start; i<arr.size(); i++)
        length.push_back(arr[i].length());
    for(int i=1; i<length.size(); i++){
        length[i]   +=  length[i-1];
        length[i]   +=  1;
    }
    for(int i=0; i<length.size(); i++){
        if(length[i] <= WidthConstraint)
            length[i]   =   pow(WidthConstraint - length[i], 2);
        else
            length[i]   =   numeric_limits<int>::max() / arr.size();
    }
    for(int i=0; i<length.size(); i++) sum += length[i];
    if(sum < WidthConstraint)   return -1;

    least   =   0;
    for(int i=1; i<length.size(); i++)
        if(length[least] > length[i])   least   =   i;
    return least + start;
}
