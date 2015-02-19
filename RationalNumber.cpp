/* ==================================================
Rational Number
Shikuan Huang
================================================== */

#include <iostream>
#include "RationalNumber.h"
using namespace std;

int main() {
	// Constructors and print functions
	Rat rat1;
	Rat rat2(2);
	Rat rat3(0, 0);
	Rat rat4(4, 2);
	Rat rat5(1, 3);
	Rat rat6(1, 4);
	
	Rat rat7 = rat4;		// Copy constructor
	Rat rat8;
	rat8 = rat4;			// Assignment
	
	Rat rat9(-16, -4);
	
	cout << "rat1 = ";
	rat1.print();
	cout << " = " << rat1 << endl;
	
	cout << "rat2 = ";
	rat2.print();
	cout << " = " << rat2 << endl;
	
	cout << "rat3 = ";
	rat3.print();
	cout << " = " << rat3 << endl;
	
	cout << "rat4 = ";
	rat4.print();
	cout << " = " << rat4 << endl;
	
	cout << "rat5 = ";
	rat5.print();
	cout << " = " << rat5 << endl;
	
	cout << "rat6 = ";
	rat6.print();
	cout << " = " << rat6 << endl;

	cout << "rat7 = ";
	rat7.print();
	cout << " = " << rat7 << endl;
	
	cout << "rat8 = ";
	rat8.print();
	cout << " = " << rat8 << endl;
	
	cout << "rat9 = ";
	rat9.print();
	cout << " = " << rat9 << endl;
	

	
	// Set
	cout << "\n===== SET =====\n";
	
	rat5.set(20, -4);
	cout << "rat5 = ";
	rat5.print();
	cout << " = " << rat5 << endl;
	
	rat6.set(-100, -4);
	cout << "rat6 = ";
	rat6.print();
	cout << " = " << rat6 << endl;
	
	rat7.set(0, 0);
	cout << "rat7 = ";
	rat7.print();
	cout << " = " << rat7 << endl;
	
	rat8.set(5);
	cout << "rat8 = ";
	rat8.print();
	cout << " = " << rat8 << endl;
	
	
	// getDouble, getNumerator, getDenominator
	cout << "\n===== GET =====\n";
	
	rat6.set(-1, 3);
	rat7.set(4, 6);
	
	cout << "rat6.double() = " << rat6.getDouble() 
		 << "\nrat6.getNumerator() = " << rat6.getNumerator()
		 << "\nrat6.getDenominator() = " << rat6.getDenominator() << endl << endl;
		 
	cout << "rat7.getDouble() = " << rat7.getDouble() 
		 << "\nrat7.getNumerator() = " << rat7.getNumerator()
		 << "\nrat7.getDenominator() = " << rat7.getDenominator() << endl << endl;
		 
		 
	// Arithmetic operators
	cout << "\n===== Arithmetic Operators =====\n";
	
	Rat result = rat6 + rat7;
	cout << "rat6 + rat7 = " << rat6 + rat7 << " = ";
	(rat6 + rat7).print();
	cout << endl;
	
	result = rat6 - rat7;
	cout << "rat6 - rat7 = " << result << " = ";
	result.print();
	cout << endl;
	
	result = rat6 * rat7;
	cout << "rat6 * rat7 = " << result << " = ";
	result.print();
	cout << endl;
	
	result = rat6 / rat7;
	cout << "rat6 / rat7 = " << result << " = ";
	result.print();
	cout << endl << endl;
	
	cout << "result = " << result << endl;
	cout << "result.abs() = " << result.abs() << endl << endl;
	
	// Increment and decrement operators
	cout << "\n===== Increment and Decrement Operators =====\n";
	cout << "result = " << result << endl;
	cout << "result++ = " << result++ << endl;
	cout << "result = " << result << endl << endl;
	
	cout << "++result = " << ++result << endl;
	cout << "result = " << result << endl << endl;
	
	cout << "result-- = " << result-- << endl;
	cout << "result = " << result << endl << endl;
	
	cout << "--result = " << --result << endl;
	cout << "result = " << result << endl;
	
	// Greatest Common Divisor
	cout << "\n===== GCD =====\n";
	cout << "GCD(100, 25) = " << GCD(100, 25) << endl;
	cout << "GCD(125, 225) = " << GCD(125, 225) << endl;
	cout << "GCD(1, 45) = " << GCD(1, 45) << endl;
	
	// Relational Operators
	cout << "\n===== Relational Operators =====\n";
	Rat ratx(-2, 4);
	Rat raty(2, -4);
	Rat ratz(-5, 2);
	
	cout << ratx << " == " << raty << "? " << (ratx == raty) << endl;
	cout << ratx << " < " << raty << "? " << (ratx < raty) << endl;
	cout << ratx << " > " << raty << "? " << (ratx > raty) << endl << endl;
	
	cout << ratx << " == " << ratz << "? " << (ratx == ratz) << endl;
	cout << ratx << " < " << ratz << "? " << (ratx < ratz) << endl;
	cout << ratx << " > " << ratz << "? " << (ratx > ratz) << endl;
}
