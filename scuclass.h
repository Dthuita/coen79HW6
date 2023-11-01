/*
Group 3
Homework 3
3 of 4
*/
#ifndef SCUCLASS_H
#define SCUCLASS_H

#include <iostream>
#include <vector>
#include "student.h"

#include <string>

namespace coen79_hw6
{
    class SCUClass
    {
    private:
        int numStudents; // Current number of students in the class
        std::vector<Student> students;

    public:
        SCUClass(){};
        ~SCUClass();
        SCUClass(SCUClass &other);

        // Member functions
        void insert(int id, const std::string name);
        void remove(int id);
        void traverse(int (*process)(const int, Student *, void *), void *);

        friend std::ostream &operator<<(std::ostream &os, const SCUClass &scuClass);
    };

    // Test function.  This is declaration only.
    int testSCUClass();
}

#endif
