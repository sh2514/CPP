/* ==================================================
Heap
Shikuan Huang
================================================== */

#include <iostream>
#include "Heap.h"
using namespace std;

int main(int argc, char ** argv) {
  MinHeap<int> myHeap;
  cout << "Size: " << myHeap.size() << ", Empty: " << myHeap.isEmpty() << ", Heap: " << myHeap << endl; 
  
  myHeap.insert(5);
  myHeap.insert(7);
  myHeap.insert(4);
  myHeap.insert(11);
  myHeap.insert(8);
  myHeap.insert(10);
  myHeap.insert(6);
  myHeap.insert(12);
  myHeap.insert(3);
  cout << "Size: " << myHeap.size() << ", Empty: " << myHeap.isEmpty() << ", Heap: " << myHeap << endl;
  
  MinHeap<int> myHeap2 = myHeap;
  cout << "myHeap == myHeap2? " << (myHeap == myHeap2) << endl;
  myHeap2.remove();
  cout << "myHeap == myHeap2? " << (myHeap == myHeap2) << endl;
  
  cout << "myHeap2.peek() = " << myHeap2.peek() << endl;
  
  while(!myHeap.isEmpty()) {
    myHeap.remove();
  }
  cout << "Size: " << myHeap.size() << ", Empty: " << myHeap.isEmpty() << ", Heap: " << myHeap << endl;
}
