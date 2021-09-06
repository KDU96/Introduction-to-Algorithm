#include "editdistance.hpp"

StringEditDistance::StringEditDistance(const string& source, const string& target)
: x(source), y(target)
{
    distanceTable   =   new int*[y.size()+1];
    for(int i=0; i <= y.size(); i++)
        distanceTable[i]    =   new int[x.size()+1];
    for(int i = 0; i < y.size(); i++)
        for(int j = 0; j < x.size(); j++)
            distanceTable[i][j]  =   0;
    for(int i = 0; i < x.size(); i++)
        distanceTable[y.size()][i]   =   x.size() - i;
    for(int i = 0; i< y.size() ;i++)
        distanceTable[i][x.size()]   =   y.size() - i;    
    distanceTable[y.size()][x.size()]   =   0;
    EditDistanceByDP();
}
StringEditDistance::~StringEditDistance(){
    for(int i=0; i<=y.size(); i++)
        delete[]    distanceTable[i];
    delete[]    distanceTable;
}
void StringEditDistance::EditDistanceByDP(){
    CostInfo    msg;
    for(int i = y.size() - 1; i >=0 ; i--)
        for(int j = x.size() - 1; j >=0; j--){
            msg =   costFunction(i, j);
            distanceTable[i][j] = distanceTable[msg.row][msg.col] + msg.cost;
        }
}
CostInfo StringEditDistance::costFunction(int row, int col){
    int deletionCost, insertionCost, replacementCost;
    CostInfo msg;
    //  deletionCost
    deletionCost    =   1;  insertionCost   =   1;
    row--;  col--;
    if(x.at(col+1) == y.at(row+1))      replacementCost    =   0;
    else                             replacementCost    =   numeric_limits<int>::max();
    msg.cost = findMinValue(deletionCost, insertionCost, replacementCost);
    if(replacementCost > insertionCost){
        msg.row =   row+1;
        msg.col =   col + 2;
    }
    else{
        msg.row     =   row + 2;
        msg.col     =   col + 2;
    }
    return msg;
}
int StringEditDistance::findMinValue(const int& x, const int& y, const int& z) const{
    if(x <= y && x<= z)
        return x;
    else if(y < x && y < z)
        return y;
    else
        return z;
}
void StringEditDistance::printDistanceTable() const{
    for(int i=0; i<=y.size(); i++){
        for(int j=0; j<=x.size(); j++)
            cout << setw(15) << left << distanceTable[i][j] << ' ';
        cout << endl;
    }
}
int StringEditDistance::getCost() const{
    return distanceTable[0][0];
}