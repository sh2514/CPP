/* ==================================================
Exponentiation
Shikuan Huang
================================================== */

#include <iostream>
using namespace std;

// Basic recursive implementation
long long rExp(long long number, int power)
{	
	if (power == 0)
		return 1;
	
	return number * rExp(number, power - 1);
}

// Basic recursive implementation for negative powers
double rNExp(double number, int power)
{
	if (power == 0)
		return 1;
	
	return (1/number) * rNExp(number, power - 1);
}

// Tail recursive implementation
long long tExp(int number, int power, long long partialProduct = 1)
{
	if (power == 0)
		return partialProduct * 1;
	
	return tExp(number, power - 1, partialProduct * number);
}

// Iterative implementation
long long iExp(int number, int power)
{
	long long result = 1;
	while (power != 0)
	{
		result = result * number;
		power--;
	}
	return result;
}

// Calls the positive and negative versions depending on "power"
long double exp(int number, int power)
{
	if (power < 0)
		return rNExp(number, -power);
	else
		return iExp(number, power);	
}

int main()
{
	int base;
	int power;
	bool end = false;
	
	while (!end)
	{
		cout << "Enter a base and a power: ";
		cin >> base >> power;

		cout << base << "^" << power << " = " << exp(base, power) << endl << endl;
	}
}
