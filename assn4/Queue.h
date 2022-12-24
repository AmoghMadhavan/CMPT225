/* 
 * Queue.h
 *
 * Description: Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author: Amogh Madhavan and Juliet Hu
 * Date: March 27, 2022
 */

#pragma once

#include "EmptyDataCollectionException.h"

template<class ElementType>
class Queue {
	
    private:
        static unsigned const INITIAL_CAPACITY = 12; // Constant INITIAL_CAPACITY
        ElementType *elements;           

        unsigned elementCount;                      // Number of elements in the Queue
        unsigned capacity;                          // Actual capacity of the data structure (number of cells in the array)
        unsigned frontindex;                        // Index the topmost element
        unsigned backindex;                         // Index where the next element will be placed 

        void resize(unsigned len);
        

    public:
        // Description:  Defualt Constructor
        Queue();
        // Description:  Copy Constructor
        Queue(Queue& aQueue); 
        // Description: Destructor
        ~Queue();
       
        // Description: Inserts newElement at the "back" of this Queue 
        // (not necessarily the "back" of its data structure) and 
        // returns "true" if successful, otherwise "false".
        // Postcondition: An array extention of double is performed should there be more elements than the capatcity and element is added to the queue.
        // Time Efficiency: O(1)
        bool enqueue(ElementType& newElement);


        // Description: Removes (but does not return) the element at the "front" of this Queue 
        //              (not necessarily the "front" of its data structure).
        // Precondition: This Queue is not empty.
        // Exception: Throws EmptyDataCollectionException if this Queue is empty.   
        // Time Efficiency: O(1)
        // Postcondition: As elements are dequeued, array size decreases according requirement but doesn't fall below min capacity of 6, last element is given 0, for printing purposes only.;
        void dequeue();


        // Description: Returns (but does not remove) the element at the "front" of this Queue
        //              (not necessarily the "front" of its data structure).
        // Precondition: This Queue is not empty.
        // Postcondition: This Queue is unchanged by this operation.
        // Exception: Throws EmptyDataCollectionException if this Queue is empty.
             ElementType& peek() const;

        // Description: Returns "true" if this Queue is empty, otherwise "false".
        // Postcondition: This Queue is unchanged by this operation.
        // Time Efficiency: O(1)
             bool isEmpty() const;
   
};


#include "Queue.cpp"
