#ifndef _MIN_HEAP_
#define _MIN_HEAP_

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Min_Heap{//prioirty queue
    private :
        int *minheap;
        int arr_size;
        int heapLength;
        void heapify(int index);
        void swap(int *x, int *y);
        void build_minheap();
    public :
        Min_Heap(int arr_size);
        ~Min_Heap();
        int get_min_key() const;
        int extract_highest_prioirty();
        void heap_increase_key(int index, int key);
        void insert_element(int key);
        void insert_random_element(int number);
        bool decrease_key(int i, int key);
};
#endif