#ifndef _BASIC_SORT_CPP_
#define _BASIC_SORT_CPP_
#define MAX_VALUE   100
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class Basic_Sort{
    private :
        int *arr;
        int arrSize;
    public :
        Basic_Sort(int size);
        ~Basic_Sort(){delete[] arr;}
        void swap(int *x, int *y){int t = *x; *x = *y; *y = t;}
        void insertionSort();
        bool is_sorted() const;
        int* getArray_address() const;
        int getArrSize() const;
};
Basic_Sort::Basic_Sort(int size)
:arrSize(size)
{
    srand(time(0));
    arr = new int[arrSize];
    for(int i=0; i<arrSize; i++)
        arr[i] = rand() % MAX_VALUE;
#if 1
    cout << "@@ random number @@" << endl;
    for(int i=0; i<arrSize; i++)
        cout << arr[i] << ' ';
    cout << endl;
#endif
}
void Basic_Sort::insertionSort(){
    cout << " @@insertion sort @@" << endl;
    int i, j, tmp;
    for(int i=1; i < arrSize; i++){
        tmp = arr[i];
        for(j = i-1; j >=0; j--){
            if(tmp < arr[j]){
                arr[j+1] = arr[j];
            }
            else
                break;
        }
        arr[j+1] = tmp;
    }
}

bool Basic_Sort::is_sorted() const{
    cout << "@@ check sorted array @@" << endl;
#if 0
    for(int i=0; i<arrSize; i++)
        cout << arr[i] << ' ';
    cout << endl;
#endif
    for(int i=0; i<arrSize-1; i++){
        if(arr[i] > arr[i+1]){
            cout << "the sort is failed" << endl;
            return false;
        }
    }
    return true;
}
int* Basic_Sort::getArray_address() const{
    return arr;
}
int Basic_Sort::getArrSize() const{
    return arrSize;
}
#if 0
int main(){
    Basic_Sort sort(100);
    sort.insertionSort();
    sort.is_sorted();
}   
#endif
#endif