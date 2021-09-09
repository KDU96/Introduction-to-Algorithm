#ifndef _MATRIX_CPP_
#define _MATRIX_CPP_
#include "Matrix.hpp"

Matrix::Matrix(const int& r, const int& c)
: row(r), col(c)
{

    Mat     =   new int*[row];
    for(int i=0; i < row; i++)
        Mat[i]  =   new int[col];
    srand(time(NULL));
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            Mat[i][j]   =   rand() % MAX_MATRIX_NUMBER;
}
#if 0
Matrix::Matrix(const string& mat){
    string tmp;
    while(1){
        if(mat.at(0) != '[' || mat.at(mat.length()-1) != ']'){
            cout << "enter the right value" << endl;
            break;
        }
    }
}
#endif
//Private Function
void Operation::addTwoNum(int x, int y){
    sum     +=   (x * y);
}
int Operation::sum  =   0;

Matrix::Matrix(const Matrix& source)    //  copy constructor
:row(source.row), col(source.col)
{
    Mat     =   new int*[row];
    for(int i=0; i < row; i++)
        Mat[i]  =   new int[col];
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            Mat[i][j]   =   source.Mat[i][j];
}
Matrix::~Matrix(){
    for(int i=0; i<row; i++)
        delete[]    Mat[i];
    delete[]    Mat;
}
Matrix Matrix::operator-(const Matrix& source){
    if(row != source.row || col != source.col){
        cout << "row/col number error" << endl;
        exit(0);
    }
    Matrix out(row, col);
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            out.Mat[i][j]   =   Mat[i][j] + source.Mat[i][j];
    return out;
}
Matrix Matrix::operator*(const int& multiplier){
    Matrix out(row, col);
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            out.Mat[i][j] *= multiplier;
    return out;
}
Matrix Matrix::operator*(const Matrix& source){
    if(col != source.row){
        cout << "row/col numbers error" << endl;
        exit(0);
    }
    Matrix out(row, source.col);
    thread *t[col];
    for(int i=0; i<row; i++){
        for(int j=0; j<source.col; j++){
            for(int k=0; k < col; k++){
                t[k] = new thread(Operation::addTwoNum, Mat[i][k], source.Mat[k][j]);
            }
            out.Mat[i][j]   =   Operation::sum;
            Operation::sum  =   0;
            for(int k=0; k<col; k++)
                (*t[k]).join();
            for(int k=0; k<col; k++)
                delete t[k];
            
        }
    }     
    return out;
}

Matrix Matrix::operator=(const Matrix& source){
    for(int i=0; i<row; i++)
        delete[] Mat[i];
    delete[] Mat;
    row     =   source.row;
    col     =   source.col;

    Mat     =   new int*[row];
    for(int i=0 ; i<row; i++)
        Mat[i]  =   new int[col];

    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            Mat[i][j]   =   source.Mat[i][j];
    return *this;
}
ostream& operator<<(ostream& out, const Matrix& source){
    for(int i=0; i<source.row; i++){
        out << setw(4) << left << '[';
        for(int j=0; j<source.col; j++)
            out << source.Mat[i][j] << ' ';
        out << " ]" << endl;
    }
    return out;
}
#endif
