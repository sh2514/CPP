/* ==================================================
LinkedList
Shikuan Huang
================================================== */

#include <iostream>
#include "LList.h"
using namespace std;

int main() {	
	/* ========================================
	SList Test
	======================================== */
	/*
	SList<int> myS1;
	myS1.push(5);
	myS1.push(10);
	myS1.push(15);
	myS1.push(20);
	
	SList<int> myS2 = myS1;
	myS2.pop();
	
	SList<int> myS3;
	myS3 = myS1;
	
	cout << "myS1.peek() = " << myS1.peek() << endl;
	cout << "myS1[2] = " << myS1[2] << endl;
	cout << "myS1 == myS2 = " << (myS1 == myS2) << endl;
	cout << "myS1 < myS2 = " << (myS1 < myS2) << endl;
	cout << "myS1 > myS2 = " << (myS1 > myS2) << endl;
	cout << "myS1 == myS3 = " << (myS1 == myS3) << endl;
	myS1.push(3);
	cout<< "myS1.push(3)" << endl;
	myS2.push(8);
	cout << "myS2.push(8)" << endl;
	cout << "myS1 == myS2 = " << (myS1 == myS2) << endl;
	cout << "myS1 < myS2 = " << (myS1 < myS2) << endl;
	cout << "myS1 > myS2 = " << (myS1 > myS2) << endl;
	cout << "myS1 == myS3 = " << (myS1 == myS3) << endl;
	
	
	cout << endl;
	cout << "myS1: " << myS1 << ", size = " << myS1.size() << ", empty = " << myS1.empty() << endl;
	cout << "myS2: " << myS2 << ", size = " << myS2.size() << ", empty = " << myS2.empty() << endl;
	cout << "myS3: " << myS3 << ", size = " << myS3.size() << ", empty = " << myS3.empty() << endl;
	*/
	
	
	/* ========================================
	QList Test
	======================================== */
	/*
	QList<int> myQ1;
	myQ1.enqueue(5);
	myQ1.enqueue(10);
	myQ1.enqueue(15);
	myQ1.enqueue(20);
	
	QList<int> myQ2 = myQ1;
	myQ2.dequeue();
	
	QList<int> myQ3;
	myQ3 = myQ1;
	
	cout << "myQ1.front() = " << myQ1.front() << endl;
	cout << "myQ1.back() = " << myQ1.back() << endl;
	cout << "myQ1[2] = " << myQ1[2] << endl;
	cout << "myQ1 == myQ2 = " << (myQ1 == myQ2) << endl;
	cout << "myQ1 < myQ2 = " << (myQ1 < myQ2) << endl;
	cout << "myQ1 > myQ2 = " << (myQ1 > myQ2) << endl;
	cout << "myQ1 == myQ3 = " << (myQ1 == myQ3) << endl;
	myQ1.enqueue(3);
	cout << "myQ1.enqueue(3)" << endl;
	myQ2.enqueue(8);
	cout << "myQ2.enqueue(8)" << endl;
	cout << "myQ1 == myQ2 = " << (myQ1 == myQ2) << endl;
	cout << "myQ1 < myQ2 = " << (myQ1 < myQ2) << endl;
	cout << "myQ1 > myQ2 = " << (myQ1 > myQ2) << endl;
	cout << "myQ1 == myQ3 = " << (myQ1 == myQ3) << endl;
	
	
	cout << endl;
	cout << "myQ1: " << myQ1 << ", size = " << myQ1.size() << ", empty = " << myQ1.empty() << endl;
	cout << "myQ2: " << myQ2 << ", size = " << myQ2.size() << ", empty = " << myQ2.empty() << endl;
	cout << "myQ3: " << myQ3 << ", size = " << myQ3.size() << ", empty = " << myQ3.empty() << endl;
	*/
	
	/*
	Stack<int> s1;
	s1.push(4);
	s1.push(5);
	s1.push(6);
	
	Stack<int> s2 = s1;
	
	cout << s1[0] << endl;
	cout << (s1 == s2) << endl;
	cout << (s1 < s2) << endl;
	cout << (s1 > s2) << endl;
	
	s1.push(3);
	
	cout << (s1 == s2) << endl;
	cout << (s1 < s2) << endl;
	cout << (s1 > s2) << endl;
	*/

	/*
	Queue<int> q1;
	q1.enqueue(4);
	q1.enqueue(5);
	q1.enqueue(6);
	
	Queue<int> q2 = q1;
	
	cout << q1[0] << endl;
	cout << (q1 == q2) << endl;
	cout << (q1 < q2) << endl;
	cout << (q1 > q2) << endl << endl;
	
	q1.enqueue(3);
	
	cout << (q1 == q2) << endl;
	cout << (q1 < q2) << endl;
	cout << (q1 > q2) << endl << endl;
	*/

	/*
	LList<int> list1;
	list1.push_back(5);
	list1.push_back(10);
	list1.push_back(15);
	
	LList<int> list2 = list1;
	
	LList<int> list3;
	list3.push_back(4);
	list3.push_back(6);
	
	LList<int> list4 = list3;
	list4.push_back(5);
	list4.eraseAll();
	list4.push_back(5);
	list4.push_back(10);
	list4.push_back(15);
	
	cout << (list1 == list2) << endl;
	cout << (list1 == list3) << endl;
	cout << (list1 == list4) << endl << endl;
	cout << (list1 < list3) << endl;
	cout << (list1 > list3) << endl;
	*/
	
	/* ========================================
	Stack Test
	======================================== */
	/*
	// Create a new stack with default constructor
	Stack<int> myStack1;
	cout << "myStack1: " << myStack1 << endl;
	cout << "empty? " << myStack1.empty() << ", size = " << myStack1.length() << endl;
	myStack1.push(10);
	myStack1.push(20);
	myStack1.push(30);
	myStack1.push(40);
	cout << "myStack1: " << myStack1 << endl;
	myStack1.pop();
	myStack1.pop();
	cout << "myStack1: " << myStack1 << endl;
	cout << "peek() = " << myStack1.peek() << endl;
	
	Stack<int> myStack2 = myStack1;
	myStack2.push(100);
	cout << "myStack1: " << myStack1 << endl;
	cout << "myStack2: " << myStack2 << endl;
	
	Stack<int> myStack3;
	myStack3 = myStack2;
	myStack3.pop();
	myStack3.pop();
	myStack3.push(54);
	myStack3.push(35);
	myStack3.push(9394);
	cout << "\nmyStack1: " << myStack1 << endl;
	cout << "myStack2: " << myStack2 << endl;
	cout << "myStack3: " << myStack3 << endl;
	
	// Const test
	cout << endl << endl;
	Stack<int> first;
	first.push(5);
	first.push(10);
	first.push(2);
	
	const Stack<int> second = first; 
	Stack<int> third = second;
	Stack<int> fourth;
	fourth = second;
	
	cout << first << endl << second << endl << third << endl << fourth << endl << endl;
	*/
	
	
	/* ========================================
	Queue Test
	======================================== */
	/*
	// Create a new queue with default constructor
	Queue<int> myQueue1;
	cout << "myQueue1: " << myQueue1 << endl;
	cout << "empty? " << myQueue1.empty() << ", size = " << myQueue1.length() << endl;
	
	// Add some numbers, then print again
	myQueue1.enqueue(4);
	myQueue1.enqueue(7);
	myQueue1.enqueue(1);
	myQueue1.enqueue(343);
	cout << "myQueue1: " << myQueue1 << endl;
	
	// Dequeue, front, back
	cout << "dequeue: " << myQueue1.dequeue() << endl;
	cout << "front: " << myQueue1.front() << endl;
	cout << "back: " << myQueue1.back() << endl;
	
	// Copy constructor
	Queue<int> myQueue2 = myQueue1;
	myQueue2.enqueue(5);
	myQueue2.dequeue();
	cout << "myQueue1: " << myQueue1 << endl;
	cout << "myQueue2: " << myQueue2 << endl;
	
	// Assignment
	Queue<int> myQueue3;
	myQueue3 = myQueue1;
	cout << "\nmyQueue1: " << myQueue1 << endl;
	cout << "myQueue2: " << myQueue2 << endl;
	cout << "myQueue3: " << myQueue3 << endl;
	
	// Const test
	cout << endl << endl;
	Queue<int> first;
	first.enqueue(5);
	first.enqueue(10);
	first.enqueue(2);
	
	const Queue<int> second = first; 
	Queue<int> third = second;
	Queue<int> fourth;
	fourth = second;
	
	cout << first << endl << second << endl << third << endl << fourth << endl << endl;
	*/
	
	
	/* ========================================
	LList Test
	======================================== */
	/*
	// Create a new LList with default constructor
	LList<int> myList1;
	
	// Print empty LList
	cout << "1 ======\n";
	cout << "empty? " << myList1.empty() << ", size? " << myList1.length() << endl;
	cout << "myList1: ";
	myList1.print();
	cout << endl;
	
	// Insert some elements then print LList
	myList1.insert(5, 0);
	myList1.insert(10, 0);
	myList1.insert(15, 2);
	myList1.insert(99, 3);
	myList1.insert(100, 0);
	myList1.insert(49, 5);
	cout << "myList1: " << myList1 << endl;
	
	// Remove some elements then print LList
	myList1.remove(0);
	myList1.remove(1);
	myList1.remove(3);
	cout << "myList1: " << myList1 << endl;
	cout << "empty? " << myList1.empty() << ", size? " << myList1.length() << endl << endl;
	
	// Use "at" function
	cout << "myList1.at(0) = " << myList1.at(0) << endl;
	cout << "myList1.at(2) = " << myList1.at(2) << endl;
	try {
		cout << "myList1.at(9) = " << myList1.at(9) << endl << endl;
	}
	catch(int exceptionAtIndex) {
		cout << "INVALID INDEX: " << exceptionAtIndex << endl << endl;
	}
	
	// Use copy constructor
	cout << "\n2 ======\n";
	LList<int> myList2 = myList1;
	cout << "myList2: " << myList2 << endl;
	cout << "empty? " << myList2.empty() << ", size? " << myList2.length() << endl << endl;
	
	// Add something to both lists
	myList1.insert(87, 1);
	myList2.insert(3813, 0);
	
	// Remove everything from both lists, then print
	while (!myList1.empty())
		myList1.remove(0);
	while (!myList2.empty())
		myList2.remove(0);
		
	cout << "myList1: " << myList1 << endl;
	cout << "myList2: " << myList2 << endl;
	
	// Add something back to both lists
	cout << "\n3 ======\n";
	myList1.insert(87, 0);
	myList1.insert(54, 0);
	
	myList2.insert(3813, 0);
	myList2.insert(3, 1);
	
	// Use overloaded assignment
	myList1 = myList1;
	cout << "\nmyList1: " << myList1 << endl;
	
	myList1 = myList2;
	cout << "myList1: " << myList1 << endl;
	
	// Test front and back functions
	cout << "\n4 ======\n";
	myList1.push_front(1001);
	myList1.push_back(2003);
	cout << "\nmyList1: " << myList1 << endl;
	
	myList1.pop_back();
	myList1.pop_front();
	cout << "\nmyList1: " << myList1 << endl;
	
	cout << "front: " << myList1.front() << ", back:" << myList1.back() << endl;
	myList1.pop_back();
	cout << "front: " << myList1.front() << ", back:" << myList1.back() << endl;
	
	// Test contains, one argument insert, and no argument remove
	cout << "\n5 ======\n";
	myList1.insert(45);
	myList1.insert(3);
	myList1.insert(526);
	myList1.remove();
	cout << "contains 0: " << myList1.contains(0) << endl;
	cout << "contains 3: " << myList1.contains(3) << endl;
	cout << "contains 3813: " << myList1.contains(3813) << endl;
	cout << "contains 292: " << myList1.contains(292) << endl;
	cout << "contains 526: " << myList1.contains(526) << endl;
	
	// Test overloaded [] operator
	cout << "\n6 ======\n";
	cout << "unmodified: " << myList1 << endl;
	cout << "mylist1[1] = " << myList1[1] << endl;
	myList1[1] = 999;
	cout << "modified: " << myList1 << endl;
	
	
	
	// Print lists again at the end
	cout << "\n================================\n";
	cout << "myList1: " << myList1 << endl;
	cout << "myList2: " << myList2 << endl;
	
	
	// Const test
	cout << endl << endl;
	LList<int> first;
	first.push_back(5);
	first.push_back(10);
	first.push_back(2);
	
	const LList<int> second = first; 
	LList<int> third = second;
	LList<int> fourth;
	fourth = second;
	
	cout << first << endl << second << endl << third << endl << fourth << endl << endl;
	*/
}
