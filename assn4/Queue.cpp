/* 
 * Queue.cpp
 *
 * Description: Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author: Amogh Madhavan and Juliet Hu
 * Date: March 27, 2022
 */
  

#include "Queue.h"

// Description:  Constructor
template<class ElementType>
Queue<ElementType>::Queue() : elementCount(0), capacity(INITIAL_CAPACITY), frontindex(0), backindex(0){
    //array is given memory in the heap
    elements = new ElementType[capacity];
}

// Description: copy constructor
template<class ElementType>
Queue<ElementType>::Queue(Queue& aQueue){
    if(aQueue == NULL){
        elements = NULL;
        elementCount = 0;
    }
    while(!aQueue.isEmpty()){
        this->enqueue(aQueue);
    }
    elementCount = aQueue.elementCount;

}

// Description: Destructor
// Postcondition: Deletes the array and frees memory.
template<class ElementType>
Queue<ElementType>::~Queue(){
    delete [] elements;
    elements = NULL;
    elementCount = 0;
}

// Description: Inserts newElement at the "back" of this Queue 
// (not necessarily the "back" of its data structure) and 
// returns "true" if successful, otherwise "false".
// Postcondition: An array extention of double is performed should there be more elements than the capatcity and element is added to the queue.
// Time Efficiency: O(1)
template<class ElementType>
bool Queue<ElementType>::enqueue(ElementType& newElement) {
    //if the number of elements is larger than the capacity, new array is made with double capacity and all elements transferred then elements becomes the new array.
    if(elements == NULL){
        return false;
    }
    if (elementCount == capacity) {
        // no more space:  double the capacity
        resize(capacity * 2);
    }
    elementCount++;
    elements[backindex] = newElement;
    backindex = (backindex + 1) % (capacity + 1);    

    return true;
} 

// Description: Removes (but does not return) the element at the "front" of this Queue 
//              (not necessarily the "front" of its data structure).
// Precondition: This Queue is not empty.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.   
// Time Efficiency: O(1)
// Postcondition: As elements are dequeued, array size decreases according requirement but doesn't fall below min capacity of 6, last element is given 0, for printing purposes only.;
template<class ElementType>
void Queue<ElementType>::dequeue() {
    //throws exception.
    if(isEmpty()){
        throw EmptyDataCollectionException("Queue is Empty");
        return;
    }
    //if elementcount is a quarter of the array size, array size is halved.
    if (elementCount <= capacity / 4) {
        if (capacity / 2 >= INITIAL_CAPACITY) {
            resize(capacity / 2);

        }
    }
    elementCount--;
    frontindex = (frontindex + 1) % capacity;
} 


// Description: Returns (but does not remove) the element at the "front" of this Queue
//              (not necessarily the "front" of its data structure).
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
template<class ElementType>
ElementType& Queue<ElementType>::peek() const {
    if (isEmpty()){
        throw EmptyDataCollectionException("Queue is Empty");
    }
    return elements[frontindex];
} 

// Description: Returns "true" if this Queue is empty, otherwise "false".
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(1)
template<class ElementType>
bool Queue<ElementType>::isEmpty() const {
    return elementCount == 0;
}

// Description:  Change the capacity of the array to newlen
// Precondition:  newlen >= INITIAL_CAPACITY
// Postcondition: Array has been doubled.
// O(n)
template<class ElementType>
void Queue<ElementType>::resize(unsigned newlen) {
    // no size change => nothing to do
    if (newlen == capacity) return;

    // precondition check
    if (newlen < INITIAL_CAPACITY) return;

    // allocate new space
    ElementType * newElements = new ElementType[newlen];
	if ( newElements == NULL ) return;
	
    // copy elements to new space
    for (unsigned int i = 0; i < elementCount; i++) {
        newElements[i] = elements[(i+frontindex) % capacity];
    }

    // recycle new space
    delete [] elements;
    elements = newElements;

    // update properties
    capacity = newlen;
    frontindex = 0;
    backindex = (elementCount % capacity);
	
	return;
} // resize
