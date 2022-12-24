/*
 * Dictionary.cpp
 * 
 * Description: Dictonary data collection ADT class.
 *              BST-based implementation.
 *              Duplicated elements not allowed.
 *              
 * Author: Amogh Madhavan and Juliet Hu
 * Date: March 9 2022
 */
#pragma once

#include "Dictionary.h"

// Default constructor
template <class ElementType>
Dictionary<ElementType>::Dictionary(){
    keyValuePairs = NULL;
}


// Parameterized constructor 
template <class ElementType>                           
Dictionary<ElementType>::Dictionary(ElementType& element){
    keyValuePairs = new BST<ElementType>(element);
}



// Destructor
// Destroys the dictionary by deleting the keyvaluepairs further invoking the destructor in the BST class freeing all the memory assigned.
template <class ElementType>           
Dictionary<ElementType>::~Dictionary(){
   
    delete keyValuePairs;
    keyValuePairs = NULL;

}                              

// Dictionary operations:
// Postcondition: return the number of elements in the dictionary.
template <class ElementType>
unsigned int Dictionary<ElementType>::getElementCount() const{
    return keyValuePairs->getElementCount();
}

// Description: Puts "newElement" into the dictionary.
// Precondition: keyvaluepairs must not be null, if it is, give it memory.
// postcondition: inserts the new element into the dictionary unless it already exists.
template <class ElementType>
void Dictionary<ElementType>::put(const ElementType& newElement){
    if(keyValuePairs == NULL){
        keyValuePairs = new BST<ElementType>();
    }   
    keyValuePairs->insert(newElement);
}
// Description: Gets "newElement" from the dictionary.
// postcondition: return the element requested.
template <class ElementType>
ElementType& Dictionary<ElementType>::get(const ElementType& targetElement) const{
    return keyValuePairs->retrieve(targetElement);
}


// Description: Displays all the elements in the dictionary and exits the program.
// Precondition: There must be a dictionary.
// Postcondition: Prints all the elements within the dictionary and their translations onto the console
template <class ElementType>
void Dictionary<ElementType>::displayContent(void visit(const ElementType&)) const{
    keyValuePairs->traverseInOrder(visit);
}

// end Dictionary

#include "Dictionary.cpp" // Including "Dictionary.cpp" (instead of copying the content of Dictionary.cpp) 
                          // is another way of creating templates.
