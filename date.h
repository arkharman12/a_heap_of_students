// date.h
#ifndef DATE_H_EXISTS
#define DATE_H_EXISTS
#include <iostream>
#include <string>

class Date {
	private: 
		std::string month; 
		std::string day; 
		std::string year; 
	public:
		// default date constructor
		Date(); 
		Date(std::string, std::string, std::string); 
		// default destructor
		~Date(); 
		// all the getters and setters
		std::string getMonth(); 
		void setMonth(std::string); 
		std::string getDay(); 
		void setDay(std::string); 
		std::string getYear(); 
		void setYear(std::string);
		// output stream for the date
		friend std::ostream& operator << (std::ostream& os, const Date& d); 
		// prints out the entire date
		void printDate(); 
};
#endif
