#include "roster.h"

void Roster::parse(string studentData)
{
	int rhs = studentData.find(",");
	string studentID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));

	DegreeProgram degreeprogram = UNKNOWN;
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string degProg = studentData.substr(lhs, rhs - lhs);
	if (degProg.at(2) == 'C') degreeprogram = SECURITY;
	else if (degProg.at(2) == 'T') degreeprogram = NETWORK;
	else if (degProg.at(2) == 'F') degreeprogram = SOFTWARE;
	else degreeprogram = UNKNOWN;

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourseourse3, DegreeProgram degreeprogram)
{
	int dayArray[3] = { daysInCourse1,daysInCourse2,daysInCourseourse3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, dayArray, degreeprogram);
}

void Roster::printAll()
{
	for (int i = 0; i < Roster::numStudents; i++)
	{
		classRosterArray[i]->print(); 
	}
}

void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getID() == studentID)
		{
				cout << classRosterArray[i]->getID() << ": ";
				cout << (classRosterArray[i]->getNumDays3Crs()[0] +
					classRosterArray[i]->getNumDays3Crs()[1] +
					classRosterArray[i]->getNumDays3Crs()[2]) / 3 << std::endl;
		}
	}
}

void Roster::printInvalidEmails()
{
	bool isNotValid = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string sEmail = (classRosterArray[i]->getEmailAddress());
		if (sEmail.find('@') == string::npos || sEmail.find('.') == string::npos || sEmail.find(' ') != string::npos)
		{
			isNotValid = true;
			cout << "Student: " << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName() << " has an invalid email on file." << std::endl;
		}
	}
	if (!isNotValid) cout << "No invalid emails to display." << std::endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
	}
	cout << std::endl;
}




void Roster::remove(string studentID)
{
	int numMinusOne = numStudents - 1; 
	bool isStudent = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getID() == studentID)
		{
			isStudent = true;
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
	if (isStudent == true)
	{
		cout << studentID << " removed from class roster." << std::endl << std::endl;

		cout << "Updated class roster: " << std::endl;
		
		for (int i = 0; i < numMinusOne; i++)
		{
			classRosterArray[i]->print();

		}

	}
	else if (isStudent == false)
	{
		cout << studentID << " not found." << std::endl << std::endl;
	}
}

Roster::~Roster()
{
	cout << "Destructor process initiated, dynamically allocated memory will be deleted" << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Destroying Student #: " << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}