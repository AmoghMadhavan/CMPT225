/* 
 * Queue.cpp
 *
 * Description: Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author: Amogh Madhavan and Juliet Hu
 * Date: February 18, 2022
 */
  

#include "Queue.h"

// Description:  Constructor
Queue::Queue() : elementCount(0), capacity(INITIAL_CAPACITY), frontindex(0), backindex(0) {
    //array is given memory in the heap
    elements = new int[capacity];
} 

// Description: Destructor
// Postcondition: Deletes the array and frees memory.
Queue::~Queue(){

    delete [] elements;
    elementCount = 0;
}

// Description:  Inserts element x at the back (O(1))
// Postcondition: An array extention of double is performed should there be more elements than the capatcity and element is added to the queue.
void Queue::enqueue(int x) {
    //if the number of elements is larger than the capacity, new array is made with double capacity and all elements transferred then elements becomes the new array.
    if(elementCount == capacity){
        capacity = capacity * 2;
        int *newArr = new int[capacity]; 
        for(int i = 0; i < elementCount; i++){
            newArr[i] = elements[i];
        }
        delete [] elements;
        elements = newArr;
    }
    elementCount++;
    elements[backindex] = x;
    backindex = (backindex + 1) % (capacity + 1);    
} 

 // Description:  Removes the frontmost element (O(1))
// Precondition:  Queue not empty
// Postcondition: As elements are dequeued, array size decreases according requirement but doesn't fall below min capacity of 6, last element is given 0, for printing purposes only.;
void Queue::dequeue() {
    if(isEmpty()){
        return;
    }
    for(int i = 0; i < elementCount - 1; i++){
        elements[i] = elements[i + 1];
    }
    elementCount--;
    backindex--;
    //if elementcount is less than 6 and its 1/4 of the capacity  and the half current capacity is greater than 6 then array is made to 6 again.
    if((elementCount  < INITIAL_CAPACITY) && (elementCount < (0.25 * capacity)) && ((capacity * 0.5) >= INITIAL_CAPACITY)){
        capacity = capacity * 0.5;
        int *newArr = new int[capacity]; 
        for(int i = 0; i < elementCount; i++){
            newArr[i] = elements[i];
        }
        delete [] elements;
        elements = newArr;
    }

} 


// Description:  Returns a copy of the frontmost element (O(1))
// Precondition:  Queue not empty
// Postcondition: If queue is empty return -1, else return the frontmost element.
int Queue::peek() const {
    if (isEmpty()){
        return -1;
    }
    return elements[frontindex];
} 


// Description:  Returns true if and only if queue empty (O(1))
// Postcondition: If elementcount is 0, true is returned else false.
bool Queue::isEmpty() const {
    return elementCount == 0;
}




