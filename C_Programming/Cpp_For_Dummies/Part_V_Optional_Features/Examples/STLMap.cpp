// STLMap - use a map container to retain a collection of objects ordered by a key
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

// SC - Student comparison function; designed to determine the sorting order of the students
struct SC
{
    bool operator()(const int id1, const int id2)const
    {
        return id1 < id2;
    }
};
// the map actually contains a Pair; the left element being the key while the right element is the data(in this case Student)
class Student;
typedef Student* SP;
typedef pair<const int, Student*> Pair;
typedef map<int, SP, SC> Map;
typedef map<int, SP, SC>::iterator MapIterator;

// collection of Students
Map students;

// Student - define the important properties of a student including the key use when looking him/her up from the student rolls(student id)
class Student
{
    public:
        Student(char* pszName, int id) : studentIDKey(id), name(pszName)
        {

        }
        // getKey - the key is used as an index into the map
        const int getKey()
        {
            return studentIDKey;
        }
        // display - create a meaningfull output for a Student object
        string display()
        {
            ostringstream out;
            out << studentIDKey << " - " << name;
            return out.str();
        }
    protected:
        // Student elements are keyed by student id
        const int studentIDKey;
        // the name of the student (plus any other data)
        string name;
};

int main(int argc, char* pArgs[])
{
    // add a few of students to the students collection - a map actually stores objects as pairs with the left member being the key
    // and the right the actual object
    Student* pS;
    pS = new Student("Sean Yours", 3456);
    Pair* ptr = new Pair(pS->getKey(), pS);
    students.insert(*ptr);

    // a map overloads the index operator to create the Pair and insert it into the map for us
    students[1234] = new Student("Fresch Man", 1234);
    students[5678] = new Student("Student, Jr.", 5678);

    // iterate through the collection of students, a map is always retained in the sorted order determined by the SC class
    cout << "Sorted list of students: " << endl;
    MapIterator iter = students.begin();
    while(iter != students.end())
    {
        Pair p = *iter;
        Student* s = p.second;
        cout << s->display() << endl;
        iter++;
    }

    // the increment and decrement operator can also be used to find the succesor and predecessor
    cout << "\nLook up student 3456" << endl;
    MapIterator p = students.find(3456);
    cout << "Found student " << p->second->display() << endl;

    MapIterator p1 = p;
    MapIterator prior = --p1;   // <- predecessor
    cout << "Predecessor = " << prior->second->display() << endl;

    MapIterator p2 = p;
    MapIterator succesor = ++p2;        // <- succesor

    cout << "Succesor = " << succesor->second->display() << endl;

    // find() returns the end iterator when it can't find the object in question; operator[] returns a NULL
    if(students.find(0123) == students.end())
    {
        cout << "The call students.find(0123) returns " << "students.end() since student 0123 doesn't exist" << endl;
    }
    // output using index
    cout << "To test index: students[3456] = " << students[3456]->display() << endl;

    if(students[0123] == NULL)
    {
        cout << "but students[0123] returns a NULL" << endl;
    }
    system("PAUSE");
    return 0;
}