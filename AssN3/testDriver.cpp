/*
 * testDriver.cpp
 * 
 * Description: Drives the testing of the BST, the BSTNode, 
 *              the WordPair and all the exceptions classes. 
 *
 * Author: AL
 * Last Modification Date: Feb. 2022
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "BST.h"
#include "WordPair.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"


void display(const WordPair& anElement) {
  cout << anElement << endl;
} // end of display


// As you discover what main() does, record your discoveries by commenting the code.
// If you do not like this main(), feel free to write your own.
// Remember, this is a test driver. Feel free to modify it as you wish!
int main(int argc, char *argv[]) {

  BST<WordPair>* testing = new BST<WordPair>();

  string aLine = "";
  string aWord = "";
  string englishW = "";
  string translationW = "";
  string filename = "dataFile.txt";
  string delimiter = ":";
  size_t pos = 0;
  WordPair translated;
 
  
  display(translated);

  ifstream myfile (filename);
  if (myfile.is_open()) {
  	cout << "Reading from a file:" << endl; 
    while ( getline (myfile,aLine) )
    {
       pos = aLine.find(delimiter);
       englishW = aLine.substr(0, pos);
       aLine.erase(0, pos + delimiter.length());
       translationW = aLine;
       WordPair aWordPair(englishW, translationW);
       try
        {
          testing->insert(aWordPair);
        }
        catch(ElementAlreadyExistsException& ex){
          cout<<ex.what();
          cout<<endl;
        }

	   // insert aWordPair into "testing" using a try/catch block
    }
    myfile.close();

    cout<<testing->getElementCount()<<endl;


    //If user entered "Display" at the command line ...
    if ( ( argc > 1 ) && ( strcmp(argv[1], "Display") == 0) ) {
        testing->traverseInOrder(&display);
        // ... then display the content of the BST.
    }

    else if (argc == 1) {
       // while user has not entered CTRL+D
       while ( getline(cin, aWord) ) {  

          WordPair aWordPair(aWord);

          try
          {
            cout<<testing->retrieve(aWordPair);
          }
          catch(ElementDoesNotExistException& ex){
            cout<<ex.what();
            cout<<endl;

          }
          
          // retrieve aWordPair from "testing" using a try/catch block
		  // print aWordPair

       }
    }
  }
  else 
    cout << "Unable to open file"; 

  return 0;
}