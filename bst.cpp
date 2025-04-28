/**
 * file:            bst.cpp
 * author:          Asher Weitz
 * date modified:   3/31/2024
 * description:     This file is the .cpp for the binary search tree class that shows all of the needed public and private methods and their definitions.
 */

 #include "bst.h"

 //public functions
 
 /**
  * Description: DVC for the BST class assigns size to 0 because root is being assigned nullptr.
  * 
  * Pre: None
  * Post: Tree is created with size 0.
 */
 BST::BST() {
     size = 0;
     root = nullptr;
 }
 
 /**
  * Description: EVC for the BST class that assigns the size to one because we have a value to insert and we assign the root node to that of the value passed in.
  * 
  * Pre: Value for the root node is passed in.
  * Post: Root node and a new BST is created.
 */
 BST::BST(int val) {
     size = 1;
     root = new Node(val);
 }
 
 /**
  * Description: This function call assigns root to what is returned from the function call with the root being passed in and the value of the new node
  * to be returned incase the tree is empty.
  * 
  * Pre: Value of new node is passed in.
  * Post: root is assign the node of what is returned from the function.
 */
 void BST::insert(int value) {
     root = insert(root, value);
 }
 
 /**
  * Description: This function returns the boolean value that is returned from the private function find which is called while also passing in the root and value.
  * 
  * Pre: The desired value is passed into the function
  * Post: The function returns true if found or false otherwise.
 */
 bool BST::find(int value) {
     return find(root, value);
 }
 
 /**
  * Description: For the function call we then assign the root node by calling the private remove function and passing in the root itself
  * and the value of the node we want to delete.
  * We do this incase the root is changed in the removal of a node.
  * 
  * Pre:Value we want to remove is passed in.
  * Post: If successfull, we assign root to the node we return.
 */
 void BST::remove(int value) {
     root = remove(root, value);
 }
 
 /**
  * Description: This public interface function returns by calling the private function passing in the root node.
  * 
  * Pre: None
  * Post: function returns by calling the function and returning the largest nodes value.
 */
 int BST::findMax() {
     return findMax(root);
 }
 
 /**
  * Description: This public interface function returns by calling the private function passing in the root node.
  * 
  * Pre: None
  * Post: function returns by calling the function and returning the smallest nodes value.
 */
 int BST::findMin() {
     return findMin(root);
 }
 
 /**
  * Description: This function first checks if the tree is empty and has an early return if so. Otherwise we call the private function passing
  * in the root to start printing the tree in the in order traversal. 
  * 
  * Pre: None
  * Post: Either the tree is printed or the user gets a cout statement and the function returns.
 */
 void BST::printInOrder() {
     if(root == nullptr) {
         std::cout << "empty tree" << std::endl;
         return;
     }
 
     printInOrder(root);
 }
 
 /**
  * Description: This function first checks if the tree is empty and has an early return if so. Otherwise we call the private function passing
  * in the root to start printing the tree in the pre order traversal. 
  * 
  * Pre: None
  * Post: Either the tree is printed or the user gets a cout statement and the function returns.
 */
 void BST::printPreOrder() {
     if(root == nullptr) {
         std::cout << "empty tree" << std::endl;
         return;
     }
 
     printPreOrder(root);
 }
 
 /**
  * Description: This function first checks if the tree is empty and has an early return if so. Otherwise we call the private function passing
  * in the root to start printing the tree in the the post order traversal. 
  * 
  * Pre: None
  * Post: Either the tree is printed or the user gets a cout statement and the function returns.
 */
 void BST::printPostOrder() {
     if(root == nullptr) {
         std::cout << "empty tree" << std::endl;
         return;
     }
 
     printPostOrder(root);
 }
 
 /**
  * Description: Used to return the size of the tree. We return the private member variable because we increment and decrement the int during
  * each function call
  * 
  * Pre: None
  * Post: Int size is returned.
 */
 int BST::getSize() {
     return size;
 }
 
 // private functions
 
 /**
  * Description: Used to remove a node in the tree. We first check if the tree is empty and if it is we just return null. If otherwise,
  * we determine which direction in the tree to go. Once we get to the else statement, we need to check for one of the three cases.
  * The first being the node has no chilrden, the second being one child, and the third where the node has two children in which we select
  * the in order successor to replace the node to be deleted.
  * 
  * Pre: The root node is passed in along with the value to be deleted.
  * Post: The node is deleted and returned.
 */
 Node * BST::remove(Node * node, int value) {
     if(node == nullptr) {
         return nullptr;
     }
     
     if (value < node->value) {
         node->leftChild = remove(node->leftChild, value);
     } else if(value > node->value) {
         node->rightChild = remove(node->rightChild, value);
     } else {
         // case no children
         if(node->leftChild == nullptr && node->rightChild == nullptr) {
             size--;
             delete node;
             return nullptr;
         }
         // case 1 child 
         else if(node->leftChild == nullptr) {
             size--;
             return node->rightChild;
         } else if(node->rightChild == nullptr) {
             size--;
             return node->leftChild;
         }
         // case 2 children
         else {
             int successor = findMin(node->rightChild);
 
             node->value = successor;
 
             node->rightChild = remove(node->rightChild, successor);
         }
     }
     return node;
 }
 
 /**
  * Description: We first check if node is null to protect from seg faults. We then check if the value we are looking for is smaller or larger 
  * than the current root node value. For either one we recursively call the function again passing in the nodes left or right child and again passing
  * in the value we are looking for. finally we return true if we end up finding it, false if we reach a null pointer first.
  * 
  * Pre: Root node is passed in along with the value we are looking for.
  * Post: Return false if we don't find it, true if we find it.
 */
 bool BST::find(Node * node, int value) {
     if(node == nullptr){
         return false;
     } else if(value < node->value) {
         return find(node->leftChild, value);
     }
     else if(value > node->value){
         return find(node->rightChild, value);
     } else {
         return true;
     }
 }
 
 
 /**
  * Description: This function is used to insert a new node in its proper place in the tree. We first check if the tree is empty,
  * then if the value should go to the left or right subtree. We recursviely call the function to traverse each subtree in order to insert the new node
  * in its proper place
  * 
  * Pre: The root node is passed in and the value for the new node.
  * Post: The new node is created with the EVC and the new value and returned.
 */
 Node * BST::insert(Node * node, int value) {
     if(node == nullptr) {
         size++;
         return new Node(value);
     } else {
         if(value < node->value) {
             node->leftChild = insert(node->leftChild, value);
         } else {
             node->rightChild = insert(node->rightChild, value);
         }
     }
     return node;
 }
 
 /**
  * Description: This function prints out the the node values in the In order traversal which is the left child, the root, and the right child.
  * We recursively call the left and right child in order to print the value.
  * 
  * Pre: Root node is passed in
  * Post: Node values in the tree are cout in the Left, Root, Right child order.
 */
 void BST::printInOrder(Node * node) {
     if(node == nullptr) {
         return;
     }
 
     printInOrder(node->leftChild);
     std::cout << node->value << " ";
     printInOrder(node->rightChild);
 }
 
 /**
  * Description: This function prints out the the node values in the Pre order traversal which is the root, left child, and right child.
  * We recursively call the left and right child in order to print the value.
  * 
  * Pre: Root node is passed in
  * Post: Node values in the tree are cout in the Root, Left, Right order.
 */
 void BST::printPreOrder(Node * node) {
     if(node == nullptr) {
         return;
     }
 
     std::cout << node->value << " ";
     printPreOrder(node->leftChild);
     printPreOrder(node->rightChild);
 }
 
 /**
  * Description: This function prints out the the node values in the Post order traversal which is the left child, right child, and the root last.
  * We recursively call the left and right child in order to print the value.
  * 
  * Pre: Root node is passed in
  * Post: Node values in the tree are cout in the Left, Right, Root order.
 */
 void BST::printPostOrder(Node * node) {
     if(node == nullptr){
         return;
     }
 
     printPostOrder(node->leftChild);
     printPostOrder(node->rightChild);
     std::cout << node->value << " ";
 }
 
 /**
  * Description: Used to find the largest node in the tree by navigating through the right sub tree until we get to the farthest to the right, and whos node
  * has no children.
  * 
  * Pre: Node which is the root, is passed in.
  * Post: The largest node in the right subtree is returned.
 */
 int BST::findMax(Node * node) {
     if(node->leftChild == nullptr && node->rightChild == nullptr) {
         return node->value;
     } else {
         while(node->rightChild != nullptr) {
             node = node->rightChild;
         }
         return node->value;
     }
 }
 
 /**
  * Description: Used to find the smallest node in the tree by navigating through the left sub tree until we get to the farthest to the left, and whos node
  * has no children.
  * 
  * Pre: Node which is the root, is passed in.
  * Post: the smallest node in the left subtree is returned.
 */
 int BST::findMin(Node * node) {
     if(node->leftChild == nullptr && node->rightChild == nullptr) {
         return node->value;
     } else {
         while(node->leftChild != nullptr) {
             node = node->leftChild;
         }
         return node->value;
     }
 }