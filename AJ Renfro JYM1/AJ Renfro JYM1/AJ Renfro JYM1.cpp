#include "roster.h"

int main()
{
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Alex,Renfro,arenf11@wgu.edu,26,19,20,25,SOFTWARE"
	};

	const int numStudents = 5;

	cout << "Scripting and Programming - Applications - C867" << std::endl;
	cout << "Programming Language: C++" << std::endl;
	cout << "Student ID: #001255644" << std::endl;
	cout << "Alex 'AJ' Renfro" << std::endl << std::endl;

	Roster classRoster;

	for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);

	cout << "Displaying Student Information: " << std::endl;
	classRoster.printAll();
	cout << std::endl;

	cout << "Displaying all invalid Student emails: " << std::endl;
	classRoster.printInvalidEmails();
	cout << std::endl;

	cout << "Displaying average days for each student to complete 3 courses: " << std::endl;
		classRoster.printAverageDaysInCourse("A1");
		classRoster.printAverageDaysInCourse("A2");
		classRoster.printAverageDaysInCourse("A3");
		classRoster.printAverageDaysInCourse("A4");
		classRoster.printAverageDaysInCourse("A5");
		cout << std::endl;


	cout << "Displaying information for students in Software Degree Program: " << std::endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << std::endl;

	cout << "Removing Student A3 from class roster" << std::endl;
	classRoster.remove("A3");
	cout << std::endl;

	cout << "Attempting to remove student A3 Again..." << std::endl;
	classRoster.remove("A3"); //should display error message. 
	cout << std::endl;

	return 0;
};