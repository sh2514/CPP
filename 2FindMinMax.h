/* ============================================================
Find the index of the minimum and maximum in an array
120414
Shikuan Huang
============================================================ */

// Return the index of the minimum element in an integer array
int findMinInt(int * array, int size)
{
	if (size <= 0)
		return -1;
	else if (size == 1)
		return 0;
	else
	{
		int min = 0;
		for (int i = 1; i < size; i++)
		{
			if (array[i] < array[min])
			{
				min = i;	
			}
		}
		
		return min;
	}
}

// Return the index of the maximum element in an integer array
int findMaxInt(int * array, int size)
{
	if (size <= 0)
		return -1;
	else if (size == 1)
		return 0;
	else
	{
		int max = 0;
		for (int i = 1; i < size; i++)
		{
			if (array[i] > array[max])
			{
				max = i;	
			}
		}
		
		return max;
	}
}

// Return the index of the minimum element in an array
template <typename T>
int findMin(T * array, int size)
{
	if (size <= 0)
		return -1;
	else if (size == 1)
		return 0;
	else
	{
		int min = 0;
		for (int i = 1; i < size; i++)
		{
			if (array[i] < array[min])
				min = i;	
		}
		return min;
	}
}

// Return the index of the maximum element in an array
template <typename T>
int findMax(T * array, int size)
{
	if (size <= 0)
		return -1;
	else if (size == 1)
		return 0;
	else
	{
		int max = 0;
		for (int i = 1; i < size; i++)
		{
			if (array[i] > array[max])
				max = i;	
		}
		return max;
	}
}
