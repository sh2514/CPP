/* ==================================================
Array References
Shikuan Huang

Array References
	The number of array elements matter
	The array does not decay to a pointer
================================================== */

#include <iostream>
using namespace std;

void printFor5(int (&arg)[5])	// array reference parameter
{
	for (int i = 0; i < 5; i++)
		cout << arg[i] << " ";
}

int main()
{
	int arrayX[5] = {6, 3, 2, 7, 1};
	int arrayY[3] = {45, 3, 24};
	printFor5(arrayX);
	//printFor5(arrayY);		// NOT OKAY - wrong type; function accepts an array of 5 integers
}
