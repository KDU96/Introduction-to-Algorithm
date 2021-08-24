#include "open_addressing.h"
#include "open_addressing.cpp"

int main(){
    srand(time(0));

    Open_Addressed_Hash<int> hash_with_linearProbing(TABLE_SIZE, LINEAR_PROBING, MANUAL_SIZING);
    Open_Addressed_Hash<int> hash_with_automatical_sizing(TABLE_SIZE, LINEAR_PROBING, AUTOMATIC_SIZING);
    int     temp_element;
    int     log[ELEMENT_SIZE];

    for(int i=0; i<ELEMENT_SIZE; i++){
        log[i] = temp_element;
        hash_with_linearProbing.HashInsert(temp_element);
        hash_with_automatical_sizing.HashInsert(temp_element);
    }
    hash_with_linearProbing.show_hashTable();
    hash_with_automatical_sizing.show_hashTable();

}