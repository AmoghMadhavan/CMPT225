/* 
 * BinaryHeap.cpp
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

#include "BinaryHeap.h" 
#include <math.h>
#include <iostream>
using namespace std;
 // Header file

  
// Default Constructor
template<class ElementType>
BinaryHeap<ElementType>::BinaryHeap():capacity(MAX_CAPACITY) {
   elementCount = 0;
   //allocated memory dynamically
	elements = new ElementType[capacity];
   
} // end of default constructor

template<class ElementType>
BinaryHeap<ElementType>::~BinaryHeap(){
	delete [] elements;
	elements = NULL;
	elementCount = 0;
}


	
// Description: Returns the number of elements in the Binary Heap.
// Postcondition:  The Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
template<class ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const {
   return elementCount;
}  // end getElementCount


// Description: Inserts newElement into the Binary Heap.
//              It returns "true" if successful, otherwise "false".        
// Postcondition: Remains a minimum Binary Heap after the insertion.
// Time Efficiency: O(log2 n)
template<class ElementType>
bool BinaryHeap<ElementType>::insert(const ElementType& newElement) {

	if(elements == NULL){
		
	}

	bool ableToInsert = false;
	unsigned int indexOfRoot = 0;
	unsigned int indexOfBottom = elementCount;

	//adds element in the end of the array then reheapifies it using the utility methods.
	elements[indexOfBottom] = newElement;
	elementCount++;

	reHeapUp(indexOfBottom);

	ableToInsert = true;
	if(indexOfBottom > indexOfRoot){
		unsigned int indexOfParent = floor((indexOfBottom - 1)/2);
		if(!(elements[indexOfParent] <= elements[indexOfBottom])){
			ElementType temp;
			temp = elements[indexOfBottom];
			elements[indexOfBottom] = elements[indexOfParent];
			elements[indexOfParent] = temp;
			reHeapUp(indexOfParent);
			ableToInsert = true;
		}
	}
    return ableToInsert;

} // end insert


// Utility method - Recursively put the array back into a minimum Binary Heap.
template<class ElementType>
void BinaryHeap<ElementType>::reHeapUp(unsigned int indexOfBottom) {

	unsigned int indexofMaxChild = indexOfBottom;
	unsigned int parent = floor((indexOfBottom - 1)/2);	
	//base case: only one element in the array
	if(indexofMaxChild  == 0) {return;}

	// If we need to swap, select the largest child
    if(elements[indexOfBottom] <= elements[parent]){
		indexofMaxChild = parent;
	}
    	
	if(indexofMaxChild != indexOfBottom) {
		
	   ElementType temp = elements[indexOfBottom];
	   elements[indexOfBottom] = elements[indexofMaxChild];
	   elements[indexofMaxChild] = temp;
	   
	   // Recursively put the array back into a heap
	   reHeapUp(indexofMaxChild);
    }

	return;
	
} // end reHeapUp


// Description: Removes (but does not return) the element located at the root.
// Precondition: This Binary Heap is not empty.
// Postcondition: Remains a minimum Binary Heap after the removal.	
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template<class ElementType>
void BinaryHeap<ElementType>::remove() {

	if(elementCount == 0){
		throw(EmptyDataCollectionException("Binary Heap is Empty.")); 
	}
	if(elements == NULL){
		return;
	}
	unsigned int indexOfRoot = 0;
	ElementType temp = elements[elementCount-1];

	//puts element that is at the root at the end then decreases elements then recursively heapifies the heap
	elements[elementCount-1] = elements[indexOfRoot];
	elements[indexOfRoot] = temp;
	elementCount--;
	reHeapDown(indexOfRoot); 
	if(indexOfRoot < elementCount - 1){
		unsigned int indexOfLeftChild = 2*indexOfRoot+1;
		unsigned int indexOfRightChild = 2*indexOfRoot+2;
		unsigned indexOfMinChild = indexOfLeftChild;
		if(indexOfRightChild < indexOfLeftChild){
			indexOfMinChild = indexOfRightChild;
		}
		if(!(elements[indexOfRoot] <= elements[indexOfMinChild])){
			ElementType temp;
			temp = elements[indexOfMinChild];
			elements[indexOfMinChild] = elements[indexOfRoot];
			elements[indexOfRoot] = temp;
			reHeapDown(indexOfMinChild);
		}


	}
	return;
	
}  // end remove


// Utility method - Recursively put the array back into a minimum Binary Heap.
template<class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot) {

	unsigned int indexOfMinChild = indexOfRoot;
	
	// Find indices of children.
	unsigned int indexOfLeftChild = 2*indexOfRoot+1;
	unsigned int indexOfRightChild = 2*indexOfRoot+2;
    // Base case: elements[indexOfRoot] is a leaf as it has no children
	if(indexOfLeftChild > elementCount-1) {return;}

	if(elementCount == 0) {return;}

	// If we need to swap, select the smallest child
    // if (elements[indexOfRoot] > elements[indexOfLeftChild])
	if(!(elements[indexOfRoot] <= elements[indexOfLeftChild])){
    		indexOfMinChild = indexOfLeftChild;
	}
		
    // Check if there is a right child, is it the smallest?
    if(indexOfRightChild < elementCount) {
		// if (elements[indexOfMinChild] > elements[indexOfRightChild])
		if ( ! (elements[indexOfMinChild] <= elements[indexOfRightChild]) )
		    indexOfMinChild = indexOfRightChild;
	}

	// Swap parent with smallest of children.
	if(indexOfMinChild != indexOfRoot) {
	   ElementType temp = elements[indexOfRoot];
	   elements[indexOfRoot] = elements[indexOfMinChild];
	   elements[indexOfMinChild] = temp;
	   
	   // Recursively put the array back into a heap
	   reHeapDown(indexOfMinChild);
    }
	return;
	
	
} // end reHeapDown


// Description: Retrieves (but does not remove) the element located at the root.
// Precondition: This Binary Heap is not empty.
// Postcondition: This Binary Heap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(1) 
template<class ElementType>
ElementType BinaryHeap<ElementType>::retrieve() const {
	//enforce precondition
   if( elementCount > 0 ){
	   return elements[0];
   }
   else
      throw(EmptyDataCollectionException("retrieve() called with an empty BinaryHeap.")); 

}  // end retrieve


// For Testing Purposes
// Description: Prints the content of "rhs".
/*
template<class ElementType>
ostream& operator<<(ostream & os, const BinaryHeap<ElementType>& rhs) {
	
	for ( unsigned int index = 0; index < rhs.elementCount; index++ )
		os << rhs.elements[index]; // Print data

	return os;
} // end of operator <<

*/
//  End of implementation file.
