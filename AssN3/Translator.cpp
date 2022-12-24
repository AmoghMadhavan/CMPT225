/*
 * Translator.cpp
 * 
 * Description: Drives the testing of the BST, the BSTNode, Dictionary,
 *              the WordPair and all the exceptions classes. 
 *
 * Author: Amogh Madhavan and Juliet Hu
 * Date: March 9 2022
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
#include "Dictionary.h"
#include "WordPair.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"


void display(const WordPair& anElement) {
  cout << anElement;
} // end of display



int main(int argc, char *argv[]) {
  //create a dictionary object of type wordpard to provide the dictionary words and their translations
  Dictionary<WordPair>* testing = new Dictionary<WordPair>();


  //assign string variables for string break up process whilst reading the file, as show below in the code.
  string aLine = "";
  string aWord = "";
  string englishW = "";
  string translationW = "";
  string filename = "myDataFile.txt";
  string delimiter = ":";
  size_t pos = 0;

  //read the file
  ifstream myfile (filename);
  if (myfile.is_open()) {
    while ( getline (myfile,aLine) )
    {
       pos = aLine.find(delimiter);
       englishW = aLine.substr(0, pos);
       aLine.erase(0, pos + delimiter.length());
       translationW = aLine;
       //wordpair object, (the english word, the translation)
       WordPair aWordPair(englishW, translationW);
       //try catch block to catch exceptions.
       try
        {
            testing->put(aWordPair);
        }
        catch(ElementAlreadyExistsException& ex){
        }
    }
    myfile.close();

    //If user entered "Display" at the command line ...
    if ( ( argc > 1 ) && ( strcmp(argv[1], "display") == 0) ) {
        testing->displayContent(&display);
        // ... then display the content of the dictionary.
    }

    else if (argc == 1) {
       // while user has not entered CTRL+D
       while ( getline(cin, aWord) ) {  

          WordPair aWordPair(aWord);

          try
          {
            cout<<testing->get(aWordPair);//displays the word and its translation onto the console.
          }
          catch(ElementDoesNotExistException& ex){
            cout<<"***Not Found!***"<<endl;
          }
          
       }
    }
  }
  else{
    cout << "Unable to open file"; 
  }

  //delete the dictionary object to free all the memory being used.
  delete testing;
  testing = NULL;
  return 0;
}
