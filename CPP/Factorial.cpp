/* ==================================================
Factorial
Shikuan Huang

Basic recursive implementation
Dynamic programming implementation
Tail recursive implementation
Iterative implementation
================================================== */

#include <iostream>
using namespace std;

// Basic recursive implementation
long long rFactorial(long long number) {
	if (number == 0 || number == 1) {
		return 1;
	}
	return number * rFactorial(number - 1);
}

// Dynamic programming implementation
long long dFactorial(long long number, long long * answers) {
	if (answers[number] != -1) {
		return answers[number];
	}
	
	if (number == 0 || number == 1) {
		answers[number] = number;
		return number;
	}
	
	answers[number] = number * dFactorial(number - 1, answers);
	return answers[number];
}

long long dFactorial(long long number) {
	long long * answers = new long long[number + 1];
	for (int i = 0; i < number + 1; i++) {
		answers[i] = -1;
	}
	long long answer = dFactorial(number, answers);
	delete[] answers;
	return answer;
}

// Tail recursive implementation
long long tFactorial(int number, long long total = 1) {
	if (number == 0 || number == 1) {
		return total;
	}
	return tFactorial(number - 1, number * total);
}

// Iterative implementation
long long iFactorial(int number) {
	long long total = 1;
	while (number != 1) {
		total = total * number;
		number--;
	}
	return total;
}

int main() {
	int input;
	
	bool end = false;
	while(!end) {
		cout << "Factorial for? ";
		cin >> input;
		
		if (input == -1) {
			end = true;
		}
		else if (input < 0) {
			cout << "Invalid: " << input << endl;	
		}
		else {
			cout << "Factorial(" << input << ") = " << dFactorial(input) <<endl;
		}
	}
}
