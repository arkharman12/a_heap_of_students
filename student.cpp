// student.cpp
#include <string>
#include <sstream>
#include "student.h"
#include "address.h"
#include "date.h"

// constructor that takes a string
Student::Student(std::string line) { 
	std::stringstream ss(line); 
	// address object
	Student::studentAddress = new Address(); 
	// date object for birthday
	Student::birthDay = new Date();
	// date object for gradDay 
	Student::gradDay = new Date(); 

	// initializes placeholder strings
	std::string tempAdd1, tempAdd2, tempCity, tempState, tempZIP, tempDOBDay, tempDOBMonth, tempDOBYear, tempGradDay, tempGradMonth, tempGradYear, tempGPA, tempCredHours; 

	// using the getline function to get the portion of lastname, firstname, tempAdd1 etc.
	getline(ss, Student::lastName, ','); 
	getline(ss, Student::firstName, ','); 
	getline(ss, tempAdd1, ','); 
	getline(ss, tempAdd2, ','); 
	getline(ss, tempCity, ','); 
	getline(ss, tempState, ','); 
	getline(ss, tempZIP, ','); 
	getline(ss, tempDOBDay, '/'); 
	getline(ss, tempDOBMonth, '/'); 
	getline(ss, tempDOBYear, ','); 
	getline(ss, tempGradDay, '/'); 
	getline(ss, tempGradMonth, '/'); 
	getline(ss, tempGradYear, ','); 
	getline(ss, tempGPA, ','); 
	getline(ss, tempCredHours); 

	// sets address 1, address 2, city , state etc.
	Student::studentAddress -> setAddLine1(tempAdd1); 
	Student::studentAddress -> setAddLine2(tempAdd2); 
	Student::studentAddress -> setCity(tempCity); 
	Student::studentAddress -> setState(tempState); 
	Student::studentAddress -> setZipCode(tempZIP); 
	Student::gradDay -> setDay(tempGradDay); 
	Student::gradDay -> setYear(tempGradYear); 
	Student::gradDay -> setMonth(tempGradMonth); 
	Student::birthDay -> setDay(tempDOBDay); 
	Student::birthDay -> setMonth(tempDOBMonth); 
	Student::birthDay -> setYear(tempDOBYear); 

	// sets gpa and credit hours
	Student::setGPA(tempGPA); 
	Student::setCreditHours(tempCredHours); 
}

// default constructor
Student::Student() { 
	Student::firstName = "";
	Student::lastName = "";
	Student::birthDay = new Date();
	Student::gradDay = new Date();
	Student::studentAddress = new Address();
	Student::gradePointAvg = "0";
	Student::completeCreditHours = "0";
}

// default destructor
Student::~Student() {
	//deletes address, birthday and graduation day from heap
	delete studentAddress;
	delete birthDay; 
	delete gradDay; 
}

// setter for first name
void Student::setFirstName(std::string firstn) { 
	Student::firstName = firstn;
}

// getter for firstname
std::string Student::getFirstName() { 
	return Student::firstName;
}

// setter for lastname
void Student::setLastName(std::string lastn) { 
	Student::lastName = lastn;
}

// getter for lastname
std::string Student::getLastName() { 
	return Student::lastName;
}

// getter for address
Address Student::getStudentAddress() { 
	return *Student::studentAddress;
}

// setter for address
void Student::setStudentAddress(Address * add) { 
	Student::studentAddress = add;
}

// getter for birthday
Date Student::getBirthDay() { 
	return *Student::birthDay;
}

// setter for birthday
void Student::setBirthDay(Date * bd) { 
	Student::birthDay = bd;
}

// getter for gradday
Date Student::getGradDay() { 
	return *Student::gradDay;
}

// setter for gradday
void Student::setGradDay(Date * gd) { 
	Student::gradDay = gd;
}

// getter for gpa
std::string Student::getGPA() { 
	return Student::gradePointAvg;
}

// setter for gpa
void Student::setGPA(std::string gpa) { 
	Student::gradePointAvg = gpa;
}

// getter for credit hours
std::string Student::getCreditHours() { 
	return Student::completeCreditHours;
}

// setter for credit hours
void Student::setCreditHours(std::string ch) { 
	Student::completeCreditHours = ch;
}

// stream the object's data 
std::ostream& operator << (std::ostream& os, const Student& s) { 
	os << s.lastName << ", " << s.firstName << " " << *s.studentAddress << " " << *s.birthDay << " " << *s.gradDay << " " << s.gradePointAvg << " " << s.completeCreditHours;
	return os;
}

// setter for the entire object, just takes a string
void Student::set(std::string line) { 
	std::stringstream ss(line);
	std::string tempAdd1, tempAdd2, tempCity, tempState, tempZIP, tempDOBDay, tempDOBMonth, tempDOBYear, tempGradDay, tempGradMonth, tempGradYear, tempGPA, tempCredHours;

	getline(ss, Student::lastName, ',');
	getline(ss, Student::firstName, ',');
	getline(ss, tempAdd1, ',');
	getline(ss, tempAdd2, ',');
	getline(ss, tempCity, ',');
	getline(ss, tempState, ',');
	getline(ss, tempZIP, ',');
	getline(ss, tempDOBDay, '/');
	getline(ss, tempDOBMonth, '/');
	getline(ss, tempDOBYear, ',');
	getline(ss, tempGradDay, '/');
	getline(ss, tempGradMonth, '/');
	getline(ss, tempGradYear, ',');
	getline(ss, tempGPA, ',');
	getline(ss, tempCredHours);

	Student::studentAddress -> setAddLine1(tempAdd1);
	Student::studentAddress -> setAddLine2(tempAdd2);
	Student::studentAddress -> setCity(tempCity);
	Student::studentAddress -> setState(tempState);
	Student::studentAddress -> setZipCode(tempZIP);

	Student::gradDay -> setDay(tempGradDay);
	Student::gradDay -> setYear(tempGradYear);
	Student::gradDay -> setMonth(tempGradMonth);

	Student::birthDay -> setDay(tempDOBDay);
	Student::birthDay -> setMonth(tempDOBMonth);
	Student::birthDay -> setYear(tempDOBYear);

	Student::setGPA(tempGPA);
	Student::setCreditHours(tempCredHours);
}

// prints the entire record
void Student::printFull() { 
	Student::printNames();
	std::cout << " ";
	studentAddress->printAddress();
	birthDay->printDate();
	std::cout << " ";
	gradDay->printDate();
	std::cout << gradePointAvg << ", " << completeCreditHours;
}

// prints the method that just prints first and last names
void Student::printNames() { 
	std::cout << firstName << " " << lastName;
}
