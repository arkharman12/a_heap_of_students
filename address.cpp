// address.cpp
#include <iostream> 
#include "address.h" 

// default constructor
Address::Address() { 
	Address::addLine1 = "";
	Address::addLine2 = "";
	Address::City = "";
	Address::State = "";
	Address::zipCode = "12345";
} // end default constructor

// non-dedault constructor
Address::Address(std::string add1, std::string add2, std::string city, std::string state, std::string zip) { 
	Address::addLine1 = add1;
	Address::addLine2 = add2;
	Address::City = city;
	Address::State = state;
	Address::zipCode = zip;
} // end non-dedault constructor

// default destructor
Address::~Address() {} 

// getter for 1st address line
std::string Address::getAddLine1() { 
	return Address::addLine1;
}

// setter for 1st address line
void Address::setAddLine1(std::string input) { 
	Address::addLine1 = input;
}

// getter for 2nd address line
std::string Address::getAddLine2() { 
	return Address::addLine2;
}

// setter for 2nd address line
void Address::setAddLine2(std::string input) { 
	Address::addLine2 = input;
}

// getter for city
std::string Address::getCity() { 
	return Address::City;
}

// setter for city
void Address::setCity(std::string city) { 
	Address::City = city;
}

// getter for state
std::string Address::getState() { 
	return Address::State;
}

// setter for state
void Address::setState(std::string state) { 
	Address::State = state;
}

// getter for zip code
std::string Address::getZipCode() { 
	return Address::zipCode;
}

// setter for zip code
void Address::setZipCode(std::string zip) { 
	Address::zipCode = zip;
}

// output stream
std::ostream& operator << (std::ostream& os, const Address& a) { 
	os << a.addLine1 << " " << a.addLine2 << " " << a.City << ", " << a.State << " " << a.zipCode;
	return os;
}

// prints out the address
void Address::printAddress() { 
	std::cout << addLine1 << " " << addLine2 << ", " << City << ", " << State << zipCode;
}

