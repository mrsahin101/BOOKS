// MultipleInheritanceFactoring - a single class can inherit from more than one base class
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

// Furniture - more fundamental concept; this class has "weight" as property
class Furniture
{
    public:
        Furniture(int w) : weight(w)
        {

        }
        int weight;
};

class Bed : public Furniture
{
    public:
        Bed(int weight) : Furniture(weight)
        {

        }
        void sleep()
        {
            cout << "Sleep" << endl;
        }
};

class Sofa : public Furniture
{
    public:
        Sofa(int weight) : Furniture(weight)
        {

        }
        void watchTV()
        {
            cout << "Watch TV" << endl;
        }
};

// SleeperSofa - is both a Bed and a Sofa
class SleeperSofa : public Bed, public Sofa
{
    public:
        SleeperSofa(int weight) : Sofa(weight), Bed(weight)
        {

        }
        void foldOut()
        {
            cout << "Fold out" << endl;
        }
};

int main(int nNumberofArgs, char* pszArgs[])
{
    SleeperSofa ss(10);

    // Section 1 - The following is ambiguous; is this a Furniture::Sofa or a Furniture::Bed?
    /* cout << "Weight = " << ss.weight << endl; */

    // Section 2 - The following specifies the inheritance path unambiguously - sorf of ruins the effect
    SleeperSofa* pSS = &ss;
    Sofa* pSofa = (Sofa*)pSS;

    Furniture* pFurniture = (Furniture*)pSofa;
    cout << "Weight = " << pFurniture->weight << endl;

    // wait until user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0;
}