#include "bin_tree.cpp"
#include <cstdlib>
#include <ctime>
#define TRIAL 10
#define KEY_VALUE_RANGE 100

int main(){
    srand(time(0));
    BinaryTree<char> myTree;
   // char ch;
  //  int key;
    
#if 0
    for(int i=0; i<TRIAL; i++){
        ch = (rand() % 65) + 62; key = rand() % KEY_VALUE_RANGE;
        myTree.add_node(key, ch);
    }
#endif
    myTree.add_node('c', 20);
    myTree.add_node('a', 33);
    myTree.add_node('k', 12);
    myTree.add_node('o', 77);
    myTree.add_node('a', 553);
    myTree.add_node('f', 22);
  
    cout << "first" << endl;
    myTree.delete_node(22);
    myTree.inorder_traversal();
    
    cout << "second" << endl;
    myTree.delete_node(33);
    myTree.inorder_traversal();

    cout << "third" << endl;
    myTree.delete_node(12);
    myTree.inorder_traversal();

    cout << "fourth" << endl;
    myTree.delete_node(20);
    myTree.inorder_traversal();

    myTree.isErrorInTree();

}