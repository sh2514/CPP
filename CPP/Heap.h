/* ==================================================
Heap
Shikuan Huang
================================================== */

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class MinHeap {
private:
  vector<T> heapArray;
  void swapElementsAtIndices(int firstPos, int secondPos) {
    int placeHolder = heapArray[firstPos];
	heapArray[firstPos] = heapArray[secondPos];
	heapArray[secondPos] = placeHolder;	
  }
  
public:
  bool insert(T itemToInsert) {
  	heapArray.push_back(itemToInsert);
  	int currentPos = heapArray.size() - 1;
  	int parentPos = (currentPos - 1) / 2;
  	while (currentPos > 0 && heapArray[parentPos] > itemToInsert) {
  	  swapElementsAtIndices(currentPos, parentPos);
  	  currentPos = parentPos;
  	  parentPos = (currentPos - 1) / 2;
  	}
  	return true;
  }
  
  // Remove and return the root of the heap
  T remove() {
  	T itemToReturn = heapArray[0];
  	swapElementsAtIndices(0, heapArray.size() - 1);
  	heapArray.erase(heapArray.begin() + heapArray.size() - 1);
  	
  	int currentPos = 0;
  	int secondChildPos = (currentPos + 1) * 2;
  	while (secondChildPos - 1 < heapArray.size() || secondChildPos < heapArray.size()) {
  	  int minChild = secondChildPos - 1;
  	  if (secondChildPos < heapArray.size() && heapArray[secondChildPos - 1] > heapArray[secondChildPos]) {
  	    minChild = secondChildPos;
  	  }
  	  
  	  if (heapArray[minChild] < heapArray[currentPos]) {
  	    swapElementsAtIndices(currentPos, minChild);
  	  }
  	  else {
  	    break;
  	  }
  	    
  	  currentPos = minChild;
  	  secondChildPos = (currentPos + 1) * 2;
  	}
  	return itemToReturn;
  }
  
  const T peek() const {
    return heapArray[0];
  }
  
  int size() const {
    return heapArray.size();
  }
  
  bool isEmpty() const {
    return heapArray.empty();
  }
  
  void print() const {
    for (int i = 0; i < heapArray.size(); i++) {
	  cout << heapArray[i] << " ";	
	}
  }
  
  bool operator==(const MinHeap & argHeap) const {
    if (heapArray.size() != argHeap.size()) {
	  return false;
    }
	  
	for (int i = 0; i < heapArray.size(); i++) {
	  if (heapArray[i] != (argHeap.heapArray)[i]) {
	    return false;
	  }
	}
	    
	return true;
  }
};

template <typename T>
ostream & operator<<(ostream & output, const MinHeap<T> & argHeap) {
  argHeap.print();
  return output;	
}
