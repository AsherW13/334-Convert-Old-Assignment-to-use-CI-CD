/**
 * file:            bst.h
 * author:          Asher Weitz
 * date modified:   3/31/2024
 * description:     This file is the .h for the binary search tree class that shows all of the needed public functions and the private helper functions.
 *                  This .h file also includes the .h file for the node class which holds the children nodes and their values.
 */

 #ifndef BST_H
 #define BST_H
 
 #include "node.h"
 #include <iostream>
 
 class BST{
 
     public:
 
         Node * root;
 
         BST();
 
         BST(int val);
 
         void insert(int value);
 
         bool find(int value);
 
         void remove(int value);
 
         int findMax();
 
         int findMin();
 
         void printInOrder();
 
         void printPreOrder();
 
         void printPostOrder();
 
         int getSize();
 
     private:
 
         int size;
 
         Node* remove(Node * node, int value);
 
         bool find(Node * node, int value);
 
         Node* insert(Node * node, int value);
 
         void printInOrder(Node * node);
 
         void printPreOrder(Node * node);
 
         void printPostOrder(Node * node);
 
         int findMax(Node * node);
 
         int findMin(Node * node);
 };
 
 
 
 #endif