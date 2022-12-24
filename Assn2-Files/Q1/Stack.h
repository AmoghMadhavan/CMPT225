/* 
 * Stack.h
 *
 * Description: Implementation of an int sequence with push/pop ...
 * Class Invariant: ... in a LIFO order
 * All the data values need to be int, else the stack implementation won't work.
 *
 * Author: Amogh Madhavan and Juliet Hu
 * Date: February 18, 2022
 */
 
class Stack {

    private:

        // Description:  Nodes for a singly-linked list
        class StackNode {
            public:
                int data;
                StackNode * next;
        };
        

        // Description:  head = ptr to the first StackNode (NULL if empty)
        //               tail = ptr to the last StackNode (NULL if empty)
        // Class Invariant:  Follows Assignment 2 requirements, namely that the implementation 
        //                   is a singly-linked list, with insert/remove 
        //                   operations at the list's tail.
        StackNode * head;
        StackNode * tail;

    public:

        // Description:  Constructor
        // Postcondition:  Stack is empty
        Stack();


        // Description:  Destructor
        // Postcondition:  Empties the stack and destroys the linked list and frees memory
        ~Stack();


        // Description:  Insert element x to the top of the stack.
        // Postcondition: The element is added to the tail of the stack if the stack is not empty, else the element is both the head and tail if the stack is empty in the beginning.
        void push(int x);


        // Description:  Remove and return element at the top of the stack.
        // Precondition:  Stack must not be empty
        // Postcondition:  Removes the last element and returns the new value at the top. If stack is empty, return -1.
        int pop();


        // Description:  Return the topmost element of the stack.
        // Precondition:  Stack must not be empty
        // Postcondition:  Return the topmost element of the stack 
        int peek() const;


        // Description:  Checks whether the stack is empty or not
        // Postcondition:  return true if it is empty else false.
        bool isEmpty() const;
};


