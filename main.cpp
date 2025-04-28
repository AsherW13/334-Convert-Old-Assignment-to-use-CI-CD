/**
 * file:            main.cpp
 * author:          Asher Weitz
 * date modified:   3/31/2024
 * description:     This main.cpp file includes all the necessary .h files for the binary search tree and the test function prototypes.
 *                  In the main function we are calling all of the necessary test functions for each binary search tree function.
 *                  Below are the test function definitions
 */

 #include<iostream>
 #include "bst.h"
 #include "node.h"
 #include "tests.h"
 
 
 int main(){
     BST tree(17);
     std::cout << tree.root->value << std::endl;
     
 
     runAllTests();
 
     return 0;
 }

 void runAllTests(){
    testCreateTree();
    testInsert();
    testRemove();
    testFind();
    testFindMax();
    testFindMin();
    printInOrderTest();
    printPreOrderTest();
    printPostOrderTest();
    testGetSize();
 }
 
 void testCreateTree(){
     BST tree(17);
 
     if(tree.root->value == 17){
         std::cout << "testCreateTree...PASS" << std::endl;
     }else{
         std::cout << "testCreateTree...FAIL" << std::endl;
     }
 }
 
 void testInsert() {
     BST testTree(10);
 
     testTree.insert(9);
 
     if(testTree.root != nullptr &&
         testTree.root->leftChild != nullptr &&
         testTree.root->value == 10 &&
         testTree.root->leftChild->value == 9 
         ) {
         std::cout << "testInsert...PASS" << std::endl;
     } else {
         std::cout << "testInsert...FAIL" << std::endl;
     }
 }
 
 void testRemove() {
     BST testTree(15);
 
     testTree.insert(10);
     testTree.insert(9);
     testTree.insert(11);
     testTree.insert(16);
     testTree.insert(18);
 
     testTree.remove(11);
     std::cout << "Test Remove Expected: 15 10 9 16 18 " << std::endl;
     std::cout << "Actual: ";
     testTree.printPreOrder();
     std::cout << std::endl;
 }
 
 void testFind() {
     BST testTree(10);
 
     testTree.insert(6);
     testTree.insert(12);
     testTree.insert(15);
 
     if(testTree.find(15)) {
         std::cout << "testFind...PASS" << std::endl;
     }
     else {
         std::cout << "testFind...Fail" << std::endl;
     }
 }
 
 void testFindMax() {
     BST testTree(10);
 
     testTree.insert(6);
     testTree.insert(15);
     testTree.insert(18);
 
     if(testTree.findMax() == 18) {
         std::cout << "testFindMax...PASS" << std::endl;
     }
     else {
         std::cout << "testFindMax...FAIL" << std::endl;
     }
 }
 
 void testFindMin() {
     BST testTree(10);
 
     testTree.insert(6);
     testTree.insert(15);
     testTree.insert(18);
     testTree.insert(3);
 
     if(testTree.findMin() == 3) {
         std::cout << "testFindMin...PASS" << std::endl;
     }
     else {
         std::cout << "testFindMin...FAIL" << std::endl;
     }
 }
 
 void printInOrderTest() {
     BST tree(10);
 
     tree.insert(8);
     tree.insert(12);
 
     std::cout << "In-Order Expected: 8 10 12 " << std::endl;
     std::cout << "Actual: ";
     tree.printInOrder();
     std::cout << std::endl;
 }
 
 void printPreOrderTest() {
     BST tree(10);
 
     tree.insert(8);
     tree.insert(12);
 
     std::cout << "Pre-Order Expected: 10 8 12 " << std::endl;
     std::cout << "Actual: ";
     tree.printPreOrder();
     std::cout << std::endl;
 }
 
 void printPostOrderTest() {
     BST tree(10);
 
     tree.insert(8);
     tree.insert(12);
 
     std::cout << "Post-Order Expected: 8 12 10 " << std::endl;
     std::cout << "Actual: ";
     tree.printPostOrder();
     std::cout << std::endl;
 }
 
 void testGetSize() {
     BST tree(10);
 
     tree.insert(11);
     tree.insert(9);
     tree.insert(8);
     tree.insert(12);
     tree.insert(3);
     tree.insert(20);
     tree.remove(3);
 
     std::cout << "Get Size Expected: 6 " << std::endl;
     std::cout << "Actual: ";
     std::cout << tree.getSize() << std::endl; 
 }