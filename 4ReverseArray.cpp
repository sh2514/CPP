/* ============================================================
Reverse array
120514
Shikuan Huang
============================================================ */

#include <iostream>
using namespace std;

// Reverse the items in an array
template <typename T>
bool reverseArray(T * array, int size)
{
	if (size == 0)
		return false;
	else if (size == 1)
		return true;
	else
	{
		T temp;
		for (int i = 0; i < size / 2; i++)
		{
			temp = array[i];
			array[i] = array[size - 1 - i];
			array[size - 1 - i] = temp;	
		}
		return true;
	}
}

int main()
{
	char array[8] = {'k', 'r', 'o', 'y', ' ', 'w', 'e', 'n'};
	
	reverseArray(array, 8);
	
	for(int i = 0; i < 8; i++)
		cout << array[i];
		
	return 0;
}
