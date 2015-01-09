/* ==================================================
Tic Tac Toe
010715
Shikuan Huang

Read keyboard input in real time
	conio.h
================================================== */

#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>

using namespace std;

class TicTacToe
{
private:
	char ** board;
	int turn;					// 0 = player 1's turn; 1 = player 2's turn; -1 = game over
	int winner;					// 0 = player 1 wins; 1 = player 2 wins; -1 = no winner
	int turnNumber;				// How many turns has it been?
	const static int rows = 3;
	const static int cols = 3;
	
public:
	// Default constructor
	TicTacToe()
	{		
		winner = -1;
		turnNumber = 1;
		
		board = new char*[rows];
		for (int i = 0; i < cols; i++)
		{
			board[i] = new char[cols];
			for (int j = 0; j < cols; j++)
				board[i][j] = ' ';
		}
	}
	
	// Copy constructor
	TicTacToe (const TicTacToe & arg)
	{
		(*this) = arg;
	}
	
	// Overloaded assignment
	TicTacToe & operator=(const TicTacToe & arg)
	{
		if (this == &arg)
			return *this;
		
		board = new char*[rows];
		for(int i = 0; i < cols; i++)
		{
			board[i] = new char[cols];
		}
		
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				board[i][j] = arg.board[i][j];
		
		turn = arg.turn;
		winner = arg.winner;
		turnNumber = arg.turnNumber;
		
		return *this;
	}
	
	// Destructor
	~TicTacToe()
	{
		for (int i = 0; i < rows; i++)
			delete[] board[i];
		delete board;
		board = NULL;
	}
	
	// Updates the game status - whether it is game over or not
	void updateStatus()
	{
		// Check if someone won
		char symbol;
		if (turn == 0)
			symbol = 'X';
		else
			symbol = 'O';
			
		if ((board[0][0] == symbol && board[0][1] == symbol && board[0][2] != symbol)
			|| (board[1][0] == symbol && board[1][1] == symbol && board[1][2] == symbol)
			|| (board[2][0] == symbol && board[2][1] == symbol && board[2][2] == symbol)
			|| (board[0][0] == symbol && board[1][0] == symbol && board[2][0] == symbol)
			|| (board[0][1] == symbol && board[1][1] == symbol && board[2][1] == symbol)
			|| (board[0][2] == symbol && board[1][2] == symbol && board[2][2] == symbol)
			|| (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
			|| (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol))
		{
			winner = turn;
			turn = -1;
		}
		else
		{
			turn = 1 - turn;
		}
	}
	
	// Makes a move on the board based on the row and column
	bool makeMove(int row, int col)
	{
		// Ensure game is not over and indices are valid
		if (turn == -1 || row < 0 || row > 2 || col < 0 || col > 2 )
			return false;
		
		// If player is trying to make a move in a spot that already has a symbol
		if (board[row][col] != ' ')
		{
			cout << "Invalid move!  Enter another move!\n";
			display();
			return false;
		}
		
		// Whose turn?
		if (turn == 0)
		{
			board[row][col] = 'X';
			updateStatus();
		}
		else
		{
			board[row][col] = 'O';
			updateStatus();
		}
		turnNumber++;
		display();				// Display updated board
		
		return true;
	}
	
	// Convert keyboard input into a valid move
	bool input(int key)
	{
		switch(key)
		{
			/*
			// Used when _getch() is not used
			case 'Q':
			case 'q':
				return makeMove(0, 0);
				break;
			case 'W':
			case 'w':
				return makeMove(0, 1);
				break;
			case 'E':
			case 'e':
				return makeMove(0, 2);
				break;
			case 'A':
			case 'a':
				return makeMove(1, 0);
				break;
			case 'S':
			case 's':
				return makeMove(1, 1);
				break;
			case 'D':
			case 'd':
				return makeMove(1, 2);
				break;
			case 'Z':
			case 'z':
				return makeMove(2, 0);
				break;
			case 'X':
			case 'x':
				return makeMove(2, 1);
				break;
			case 'C':
			case 'c':
				return makeMove(2, 2);	
				break;
			default:
				return makeMove(99, 99);
				break;
			*/
			case 113:	// q
			case 81:	// Q
				return makeMove(0, 0);
				break;
			case 119:	// w
			case 87:	// W
				return makeMove(0, 1);
				break;
			case 101:	// e
			case 69:	// E
				return makeMove(0, 2);
				break;
			case 97:	// a
			case 65:	// A
				return makeMove(1, 0);
				break;
			case 115:	// s
			case 83:	// S
				return makeMove(1, 1);
				break;
			case 100:	// d
			case 68:	// D
				return makeMove(1, 2);
				break;
			case 122:	// z
			case 90:	// Z
				return makeMove(2, 0);
				break;
			case 120:	// x
			case 88:	// X
				return makeMove(2, 1);
				break;
			case 99:	// c
			case 67:	// C
				return makeMove(2, 2);	
				break;
			default:
				return makeMove(99, 99);
				break;	
		}
	}
	
	// Print the board, then print the status line
	void display() const
	{
		cout << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (j == 1)
					cout << "|" << board[i][j] << "|";	// Print the grid
				else
					cout << board[i][j];	
			}
			if (i < 2)
				cout << "\n-----\n";					// Print the grid
			else
				cout << endl;
		}
		
		if (turn == 0)
			cout << "Turn " << turnNumber << " - Game ongoing: X's turn...\n";
		else if (turn == 1)
			cout << "Turn " << turnNumber << " - Game ongoing: O's turn...\n";
		else
		{
			if (winner == 0)
				cout << "Game Over: X wins!\n";
			else
				cout << "Game Over: O wins!\n";
		}
		cout << endl << endl;
	}
	
	// Clears the board for a new game
	void clearBoard()
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				board[i][j] = ' ';	
	}
	
	// Start TicTacToe
	void startGame()
	{
		bool endGame = false;		// Continue game?
		while (!endGame)
		{
			// *** LOAD GAME HERE
			string input = "NA";
			// Play X or O, or exit game 
			while (input != "X" && input != "O" && input != "exit")
			{
				cout << "Play as X or O? ";
				cin >> input;
				if (input == "X")
					turn = 0;
				else if (input == "O")
					turn = 1;
				else
					exit(0);
			}
			cout << endl << endl;
			
			// Read moves from user
			int key = 0;
			display();
			while (turn != -1)
			{
				//cin >> key;	// Used when _getch() is not used
				key = _getch();
				this->input(key);
			}
			
			// Start a new game?  If yes, clear board and reset game variables
			input = "NA";
			while (input != "Y" && input != "N")
			{
				cout << "Start new game (Y/N)?";
				cin >> input;
				if (input == "Y")
				{
					winner = -1;
					turnNumber = 1;
					clearBoard();
				}
				else if (input == "N")
				{
					endGame = true;
				}
			}
		}
	}
};

// Overloaded stream insertion
ostream & operator<<(ostream & output, TicTacToe arg)
{
	arg.display();
	return output;
}	

int main()
{
	TicTacToe myGame;
	myGame.startGame();
	
	TicTacToe myGame2 = myGame;
	TicTacToe myGame3;
	myGame3 = myGame2;
}
