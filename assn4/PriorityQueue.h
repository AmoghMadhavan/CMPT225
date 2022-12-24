/* 
 * PriorityQueue.h
 *
 * Description: Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order but based on priorty.
 * Is a wrapper, calls functions defined in the binary heap file.
 *
 * Author: Amogh Madhavan and Juliet Hu
 * Date: March 27, 2022
 */

#pragma once

#include "EmptyDataCollectionException.h"
#include "BinaryHeap.h"

template<class ElementType>
class PriorityQueue {
	
    private:

        BinaryHeap<ElementType> * elements; //Binary heap object of type elementtype      

    public:
        // Description:  Constructor
        PriorityQueue();
        // Description: Destructor
        ~PriorityQueue();



   
  


        // Description: Inserts newElement in this Priority Queue and 
        //              returns "true" if successful, otherwise "false".
        // Postcondition: An array extention of double is performed should there be more elements than the capatcity and element is added to the queue.
        bool enqueue(ElementType& newElement);


        // Description: Removes (but does not return) the element with the next
        //              "highest" priority value from the Priority Queue.
        // Precondition: This Priority Queue is not empty.
        // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
        void dequeue();


        // Description: Returns (but does not remove) the element with the next 
        //              "highest" priority from the Priority Queue.
        // Precondition: This Priority Queue is not empty.
        // Postcondition: This Priority Queue is unchanged by this operation.
        // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
        ElementType peek() const;


        // Description: Returns "true" if this Priority Queue is empty, otherwise "false".
        // Postcondition: This Priority Queue is unchanged by this operation.
        // Time Efficiency: O(1)
        bool isEmpty() const;
 
};


#include "PriorityQueue.cpp"
