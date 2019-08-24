// address.h
#ifndef ADDRESS_H_EXISTS
#define ADDRESS_H_EXISTS
#include <string> 
#include <iostream>

class Address {
	private: 
		std::string addLine1; 
		std::string addLine2; 
		std::string City; 
		std::string State; 
		std::string zipCode;

	public:
		// default address constructor
		Address(); 
		Address(std::string, std::string, std::string, std::string, std::string);
		// destructor
		~Address(); 
		// all the getters and setters
		std::string getAddLine1(); 
		void setAddLine1(std::string); 
		std::string getAddLine2(); 
		void setAddLine2(std::string); 
		std::string getCity(); 
		void setCity(std::string); 
		std::string getState(); 
		void setState(std::string); 
		std::string getZipCode(); 
		void setZipCode(std::string); 
		// output stream
		friend std::ostream& operator << (std::ostream& os, const Address& a);
		// prints out the address
		void printAddress(); 
};
#endif
