#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

#include "../Lecture5/bin_tree.h"

template<typename T>
class AVLTree : public BinaryTree<T>{
    private :
        void rotation();
    public :
        AVLTree();
        ~AVLTree(){}
};

#endif
