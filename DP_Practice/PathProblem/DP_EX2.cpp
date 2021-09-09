#include <iostream>
#include <vector>
#define     CHEEZE            100
#define     NORMAL              0
#define     ROW                 9
#define     COL                 9
using namespace std;

struct EntryInfo{
    int row;
    int col;
    int value;
};
#if 0
int Table[ROW][COL] = {{NORMAL_COST, NORMAL_COST, NORMAL_COST},
                       {NORMAL_COST, CHEEZE_COST, NORMAL_COST},
                       {NORMAL_COST, NORMAL_COST, NORMAL_COST}};
#endif

int Table[ROW][COL] = {{NORMAL, NORMAL, NORMAL, NORMAL, NORMAL, NORMAL, NORMAL, NORMAL, NORMAL},
                       {NORMAL, NORMAL, NORMAL, NORMAL, NORMAL, CHEEZE, NORMAL, NORMAL, NORMAL},
                       {NORMAL, CHEEZE, NORMAL, NORMAL, CHEEZE, NORMAL, NORMAL, NORMAL, NORMAL},
                       {NORMAL, NORMAL, NORMAL, NORMAL, NORMAL, NORMAL, CHEEZE, NORMAL, NORMAL},
                       {NORMAL, CHEEZE, NORMAL, CHEEZE, NORMAL, NORMAL, NORMAL, NORMAL, NORMAL},
                       {NORMAL, NORMAL, NORMAL, NORMAL, CHEEZE, NORMAL, NORMAL, NORMAL, NORMAL},
                       {CHEEZE, NORMAL, NORMAL, NORMAL, NORMAL, NORMAL, NORMAL, CHEEZE, NORMAL},
                       {NORMAL, NORMAL, NORMAL, NORMAL, NORMAL, CHEEZE, NORMAL, NORMAL, NORMAL},
                       {NORMAL, NORMAL, CHEEZE, NORMAL, NORMAL, NORMAL, NORMAL, NORMAL, NORMAL}};

int CostTable[ROW][COL];

EntryInfo costFunction(int row, int col);
void PrintPathTable();
int findOptimalPath(vector<EntryInfo>& ParentPointer);
int ReturnMax(int& x, int& y);

int main(){
    vector<EntryInfo> trace;
    for(int i=0; i<ROW; i++)
        for(int j=0; j<COL; j++)
            CostTable[i][j] =  0;

    cout << "total cheeze : " << findOptimalPath(trace) / 100 << endl;

#if 0
    for(int i = ROW - 1; i >= 0; i--){
        for(int j = 0; j < COL; j++){
            if(PathTable[i][j]  ==   1)
                cout << "□ " << ' ';
            else
                cout << "■ " << ' ';
        }
        cout << endl;
    }
#endif
}
int findOptimalPath(vector<EntryInfo>& ParentPointer){
    EntryInfo tmp;
    int totalCost = 0;
    for(int i=0; i < COL; i++)
       CostTable[0][i]  =   Table[0][i]; 
    for(int i=1; i < COL; i++)
        CostTable[0][i] += CostTable[0][i-1];
    for(int i=0; i < ROW; i++)
        CostTable[i][0] =   Table[i][0];
    for(int i=1; i < ROW; i++)
        CostTable[i][0] =   CostTable[i-1][0];

    for(int i = 1; i < ROW; i++)
        for(int j = 1; j < COL; j++){
            tmp     =   costFunction(i, j);
            CostTable[i][j] = tmp.value + Table[i][j];
        }
    return CostTable[ROW-1][COL-1];
}
EntryInfo costFunction(int row, int col){
    int max;
    EntryInfo tmp;
    if(row == 0){
        tmp.col     =   col - 1;
        tmp.row     =   row;
        tmp.value   =   Table[row][col-1];
    }
    else if(col == 0){
        tmp.col     =   col;
        tmp.row     =   row - 1;
        tmp.value   =   Table[row-1][col]; 
    }
    else{
        tmp.value   =   ReturnMax(CostTable[row-1][col], CostTable[row][col-1]);
        if(tmp.value == Table[row-1][col]){
            tmp.row     =   row-1;
            tmp.col     =   col;
        }
        else{
            tmp.row     =   row;
            tmp.col     =   col-1;
        }
    }
    return tmp;
    
}
int ReturnMax(int &x, int &y){
    if(x >= y)  return x;
    return y;
}

