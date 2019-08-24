// date.cpp
#include <string> 
#include <iostream> 
#include "date.h" 

// default constructor
Date::Date() { 
	Date::month = "0";
	Date::day = "0";
	Date::year = "0";
} // end default constructor

// date constructor
Date::Date(std::string month, std::string day, std::string year) { 
	Date::month = month;
	Date::day = day;
	Date::year = year;
} // end date constructor

// default destructor
Date::~Date() {} 

// getter for month
std::string Date::getMonth() { 
	return Date::month;
}

// setter for month
void Date::setMonth(std::string monthnum) { 
	Date::month = monthnum;
}

// getter for day
std::string Date::getDay() {
	return Date::day;
}

// setter for day
void Date::setDay(std::string daynum) { 
	Date::day = daynum;
}

// getter for year
std::string Date::getYear() { 
	return Date::year;
}

// setter for year
void Date::setYear(std::string yearnum) { 
	Date::year = yearnum;
}

// creates function for operator that streams out the date content
std::ostream& operator << (std::ostream& os, const Date& d) {
	os << d.month << "/" << d.day << "/" << d.year;
	return os;
}

// prints date contents
void Date::printDate() { 
	std::cout << month << "/" << day << "/" << year;
}
