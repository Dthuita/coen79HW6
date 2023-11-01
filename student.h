/*
Group 3
Homework 3
3 of 4
*/
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
// #include <algorithm>

#include <string>

namespace coen79_hw6
{
    class Student
    {
    private:
        int studentID;
        std::string firstName;
        // std::string lastName;

    public:
        Student(); // Constructor

        // Getters and setters
        int getStudentID() const;
        std::string getFirstName() const;
        void setStudentID(int id);
        void setFirstName(const std::string &firstName);

        friend std::ostream &operator<<(std::ostream &os, const Student &student);
    };

}

#endif
