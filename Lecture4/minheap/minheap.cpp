#include "minheap.hpp"

// constructor and destructor
Min_Heap::Min_Heap(int arr_s)
:arr_size(arr_s), heapLength(0){
    minheap = new int[arr_size];
    minheap[1] = -1;
}
Min_Heap::~Min_Heap(){
    delete[] minheap;
}

// private method
void Min_Heap::heapify(int index){
    int smallest;
    if(2 * index <= heapLength && minheap[2*index] < minheap[index])
        smallest = 2 * index;
    else
        smallest = index;
    
    if(2 * index + 1 <= heapLength && minheap[2*index + 1] < minheap[smallest])
        smallest = 2*index + 1;
    
    if(smallest != index){
        swap(&minheap[index], &minheap[smallest]);
        heapify(smallest);
    }
}
void Min_Heap::swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
void Min_Heap::build_minheap(){
    for(int i=heapLength / 2; i >=1; i--)
        heapify(i);
}

//public method
int Min_Heap::get_min_key() const{
    return minheap[1];
}
int Min_Heap::extract_highest_prioirty(){
    int element_with_highest_prioirty = minheap[1];
    minheap[1] = minheap[heapLength--];
    heapify(1);
    return element_with_highest_prioirty;
}
void Min_Heap::insert_element(int key){
    minheap[++heapLength] = key;
    for(int i = heapLength; i > 1; i /= 2){
        if(minheap[i / 2] > minheap[i])
            swap(&minheap[i/2], &minheap[i]);
        else
            break;
    }
}
void Min_Heap::insert_random_element(int number){
    heapLength = number;
    srand(time(0));
    for(int i=1; i<=heapLength; i++)
        minheap[i] = rand() % 1000;
    build_minheap();
}
bool Min_Heap::decrease_key(int i, int key){
    if(key > minheap[i]){
        cout << "input error" << endl;
        return false;
    }
    minheap[i] = key;
    for(int idx = i; idx > 1; idx /= 2){
        if(minheap[idx / 2] > minheap[idx])
            swap(&minheap[idx/2], &minheap[i]);
        else
            break;
    }
    return true;
}