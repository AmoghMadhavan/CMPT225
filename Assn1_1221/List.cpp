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


#include <iostream>

#include"Patient.h"
#include "List.h"

using namespace std;


	// Default constructor
List::List(){
	elementCount = 0;
	capacity = INITIAL_CAPACITY;
}
	
	// Destructor
	// Description: Destruct a List object, releasing heap-allocated memory.
List::~List(){
	this->removeAll();
}

	// Description: Returns the total element count currently stored in List.
int  List::getElementCount() const{
	return elementCount;
}

	// Description: Insert an element.
	// Precondition: newElement must not already be in data collection.  
	// Postcondition: newElement inserted and elementCount has been incremented.   
bool List::insert(const Patient& newElement){
	//Alocates memory on the heap to the array based on each new element.
	if(elementCount == 0){
		elements = new Patient[capacity];
		//in the event heap allocation fails, the funtion will return false.
		if(elements == NULL){
			//cout<<"Heap allocation has failed!"<<endl;
			return false;
		}
	}
	// checks if there already exists a carecard with the same number to maintain the integrity of the invariant.
	if(elementCount > 0){
		for(int i = 0; i < elementCount; i++){			
			if(elements[i].getCareCard() == newElement.getCareCard()){
			//cout<<"Patient with this carecard number already exists.";
			return false;
			}

		}
		for (int i = elementCount; i >= 1; i--){
			elements[i] = elements[i - 1];
		}
	}
	//makes room in the list for a element at point 0 so basically the front of array.
	//No reason, I just find it easier to know where the patient is being enetered.
	
	elements[0] = newElement;
	elementCount++;
	//sorting algorithm (implemented below) to sort the list in decending order.
	sortalgo();
	return true;

}

	// Description: Remove an element. 
	//Precondition: There must be at least one element present in the list.
	// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
bool List::remove( const Patient& toBeRemoved ){
	int flag;
	if(elements == NULL){
		return false;
	}
	if(elements == 0){
		//cout<<"List is empty.";
		return false;
	}
	for(int i = 0; i < elementCount; i++){
		if(elements[i].getCareCard() == toBeRemoved.getCareCard()){
			flag = i;
		}
	}
	
	for(int p = flag; p <= elementCount; p++){
		elements[p] = elements[p + 1];
	}
	elementCount--;
	//sorting algorithm (implemented below) to sort the list in decending order.
	sortalgo();
	return true;

//need to work on this algorithm...
//need to implement a sorting algorithm here before returning true.

}
	
	// Description: Remove all elements.
	// PreCondition: The list needs to have elements to remove if not it will just set to 0.
	// PostCondition: The list needs to remove all elements and set elementcount to 0.
void List::removeAll(){
	delete [] elements;
	elements = NULL;
	elementCount = 0;
}

	//delete the whole array delete [] the name of the array

   
	// Description: Search for target element.
	//              Returns a pointer to the element if found,
	//              otherwise, returns NULL.
	// PreCondition:The list needs to have elements.
	// PostCondition: The list needs to return the address of the target element from the list.
Patient* List::search(const Patient& target){

	for (int i = 0; i < elementCount; i++){
		if (elements[i].getCareCard() == target.getCareCard()){
			return &elements[i];
		}
	}
	return NULL;
}
	
	// Description: Prints all elements stored in List by descending order of search key.
	//Precondition: List needs to be sorted prior to running the function.
	//Postcondition: List needs to be printed in time complexity O(n).
void List::printList(){
	for(int i = 0; i < elementCount; i++){
		cout<<elements[i]<<endl;
	}
}

//Sorting algoritm, sorts the list at the time of call, however many present patient objects within the list, will be sorted in descending order.
void List::sortalgo(){
	for(int i=0; i < elementCount;i++){		
		for(int j=i+1; j < elementCount;j++)
		{
			//converts the carecard no. to int, so it  can be compared, so the list can be sorted.
			if((stol(elements[i].getCareCard())) < (stol(elements[j].getCareCard())))
			{
				Patient temp  = elements[i];
				elements[i] = elements[j];
				elements[j] = temp;
			}
		}
	}
}//End of List.cpp.


