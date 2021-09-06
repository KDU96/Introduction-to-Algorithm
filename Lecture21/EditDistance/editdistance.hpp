#ifndef __EDIT_DISTANCE_HPP_
#define __EDIT_DISTANCE_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include <vector>

using namespace std;
struct CostInfo{
    int row;
    int col;
    int cost;
};

class StringEditDistance{
    private :
        string x;
        string y;
        int**   distanceTable;
   //     vector<Path> pathTable;
        int  findMinValue(const int& x, const int& y, const int& z) const;
        void EditDistanceByDP();
        CostInfo costFunction(int row, int col);



    public :
        StringEditDistance(const string& source, const string& target);
        ~StringEditDistance();
        void printDistanceTable() const;
        int getCost() const;
};



#endif
