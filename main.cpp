// main.cpp 
#include <sstream>
#include <fstream>
#include "student.h"

// the swap function that changes string locations
void swap(std::string * a, std::string * b) { 
	std::string temporary = *a; 
	*a = *b; 
	*b = temporary; 
} //end swap

int i, j; 
// implements the bubblesort algorithms but with strings
void sortArray(std::string arr[]) { 
	for(i = 0; i < 51; i++) {
		for(j = 0; j < (51- i - 1); j++) {
			if (arr[j] > arr[j+1]) {
				swap(&arr[j], &arr[j+1]); 
			}
		}
	}
} // end sortArray

int main() {
	// this ifstream represents the input
	std::ifstream inFile; 
	//tells the current line on the file
	std::string currentLine; 
	
	// output stream for all three files
	std::ofstream fullReport; 
    	std::ofstream shortReport; 
    	std::ofstream alphaReport; 

	// open all three .txt files
  	fullReport.open("fullReport.txt"); 
  	shortReport.open("shortReport.txt"); 
  	alphaReport.open("alphaReport.txt" ); 
	
	// initializes a stringstream
	std::stringstream ss; 

	// array of pointers to each student student object on the heap
	Student *studArray = new Student[51];
	// arrayIndex counter for iteration
	int arrayIndex = 0;

	// open "student.dat" file
	inFile.open("students.dat");
	std::string inputline; 
	// for loop for  51 lines in the "students.dat" file
	for(arrayIndex = 0; arrayIndex < 51; arrayIndex++) {
		getline(inFile, inputline);
		studArray[arrayIndex].set(inputline); 
	}
	
	// counter variables for each file
	int x, y, z; 

	// this for loop will generate the full report file
	for (x = 0; x < 51; x++) { 
		fullReport << studArray[x] << std::endl;
	}

	// this for loop will generate short report file
	for (y = 0; y < 51; y++) {
		shortReport << studArray[y].getFirstName() << " " << studArray[y].getLastName() << std::endl;
	}

	std::string toBeSorted[51]; // initializes array of strings of first and last name to be sorted

	// loop to create the content for the array and to assign each element
    	for (int k = 0; k < 51; k++) { 
		toBeSorted[k] = studArray[k].getFirstName() + " " + studArray[k].getLastName();
	}

	//calling the function sortArray
	sortArray(toBeSorted);
	//this for will sort the array for us
	for (z = 0; z < 51; z++) { 
		alphaReport << toBeSorted[z] << std::endl;
	}

	// close all three files successfully
	fullReport.close(); 
    	shortReport.close(); 
    	alphaReport.close(); 

	// destructor for all the student array object
	delete[] studArray; 
	return 0; 
} // end main
