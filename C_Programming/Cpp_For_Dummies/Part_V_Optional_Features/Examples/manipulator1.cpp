#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

void fn(float interest, float dollarAmount)
{
    cout << "Dollar amount : ";
    cout.precision(2);
    cout << dollarAmount;
    cout.precision(4);
    cout << "\ninterest :";
    cout << interest << "\n";
}
void fn2(float interest, float dollarAmount)
{
    cout << "Dollar amount = " << setprecision(2) << dollarAmount << "\nInterest = "<< setprecision(4) << interest << "\n";
}

int main(int argcs, char* argv[])
{
    fn(4.123456789, 2.123456789);
    fn2(4.123456789, 2.123456789);
}