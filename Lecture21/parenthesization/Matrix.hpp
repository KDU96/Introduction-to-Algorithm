#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include <thread>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#define  MAX_MATRIX_NUMBER 2
using namespace std;

class Operation{
    public :
        static int sum;
        static void addTwoNum(int x, int y);
};

class Matrix{
    private :
        int row;
        int col;
        int **Mat;
        int get2by2MatrixDeterminant(const int& r, const int& c) const;
        Matrix AdjacencyMatrix();
    public :
        Matrix(const int& r, const int& c);   //  make random matrix
        Matrix(const string& mat);
        ~Matrix();
        Matrix inverse();
        Matrix(const Matrix& source);
        Matrix operator-(const Matrix& source);
        Matrix operator+(const Matrix& source);
        Matrix operator*(const int& multiplier);
        Matrix operator*(const Matrix& source);
        Matrix operator/(const int& dividend);
        Matrix operator=(const Matrix& source);
        int  GetDeterminant() const;
        friend ostream& operator<<(ostream& out, const Matrix& source);
        int getRow() const{return row;}
        int getCol() const{return col;}
};

#endif
