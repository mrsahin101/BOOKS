// STLListUserClass - use a list to contain and sort a user defined class
#include <list>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

// Student - some example user defined class
class Student
{
    public:
        Student(char* pszName, int id)
        {
            name = new string(pszName);
            ssID = id;
        }
        string* name;
        int ssID;
};
// the following function is required to support the sort operation
bool operator<(Student& s1, Student& s2)
{
    return s1.ssID < s2.ssID;
}
// define the collection of students
list<Student> students;

int main(int argc, char* pArgs[])
{
    // add three student objects to the list
    students.push_back(*new Student("Marion Haste", 10));
    students.push_back(*new Student("Dewie Cheatum", 5));
    students.push_back(*new Student("Stew Dent, Sr.", 15));

    // now sort the list
    students.sort();

    // and iterate through the list
    // 1) allocate an iterator that points to the first element in the list
    list<Student>::iterator iter = students.begin();

    // 2) continue to loop through the list until the iterator hits the end of the list
    while(iter != students.end())
    {
        // 3) retrieve the Student that the iterator points at
        Student& s = *iter;
        cout << s.ssID << " - " << *s.name << endl;

        // 4) now move the iterator over to the next element in the list
        iter++;
    }
    system("PAUSE");
    return 0;
}