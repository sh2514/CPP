/* ==================================================
Tower of Hanoi
011215
Shikuan Huang
================================================== */

#include <iostream>
#include "LList.h"
using namespace std;

class ToH
{
private:
	int numberOfRings;		// number of rings
	Stack<int> towers[3];	// the three towers
	int moves;				// count the number of moves
	
public:
	// Construct ToH with "rings" number of rings
	ToH(int rings = 1)
	{
		moves = 0;
		if (rings <= 0)
			numberOfRings = 1;
		else
			numberOfRings = rings;
			
		for (int i = numberOfRings; i >= 1; i--)
			towers[0].push(i);
	}
	
	// Move top ring from tower "from" to tower "to"
	void moveRing(int from, int to)
	{
		moves++;
		int temp = towers[from].peek();
		towers[from].pop();
		towers[to].push(temp);	
	}
	
	// Solve the puzzle
	void solve(bool showSteps = false)
	{
		normalToH(0, 2, 1, numberOfRings, showSteps);
	}
	
	// Solves the normal ToH
	void normalToH(int from, int to, int extra, int rings, bool showSteps)
	{
		if (towers[from].size() == 0)
			throw 1;
		
		// Base case
		if (rings == 1)
		{
			moveRing(from, to);
			if (showSteps)
			{
				print();
				cout << endl;
				cin.ignore();
			}
			return;
		}
		
		// Recursively solve the smaller problem
		normalToH(from, extra, to, rings - 1, showSteps);
		moveRing(from, to);
		if (showSteps)
		{
			print();
			cout << endl;
			cin.ignore();
		}

		normalToH(extra, to, from, rings - 1, showSteps);
	}
	
	// Return the number of moves
	int getMoves() const
	{
		return moves;
	}
	
	// Output the towers
	void print() const
	{
		for (int i = 0; i < 3; i++)
			cout << "> " << towers[i] << endl;
	}
};

// Overloaded stream insertion
ostream & operator<<(ostream & output, const ToH & arg)
{
	arg.print();
	return output;	
}

int main()
{
	ToH newPuzzle(15);
	newPuzzle.solve(0);
	cout << newPuzzle << endl;
	cout << "Moves: " << newPuzzle.getMoves() << endl;
}
