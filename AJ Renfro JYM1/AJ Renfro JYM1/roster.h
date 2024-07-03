#pragma once
#include "student.h"

class Roster
{
public:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];

public:
	void parse(string studentData);

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);

	void remove(string studentID); //Removes student from roster by student ID, prints error if the student wasn't found. 
	void printAll(); //Loop through classRosterArray and call print() for each student. 
	void printAverageDaysInCourse(string studentID); //takes in Student ID, goes to that students 3 days array, adds them together and divides by 3. 
	void printInvalidEmails(); //A valid email should have an '@', a '.', and should not have a space. 
	void printByDegreeProgram(DegreeProgram degreeProgram); //prints students in the specified degree program, DegreeProgram being an enumerated type. 
	~Roster();
};