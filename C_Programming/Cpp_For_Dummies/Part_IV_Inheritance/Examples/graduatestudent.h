// GraduateStudent - a special type of Student
#ifndef _GRADUATE_STUDENT_
#define _GRADUATE_STUDENT_
#include "student.h"

namespace Schools
{
    class GraduateStudent : public Student
    {
        public:
            // Trivial constructors
            GraduateStudent(char* pszName, int nID) : Student(pszName, nID)
            {

            }
            // demonstration virtual function
            virtual char* display();
    };
}
#endif