/* ==================================================
Binary Search Tree
Shikuan Huang
================================================== */

#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main() {
	// Testing equality operator
	BST<int> myBSTx = BST<int>();
	myBSTx.insert(98);
	myBSTx.insert(100);
	myBSTx.insert(4);
	myBSTx.insert(16);
	myBSTx.insert(16);
	myBSTx.insert(16);
	myBSTx.insert(18);
	myBSTx.insert(102);
	myBSTx.insert(99);
	myBSTx.insert(206);
	myBSTx.insert(2);
	myBSTx.insert(0);
	myBSTx.insert(14);
	myBSTx.insert(15);
	
	BST<int> myBSTz = myBSTx;
	cout << (myBSTx == myBSTz) << endl;
	
	myBSTz.insert(5);
	myBSTz.insert(11);
	cout << (myBSTx == myBSTz) << endl << endl;
	
	cout << myBSTx.size() << " " << myBSTz.size() << endl;
	
	myBSTx.insert(11);
	myBSTx.insert(5);
	cout << (myBSTx == myBSTz) << endl;
	
	myBSTx.remove(5);
	myBSTx.remove(11);
	myBSTz.remove(5);
	myBSTz.remove(11);
	cout << (myBSTx == myBSTz) << endl << endl;
	
	cout << myBSTx.size() << " " << myBSTz.size() << endl;
	
	
	
	/*
	BST<int> myBST = BST<int>();
	myBST.insert(98);
	myBST.insert(100);
	myBST.insert(4);
	myBST.insert(16);
	myBST.insert(16);
	myBST.insert(16);
	myBST.insert(18);
	myBST.insert(102);
	myBST.insert(99);
	myBST.insert(206);
	myBST.insert(2);
	myBST.insert(0);
	myBST.insert(14);
	myBST.insert(15);
	
	cout << "Preorder: ";	// 98 4 2 0 16 14 15 16 16 18 100 99 102 206
	myBST.printPreorder();
	cout << endl;
	
	cout << "Inorder: ";	// 0 2 4 14 15 16 16 16 18 98 99 100 102 206
	myBST.printInorder();
	cout << endl;
	
	cout << "Postorder: ";	// 0 2 15 14 18 16 16 16 4 99 206 102 100 98
	myBST.printPostorder();
	cout << endl;
	
	cout << "BFS: ";		// 98 4 100 2 16 99 102 0 14 16 206 15 16 18
	myBST.printBFS();
	cout << endl;
	
	BST<int> myBST1;
	BST<int> myBST2;
	BST<int> myBST3 = myBST2 = myBST1 = myBST = myBST;
	
	cout << "myBST1: ";
	myBST1.printBFS();
	cout << endl;
	
	cout << "myBST2: ";
	myBST2.printBFS();
	cout << endl;
	
	cout << "myBST3: ";
	myBST3.printBFS();
	cout << endl;
	
	cout << "myBST: " << myBST << endl;
	
	myBST2.insert(45);
	cout << "myBST2: ";
	myBST2.printBFS();
	cout << endl;
	
	
	const BST<int> myBST4 = myBST;
	const BST<int> myBST5 = myBST4;
	myBST2 = myBST4;
	*/
	
	/*
	myBST2.remove(98);
	myBST2.remove(16);
	myBST2.remove(4);
	myBST2.remove(99);
	myBST2.remove(18);
	myBST2.remove(0);
	myBST2.remove(15);
	myBST2.remove(16);
	myBST2.remove(206);
	myBST2.remove(14);
	myBST2.remove(100);
	myBST2.remove(2);
	myBST2.remove(16);
	myBST2.remove(102);
	cout << "myBST2: ";
	myBST2.printBFS();
	cout << endl;
	myBST2.insert(39394);
	cout << "myBST2: ";
	myBST2.printBFS();
	cout << endl;
	*/
	
	/*
	myBST.remove(98);
	myBST.remove(16);
	myBST.remove(4);
	myBST.remove(99);
	myBST.remove(18);
	myBST.remove(0);
	myBST.remove(15);
	myBST.remove(16);
	myBST.remove(206);
	myBST.remove(14);
	myBST.remove(100);
	myBST.remove(2);
	myBST.remove(16);
	myBST.remove(102);
	cout << "\nPreorder: ";	// 99 14 2 0 16 15 16 18 100 102 206
	myBST.printPreorder();
	cout << endl;
	
	cout << "Inorder: ";	// 0 2 14 15 16 16 18 99 100 102 206
	myBST.printInorder();
	cout << endl;
	
	cout << "Postorder: ";	// 0 2 15 18 16 16 14 206 102 100 99
	myBST.printPostorder();
	cout << endl;
	
	cout << "BFS: ";		// 99 14 100 2 16 102 0 15 16 206 18
	myBST.printBFS();
	cout << endl;
	*/
	
	/*
	myBST.remove(98);
	myBST.remove(16);
	myBST.remove(4);
	cout << "\nPreorder: ";	// 99 14 2 0 16 15 16 18 100 102 206
	myBST.printPreorder();
	cout << endl;
	
	cout << "Inorder: ";	// 0 2 14 15 16 16 18 99 100 102 206
	myBST.printInorder();
	cout << endl;
	
	cout << "Postorder: ";	// 0 2 15 18 16 16 14 206 102 100 99
	myBST.printPostorder();
	cout << endl;
	
	cout << "BFS: ";		// 99 14 100 2 16 102 0 15 16 206 18
	myBST.printBFS();
	cout << endl;
	*/
	
	/*
	myBST.remove(4);
	cout << "\nPreorder: ";	// 98 14 2 0 16 15 16 16 18 100 99 102 206
	myBST.printPreorder();
	cout << endl;
	
	cout << "Inorder: ";	// 0 2 14 15 16 16 16 18 98 99 100 102 206
	myBST.printInorder();
	cout << endl;
	
	cout << "Postorder: ";	// 0 2 15 18 16 16 16 14 99 206 102 100 98
	myBST.printPostorder();
	cout << endl;
	
	cout << "BFS: ";		// 98 14 100 2 16 99 102 0 15 16 206 16 18
	myBST.printBFS();
	cout << endl;
	*/
	
	/*
	myBST.remove(2);
	cout << "\nPreorder: ";	// 98 4 0 16 14 15 16 16 18 100 99 102 206
	myBST.printPreorder();
	cout << endl;
	
	cout << "Inorder: ";	// 0 4 14 15 16 16 16 18 98 99 100 102 206
	myBST.printInorder();
	cout << endl;
	
	cout << "Postorder: ";	// 0 15 14 18 16 16 16 4 99 206 102 100 98
	myBST.printPostorder();
	cout << endl;
	
	cout << "BFS: ";		// 98 4 100 2 16 99 102 0 14 16 206 15 16 18
	myBST.printBFS();
	cout << endl;
	*/
	
	return 0;
}
