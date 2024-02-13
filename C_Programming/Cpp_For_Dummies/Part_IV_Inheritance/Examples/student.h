// Student - basic student
#ifndef _STUDENT
#define _STUDENT

namespace Schools
{
    class Student
    {
        public:
            Student(char* pszName, int nID);
            virtual char* display();
        protected:
            // student's name
            char* pszName;
            int nID;
    };
}
#endif