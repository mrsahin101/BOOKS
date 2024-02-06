// Program to convert temperature from Celcuis to degree
// units into Fahrenheit degree units
// Fahrenheit = Celcius * (212 - 32) / 100 + 32

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int nNumberofArgs, char *pszArgs[])
{
	// enter the temperature in Celcius
	int celsius;
	cout << "Enter the temperature in Celsius :";
	cin >> celsius;
	
	// calculate conversion factor for Celcius to Fahrenheit
	int factor;
	factor = 212 - 32;
	
	// use conversion factor to convert Celcius into Fahrenheit values
	int fahrenheit;
	fahrenheit = factor * celsius / 100 + 32;
	
	// output the results (followed by a newline)
	cout << "Fahrenheit value is:";
	cout << fahrenheit << endl;
	
	// wait until user is ready before terminating program to allow the user to see the program results
	system("PAUSE");
	return 0;
}
