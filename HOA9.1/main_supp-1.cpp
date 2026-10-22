#include <iostream>
#include "BST_SUPPLE.h"

int main() {
    BinarySearchTree<int> tree(2);

    tree.insert(3);
    tree.insert(9);
    tree.insert(18);
    tree.insert(0);
    tree.insert(1);
    tree.insert(4);
    tree.insert(5);

    // Tree structure:
    /*
              2
             / \
            0   3
             \   \
              1   9
                 / \
                4   18
                 \
                  5
    //PREORDER
         2  // 1st
        /   \
       /     \
     0        3  // 4th
   // 2nd      \
     \          \
      1          9  // 5th
    // 3rd     /   \
              /     \
             4       18
           // 6th   // 8th
              \
               5
             // 7th
            
    //INORDER
          2  // 3rd
        /   \
       /     \
     0        3  // 4th
   // 1st      \
     \          \
      1          9  // 7th
    // 2nd     /   \
              /     \
             4       18
           // 5th   // 8th
              \
               5
             // 6th

    //POST ORDER
          2  // 8th
        /   \
       /     \
     0        3  // 7th
   // 2nd      \
     \          \
      1          9  // 6th
    // 1st     /   \
              /     \
             4       18
           // 4th   // 5th
              \
               5
             // 3rd
    */
    std::cout << "PreOrder: " << "\n";
    tree.preOrder();
    std::cout << "\n";

    std::cout << "InOrder: " << "\n";
    tree.inOrder();
    std::cout << "\n";

    std::cout << "PostOrder: " << "\n";
    tree.postOrder();
    std::cout << "\n";

    return 0;
}