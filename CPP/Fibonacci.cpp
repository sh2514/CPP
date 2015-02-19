/* ==================================================
Fibonacci
Shikuan Huang

Basic recursive implementation
Dynamic programming implementation
Tail recursive implementation
Iterative implementation
================================================== */

#include <iostream>
using namespace std;

// Basic recursive implemenation
long long rFibonacci(long long number) {
	if (number < 0) {
		throw number;
	}
		
	if (number == 0 || number == 1) {
		return number;
	}
	else {
		return rFibonacci(number - 1) + rFibonacci(number - 2);
	}
}

// Helper function that performs the actual computation
long long dFib(int number, long long * answers) {	
	if (number == 0 || number == 1) {
		return number;
	}
	
	if (answers[number - 1] != -1) {
		return answers[number - 1];
	}
	
	answers[number - 1] = dFib(number - 1, answers) + dFib(number - 2, answers);
	return answers[number - 1];
}

// Dynamic programming implementation
long long dFibonacci(int number) {
	if (number < 0) {
		throw number;
	}
	
	long long * answers = new long long[number];
	for (int i = 0; i < number; i++) {
		answers[i] = -1;
	}
		
	long long answer = dFib(number, answers);
	delete[] answers;
	return answer;
}

// Tail recursive implementation
long long tFibonacci(int number, long long first, long long second) {
	if (number == 0) {
		return second;
	}
	return tFibonacci(number - 1, second, first + second);
}

long long tFibonacci(int number) {
	if (number == 0) {
	  return number;
	}
	return tFibonacci(number - 1, 0, 1);
}

// Iterative implementation
long long iFibonacci(long long number) {
	if (number < 0) {
		throw number;
	}
		
	if (number == 0) {
		return 0;
	}
		
	long long first = 0;
	long long second = 1;
	long long next = 0;
	
	for (long long i = 1; i < number; i++) {
		next = first + second;
		first = second;
		second = next;
	}
	
	return second;
}

int main() {
	int input;
	bool end = false;
	while (!end) {
		cout << "factorial for? ";
		cin >> input;
		if (input < 0) {
			cout << "INVALID INPUT\n\n";
		}
		else {
			cout << "fibonacci(" << input << ") = " << tFibonacci(input) << endl << endl;
		}
	}
}
