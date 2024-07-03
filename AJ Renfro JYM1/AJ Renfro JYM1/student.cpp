#include "student.h"
#include "degree.h"

Student::Student() 
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysArray; i++) this->numDaysIn3Courses[i] = 0;
	this->studentDegreeProgram = DegreeProgram::UNKNOWN;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDaysIn3Courses[], DegreeProgram studentDegreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysArray; i++) this->numDaysIn3Courses[i] = numDaysIn3Courses[i];
	this->studentDegreeProgram = studentDegreeProgram;
}

Student::~Student() {}

string Student::getID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getStudentAge() { return this->age; }
int* Student::getNumDays3Crs() { return this->numDaysIn3Courses; }
DegreeProgram Student::getDegreeProgram() { return this->studentDegreeProgram; }

void Student::setID(string ID) { this->studentID = ID; }
void Student::setFName(string fName) { this->firstName = fName; }
void Student::setLName(string lName) { this->lastName = lName; }
void Student::setEmailAddr(string emailAddr) { this->emailAddress = emailAddr; }
void Student::setStudentAge(int ageOfStudent) { this->age = ageOfStudent; }
void Student::setNumDays3Courses(int numDaysIn3Crs[])
{
	for (int i = 0; i < daysArray; i++) this->numDaysIn3Courses[i] = numDaysIn3Courses[i];
}
void Student::setDegreeProgram(DegreeProgram studentDegree) { this->studentDegreeProgram = studentDegree; }


void Student::print()
{
	cout << this->getID() << '\t';
	cout << "First Name: " << this->getFirstName() << '\t';
	cout << "Last Name: " << this->getLastName() << '\t';
	cout << "Age: " << this->getStudentAge() << '\t';
	cout << "daysInCourse: {" << this->getNumDays3Crs()[0] << ", ";
	cout << this->getNumDays3Crs()[1] << ", ";
	cout << this->getNumDays3Crs()[2] << "} ";
	cout << "Degree Program: " << degreeProgramStrings[this->getDegreeProgram()] << '\n';
}