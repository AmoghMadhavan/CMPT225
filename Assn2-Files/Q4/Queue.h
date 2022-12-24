/* 
 * Queue.h
 *
 * Description: Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author: Amogh Madhavan and Juliet Hu
 * Date: February 18, 2022
 */
  
class Queue {
	
    private:
        static unsigned const INITIAL_CAPACITY = 6; // Constant INITIAL_CAPACITY
        int *elements;            

        unsigned elementCount;                      // Number of elements in the Queue
        unsigned capacity;                          // Actual capacity of the data structure (number of cells in the array)
        unsigned frontindex;                        // Index the topmost element
        unsigned backindex;                         // Index where the next element will be placed                     

    public:
        // Description:  Constructor
        Queue();

        // Description: Destructor
        ~Queue();


        // Description:  Inserts element x at the back (O(1))
        // Postcondition: An array extention of double is performed should there be more elements than the capatcity and element is added to the queue.
        void enqueue(int x);


        // Description:  Removes the frontmost element (O(1))
        // Precondition:  Queue not empty
        // Postcondition: As elements are dequeued, array size decreases according requirement but doesn't fall below min capacity of 6, last element is given 0, for printing purposes only.;
        void dequeue();


        // Description:  Returns a copy of the frontmost element (O(1))
        // Precondition:  Queue not empty
        // Postcondition: If queue is empty return -1, else return the frontmost element.
        int peek() const;


        // Description:  Returns true if and only if queue empty (O(1))
        // Postcondition: If elementcount is 0, true is returned else false.
        bool isEmpty() const;
};


