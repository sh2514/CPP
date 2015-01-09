/* ==================================================
Square Root
010315
Shikuan Huang

Newton's Method
---------------
If y is a guess for the square root of x, then (y + (x/y)) / 2 is a better guess
1. Start with a guess y for the square root of x
2. Repeatedly update the guess using the above formula
3. Stop when y^2 and x are close enough
================================================== */

#include <iostream>
using namespace std;

double square(double number)
{
	return number * number;	
}

double abs(double number)
{
	if (number >= 0)
		return number;
	return -number;	
}

bool closeEnough(double first, double second)
{
	return (abs(first - second) < 0.0001);
}

double squareRoot(int number)
{
	if (number < 0)
		throw number;
	
	if (number == 0)
		return 0;
		
	double guess = number / 2;
	while (!closeEnough( number, square(guess)))
	{
		guess = (guess + (number / guess)) / 2;
	}
	return guess;
}

int main()
{
	cout << squareRoot(0);
}
