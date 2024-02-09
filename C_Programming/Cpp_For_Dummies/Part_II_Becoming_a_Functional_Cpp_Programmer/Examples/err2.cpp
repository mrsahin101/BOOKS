// ErrorProgram - this program averages a series of numbers, except that it contains
// at least one fatal bug
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(int nNumberofArgs, char* pszArgs[])
{
	cout << "This program generates incorrect results" <<endl;
	
	// accumulate input numbers until the user enters a negative number, then return
	// the average
	int nSum;
	
	for(int nNums = 0; ; nNums++)
	{
		// enter another number to add
		int nValue;
		cout << "Enter another number";
		cin >> nValue;
		cout << endl;
		
		// if the input number is negative
		if(nValue < 0)
		{
			// ... then output the average
			cout << "\nAverage is : " 
				 << nSum / nNums
				 << "\n";
			break;
		}
		// output critical information
		cout << "nSum = " << nSum << "\n";
		cout << "nNums = " << nNums << "\n";
		cout << "nValue = " << nValue << "\n";
		cout << endl;
		
		// not negative, add the value the accumulator
		nSum += nValue;
	}
	// wait until user is ready before terminating program to allow the user to see
	// the program results
	system("PAUSE");
	return 0;
}
