// VirtualInheritance - using virtual inheritance the Bed and Sofa classes can share a common base
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

// Furniture - more fundamental concept; this class has "weight" as a property
class Furniture
{
    public:
        Furniture(int w = 0) : weight(w)
        {

        }
        int weight;
};

class Bed : virtual public Furniture
{
    public:
        Bed()
        {

        }
        void sleep()
        {
            cout << "Sleep" << endl;
        }
};

class Sofa : virtual public Furniture
{
    public:
        Sofa()
        {

        }
        void watchTv()
        {
            cout << "Watch TV" << endl;
        }
};

// SleeperSofa - is both a Bed and a Sofa
class SleeperSofa : public Bed, public Sofa
{
    public:
        SleeperSofa(int weight) : Furniture(weight)
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

    // Section 1 - the following is no longer ambiguous there's one weight shared between Sofa and Bed Furniture::Sofa or a Furniture::Bed?
    cout << "Weight = " << ss.weight << endl;

    // Section 2 - the following specifies the inheritance path unambiguously - sort of ruins the effect
    SleeperSofa* pSS = &ss;
    Sofa* pSofa = (Sofa*)pSS;
    Furniture* pFurniture = (Furniture*) pSofa;

    cout << "Weight = " << pFurniture->weight << endl;

    // wait until user is ready before terminating program to allow the user to see the program results
    system("PAUSE");
    return 0;
}