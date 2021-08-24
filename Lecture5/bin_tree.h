#ifndef _BIN_TREE_H
#define _BIN_TREE_H
#include <iostream>
using namespace std;

template<typename T>
class TreeNode{
    public :
        T item;
        int key;
        TreeNode* left_child;
        TreeNode* right_child;
};

template<typename T>
class BinaryTree{
    private :
        TreeNode<T>* root;
        int node_numbers;
        void delete_node_by_addr(TreeNode<T> *p);
        void inorder_traversal(TreeNode<T> *p) const;
        void preorder_traversal(TreeNode<T> *p) const;
        void postorder_traversal(TreeNode<T> *p) const;
        void isErrorInTree(TreeNode<T> *p) const;
    public :
        BinaryTree();
        ~BinaryTree();
        //update
        void add_node(T item, int key);
        void delete_node(int key);
        //traversal
        void inorder_traversal() const;
        void preorder_traversal() const;
        void postorder_traversal() const;
        //query
        bool isLeafNode(TreeNode<T> *p) const;
        bool isInternalNode_leftChild(TreeNode<T> *p) const;
        bool isInternalNode_rightChild(TreeNode<T> *p) const;
        void isErrorInTree() const;
        bool isInternalNode_twoChildren(TreeNode<T> *p) const;
        //search
};
#endif