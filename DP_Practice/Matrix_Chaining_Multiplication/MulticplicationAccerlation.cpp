#include "../../Lecture21/parenthesization/Matrix.hpp"
#include "../../Lecture21/parenthesization/Matrix.cpp"
#include <list>
#include <vector>
#include <limits>

#define MatrixNum   4

void BruteForce(list<Matrix*>& MatList);
void MatrixProductionAcceleration(list<Matrix*>& MatList);

int main(){
    Matrix* mat[MatrixNum];
    list<Matrix*> MatList;
    clock_t start, end;
    

    mat[0] =    new Matrix(10, 100);
    mat[1] =    new Matrix(100, 200);
    mat[2] =    new Matrix(200, 50);
    mat[3] =    new Matrix(50, 20);

    for(int i=0; i < MatrixNum; i++)
        MatList.push_back(mat[i]);

#if 1
    start   =   clock();
//    (*mat[0]) * (*mat[1]) * (*mat[2]) * (*mat[3]);
    BruteForce(MatList); 
    end     =   clock();
    cout << "Brute Force : " << static_cast<float>(end - start) / CLOCKS_PER_SEC << endl;

    start   =   clock();
    MatrixProductionAcceleration(MatList);
    end     =   clock();
    cout << "Acceleration : " << static_cast<float>(end - start) / CLOCKS_PER_SEC << endl;
    
    for(int i=0; i <MatrixNum; i++)
        delete  mat[i];
#endif
}

#if 1
void BruteForce(list<Matrix*>& MatList){
    list<Matrix*>::iterator iter = MatList.begin();

    Matrix  output(**iter);
    iter++;

    while(iter != MatList.end()){
       output = output * (**iter);
       iter++;
    }
#if 0
    cout << "output : " << endl;
    cout << output << endl;
#endif
}
#endif
void MatrixProductionAcceleration(list<Matrix*>& MatList){
   list<Matrix*>::iterator iter =   MatList.begin(); 
   list<Matrix*>::iterator childIter;
   list<Matrix*>::iterator searchingIter;
   Matrix output(1, 1);
   vector<int> CostTable;
   int count;
    
   while(MatList.size() > 1){
       //initialize
         count    =   0;
         CostTable.clear();
         searchingIter  =   MatList.begin();
         iter           =   MatList.begin();

         while(count < MatList.size() - 1){
             childIter     =   iter;
             childIter++;
             if((**iter).getCol()   ==   (**childIter).getRow())      
                CostTable.push_back((**iter).getRow() * (**iter).getCol() * (**(++iter)).getCol());
             else
                 CostTable.push_back(numeric_limits<int>::max());
             count++;
        }
        int least = 0;
        for(int i=1; i < CostTable.size(); i++){
            if(CostTable[least] > CostTable[i]) least   =   i; 
        }
        for(int i=0; i < CostTable.size(); i++)
            cout << CostTable[i] << ' ';
        cout << endl;

        for(int i=0; i<least; i++)  searchingIter++;
        childIter   =   searchingIter;  childIter++;
        output  =   (**searchingIter) * (**(childIter));
        MatList.insert(searchingIter, &output);
        childIter   =   searchingIter;
        childIter++;
        MatList.erase(searchingIter);
        MatList.erase(childIter);
   }
}
