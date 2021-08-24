#ifndef     _OPEN_ADDRESSING_H_
#define     _OPEN_ADDRESSING_H_

#include    <iostream>
#include    <ctime>
#include    <cstdlib>

#define     LINEAR_PROBING      0 
#define     DOUBLE_HASHING      1
#define     QUADRATIC_PROBING   2
#define     TABLE_SIZE          13
#define     ELEMENT_SIZE        10
#define     RANDOM_LIMIT        1000
#define     AUTOMATIC_SIZING    1
#define     MANUAL_SIZING       2

//  Linear Probing
//  (h'(k) + i) mod m

//  Quadratic Probing
//  h(k, i) = (h'(k) + c1 * i + c2 * i^2)

//  Double Hashing
//  h(k, i) = (h1(k) + i*h2(k)) mod m

using namespace std;

template<class T>
struct Hashed_Element{
    int key;
    bool log;
    T item;
};

template<class T>
class Open_Addressed_Hash{
    private :
        Hashed_Element<T>* hashTable;
        int tableSize;
        int element_count;
        unsigned char hash_method;
        unsigned char sizing_method;
        void updateTableSize();
    protected :
        bool hashing(int& key, const T& item);
    public :
        Open_Addressed_Hash(int size, unsigned char method, unsigned char sizing_method);
        ~Open_Addressed_Hash();
        bool HashInsert(const T& item);
        bool HashDelete(const T& item);
        int HashSearch(const T& item) const;
        void show_hashTable() const;
};
#endif