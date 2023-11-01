/*
Group 3
Homework 3
2 of 4
*/
#include <string>
#include "scuclass.h"

namespace coen79_hw6
{
	SCUClass::~SCUClass()
	{
		// clear entire students vector
		students.clear();
	}

	void SCUClass::insert(int id, const std::string name)
	{
		// create Student instance and init
		Student new_student; // look up instance of class and pointers

		new_student.setStudentID(id);
		new_student.setFirstName(name);

		// store instance in vector
		students.push_back(new_student);
		numStudents++;
	}

	void SCUClass::remove(int id)
	{
		int position = 0;
		for (auto item = students.begin(); item != students.end(); ++item, ++position)
		{
			if (students[position].getStudentID() == id)
				students.erase(item);
		}
	}

	void SCUClass::traverse(int (*mapFunc)(const int, Student *, void *), void *n)
	{
		int i = 0;
		for (auto it = students.begin(); it != students.end(); ++it, ++i)
			(void)mapFunc(i, &students[i], n);
	}

}
