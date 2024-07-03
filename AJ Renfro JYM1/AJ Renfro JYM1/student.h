#pragma once
#include <iostream>
#include <iomanip>

#include "degree.h"

using std::string;
using std::cout;

class Student
{
public:
	const static int daysArray = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int numDaysIn3Courses[daysArray];
	DegreeProgram studentDegreeProgram;
public:
	Student(); //No parameters, sets to default values. 
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDaysIn3Courses[], DegreeProgram studentDegreeProgram); //Full constructor. 
	~Student();

	//Getters
	string getID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getStudentAge();
	int* getNumDays3Crs();
	DegreeProgram getDegreeProgram();

	//Setters
	void setID(string ID);
	void setFName(string fName);
	void setLName(string lName);
	void setEmailAddr(string emailAddr);
	void setStudentAge(int ageOfStudent);
	void setNumDays3Courses(int numDaysIn3Crs[]);
	void setDegreeProgram(DegreeProgram studentDegree);

	//static void printHeader();

	void print();
};