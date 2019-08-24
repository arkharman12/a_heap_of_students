// student.h
#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS
#include "address.h"
#include "date.h"
#include <string>

class Student {
	private: 
		std::string firstName; 
		std::string lastName; 
		// address object
		Address * studentAddress; 
		// birthday object
		Date * birthDay; 
		// graduation date object
		Date * gradDay; 
		std::string gradePointAvg; 
		std::string completeCreditHours; 

	public:
		// default constructor
		Student(); 
		Student(std::string); 
		void set(std::string); 
		// destructor
		~Student(); 
		// all the getters and setters
		std::string getFirstName(); 
		void setFirstName(std::string); 
		std::string getLastName(); 
		void setLastName(std::string); 
		Address getStudentAddress(); 
		void setStudentAddress(Address*); 
		Date getBirthDay(); 
		void setBirthDay(Date*); 
		Date getGradDay(); 
		void setGradDay(Date*); 
		std::string getGPA(); 
		void setGPA(std::string); 
		std::string getCreditHours(); 
		void setCreditHours(std::string);
		// for printing the full object
		void printFull(); 
		// for just printing the name
		void printNames(); 
		// stream object that outputs the entire object
		friend std::ostream& operator<<(std::ostream& os, const Student& s); 
};
#endif 
