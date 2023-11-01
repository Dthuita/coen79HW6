/*
Group 3
Homework 3
4 of 4
*/
#include "scuclass.h"

namespace coen79_hw6
{
    Student::Student() {}

    int Student::getStudentID() const
    {
        return studentID;
    }

    std::string Student::getFirstName() const
    {
        return firstName;
    }

    void Student::setStudentID(int id)
    {
        studentID = id;
    }

    void Student::setFirstName(const std::string &fName)
    {
        firstName = fName;
    }

    std::ostream &operator<<(std::ostream &os, const Student &student)
    {
        std::cout << "Student ID: " << student.getStudentID() << "  First Name: " << student.getFirstName() << std::endl;

        return os;
    }
}
