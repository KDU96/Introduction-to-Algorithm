#ifndef _MAX_HEAP_HPP
#define _MAX_HEAP_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class MaxHeap{
    private :
        int *heap;
        int heapSize;
        int arr_size;
        void heapify(int index);     //applying heap property
        void swap(int *x, int *y);
        void build_maxheap();
    public :
        MaxHeap(int arr_size);
        ~MaxHeap();
        int get_max_key() const;
        int extract_high_prioirty();    //for priority queue 
        void insert_element(int key);   //insert
        void insert_random_element(int number); //for test
        void heap_sort();   //heap sort
        bool sort_check();  //function for checking
};
#endif