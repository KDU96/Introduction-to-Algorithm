#ifndef     _BASIC_HASHING_HPP_
#define     _BASIC_HASHING_HPP_

#include    <iostream>
#include    <cstdlib>
#include    <ctime>
#include    <cmath>
#include    <random>
#include    <limits>

#define     HASH_TABLE_SIZE         100
#define     PRIME_NUMBER            113
#define     ELEMENT_NUM             1000
#define     ITEM_LIMIT              100000
#define     HASH_VAR_LIMIT          10000
#define     DIVISION_METHOD         1
#define     MULTIPLICATION_METHOD   2
#define     UNIVERSAL_METHOD        3
#define     WORD                    64

using namespace std;

// hash is implemented to the division method.

template <typename T>
struct Hashed_Element{
    int key;
    T item;
    Hashed_Element* next;
    Hashed_Element* pre;
};

template <typename T>
class Basic_Chained_Hash{
    private :
        Hashed_Element<T> **hashPtr;
        int size;
        unsigned char   hash_function;
        int a, b;       //random value for hashing
        char* count;
        unsigned long R_for_multiplication_value;
    protected :
        void hash_method(int& key);
        void hash_method(double& key);
    public :
        Basic_Chained_Hash(int size, unsigned char method = DIVISION_METHOD);
        ~Basic_Chained_Hash();
        bool Chained_Hash_Insert(const Hashed_Element<T>& element);
        bool Chained_Hash_Delete(const Hashed_Element<T>& element);
        bool Search_Element(const Hashed_Element<T>& element, Hashed_Element<T>** p);
        void Print_Hash_Table() const;
        void show_cluster() const;
};
#endif