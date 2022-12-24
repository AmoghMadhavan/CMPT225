/*
 * BST.cpp
 * 
 * Description: Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are not allowed.
 *
 * Class invariant: It is always a BST.
 * 
 * Author: Amogh Madhavan and Juliet Hu
 * Date: March 9 2022*/

 

#include "BST.h"

#include <iostream>
using namespace std;

/* Constructors and destructor */

	// Default constructor
    template<class ElementType>
	BST<ElementType>::BST() {
		root = NULL;
		elementCount = 0;
	}
	
	// Parameterized constructor
    template<class ElementType>      
    BST<ElementType>::BST(ElementType& element) {
		root = new BSTNode<ElementType>(element);
		elementCount = 1;	
	}               

    // Copy constructor
    template<class ElementType>  
	BST<ElementType>::BST(const BST<ElementType>& aBST)  
	{
		if(aBST == NULL){
			root = NULL;
			elementCount = 0;
		}
		this->insert(aBST.root->element); 
		elementCount = aBST.elementCount;	

	}

	// Destructor 
    template<class ElementType> 
	BST<ElementType>::~BST() {

		this->destroy(root);
		root = NULL; 
    }                     
	
	
/* Getters and setters */

    // Description: Returns the number of elements currently stored in the binary search tree.	
	// Time efficiency: O(1)
	// Postcondition: Returns the number of elements within the BST
    template<class ElementType>	
	unsigned int BST<ElementType>::getElementCount() const {		
		return this->elementCount;
	}
	

/* BST Operations */

    // Description: Inserts an element into the binary search tree.
	//              This is a wrapper method which calls the recursive insertR( ).
	// Precondition: "newElement" does not already exist in the binary search tree.
    // Exception: Throws the exception "ElementAlreadyExistsException" 
	//            if "newElement" already exists in the binary search tree.
	// Time efficiency: O(log2 n)	
	// Postcondition: Inserts the element into the BST else if the element is already in the BST, throws and exception
    template<class ElementType>
	void BST<ElementType>::insert(const ElementType& newElement) {
	    // Binary search tree is empty, so add the new element as the root
		if (elementCount == 0) {
			root = new BSTNode<ElementType>(newElement);
			elementCount++;
		}
		else 
		  if ( !insertR(newElement, root) ) {
  	         throw ElementAlreadyExistsException("Element already exists in the data collection.");
  	      }
  	   return;
  	}

    // Description: Recursive insertion into a binary search tree.
	//              Returns true when "anElement" has been successfully inserted into the 
	//              binary search tree. Otherwise, returns false.
	//Precondition: Element must not exist in the BST
	//Postcondition: return false if element already exists else if the new element is lower in ascii value to the root, store in left side of tree else store in right side of tree.
    template<class ElementType>
	bool BST<ElementType>::insertR(const ElementType& anElement, BSTNode<ElementType>* current) { 

		if(current->element == anElement){
			return false;
		}
		
		if (current->element > anElement){
			if(current->left == NULL){
				current->left = new BSTNode<ElementType>(anElement);
				elementCount++;
				return true;
			}
			return insertR(anElement, current->left);
		}
		else{
			if(current->right == NULL){
				current->right = new BSTNode<ElementType>(anElement);
				elementCount++;
				return true;
			}
			return insertR(anElement, current->right);
		}
		
		return false;
	}

	
    // Description: Retrieves "targetElement" from the binary search tree.
	//              This is a wrapper method which calls the recursive retrieveR( ).
	// Precondition: Binary search tree is not empty.
    // Exception: Throws the exception "EmptyDataCollectionException" 
	//            if the binary search tree is empty.
	// Exception: Throws (propagates) the exception "ElementDoesNotExistException" 
	//            thrown from the retrieveR(...)
	//            if "targetElement" is not in the binary search tree.
	// Time efficiency: O(log2 n)
	// Postcondition: returns the tartgetelement.
    template<class ElementType>
    ElementType& BST<ElementType>::retrieve(const ElementType& targetElement) const {
        
	    // Check precondition: If binary search tree is empty
		if (elementCount == 0)  
			throw EmptyDataCollectionException("Binary search tree is empty.");
		
		// Otherwise, search for it		
		ElementType& translated = retrieveR(targetElement, root);

		return translated;
	}

    // Description: Recursive retrieval from a binary search tree.
	// Exception: Throws the exception "ElementDoesNotExistException" 
	//            if "targetElement" is not found in the binary search tree.
	//Precondition: BST must not be empty.
	//Postcondition: traverse through the tree inorder and find the targetelement, once found, return the element
    template<class ElementType>
    ElementType& BST<ElementType>::retrieveR(const ElementType& targetElement, BSTNode<ElementType>* current) const {

		if(elementCount == 1 && current->element == targetElement){
			return current->element;
		}
		if(current == NULL){
			throw ElementDoesNotExistException("Element does not exist.");
		}

		if(current->element == targetElement){
			return current->element;
		}

		if(targetElement < current->element){
			return retrieveR(targetElement, current->left);
		}
		else {
			return retrieveR(targetElement, current->right);
		}

	} // end of retrieveR
				
	
    // Description: Traverses the binary search tree in order.
	//              This is a wrapper method which calls the recursive traverseInOrderR( ).
	//              The action to be done on each element during the traverse is the function "visit".
	// Precondition: Binary search tree is not empty.
    // Exception: Throws the exception "EmptyDataCollectionException" 
	//            if the binary search tree is empty.
	// Time efficiency: O(n)		
    template<class ElementType>
	void BST<ElementType>::traverseInOrder(void visit(const ElementType&)) const {
		
		// Check precondition: If binary search tree is empty
		if (elementCount == 0)  
			throw EmptyDataCollectionException("Binary search tree is empty.");

		traverseInOrderR(visit, root);
		
		return;
	}

    // Description: Recursive in order traversal of a binary search tree.
	// Precondition: BST must not be empty.
	// Postcondition: Traverse through the BST using inorder, once done return.	
	template<class ElementType>
	void BST<ElementType>::traverseInOrderR(void visit(const ElementType&), BSTNode<ElementType>* current) const {
		
		if (current == NULL){
			return;
		}
		
		traverseInOrderR(visit, current->left);
		visit(current->element);
		traverseInOrderR(visit, current->right);

		return;
	}
	

    // Description: Destroys the nodes of the BST one by one using inorder traversal
	// Precondition: BST must not be empty.
	// Postcondition: Traverse through the BST using inorder and delete every single node until the root node is null	
	template<class ElementType>
	void BST<ElementType>::destroy(BSTNode<ElementType>* current) {
		
		if(current != NULL){
			destroy(current->left);
			delete current;
			destroy(current->right);
			

		}
		current = NULL;
	}
