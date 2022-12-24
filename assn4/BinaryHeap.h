/* 
 * BinaryHeap.h
 *
 *
 * Description: Minimum Binary Heap data collection ADT class. 
 *              BST implementation.
 *
 * Class Invariant:  Always a Minimum Binary Heap
 * 
 * Author: Amogh Madhavan and Juliet Hu
 *
 * Date: March 27 2022
 *
 */  
#pragma once

#include <iostream>

#include "Event.h"
#include "EmptyDataCollectionException.h"   

using namespace std;

template<class ElementType>
class BinaryHeap {

private:

	unsigned int elementCount; //elementcount to keep track of number of elements.
	static const int MAX_CAPACITY = 12; //Allocate a MAX size for the array in the heap
	unsigned int capacity; //capacity of the array.
	ElementType* elements; //Array
	
	
	// Utility method - Recursively put the array back into a minimum Binary Heap.
	void reHeapUp(unsigned int indexOfBottom);

	// Utility method - Recursively put the array back into a minimum Binary Heap.
	void reHeapDown(unsigned int indexOfRoot);  
   
public:
	// Default Constructor
	BinaryHeap(); 

	// Description: Destructor
	~BinaryHeap();
	
    // Description: Returns the number of elements in the Binary Heap.
    // Postcondition:  The Binary Heap is unchanged by this operation.
	// Time Efficiency: O(1)
    unsigned int getElementCount() const;

	// Description: Inserts newElement into the Binary Heap.
	//              It returns "true" if successful, otherwise "false".        
	// Postcondition: Remains a minimum Binary Heap after the insertion.
	// Time Efficiency: O(log2 n)
	bool insert(const ElementType& newElement);
	   
	// Description: Removes (but does not return) the element located at the root.
	// Precondition: This Binary Heap is not empty.
	// Postcondition: Remains a minimum Binary Heap after the removal.	
	// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
	// Time Efficiency: O(log2 n)
	void remove();

	// Description: Retrieves (but does not remove) the element located at the root.
	// Precondition: This Binary Heap is not empty.
	// Postcondition: This Binary Heap is unchanged.
	// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
	// Time Efficiency: O(1) 
	ElementType retrieve() const;

	// For Testing Purposes
	// Description: Prints the content of "this". 
	//friend ostream & operator<<(ostream & os, const BinaryHeap& rhs);
   

}; // end BinaryHeap

#include "BinaryHeap.cpp"
