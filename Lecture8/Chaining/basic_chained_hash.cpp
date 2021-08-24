#ifndef _BASIC_CHAINED_HASH_CPP_
#define _BASIC_CHAINED_HASH_CPP_
#include "basic_chained_hash.hpp"

//Constructor & Destructor
template <typename T>
Basic_Chained_Hash<T>::Basic_Chained_Hash(int s, unsigned char method){
    srand(time(0));
    size = s;
    hash_function = method;
    hashPtr = new Hashed_Element<T>*[size];
    count = new char[size];
    for(int i=0; i<size; i++){
        hashPtr[i] = NULL;
        count[i] = 0;
    }
    a = rand() % HASH_VAR_LIMIT;
    b = rand() % HASH_VAR_LIMIT;
    R_for_multiplication_value = static_cast<unsigned long>(rand()) | (static_cast<unsigned long>(rand()) << 32);
}
template<typename T>
Basic_Chained_Hash<T>::~Basic_Chained_Hash(){
    Hashed_Element<T> *p, *q;
    for(int i=0; i<size; i++){
        p = hashPtr[i];
        while(p != NULL){
            q = p;
            p = p->next;
            delete q;  
        }
    }
    delete[] hashPtr;
    delete[] count;
}

//hash function with division method
template<typename T>
void Basic_Chained_Hash<T>::hash_method(int& key){
    if(hash_function == DIVISION_METHOD){
        key %= size;
    }
    else if(hash_function == UNIVERSAL_METHOD){
        key = ((a * key + b) % PRIME_NUMBER) % size;
    }
    else if(hash_function == MULTIPLICATION_METHOD){
        unsigned long tmp = static_cast<unsigned long>(key);
        tmp = R_for_multiplication_value * tmp;
        tmp &= 0xffff;
        key = (static_cast<int>(tmp) >> (32 - rand() % 32)) % size;
    }
}

template<typename T>
bool Basic_Chained_Hash<T>::Chained_Hash_Insert(const Hashed_Element<T>& element){
    int key = element.key;
    Hashed_Element<T>* newNode = new Hashed_Element<T>;
    if(!newNode){
        cout << "memory allocation error" << endl;
        return false;
    }
    newNode->item = element.item;
    newNode->next = newNode->pre = NULL;
    hash_method((key));
    newNode->key = key;
    Hashed_Element<T> *p = hashPtr[key];
    if(!p){
        hashPtr[key] = newNode;
    }else{
        while(p->next)
            p = p->next;
        p->next = newNode;
        newNode->pre = p;
    }
    count[key]++;
    return true;
}
template<typename T>
bool Basic_Chained_Hash<T>::Chained_Hash_Delete(const Hashed_Element<T>& element){
    Hashed_Element<T>* p;
    if(!Search_Element(element, &p)) return false;
    else{
        int key = element.key;
        hash_method(key);
        if(!p->pre){
            if(p->next){
                hashPtr[key] = p->next;
                p->next->pre = NULL;
            }
            else{
                hashPtr[key] = NULL;
            }
        }
        else{
            p->pre->next = p->next;
            p->next->pre = p->pre;
        }
        delete p;
        count[key]--;
        return true;
    }
}
template<typename T>
bool Basic_Chained_Hash<T>::Search_Element(const Hashed_Element<T>& element, Hashed_Element<T>** p){
    int key = element.key;
    hash_method(key);
    *p = hashPtr[key];
    if(!(*p))  return false;   //Searching is failed
    else{
        while(*p != NULL){
            if((*p)->key == key)   return true; //Searching is success.
            *p = (*p)->next; 
        }
        return false;   //Searching is failed.
    }
}
template<typename T>
void Basic_Chained_Hash<T>::Print_Hash_Table() const{
    Hashed_Element<T>* p;
    for(int i=0; i<size; i++){
        p = hashPtr[i];
        cout << '[' << i << "] : ";
        while(p){
            cout << "item : " << p->item << " key : " << p->key << " | ";
            p = p->next;
        }
       
        cout << endl;
    }
}
template <typename T>
void Basic_Chained_Hash<T>::show_cluster() const{
    for(int i=0; i<size; i++){
        cout << '[' << i << "]:" << "||";
        for(int j=0; j < count[i]; j++)     cout << '*';
        cout << endl;
    }
}
#endif