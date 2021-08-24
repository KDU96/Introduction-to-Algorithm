#include "minheap.hpp"

int main(){
    Min_Heap my_heap(200);

    my_heap.insert_random_element(10);

    my_heap.insert_element(1);
    my_heap.insert_element(2);
    my_heap.decrease_key(4, 1);
    for(int i=0; i<11; i++)
        cout << my_heap.extract_highest_prioirty() << ' ';
    
    cout << endl;
}