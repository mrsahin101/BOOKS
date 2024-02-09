// SavingsClassInline - invoke a member function that's both declared and defined within the class Student
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;
#include "savings.h"

// Define the member function Savings:: deposit() (normally this is contained in a separate file that is 
// combined with a different file that is combined)
float Savings::deposit(float amount)
{
    balance += amount;
    return balance;
}
int main(int nNumberofArgs, char* pszArgs[])
{
    Savings s;
    s.accountNumber = 123456;
    s.balance = 0.0;

    // now add something to the account
    cout << "Depositing 10 to account " << s.accountNumber << endl;
    s.deposit(10);
    cout << "Balance is " << s.balance << endl;

    // wait until user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0;
}