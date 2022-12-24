/* 
 * PriorityQueue.cpp
 *
 * Description: Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order but based on priorty.
 * Is a wrapper, calls functions defined in the binary heap file.
 *
 * Author: Amogh Madhavan and Juliet Hu
 * Date: March 27, 2022
 */
  

#include "PriorityQueue.h"

// Description: Default Constructor
template<class ElementType>
PriorityQueue<ElementType>::PriorityQueue(){
    elements = new BinaryHeap<ElementType>();
}

// Description: Destructor
// Postcondition: Deletes the array and frees memory.
template<class ElementType>
PriorityQueue<ElementType>::~PriorityQueue(){
    delete elements;
    elements = NULL;    

}

// Description: Inserts newElement in this Priority Queue and 
//              returns "true" if successful, otherwise "false".
// Postcondition: An array extention of double is performed should there be more elements than the capatcity and element is added to the queue.
template<class ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType& newElement) {
    if(elements == NULL){
        return false; 
    }
    //wrapper method to call insert in binary heap file
    elements->insert(newElement);
    return true;
} 

// Description: Removes (but does not return) the element with the next
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
template<class ElementType>
void PriorityQueue<ElementType>::dequeue() {
    if(elements == NULL){
        return;
    }
    if(isEmpty()){
        throw EmptyDataCollectionException("PriorityQueue is Empty");
    }
    //wrapper method to call remove in binary heap file
    elements->remove();
} 


// Description: Returns (but does not remove) the element with the next 
//              "highest" priority from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
template<class ElementType>
ElementType PriorityQueue<ElementType>::peek() const {
    if (isEmpty()){
        throw EmptyDataCollectionException("PriorityQueue is Empty");
    }
    //wrapper method to call retrieve in binary heap file.
    return elements->retrieve();
} 

// Description: Returns "true" if this Priority Queue is empty, otherwise "false".
// Postcondition: This Priority Queue is unchanged by this operation.
// Time Efficiency: O(1)
template<class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const {
    return elements->getElementCount() == 0; 
}
