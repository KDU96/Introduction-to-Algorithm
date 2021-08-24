#ifndef     _OPEN_ADDRESSING_CPP_
#define     _OPEN_ADDRESSING_CPP_

#include     "open_addressing.h"

template<class T>
Open_Addressed_Hash<T>::Open_Addressed_Hash(int size, unsigned char method, unsigned char s_method)
:hash_method(method), element_count(0), sizing_method(s_method)
{
    if(sizing_method == MANUAL_SIZING){
        tableSize   =   size;
        hashTable   =   new Hashed_Element<T>[tableSize];
        for(int i=0; i<tableSize; i++){
             hashTable[i].key   =    -1;
             hashTable[i].log   =    false;
         }
    }
    else{
        tableSize   =   1;
        hashTable   =   new Hashed_Element<T>[tableSize];
        for(int i=0; i<tableSize; i++){
            hashTable[i].key    =   -1;
            hashTable[i].log    =   false;
        }
    }
}
template<class T>
Open_Addressed_Hash<T>::~Open_Addressed_Hash(){
    delete[] hashTable;
}
template<class T>
bool Open_Addressed_Hash<T>::HashInsert(const T& item){
    int key = static_cast<int>(item);
    hashing(key, item);
    if(hashTable[key].log == true){
           return false;
           cout << "hashing error" << endl;
    }
    hashTable[key].item     =    item;
    hashTable[key].log      =    true;
    hashTable[key].key      =    key;
    element_count++;
    return true;
}

template<class T>
bool Open_Addressed_Hash<T>::HashDelete(const T& item){
    int result = HashSearch(item);
    if(result == -1){
        cout << "search is failed" << endl;
        return false;
    }
    hashTable[result].log   =   false;
    element_count--;
    return true;
}
#if 0
template<class T>
int Open_Addressed_Hash<T>::HashSearch(const T& item) const{
    int key     =   item.key;    
}
#endif

template<class T>
bool Open_Addressed_Hash<T>::hashing(int& key, const T& item){
    key %= tableSize;
    if(hash_method == LINEAR_PROBING){
        int count = 0;
        while(hashTable[key].item = item || hashTable[key].log == false){
            key = (key+1) % tableSize;
            count++;
            if(count >= tableSize)  return false;
        }
    }
    else if(hash_method == DOUBLE_HASHING){

    }
    else if(hash_method ==  QUADRATIC_PROBING){

    }
}
template<class T>
void Open_Addressed_Hash<T>::show_hashTable() const{
    cout << "hash table" << endl;
    for(int i=0; i<tableSize; i++){
        cout << '[' << i << ']' << ' ' << hashTable[i].item;
        cout << endl;
    }
    cout << endl;
}
template<class T>
void Open_Addressed_Hash<T>::updateTableSize(){
    // if   m < n/4     -->     shrink
    // if   m > n/4     -->     doubling
    if(element_count < tableSize / 4){  // shrink
        Hashed_Element<T>  buffer[element_count];
        for(int i=0; i<element_count; i++){
            buffer[i]   =   hashTable[i];
        }
        delete[]    hashTable;
        hashTable   =   new Hashed_Element<T>[4 * tableSize];
        for(int i=0; i<element_count; i++)  hashTable[i]    =   buffer[i];
        for(int i=element_count; i<4*tableSize; i++){
            hashTable[i].key    =   -1;
            hashTable[i].log    =   false;
        }
        tableSize   *=  4;
    } 
    else{   //  doubling
        Hashed_Element<T>  buffer[element_count];
        for(int i=0; i<element_count; i++)
            buffer[i]   =   hashTable[i];
        
        delete[]    hashTable;
        hashTable   =   new Hashed_Element<T>[4 * tableSize];
        for(int i=0; i < element_count; i++)    hashTable[i]    =   buffer[i];
        for(int i=element_count; i < tableSize/4; i++){
            hashTable[i].key    =   -1;
            hashTable[i].log    =   false;
        }
        tableSize   /=  4;
    }
}


#endif