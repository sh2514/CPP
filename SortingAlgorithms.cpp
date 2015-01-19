/* ============================================================
Sorting Algorithms
Shikuan Huang
============================================================ */

#include <iostream>
#include <cstdlib>
#include "SortingAlgorithms.h"
using namespace std;

int main()
{
	int array[20];
	for (int i = 0; i < 20; i++)
	{
		if (i == 10)
			cout << endl;
		array[i] = rand();
	}
	
	// Output unsorted array
	printArray(array, 20);
	cout << endl << endl;
	
	// Sort array and output sorted array
	RadixSort(array, 20);
	printArray(array, 20);
	cout << endl;
	
	// Sort a second time and output sorted array
	RadixSort(array, 20);
	cout << endl;
	printArray(array, 20);
	cout << endl;
	
	cout << "The array is in decreasing order: " << isDecreasing(array, 20);	
}


