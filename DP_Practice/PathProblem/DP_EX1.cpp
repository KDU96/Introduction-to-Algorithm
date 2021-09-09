#include <iostream>
#include <vector>
using namespace std;

#define     ROW     8
#define     COL     9

struct MatrixIndex{
    int row;
    int col;
    int value;
};
#if 0
const int Table[3][3]   =   {{3,    4,   9},
                             {223,  7,   8},
                             {2,    51, -23}};
#endif
#if 1
const int Table[8][9]   =  {{3,   4, 9, -2,  2,  51,-23, 2, -1},
                            {223, 7, 8, -11, 5, -99,2,   3, -4},
                            {2,  51,-23,-23, 6, 3,  2,   4,  5},
                            {5, -99, 2, -1, 32, 2,  5,  -99, 2},
                            {6,  3,  3, -4, 2, -1,  6,   3,  3},
                            {32, 2,  4,  5, 3, -4,  2,  -1,  4},
                            {4,  4,  23, 6, 2, -1,  3,  -4, 34},
                            {78, 32, 1,  7, 3, -4, -23, -23, 6}};
#endif
MatrixIndex costFunction(int row, int col);
int FindOptimalPath(vector<MatrixIndex>* Trace, int size);
int ReturnMax(int x, int y, int z);

int main(){
    vector<MatrixIndex> Trace[COL];
    int largest   =   FindOptimalPath(Trace, COL);
    int totalCost   =   Table[ROW-1][largest];
    for(int i=Trace[largest].size() - 1; i >= 0; i--){
        cout << '(' << Trace[largest].at(i).row << ',';
        cout << Trace[largest].at(i).col << ')';
        cout << '\t' << Trace[largest].at(i).value << endl;
        totalCost   +=  Trace[largest].at(i).value;
    }
    cout << '(' << ROW - 1 << ',' << largest << ')' << '\t' << Table[ROW-1][largest] << endl;;
    cout << "Total Cost : " << totalCost << endl;
}


int FindOptimalPath(vector<MatrixIndex>* Trace, int size){
    int CostTable[COL];
    int nextCol;
    
    for(int i=0; i<COL; i++){// initialize
        CostTable[i]    =   Table[ROW-1][i];
    }

    MatrixIndex tmp; 

    for(int i=0; i < COL; i++){
        nextCol     =   i;
        for(int j= ROW - 2; j >= 0; j--){   //  j : row
            tmp          =   costFunction(j, nextCol);
            nextCol      =   tmp.col;
            CostTable[i]+=  tmp.value;
            Trace[i].push_back(tmp);
        }
    }
    for(int i=0; i<COL; i++){
        cout << CostTable[i] << ' ';
    }
    cout << endl;
    int largest = 0;
    for(int i = 0; i < COL; i++){
        if(CostTable[largest] < CostTable[i])
            largest     =   i;
    }
    return largest;
}
int ReturnMax(int x, int y, int z){
    if(x >= y && x >= z)    return x;
    if(y > x && y > z)      return y;
    if(z > x && z > y)      return z; 
    return -1;
}
MatrixIndex costFunction(int row, int col){ // find next entry that has amx cost
    MatrixIndex tmp;
    if(col == 0){
        int max = ReturnMax(0, Table[row][col], Table[row][col+1]);
        if(max == Table[row][col]){
            tmp.col     =   col;
            tmp.row     =   row;
            tmp.value   =   max;
        }
        else{
            tmp.col     =   col+1;
            tmp.row     =   row;
            tmp.value   =   max;
        }
    }
    else if(col == COL - 1){
        int max     =   ReturnMax(Table[row][col-1], Table[row][col], 0);
        if(max == Table[row][col-1]){
            tmp.col     =   col-1;
            tmp.row     =   row;
            tmp.value   =   max;
        }
        else{
            tmp.col     =   col;
            tmp.row     =   row;
            tmp.value   =   max;
        }
    }
    else{
        int max     =   ReturnMax(Table[row][col-1], Table[row][col], Table[row][col+1]);
        if(max == Table[row][col-1]){
            tmp.col     =   col-1;
            tmp.row     =   row;
            tmp.value   =   max;
        }
        else if(max == Table[row][col]){
            tmp.col     =   col;
            tmp.row     =   row;
            tmp.value   =   max;
        }
        else{
            tmp.col     =   col+1;
            tmp.row     =   row;
            tmp.value   =   max;
        }
    }
    return tmp;
}
