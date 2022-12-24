/*
 * Dictionary.h
 * 
 * Description: Dictonary data collection ADT class.
 *              BST-based implementation.
 *              Duplicated elements not allowed.
 *              
 * Author: Amogh Madhavan and Juliet Hu
 * Date: March 9 2022
 */

 #pragma once

#include "BST.h"

template <class ElementType>
class Dictionary {
	
private:

/* You cannot change the following data member of this class. */
    BST<ElementType> * keyValuePairs;    
          
	
public:



    // Constructors and destructor:
	Dictionary();                               // Default constructor
    Dictionary(ElementType& element);           // Parameterized constructor 
    ~Dictionary();                              // Destructor 
	
    // Dictionary operations:
    // Postcondition: return the number of elements in the dictionary.
	unsigned int getElementCount() const;
	
	// Description: Puts "newElement" into the dictionary.
    // Precondition: keyvaluepairs must not be null, if it is, give it memory.
    // postcondition: inserts the new element into the dictionary unless it already exists.
	void put(const ElementType& newElement);

    // Description: Gets "newElement" from the dictionary.
    // postcondition: return the element requested.
	ElementType& get(const ElementType& targetElement) const;

    // Description: Displays all the elements in the dictionary and exits the program.
    // Precondition: There must be a dictionary.
    // Postcondition: Prints all the elements within the dictionary and their translations onto the console
    void displayContent(void visit(const ElementType&)) const;
	
}; // end Dictionary

#include "Dictionary.cpp" // Including "Dictionary.cpp" (instead of copying the content of Dictionary.cpp) 
                          // is another way of creating templates.
