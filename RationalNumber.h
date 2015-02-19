/* ==================================================
Rational Number
Shikuan Huang

Euclid's Algorithm (greatest common divisor algorithm for two non-zero numbers)
http://en.wikipedia.org/wiki/Euclidean_algorithm
================================================== */

#include <iostream>
using namespace std;

// Absolute Value
int absValue(int number) {
	if (number < 0) {
		return -number;
	}
	return number;	
}

// Euclid's Algorithm
int GCD(int first, int second) {	
	first = absValue(first);
	second = absValue(second);
	
	if (second > first) {
		int temp = first;
		first = second;
		second = temp;	
	}
	
	if (second == 0) {
		throw second;
	}
	
	int remainder = first % second;
	while (remainder != 0) {
		first = second;
		second = remainder;
		remainder = first % second;
	}
	return second;
}

class Rat {
private:
	int numerator;
	int denominator;
	
public:	
	// Initializes the number to 0/1
	Rat() 
	: numerator(0), denominator(1)
	{};
	
	// Constructor - takes a numerator and a denominator
	Rat(int numer, int denom = 1) {
		if (!set(numer, denom)) {
			numerator = 0;
			denominator = 1;
		}
	}
	
	int getNumerator() const {
		return numerator;
	}
	
	int getDenominator() const  {
		return denominator;
	}
	
	// Change the rational number (always in lowest form with negative in numerator)
	bool set(int numer, int denom = 1) {
		if (denom == 0) {
			return false;
		}
		
		// Adjust negatives and if "Rat" is negative make numerator negative
		if ((numer < 0 && denom < 0) || denom < 0) {
			numer = -numer;
			denom = -denom;	
		}
		
		int divisor = GCD(numer, denom);
		
		numerator = numer/divisor;
		denominator = denom/divisor;
		return true;	
	}
	
	// Return a double representation
	double getDouble() const {
		double result = (double)numerator / denominator;
		return result;
	}
	
	// Returns the absolute value double representation
	double abs() const {
		double result = getDouble();
		if (result < 0) {
			result = -result;
		}
		return result;	
	}
	
	// Outputs the rational number with a slash
	void print() const {
		cout << numerator << "/" << denominator;
	}
	
	// Output the rational number in double form
	void printDouble() const {
		double result = (double)numerator / denominator;
		cout << result;	
	}
	
	// Reduce rational number to lowest form
	void reduce() {
		int divisor = GCD(numerator, denominator);
		numerator = numerator/divisor;
		denominator = denominator/divisor;	
	}
	
	Rat operator+(Rat second) const {
		int numer = (numerator * second.denominator) + (denominator * second.numerator);
		int denom = denominator * second.denominator;		
		int divisor = GCD(numer, denom);
		
		return Rat(numer/divisor, denom/divisor);
	}
	
	Rat operator-(Rat second) const {
		int numer = (numerator * second.denominator) - (denominator * second.numerator);
		int denom = denominator * second.denominator;		
		int divisor = GCD(numer, denom);
		
		return Rat(numer/divisor, denom/divisor);
	}
	
	Rat operator*(Rat second) const {
		int numer = numerator * second.numerator;
		int denom = denominator * second.denominator;		
		int divisor = GCD(numer, denom);
		
		return Rat(numer/divisor, denom/divisor);
	}
	
	Rat operator/(Rat second) const {
		int numer = numerator * second.denominator;
		int denom = denominator * second.numerator;		
		int divisor = GCD(numer, denom);
		
		return Rat(numer/divisor, denom/divisor);
	}
	
	Rat operator++() {
		numerator = numerator + denominator;
		reduce();
		
		return Rat(numerator, denominator);	
	}
	
	Rat operator++(int) {
		Rat result(numerator, denominator);
		numerator = numerator + denominator;
		reduce();
		
		return result;
	}

	Rat operator--() {
		numerator = numerator - denominator;
		reduce();
		
		return Rat(numerator, denominator);	
	}
	
	Rat operator--(int) {
		Rat result(numerator, denominator);
		numerator = numerator - denominator;
		reduce();
		
		return result;
	}
	
	bool operator==(const Rat & arg) {	
		return (numerator == arg.numerator && denominator == arg.denominator);
	}
	
	bool operator<(const Rat & arg) {		
		return (numerator * arg.denominator) < (arg.numerator * denominator);
	}
	
	bool operator>(const Rat & arg) {
		return (numerator * arg.denominator) > (arg.numerator * denominator);
	}
};

ostream & operator<<(ostream & output, const Rat & number) {
	number.printDouble();
	return output;	
}
