/*
 * Patient.cpp
 * 
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified. 
 * 					The list must be sorted.
 * 					Must be printed in O(n). 
 *
 * Authors: Amogh Madhavan and Juliet Hu.
 * Date: Feb 1, 2022
 */


#include <iostream>
#include <string>
#include "Patient.h"

// Default Constructor
// Description: Create a patient with a care card number of "0000000000". 
// Postcondition: All data members set to "To be entered", 
//                except the care card number which is set to "0000000000".       
Patient::Patient() {
	
	careCard = "0000000000";
	name = "To be entered";
	address = "To be entered";
	email = "To be entered";
	phone = "To be entered";


}

// Parameterized Constructor
// Description: Create a patient with the given care card number.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aCareCard) {
	
	if (aCareCard.size() != 10){
		careCard = "0000000000";
	}
	else{
		careCard = aCareCard;	
	}
	
	name = "To be entered";
	address = "To be entered";
	email = "To be entered";
	phone = "To be entered";

}


// Parameterized Constructor
// Description: Create a patient with the given care card number.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members that aren't passed on by the user at the input time will be set to "To be entered".

//my made constructor, creates a patient object with whatever data the user inputs at the time, whatever not inputted
//will be set to the default data, ei("to be entered")...
Patient::Patient(string aCareCard, string patientName, string patientAddress, string patientEmail, string patientPhone){
	if (aCareCard.size() != 10){
		careCard = "0000000000";
	}
	else{
		careCard = aCareCard;	
	}
	if (patientName.size() > 0 ){
		name = patientName;
	}
	else{
		name = "To be entered";	
	}
	if (patientAddress.size() > 0 ){
		address = patientAddress;
	}
	else{
		address = "To be entered";	
	}
	if (patientEmail.size() > 0 ){
		email = patientEmail;
	}
	else{
		email = "To be entered";	
	}
	if (patientPhone.size() > 0 ){
		phone = patientPhone;
	}
	else{
		phone = "To be entered";	
	}
}



	// Getters and setters
	// Description: Returns patient's name.
string Patient::getName() const{
	return name;
}

	// Description: Returns patient's address.
string Patient::getAddress() const{
	return address;
}

	// Description: Returns patient's phone.
string Patient::getPhone() const{
	return phone;
}

	// Description: Returns patient's email.
string Patient::getEmail() const{
	return email;
}
	
	// Description: Returns patient's care card.
string Patient::getCareCard() const{
	return careCard;
}

	// Description: Sets the patient's name.
void Patient::setName(const string aName){
	name = aName;
}

	// Description: Sets the patient's address.
void Patient::setAddress(const string anAddress){
	address = anAddress;	
}

	// Description: Sets the patient's phone.
void Patient::setPhone(const string aPhone){
	phone = aPhone;
}

	// Description: Sets the patient's email.
void Patient::setEmail(const string anEmail){
	email = anEmail;
}




// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number.
bool Patient::operator == (const Patient & rhs) {
	
	// Compare both Patient objects
	return this->careCard == rhs.getCareCard();
	
} // end of operator ==

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is > the care card 
//              number of "rhs" Patient object
bool Patient::operator > (const Patient & rhs) {
	
	// Compare both Patient objects
	return this->careCard > rhs.getCareCard();
	
} // end of operator >

// Description: Less than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is < the care card 
//              number of "rhs" Patient object.
bool Patient::operator < (const Patient & rhs) {
	
	// Compare both Patient objects
	return this->careCard < rhs.getCareCard();
	
} // end of operator <

// For testing purposes!
// Description: Prints the content of "this".
ostream & operator<<(ostream & os, const Patient & p) {
	
	os << p.careCard << " - Patient: " << p.name << ", "
	   << p.address << ", " << p.phone << ", " << p.email << endl;  
	     
	return os;

} // end of operator<<

// end of Patient.cpp
