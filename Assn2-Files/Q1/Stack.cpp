/* 
 * Stack.cpp
 *
 * Description: Implementation of an int sequence with push/pop ...
 * Class Invariant: ... in a LIFO order
 * All the data values need to be int, else the stack implementation won't work.
 *
 * Author: Amogh Madhavan and Juliet Hu
 * Date: February 18, 2022
 */

#include <cstddef>  // For NULL
#include "Stack.h"

using namespace std;




        // Description:  Constructor
        // Postcondition:  Stack is empty
Stack::Stack(){
        head = NULL;
        tail = NULL;
}


        // Description: Destructor 
        // Postcondition: removes all the elements and destroys the stack and frees memory. Then head is NULL and tail is NULL to prevent memory leak.
Stack::~Stack(){  
        while(!isEmpty()){
                this->pop();
        }
        
        head = NULL;
        tail = NULL;
        //condition will be head is equal to null
}


        // Description:  Insert element x to the top of the stack.
        // Postcondition:  Element is inserted to the end of the stack meaning the tail.
void Stack::push(int x){
        StackNode* newNode = new StackNode();
        newNode->data = x;
        newNode->next = NULL;
        if(isEmpty()){
                head = newNode;
                tail = newNode;
                newNode = NULL;

        }
        else{
                tail->next = newNode;
                tail = newNode;
        }
}


        // Description:  Remove and return element at the top of the stack.
        // Precondition:  Stack must not be empty.
        // Postcondition:  Stack removes the last element (tail), else returns -1.
int Stack::pop(){
        //if stack is empty, -1 is retuned.
        if (isEmpty()){
                return -1;
        }
        //two pointers are used to traverse through the linked list and used to shift the tail back one node and delete the last node.
        StackNode* current;
        StackNode* previous;
        current = head;
        if (head->next == NULL){
                int val = current->data;
                delete head;
                head = NULL;
                tail = NULL;
                return val;
        }
        while(current->next != NULL){
                previous = current;
                current = current->next;
        }
        tail = previous;
        previous->next = NULL;
        int val = current->data;
        delete current;
        current = NULL;

        return val;      
}


        // Description:  Return the topmost element of the stack.
        // Precondition:  The list must not be empty
        // Postcondition:  top element is returned.
int Stack::peek() const{
        if(!isEmpty()){
                return tail->data;
        }
        else{
                return -1;
        }
}


        // Description:  Checks if the stack is empty.
        // Postcondition:  If tail is NULL, meaning no more nodes, true is returned else false is returned.
bool Stack::isEmpty() const{
        return tail == NULL;
}
