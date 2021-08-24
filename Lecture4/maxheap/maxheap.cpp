#include "maxheap.hpp"

//consturctor and destructor
MaxHeap::MaxHeap(int a_size)
: heapSize(0), arr_size(a_size)
{
    heap = new int[arr_size];
    heap[0] = -1;
}
MaxHeap::~MaxHeap(){
    delete[] heap;
}

//private function
void MaxHeap::swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
void MaxHeap::heapify(int index){
    int largest;
    if(2 *index <= heapSize && heap[2*index] > heap[index]) 
       largest = 2 * index;
    else
        largest = index;
    if(2*index+1 <= heapSize && heap[2*index+1] > heap[largest])
        largest = 2 * index + 1;
    if(largest != index){
        swap(&heap[index], &heap[largest]);
        heapify(largest);
    }
}
void MaxHeap::build_maxheap(){
    for(int i = heapSize/2; i >= 1; i--)
        heapify(i);
}
//public method
int MaxHeap::get_max_key() const{
    return heap[1];
}
int MaxHeap::extract_high_prioirty(){
    int key_with_high_prioirty = heap[1];
    heap[1] = heap[heapSize--];
    heapify(1);
    return key_with_high_prioirty;
}
void MaxHeap::insert_element(int key){
    heap[++heapSize] = key;
    build_maxheap();
}
void MaxHeap::insert_random_element(int number){
    heapSize = number;
    srand(time(0));
    for(int i=1; i<=heapSize; i++)
        heap[i] = rand() % 1000;
    build_maxheap();
}
void MaxHeap::heap_sort(){//O(nlogn)
    int tmp = heapSize;
    while(heapSize > 1){    //O(n)
        swap(&heap[1], &heap[heapSize]);
        heapSize--;
        heapify(1);     //O(logn)
    }
    heapSize = tmp;
}
bool MaxHeap::sort_check(){
    for(int i=1; i<=heapSize-1; i++)
        if(heap[i] > heap[i+1]){
            cout << "sort is failed" << endl;
            return false;
        }
    return true;
}