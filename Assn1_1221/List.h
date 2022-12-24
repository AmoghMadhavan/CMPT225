/*
 * List.cpp
 * 
 * Class Description: Creates a array on the heap to store all the patients that are inputted into the walk in clinic..
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified. 
 * 					The list must be sorted.
 * 					Must be printed in O(n).
 *
 * Authors: Amogh Madhavan and Juliet Hu.
 * Date: Feb 1, 2022
 */

#pragma once

#include <string>
#include "Patient.h"

using namespace std;

// Array data structure to hold the patients
class List {

private:

	static const int INITIAL_CAPACITY = 10;                // constant INITIAL_CAPACITY
	Patient * elements;                  // Data structure of elements
	int elementCount;                  // Number of elements in the data structure
	int capacity;                      // Actual maximum capacity of data structure   

public:


	// Default constructor
	List();
	
	// Destructor
	// Description: Destruct a List object, releasing heap-allocated memory.
	~List();

	// Description: Returns the total element count currently stored in List.
	int  getElementCount() const;

	// Description: Insert an element.
	// Precondition: newElement must not already be in data collection.  
	// Postcondition: newElement inserted and elementCount has been incremented.   
	bool insert(const Patient& newElement);

	// Description: Remove an element. 
	// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
	bool remove( const Patient& toBeRemoved );
	
	// Description: Remove all elements.
	// Precondition: List must not be empty.
	// Postcondition: List should be empty and elementCount should be set to 0.
	void removeAll();

	//delete the whole array delete [] the name of the array

   
	// Description: Search for target element.
	//              Returns a pointer to the element if found,
	//              otherwise, returns NULL.
	// Precondition: List must not be empty and patient needs to have a valid carecard number.
	// Postcondition: Return the Patient with matching carecard number.
	Patient* search(const Patient& target);
	
	// Description: Prints all elements stored in List by descending order of search key.
	// Precondition: Elements stored in the list need to be in descending order.
	// Postcondition: Elements need to be printed in time complexity O(N).
	void printList();

	// Description: Sorts the patient objects based on the format requirement in descending.
	// Precondition: List must not be empty
	// Postcondition: List needs to be sorted in descending order by carecard number, as requested by the end user.
	void sortalgo();
	


}; // end List.h
