/* ==================================================
Factorial
010915
Shikuan Huang
================================================== */

#include <iostream>
using namespace std;

// Basic recursive implementation
long long rFactorial(int number)
{
	if (number == 0 || number == 1)
		return 1;
	return number * rFactorial(number - 1);
}

// Tail recursive implementation
long long tFactorial(int number, long long total = 1)
{
	if (number == 0 || number == 1)
		return total;
	return tFactorial(number - 1, number * total);
}

// Iterative implementation
long long iFactorial(int number)
{
	long long total = 1;
	while (number != 1)
	{
		total = total * number;
		number--;
	}
	return total;
}

int main()
{
	int input;
	
	bool end = false;
	while(!end)
	{
		cout << "Factorial for? ";
		cin >> input;
		
		if (input == -1)
			end = true;
		else if (input < 0)
			cout << "Invalid: " << input << endl;	
		else
		{
			cout << "Factorial(" << input << ") = " << iFactorial(input) <<endl;
		}
	}
}
