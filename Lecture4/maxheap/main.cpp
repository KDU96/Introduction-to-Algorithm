#include "maxheap.hpp"

int main(){
    MaxHeap my_heap(1000);

    my_heap.insert_random_element(500);
    my_heap.insert_element(10);
    my_heap.insert_element(999);

    cout << my_heap.extract_high_prioirty() << endl;

    my_heap.heap_sort();
    my_heap.sort_check();
}