/*
 * walkIn.cpp
 * 
 * Class Description: Walk In Clinic Application.
 *
 * In this version, we use a List ADT on the Heap.
 * 
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified. 
 * 					        The list must be sorted.
 * 					        Must be printed in O(n).
 *
 * Created on: Feb 1, 2022
 * Date: Feb 1, 2022
 * Authors: Amogh Madhavan and Juliet Hu
 */

#include <iostream>
#include <string>
#include <cctype>
#include "Patient.h"
#include "List.h"

using namespace std;

/*Function calls the insert function implemented in list.cpp and inserts patients into the walk in clinic.*/
void join(List * thePatients, Patient placehol){
 
    string carecard="", name="", phone="", email="", address="";
    
    

    cout<< "Please enter the following Details: "<<endl;
    cin.ignore();
    cout << "Please, enter your carecard no: "; 
    getline(cin, carecard); 
    cout << "Please, enter your name: "; 
    getline(cin, name);
    cout << "Please, enter your address: "; 
    getline(cin, address);
    cout << "Please, enter your email id: "; 
    getline(cin, email);
    cout << "Please, enter your phone: "; 
    getline(cin, phone);
    //Conditions invoking different constructors depeneding on the information inputed from the user, patient records are created.
    if(carecard.size() == 0){
    //cout<<"Please enter a valid 10 digit carecard number."<<endl;
    return;
    }
    if((name.size() || phone.size() || email.size() || address.size()) > 0){
      //Calling constructor which takes in every data member input and based on what is presents creates the patient object.
      Patient patient_record(carecard, name, address, email, phone);
      placehol = patient_record;
      if ( thePatients->insert(placehol) ){
      cout << "Patient no.: " << placehol.getCareCard() << " has successfully joined the Walk In Clinic." << endl;
      }
      else
        cout << placehol << " was unable to join the Walk In Clinic!" << endl;
    }
    else{
      //invokes the constructor that onlys initialzes object with carecard number.
      Patient patient_record(carecard);
      placehol = patient_record;
      if ( thePatients->insert(placehol) ){
      cout << "Patient no.: " << placehol.getCareCard() << " has successfully joined the Walk In Clinic." << endl;
      }
      else
        cout << placehol << " was unable to join the Walk In Clinic!" << endl;
    }
  return;
}



//Search function looks for the target patient within the walk in clinic.
void search(List* thePatients){

  //If list is empty, it returns nothing, bringing you back to the options.;
  if(thePatients->getElementCount() == 0){
    cout<<"There are no patients currently in the Walk In Clinic!"<<endl;
    return;
  }
  string details;
  //creates a patient object with only the carecard to compare with the one inside the list, so the target element can be found.
  cout<<"Please enter a name or carecard no.: "; cin.ignore(); getline(cin, details);
  if(details.size() != 10){
    return;
  }
  Patient defaullt(details);
  Patient* ans = thePatients->search(defaullt);

  cout<<"The follwing is the Patient record you have requested: "<<endl;
  cout<<ans->getCareCard()<<" - Patient: "<<ans->getName()<<", "<<ans->getAddress()<<", "<<ans->getPhone()<<", "<<ans->getEmail()<<endl;

}


//function deletes patient requested based on carecard no. from the list and reduces the elementcount once its done.
void leave(List * thePatients) {
  string thecarecard = "";

  if ( thePatients->getElementCount() > 0 ) {


    thePatients->printList();

    // Get the patients's carecard no by creating a patient object.
    cout << "Please, enter the carecard of the Patient leaving: ";
    cin.ignore();
    getline(cin, thecarecard);
    if(thecarecard.size() != 10){
      return;
    }
    
    Patient member(thecarecard);

    // Remove Patient from list
    if ( thePatients->remove(member) )
      cout << "Patient has now left the records." << endl;
    else
      cout << "Patient was unable to leave!" << endl;  
    }
  else
      cout << "There are no patients yet!" << endl;  

  return;   
}

//Function modifies the patient information within the walk in clinic list. 
//All data members except carecard no. can be changed.
void modify(List * thePatients) {

  // if list is empty, returns nothing and takes you back to the options.
  if(thePatients->getElementCount() == 0){
    cout<<"There are no patients currently in the Walk In Clinic!"<<endl;
    return;
  }
  string details, newName, newAddress, newPhone, newEmail;
  cout<<"Please enter the carecard no. of the Patient whose details you want to modify: "; cin.ignore(); getline(cin, details);
  if(details.size() != 10){
    return;
  }
  Patient defaullt(details);
  Patient* ans = thePatients->search(defaullt);
  cout<<ans->getCareCard()<<" - Patient: "<<ans->getName()<<", "<<ans->getAddress()<<", "<<ans->getPhone()<<", "<<ans->getEmail()<<endl;
  cout<<"Please enter the Name: "; getline(cin, newName);
  if(newName.size() > 0)ans->setName(newName);
  cout<<"Please enter the address: "; getline(cin, newAddress);
  if(newAddress.size() > 0)ans->setAddress(newAddress);
  cout<<"Please enter the phone no: "; getline(cin, newPhone);
  if(newPhone.size() > 0)ans->setPhone(newPhone);
  cout<<"Please enter the email ID: "; getline(cin, newEmail);
  if(newEmail.size() > 0)ans->setEmail(newEmail);
}


//Basic switch cases are used here to call the functions by providing different options in the forms of cases.
int main() {

  // Variables declaration
  List* patients_sick = new List();
  Patient placehol;
  bool done = false;
  char input = 0;
  


  // Keep doing what the user selects until the user exits
  while (not done) {
    // Print menu to user 
    cout << "\n----Welcome to the Walk In Clinic!\n" << endl;
    cout << "To enter a new patient: n" << endl;
    cout << "To modify an existing patient: m" << endl;
    cout << "To search for a patient record: s" << endl;
    cout << "To leave the clinic enter: l" << endl;
    cout << "To delete all the patient records enter: r" << endl;
    cout << "To exit Patientform enter: x\n" << endl;

    cout << "Your choice: ";
    cin >> input;
    input = tolower(input);
    switch(input) {
      case 'n': join(patients_sick, placehol); break;
      case 's': search(patients_sick); break;
      case 'm': modify(patients_sick);break;
      case 'l': leave(patients_sick); break;
      case 'r': patients_sick->removeAll(); break;
      //prints all the patients within the walk in clinic in O(n).
      case 'x': cout<< "\n----Bye!\n" << endl; patients_sick->printList(); cout<<endl; done = true; break;
      default: cout << "Not sure what you mean! Please, try again!" << endl;
    }
    cout << "There are now " << patients_sick->getElementCount() << " patients in the Walk In Clinic." << endl; 
  }

  //frees the heap allocated space to prevent memory leak.
  delete patients_sick; 
  
  return 0;
}// end of walkIn.ccp.
