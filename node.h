/**
 * file:            node.h
 * author:          Asher Weitz
 * date modified:   3/31/24
 * description:     This is the Node class that creates each node in the EVC, as well as assigns the class data members of the 
 *                  value, leftChild, and the rightChild.
 */

 #ifndef NODE_H
 #define NODE_H
 
 class Node{
 
     public:
 
         Node(int val){
             value = val;
             leftChild = nullptr;
             rightChild = nullptr;
         }
 
         int value;
         Node * leftChild;
         Node * rightChild;
 };
 
 #endif