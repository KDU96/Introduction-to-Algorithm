#include <iostream>
using namespace std;

#define     CH      100
#define     OK       0
#define     TR      -100000000
#define     ROW     9
#define     COL     9


struct EnryInfo{
    int row;
    int col;
    int value;
};
#if 0
const int Table[ROW][COL]     =   {{OK,  CH,  CH},
                                  {CH,   TR,  OK},
                                  {OK,   CH,  OK}};
#endif
#if 1
const int Table[ROW][COL] = {{OK, OK, OK, OK, OK, OK, OK, OK, OK},
                             {OK, OK, OK, OK, OK, CH, OK, OK, OK},
                             {OK, CH, OK, OK, CH, OK, OK, OK, OK},
                             {OK, OK, OK, OK, OK, TR, OK, TR, OK},
                             {OK, CH, OK, CH, OK, OK, OK, OK ,OK},
                             {OK, OK, OK, OK, CH, TR, OK, OK, OK},
                             {CH, OK, TR, OK, OK, OK, OK, CH, OK},
                             {OK, OK, OK, OK, OK, CH, OK, TR, OK},
                             {OK, OK, CH, OK, OK, OK, OK, OK, OK}};
#endif
int CostTable[ROW][COL];

int findOptimalPath();
int ReturnMax(int& x, int &y);
EnryInfo costFunction(int row, int col);

int main(){
    for(int i=0; i<ROW; i++)
        for(int j=0; j<COL; j++)
            CostTable[i][j] =   0;
    cout << "total cheeze : " << findOptimalPath() / 100 << endl;
}
int ReturnMax(int& x, int &y){
    if(x >= y)  return x;
    return y;
}

EnryInfo costFunction(int row, int col){
    EnryInfo tmp;
    tmp.value   =   ReturnMax(CostTable[row-1][col], CostTable[row][col-1]);
    if(tmp.value == Table[row-1][col]){
        tmp.row     =   row-1;
        tmp.col     =   col;
    }
    else{
        tmp.row     =   row;
        tmp.col     =   col-1;
    }
    return tmp;
}
int findOptimalPath(){
    EnryInfo tmp;
    for(int i=0; i<COL; i++)
        CostTable[0][i]     =   Table[0][i];
    for(int i=1; i < COL; i++)
        CostTable[0][i]     +=  CostTable[0][i-1];
    for(int i=0; i < ROW; i++)
        CostTable[i][0]     =   Table[i][0];
    for(int i=1; i < ROW; i++)
        CostTable[i][0]    +=   CostTable[i-1][0];

    for(int i = 1; i < ROW; i++)
        for(int j = 1; j < COL; j++){
            tmp     =   costFunction(i, j);
            CostTable[i][j]     =   tmp.value + Table[i][j];
        }
    return CostTable[ROW-1][COL-1];

}
