/* ============================================================
BinarySearch
122514
Shikuan Huang

* Requires array to be sorted
============================================================ */

#include <iostream>
#include <cstdlib>
using namespace std;

#include "SortingAlgorithms.h"

/*
// Output array in rows of 10
void printArray(int * array, int size)
{
	if (size <= 0)
		return;
	for (int i = 0; i < 20; i++)
	{
		if (i == 10)
			cout << endl;
		cout << array[i] << " ";
	}
}
*/

// Returns the position of the search item or -1 if not found
// Assumes items sorted in DECREASING order
template <typename T>
int BinarySearch(T * array, int start, int end, T key)
{
	// Base case
	if (start >= end)
	{
		if (array[start] == key)
			return start;
		return -1;	
	}
	
	int middle = (end - start) / 2 + start;
	if (array[middle] == key)
		return middle;
	else if (array[middle] < key)
		return BinarySearch(array, start, middle - 1, key);
	else if (array[middle] > key)
		return BinarySearch(array, middle + 1, end, key);
}

int main()
{
	int array[20];
	for (int i = 0; i < 20; i++)
	{
		if (i == 10)
			cout << endl;
		array[i] = rand();
	}
	
	callMergeSort(array, 20);
	
	// Output unsorted array
	printArray(array, 20);
	cout << endl << endl;
	
	int key = 0;
	int result = -1;
	while (key != -1)
	{
		cout << "Enter a search key: ";
		cin >> key;
		result = BinarySearch(array, 0, 19, key);
		if (result != -1)
			cout << key << " found at position " << result << endl;
		else
			cout << key << " not found in array" << endl;
	}
	
}
