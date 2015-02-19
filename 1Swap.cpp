/* ============================================================
Swap the value of two variables
Shikuan Huang
============================================================ */

#include <iostream>
using namespace std;

// Swaps two integers by reference
void swapTwoInts(int & first, int & second) {
	int temp = first;
	first = second;
	second = temp;
}

// Swaps two objects by reference
template <typename T>
bool mySwap(T & first, T & second) {
	T temp = first;
	first = second;
	second = temp;	
}

int main() {
	int a = 1;
	int b = 99;
	
	cout << "Before swapTwoInts, a = " << a << " and b = " << b << endl;
	swapTwoInts(a, b);
	cout << "After swapTwoInts, a = " << a << " and b = " << b << endl;
	
	float x = 1.23;
	float y = 3.14;
	cout << "Before mySwap, x = " << x << " and y = " << y << endl;
	mySwap(x, y);
	cout << "After mySwap, x = " << x << " and y = " << y << endl;
	
	return 0;
}
