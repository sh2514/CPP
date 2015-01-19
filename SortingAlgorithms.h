/* ============================================================
Sorting Algorithms
122314
Shikuan Huang

Selection Sort
Insertion Sort
Bubble Sort
Merge Sort
Quick Sort
Radix Sort (imcomplete)
============================================================ */

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <list>
using namespace std;
using std::list;

// Determine whether the array is in decreasing order
bool isDecreasing(int * array, int size)
{
	bool result = true;
	for (int i = 0; i < size - 1; i++)
		if (array[i] < array[i + 1])
			result = false;
	return result;
}

// Determine whether the array is in increasing order
bool isIncreasing(int * array, int size)
{
	bool result = true;
	for (int i = 0; i < size - 1; i++)
		if (array[i] > array[i + 1])
			result = false;
	return result;
}

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

// Swap the items pointed to by the pointers
template <typename T>
void swap(T * first, T * second)
{
	T temp = *first;
	*first = *second;
	*second = temp;
}

// Return the index of the largest item in the array
template <typename T>
int findMax(T * array, int size)
{
	// If the array is empty or size is invalid
	if (size <= 0)
		return -1;
	
	// Assume largest item is in index 0, then check all elements for the largest
	T max = 0;
	for (int i = 1; i < size; i++)
	{
		if (array[i] > array[max])
			max = i;
	}
	
	return max;
}

/* ============================================================
Selection Sort
============================================================ */
template <typename T>
void SelectionSort(T * array, int size)
{
	if (size <= 1)
		return;
	int currentLargest = 0;
	for (int i = 0; i < size - 1; i++)
	{
		// Find largest in remaining array, then place in the current position
		currentLargest = i + findMax( &(array[i]), size - i );	// adjust to get absolute position
		// cout << currentLargest << " ";
		swap(&(array[i]), &(array[currentLargest]));
	}
}

/* ============================================================
Insertion Sort
============================================================ */
template <typename T>
void InsertionSort(T * array, int size)
{
	if (size <= 1)
		return;
	int currentPosition = 0;
	for (int i = 1; i < size; i++)
	{
		// Move items that are greater/less than ahead
		T item = array[i];
		currentPosition = i;
		while (currentPosition > 0 && item > array[currentPosition - 1])
		{
			swap(&(array[currentPosition]), &(array[currentPosition - 1]));
			currentPosition--;
		}
		// currentPosition is the correct position to insert for this iteration
		array[currentPosition] = item;
	}
}

/* ============================================================
Bubble Sort
============================================================ */
template <typename T>
void BubbleSort(T * array, int size)
{
	if (size <= 1)
		return;
	for (int i = 0; i < size - 1; i++)
	{
		// Swap pairs of numbers if they are out of order, increment current position by 1
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (array[j] < array[j + 1])
				swap(&(array[j]), &(array[j + 1]));
		}
	}
}

/* ============================================================
Merge Sort
============================================================ */
// Merge the two subarrays, denoted a and b, into one ordered array
template <typename T>
void Merge(T * array, int aBegin, int aEnd, int bBegin, int bEnd)
{
	int arrayBegin = aBegin;	// beginning position of the current part of the actual array
	int totalArraySize = (aEnd - aBegin + 1) + (bEnd - bBegin + 1);
	int currentPosition = 0;	// current position in tempArray
	T * tempArray = new T[totalArraySize];
	
	// While there are elements in either of the arrays that haven't been used yet
	while(aBegin <= aEnd && bBegin <= bEnd)
	{
		// array a has the larger element
		if (array[aBegin] >= array[bBegin])
		{
			tempArray[currentPosition] = array[aBegin];
			currentPosition++;
			aBegin++;
		}
		// array b has the larger element
		else
		{
			tempArray[currentPosition] = array[bBegin];
			currentPosition++;
			bBegin++;
		}
	}
	
	// Array a's elements have not all been used
	while (aBegin <= aEnd)
	{
		tempArray[currentPosition] = array[aBegin];
		currentPosition++;
		aBegin++;
	}
	// Array b's elements have not all been used
	while (bBegin <= bEnd)
	{
		tempArray[currentPosition] = array[bBegin];
		currentPosition++;
		bBegin++;
	}
	
	// Copy the temp array into the actual array
	for (int i = 0; i < totalArraySize; i++)
	{
		array[arrayBegin + i] = tempArray[i];
	}
}

// Recursively divide the array and merge subarrays
template <typename T>
void MergeSort(T * array, int start, int end)
{
	// Base case - sort one element
	if (end - start == 0)
	{
		return;
	}
	
	int range = end - start;	
	int mid = start + (range / 2);
	int aBegin = start;
	int aEnd = mid;
	int bBegin = mid + 1;
	int bEnd = end;
	MergeSort(array, aBegin, aEnd);
	MergeSort(array, bBegin, bEnd);
	Merge(array, aBegin, aEnd, bBegin, bEnd);
}

// Used to initialize call to MergeSort
template <typename T>
void callMergeSort(T * array, int size)
{
	MergeSort(array, 0, size - 1);	
}


/* ============================================================
Quick Sort
============================================================ */
template <typename T>
void QuickSort(T * array, int start, int end)
{
	if (end - start <= 0)
		return;
	
	int pivot = rand() % (end - start + 1) + start;
	int currentPos = start + 1;					// The index to swap elements into
	swap(&(array[pivot]), &(array[start]));		// Move the pivot to the first index
	pivot = start;
	
	
	for (int i = start + 1; i <= end; i++)
	{
		if (array[i] > array[pivot])
		{
			swap(&(array[i]), &(array[currentPos]));
			currentPos++;
		}
	}
	
	swap(&(array[pivot]), &(array[currentPos - 1]));
	
	QuickSort(array, start, currentPos - 2);
	QuickSort(array, currentPos, end);
}

template <typename T>
void callQuickSort(T * array, int size)
{
	QuickSort(array, 0, size - 1);	
}

/* ============================================================
Radix Sort (IMCOMPLETE)
============================================================ */
template <typename T>
void RadixSort(T * array, int size)
{	
	if (size <= 0)
		return;
	
	list<T> Bins[10];
		
	int maxDigit = 0;
	int currentNumberLength = 0;

	string * intStrings = new string[size];
	for (int i = 0; i < size; i++)
	{
		ostringstream convert;
		convert << array[i];
		intStrings[i] = convert.str();
		
		if ((intStrings[i]).length() > maxDigit)
			maxDigit = (intStrings[i]).length();
	}
	
	// Put all the numbers into the bins based on one's digit
	for (int i = 0; i < size; i++)
	{
		currentNumberLength = (intStrings[i]).length();
		switch(intStrings[currentNumberLength])
		{
			case 0:
				Bins[0].push_back(intStrings[i]);
				break;	
			case 1:
				Bins[1].push_back(intStrings[i]);
				break;	
			case 2:
				Bins[2].push_back(intStrings[i]);
				break;	
			case 3:
				Bins[3].push_back(intStrings[i]);
				break;	
			case 4:
				Bins[4].push_back(intStrings[i]);
				break;	
			case 5:
				Bins[5].push_back(intStrings[i]);
				break;	
			case 6:
				Bins[6].push_back(intStrings[i]);
				break;	
			case 7:
				Bins[7].push_back(intStrings[i]);
				break;	
			case 8:
				Bins[8].push_back(intStrings[i]);
				break;	
			case 9:
				Bins[9].push_back(intStrings[i]);
				break;	
			default:
				break;
		}
	}
	
	// Iterate for each digit, starting with the smallest digit
	for (int i = 2; i <= maxDigit; i++)
	{
		// Go through each bin, starting with the 9 bin
		for (int j = 9; j >= 0; j--)
		{
			while (!(Bins[j].empty()))
			{
				// If the number doesn't the current digit
				if (Bins[j].front().length() < i)
				{
					
				}
			}
		}
	}
	
}


