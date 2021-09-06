#include    <iostream>
#include    <cstdlib>
#include    <ctime>
#include    <list>
#include    <vector> 

#define     MAX_ELEMENT_SIZE    10
using namespace std;

// Implement the substring problem as the Matrix Production Operation

class MatrixRowColInfo{
    public :
        int row;
        int col;
};
class Matrix
{
    public :
        MatrixRowColInfo info;
        int** mat2D;
};

// Functions' Prototype
bool MatrixProduct(Matrix& result, Matrix& source1, Matrix& source2);  // 2D matrix product operaition
bool MakingRandomMatrix(Matrix& source, const int& row, const int& col);
void DeleteMatrix(Matrix& source);
void PrintMatrix(const Matrix& source);
void SequentialMatrixOperation(list<Matrix>& ml, int size);

int main(){

        srand(time(NULL));
        list<Matrix> matrixList;
        Matrix A[8];

        MakingRandomMatrix(A[0], 10, 1);
        MakingRandomMatrix(A[1], 1, 10);
        MakingRandomMatrix(A[2], 10, 1);
        MakingRandomMatrix(A[3], 1, 10);
        MakingRandomMatrix(A[4], 10, 10);
        MakingRandomMatrix(A[5], 10, 1);
        MakingRandomMatrix(A[6], 1, 10);
        MakingRandomMatrix(A[7], 10, 1);

        for(int i=0; i<8; i++)
            matrixList.push_back(A[i]);

       SequentialMatrixOperation(matrixList, 8);
    
}
#if 0
void SequentialMatrixOperation(list<Matrix>& ml, int size){ // cost : row * col
    vector<int> costMatrix;
    while(ml.size() > 1){
        costMatrix.clear();
        for(int i=0; i < ml.size() - 1; i++){
        }
}
#endif


bool MatrixProduct(Matrix& result, Matrix& source1, Matrix& source2){  //result = source1 * source2
    if(source1.info.col != source2.info.row){
        cout << "Matrix Entry False" << endl;
        return false;
    }
    result.info.row =   source1.info.row;
    result.info.col =   source2.info.col;
    result.mat2D = new int*[source1.info.row];

    for(int i=0; i < source1.info.row; i++)
        result.mat2D[i]     =   new int[source2.info.col];

    for(int i=0; i< result.info.row; i++)
        for(int j=0; j<result.info.col; j++)
            result.mat2D[i][j]  =   0;

    for(int i=0; i < result.info.row; i++)
        for(int j=0; j<result.info.col; j++)
            for(int k=0; k<source1.info.col; k++)
                result.mat2D[i][j]  +=   (source1.mat2D[i][k] * source2.mat2D[k][j]);
    return true;
}

bool MakingRandomMatrix(Matrix& source, const int& row, const int& col){
    source.info.col =   col;
    source.info.row =   row;

    source.mat2D    =   new int*[source.info.row];
    for(int i=0; i < source.info.row; i++)
        source.mat2D[i]  =   new int[source.info.col];

    for(int i=0; i < source.info.row; i++)
        for(int j=0; j<source.info.col; j++)
            source.mat2D[i][j]  =   rand() % MAX_ELEMENT_SIZE;
    return true;
}

void DeleteMatrix(Matrix& source){
    for(int i=0; i<source.info.col; i++)    delete[]    source.mat2D[i];
    delete[]    source.mat2D;
}
void PrintMatrix(const Matrix& source){
    for(int i=0; i<source.info.row; i++){
        for(int j=0; j<source.info.col; j++)
            cout << source.mat2D[i][j]  << ' ';
        cout << endl;
    }
}
