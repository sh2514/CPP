/* ============================================================
BinarySearch
122514
Shikuan Huang

* Requires array to be sorted
============================================================ */

#include <iostream>
#include <cstdlib>
#include "SortingAlgorithms.h"
using namespace std;

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
	
	// Determine whether the key is found, or is in lower half or upper half
	int middle = (end - start) / 2 + start;
	if (array[middle] == key)
		return middle;
	else if (array[middle] < key)
		return BinarySearch(array, start, middle - 1, key);
	else if (array[middle] > key)
		return BinarySearch(array, middle + 1, end, key);
}

// Iterative implementation
// Returns the position of the searchitem or -1 if not found
// Assumes items sorted in DECREASING order
template <typename T>
int iBinarySearch(T * array, int start, int end, T key)
{
	// Invalid indices check
	if (start > end)
		return -1;
	
	// While starting index is less than or equal to ending index
	while (start <= end)
	{
		int middle = (end - start) / 2 + start;
		
		if (array[middle] == key)
			return middle;
		else if (array[middle] < key)
			end = middle - 1;
		else if (array[middle] > key)
			start = middle + 1;
	}	
	
	// The array has been checked and key is not found
	return -1;
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
	
	// Output sorted array
	printArray(array, 20);
	cout << endl << endl;
	
	int key = 0;
	int result = -1;
	while (key != -1)
	{
		cout << "Enter a search key: ";
		cin >> key;
		result = iBinarySearch(array, 0, 19, key);
		if (result != -1)
			cout << key << " found at position " << result << endl;
		else
			cout << key << " not found in array" << endl;
	}
}
