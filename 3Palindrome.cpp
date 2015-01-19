/* ============================================================
Determine whether a string is a palindrome
120514
Shikuan Huang
============================================================ */

#include <iostream>
#include <string>
using namespace std;

// Determine whether the string argument is a palindrome
bool isPalindrome(string arg)
{
	if (arg.length() == 0)
		return false;
	for (int i = 0; i <= arg.length() / 2; i++)
	{
		if (arg[i] != arg[arg.length() - 1 - i])	// Check the current front and current end
			return false;
	}
	return true;
}

int main()
{
	string a = "Duran";
	string b = "racecar";
	string c = "level";
	string d = "Irelia";
	string e = "";
	string f = "ieffei";
	
	cout << isPalindrome(a) << " "
		 << isPalindrome(b) << " "
		 << isPalindrome(c) << " "
		 << isPalindrome(d) << " "
		 << isPalindrome(e) << " "
		 << isPalindrome(f) << endl;
}
