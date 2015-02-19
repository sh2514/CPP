/* ==================================================
Arbitrary Tree
Shikuan Huang

Left child is descendant
Right child is sibling
================================================== */

#include <iostream>
#include "ATree.h"
using namespace std;

int main(int argc, char ** argv) {
  ATree<int> myTree;
  
  myTree.insert(5);
  myTree.insert(6, 1);
  myTree.insert(7, 2);
  myTree.insert(8, 1);
  myTree.insert(11, 1);
  myTree.insert(9, 4);
  myTree.insert(9, 3);
  myTree.insert(10, 4);
  cout << "myTree.size() = " << myTree.size() << endl << myTree << endl;
  
  myTree.remove(8);
  myTree.remove(10);
  myTree.remove(7);
  myTree.remove(11);
  myTree.remove(5);
  myTree.remove(6);
  myTree.remove(9);
  cout << "myTree.size() = " << myTree.size() << endl << myTree << endl;
  
  
  /*
  myTree.insert(5);
  myTree.insert(6, 1);
  cout << "myTree: \n" << myTree << endl;
  myTree.remove(5);
  myTree.remove(6);
  cout << "myTree: \n" << myTree << endl;
  */
}
