#include "basic_chained_hash.hpp"
#include "basic_chained_hash.cpp"
int main(){//for test
    srand(time(0));
    Basic_Chained_Hash<int> hash_table_with_DIVISION_METHOD(HASH_TABLE_SIZE, DIVISION_METHOD);
    Basic_Chained_Hash<int> hash_table_with_UNIVERSAL_HASHING(HASH_TABLE_SIZE, UNIVERSAL_METHOD);
    Basic_Chained_Hash<int> hash_table_with_MULTIPLICATION_METHOD(HASH_TABLE_SIZE, MULTIPLICATION_METHOD);
    Hashed_Element<int> temp_element;
    Hashed_Element<int> certain_element[ELEMENT_NUM];
    #if 1
    for(int i=0; i<ELEMENT_NUM; i++){
        temp_element.item = rand();
        temp_element.key = temp_element.item % ITEM_LIMIT;
        certain_element[i] = temp_element;
        hash_table_with_UNIVERSAL_HASHING.Chained_Hash_Insert(temp_element);
        hash_table_with_DIVISION_METHOD.Chained_Hash_Insert(temp_element);
        hash_table_with_MULTIPLICATION_METHOD.Chained_Hash_Insert(temp_element);
    }
    #endif
#if 0       //show hash table
    cout << "before deletion" << endl;;
    my_hash_table.Print_Hash_Table();
    cout << endl;

    cout << "@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "deletion..." << endl;
    for(int i=0; i<ELEMENT_NUM; i++){
 //       cout << "key : " << certain_element[i].key << endl;
 //       cout << "item :" << certain_element[i].item << endl;
        my_hash_table.Chained_Hash_Delete(certain_element[i]);
    }

    cout << "result" << endl;
    my_hash_table.Print_Hash_Table();
#endif

#if 1   //show cluster
    cout << "@@  division method" <<endl;
    hash_table_with_DIVISION_METHOD.show_cluster();
    cout << endl <<"@@  universal method " << endl;
    hash_table_with_UNIVERSAL_HASHING.show_cluster();
    cout << endl << "@@  multiplication method" << endl;
    hash_table_with_MULTIPLICATION_METHOD.show_cluster();
#endif
}