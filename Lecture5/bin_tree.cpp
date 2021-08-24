#ifndef _BIN_TREE_CPP_
#define _BIN_TREE_CPP_
#include "bin_tree.h"

template<typename T>
BinaryTree<T>::BinaryTree(){
    root = NULL;    node_numbers = 0;
}
template<typename T>
BinaryTree<T>::~BinaryTree(){
    delete_node_by_addr(root);
}
template<typename T>
void BinaryTree<T>::delete_node_by_addr(TreeNode<T> *p){
    if(p){
        delete_node_by_addr(p->left_child);
        delete_node_by_addr(p->right_child);
        delete p;
    }
}
template<typename T>
void BinaryTree<T>::add_node(T item, int key){
    TreeNode<T> *new_node = new TreeNode<T>;
    if(!new_node){
        cout << "memory error" << endl;
        return;
    }
    node_numbers++;
    new_node->key = key;
    new_node->item = item;

    if(!root){
        root = new_node;
        new_node->left_child = NULL;
        new_node->right_child = NULL;
    }
    else{
        TreeNode<T> *p = root, *t;
        while(1){
            t = (new_node->key < p->key) ? p->left_child : p->right_child;
            if(t == NULL){
                if(key < p->key){
                    p->left_child = new_node;
                    break;
                }
                else{
                    p->right_child = new_node;
                    break;
                }
            }
            p = t;
        }
    }
      
}

template<typename T>
void BinaryTree<T>::delete_node(int key){//right child's left
    TreeNode<T> *p = root, *t;
    while(1){
        if(key == root->key){
             t = root;
             break;
        }
        if(key < p->key)    t = p->left_child;
        else                t = p->right_child;
        
        if(t == NULL){
            cout << "There is no item" << endl;
            return;
        }
        if(t->key == key)   break;
        p = t;
    }
    if(isLeafNode(t)){
        if(p->left_child == t)  p->left_child = NULL;
        else                    p->right_child = NULL;
        delete t;
        
    }
    else if(isInternalNode_leftChild(t)){
        if(t == root){
            root = root->left_child;
            delete t;
        }
        else{
            p->left_child = t->left_child;
            delete t;
        }
    }
    else if(isInternalNode_rightChild(t)){
        if(t == root){
            root = root->right_child;
            delete t;
        }
        else{
            p->right_child = t->right_child;
            delete t;
        }
    }
    else{
        TreeNode<T>* v = t->right_child;    //parent
        TreeNode<T>* u = v->left_child;     //child
        if(!u){
            if(t == root){
                root = t->right_child;
                root->left_child = t->left_child;
                delete t;
            }
            else{
                p->right_child = v;
                delete t;
            }
        }
        else{
            while(u){
                v = u;
                u = u->left_child;
            }
            if(t == root){
                root = v;
                v->left_child = t->left_child;
                v->right_child = t->right_child;
                delete t;
            }
            else{
                p->right_child = v;
                v->left_child = t->left_child;
                v->right_child = t->right_child;
                delete t;
            }
        }
    }
}
template<typename T>
void BinaryTree<T>::inorder_traversal() const{
    inorder_traversal(root);
}

template<typename T>
void BinaryTree<T>::preorder_traversal() const{
    preorder_traversal(root);
    
}

template<typename T>
void BinaryTree<T>::postorder_traversal() const{
    postorder_traversal(root);
}

template<typename T>
void BinaryTree<T>::inorder_traversal(TreeNode<T> *p) const{
    if(p){
        inorder_traversal(p->left_child);
        cout << "item : " << p->item << '\t' << "key : " << p->key << endl;
        inorder_traversal(p->right_child);
    }
}
template<typename T>
void BinaryTree<T>::preorder_traversal(TreeNode<T> *p) const{
    if(p){
        cout << "item : " << p->item << '\t' << "key : " << p->key << endl;
        preorder_traversal(p->left_child);
        preorder_traversal(p->right_child);
    }
}

template<typename T>
void BinaryTree<T>::postorder_traversal(TreeNode<T> *p) const{
    if(p){
        postorder_traversal(p->left_child);
        postorder_traversal(p->right_child);
        cout << "item : " << p->item << '\t' << "key : " << p->key << endl;
    }
}

template<typename T>
bool BinaryTree<T>::isLeafNode(TreeNode<T> *p) const{
    if(p->left_child == NULL && p->right_child == NULL)
        return true;
    else 
        return false;
}
template<typename T>
bool BinaryTree<T>::isInternalNode_leftChild(TreeNode<T> *p) const{
    if(p->left_child != NULL && p->right_child == NULL)     return true;
    else    return false;
}
template<typename T>
bool BinaryTree<T>::isInternalNode_rightChild(TreeNode<T> *p) const{
    if(p->right_child == NULL && p->left_child != NULL)     return true;
    else    return false;
}
template<typename T>
bool BinaryTree<T>::isInternalNode_twoChildren(TreeNode<T> *p) const{
    if(p->left_child != NULL && p->right_child != NULL)  return true;
    else    return false;
}
template<typename T>
void BinaryTree<T>::isErrorInTree(TreeNode<T> *p) const{
    if(!p)
        return;

    isErrorInTree(p->left_child);
    isErrorInTree(p->right_child);
    if((p->left_child != NULL) && (p->left_child->key > p->key)){
        cout << "tree error" << endl;
        return;
    }
    if((p->right_child != NULL) && (p->right_child->key < p->key)){
        cout << "tree error" << endl;
        return;
    }
}
template<typename T>
void BinaryTree<T>::isErrorInTree() const{
    isErrorInTree(root);
}
#endif